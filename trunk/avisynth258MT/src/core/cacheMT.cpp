// Avisynth v2.5.  Copyright 2002 Ben Rudiak-Gould et al.
// http://www.avisynth.org

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA, or visit
// http://www.gnu.org/copyleft/gpl.html .
//
// Linking Avisynth statically or dynamically with other modules is making a
// combined work based on Avisynth.  Thus, the terms and conditions of the GNU
// General Public License cover the whole combination.
//
// As a special exception, the copyright holders of Avisynth give you
// permission to link Avisynth with independent modules that communicate with
// Avisynth solely through the interfaces defined in avisynth.h, regardless of the license
// terms of these independent modules, and to copy and distribute the
// resulting combined work under terms of your choice, provided that
// every copy of the combined work is accompanied by a complete copy of
// the source code of Avisynth (the version of Avisynth used to produce the
// combined work), being distributed under the terms of the GNU General
// Public License plus this exception.  An independent module is a module
// which is not derived from or based on Avisynth, such as 3rd-party filters,
// import and export plugins, or graphical user interfaces.


#include "stdafx.h"

#include "cacheMT.h"


#ifndef _DEBUG
// Release mode logging
//#define OPT_RELS_LOGGING
#ifdef OPT_RELS_LOGGING

#undef _RPT0
#undef _RPT1
#undef _RPT2
#undef _RPT3
#undef _RPT4

#define _RPT0(rptno, msg)                     ReportMe(msg)                         
#define _RPT1(rptno, msg, a1)                 ReportMe(msg, a1)                  
#define _RPT2(rptno, msg, a1, a2)             ReportMe(msg, a1, a2)            
#define _RPT3(rptno, msg, a1, a2, a3)         ReportMe(msg, a1, a2, a3)      
#define _RPT4(rptno, msg, a1, a2, a3, a4)     ReportMe(msg, a1, a2, a3, a4)
#define _RPT5(rptno, msg, a1, a2, a3, a4, a5) ReportMe(msg, a1, a2, a3, a4, a5)

void ReportMe(const char * msg, ...);

#else
#define _RPT5(rptno, msg, a1, a2, a3, a4, a5)
#endif
#else
#define _RPT5(rptno, msg, a1, a2, a3, a4, a5) _RPT4(rptno, msg, a1, a2, a3, a4)
#endif

extern DWORD TlsIndex;  // in main.cpp


// Global statistics counters
extern struct {
  unsigned long resets;
  unsigned long vfb_found;
  unsigned long vfb_modified;
  unsigned long vfb_stolen;
  unsigned long vfb_notfound;
  unsigned long vfb_never;
  long          vfb_locks;
  long          vfb_protects;
  char tag[72];
} g_Cache_stats;


AVSFunction CacheMT_filters[] = {
  { "InternalCacheMT", "c+", CacheMT::Create_Cache },
  { 0 }
};
 

int wokingthreadcount = 0;

enum {CACHE_SCALE_FACTOR      =  16}; // Granularity fraction for cache size - 1/16th
enum {MAX_CACHE_MISSES        = 100}; // Consecutive misses before a reset
enum {MAX_CACHED_VIDEO_FRAMES = 200}; // Maximum number of VFB's that are tracked
enum {MAX_CACHE_RANGE         =  21}; // Maximum CACHE_RANGE span i.e. number of protected VFB's

/*******************************
 *******   Mode3Gate      ******
 ******************************/

Mode3Gate::Mode3Gate(PClip clip,Mode3Gate* last,IScriptEnvironment *env):GenericVideoFilter(clip),last(last){}

void Mode3Gate::SetCriticalSection(CRITICAL_SECTION* csmode3)
{
	cs=csmode3;
    if(last)
		last->SetCriticalSection(csmode3);
}

PVideoFrame Mode3Gate::GetFrame(int n, IScriptEnvironment* env)
{
	LeaveCriticalSection(cs);
	PVideoFrame retval=child->GetFrame(n,env);
	EnterCriticalSection(cs);
	return retval;
}
/*******************************
 *******   Mode5Gate      ******
 ******************************/
HANDLE Mode5Gate::WorkQueue;
long Mode5Gate::refcount;
long Mode5Gate::suspendedthreads;
int Mode5Gate::nthreads;
HANDLE* Mode5Gate::workerthreads;


Mode5Gate::Mode5Gate(PClip clip,IScriptEnvironment *env):GenericVideoFilter(clip),last_n(-1000),last_nn(-1),delta(1)
{
	
	if(InterlockedCompareExchange(&refcount,1,0)==0){
		WorkQueue=CreateIoCompletionPort(INVALID_HANDLE_VALUE,NULL,0,0);
		nthreads=env->GetMTMode(true);
		workerthreads=new HANDLE[nthreads];
		for(int i=0;i<nthreads;i++)
			workerthreads[i]=CreateThread(NULL,0,workerthread,WorkQueue,0,0);
	}
	else
		InterlockedIncrement(&refcount);
	env->SetVar("Current_n",0);
}

Mode5Gate::~Mode5Gate()
{
	if(!InterlockedDecrement(&refcount))
	{
    int i;
		for(i=0;i<nthreads;i++)
			PostQueuedCompletionStatus(WorkQueue,0,0,0);
		WaitForMultipleObjects(nthreads,workerthreads,true,INFINITE);
		for(i=0;i<nthreads;i++)
			CloseHandle(workerthreads[i]);
		delete workerthreads;
        CloseHandle(WorkQueue);
	}
}
	
DWORD Mode5Gate::workerthread(HANDLE WorkQueue)
{
	bool endthread=false;
	DWORD n;
	IScriptEnvironment* env;
	PClip *child;
	TlsSetValue(TlsIndex,new ScriptEnvironmentTLS());
	while(!endthread)
	{
		GetQueuedCompletionStatus(WorkQueue, &n, (PULONG_PTR)&env, (LPOVERLAPPED*)&child, INFINITE);
		if(env==0)
			endthread=true;
		else
			(*child)->GetFrame(n,env);
	}
	delete((ScriptEnvironmentTLS*)TlsGetValue(TlsIndex));
	return 0;
}

PVideoFrame Mode5Gate::GetFrame(int n, IScriptEnvironment* env)
{

	if(env->GetVar("Current_n").AsInt()!=last_n)
	{
		delta=n-last_nn;
		last_nn=n;
		last_n=env->GetVar("Current_n").AsInt();
	}
	if(suspendedthreads)
		PostQueuedCompletionStatus(WorkQueue,n+delta,(ULONG_PTR)env,(LPOVERLAPPED)&child);
	return child->GetFrame(n,env);
}
/*******************************
 *******   Cache filter   ******
 ******************************/


CacheMT::CacheMT(PClip _child,IScriptEnvironment *env) 
: GenericVideoFilter(_child) { 
  
  threads=env->GetMTMode(true);
  e_generated_refcount=new long[threads];
  e_generated=new HANDLE[threads];
  InitializeCriticalSectionAndSpinCount(&cs_cache,4000);
  for(int i=0;i<threads;i++){
	  e_generated[i]=CreateEvent(NULL,true,false,NULL);
	  e_generated_refcount[i]=0;
  }

  h_policy = CACHE_ALL;  // Since hints are not used per default, this is to describe the lowest default cache mode.
  h_audiopolicy = CACHE_NOTHING;  // Don't cache audio per default.

  cache_limit = CACHE_SCALE_FACTOR / 2;  // Start half way towards 1 buffer
  cache_init  = 0;
  fault_rate = 0;
  miss_count = 0x80000000; // Hugh negative

//h_total_frames = 0; // Hint cache not init'ed
  h_span = 0;
  protectcount = 0;

  ac_expected_next = 0;
  ac_currentscore = 100;

  maxframe = -1;
  minframe = vi.num_frames;

 }

/*********** V I D E O   C A C H E ************/

long CacheMT::GetFreeEvent()
{
	while(true)
	  for(int i=0;i<threads;i++)
	    if(InterlockedCompareExchange(&e_generated_refcount[i],1,0)==0)
		  return i;
}

// Any vfb's that are still current we give back for earlier reuse
void CacheMT::ReturnVideoFrameBuffer(CachedVideoFrame *i, IScriptEnvironment* env)
{
	// A vfb purge has occured
	if (!i->vfb) return;

	// if vfb is not current (i.e ours) leave it alone
	if (i->vfb->GetSequenceNumber() != i->sequence_number) return;

	// return vfb to vfb pool for immediate reuse
    env->ManageCache(MC_ReturnVideoFrameBuffer, i->vfb);
}


// If the cache is not being used reset it
void CacheMT::ResetCache(IScriptEnvironment* env)
{
  ++g_Cache_stats.resets;
  CachedVideoFrame *i, *j;

  _RPT3(0, "CacheMT:%x: Cache Reset, cache_limit %d, cache_init %d\n", this, cache_limit, CACHE_SCALE_FACTOR*cache_init);

  int count=0;
  for (i = video_frames.next; i != &video_frames; i = i->next) {
	if (++count >= cache_init) goto purge_old_frame;
  }
  return;

purge_old_frame:

  // Truncate the tail of the chain
  j = i->next;
  video_frames.prev = i;
  i->next = &video_frames;
  
  // Delete the excess CachedVideoFrames
  while (j != &video_frames) {
	i = j->next;
	if (j->vfb_protected) UnProtectVFB(j);
	if (j->vfb_locked) UnlockVFB(j);
	ReturnVideoFrameBuffer(j, env); // Return old vfb to vfb pool for early reuse
	delete j;
	j = i;
  }
  cache_limit = CACHE_SCALE_FACTOR*cache_init;
}


// This seems to be an excelent place for catching out of bounds violations
// on VideoFrameBuffer's. Well at least some of them, VFB's have a small
// variable margin due to alignment constraints. Here we catch those accesses
// that violate that, for those are the ones that are going to cause problems.


PVideoFrame __stdcall CacheMT::childGetFrame(int n, IScriptEnvironment* env) 
{ 
  PVideoFrame result = child->GetFrame(n, env);

  if (!result)
    env->ThrowError("CacheMT: Filter returned NULL PVideoFrame");

#ifdef _DEBUG
  int *p=(int *)(result->vfb->data);
  if ((p[-4] != 0xDEADBEAF)
   || (p[-3] != 0xDEADBEAF)
   || (p[-2] != 0xDEADBEAF)
   || (p[-1] != 0xDEADBEAF)) {
    env->ThrowError("Debug CacheMT: Write before start of VFB! Addr=%x", p);
  }
  p=(int *)(result->vfb->data + result->vfb->data_size);
  if ((p[0] != 0xDEADBEAF)
   || (p[1] != 0xDEADBEAF)
   || (p[2] != 0xDEADBEAF)
   || (p[3] != 0xDEADBEAF)) {
    env->ThrowError("Debug CacheMT: Write after end of VFB! Addr=%x", p);
  }
#endif
  return result;
}



// Unfortunatly the code for "return child->GetFrame(n,env);" seems highly likely 
// to generate code that relies on the contents of the ebx register being preserved
// across the call. By inserting a "mov ebx,ebx" before the call the compiler can
// be convinced the ebx register has been changed and emit altermate code that is not
// dependant on the ebx registers contents.
//
// The other half of the problem is when using inline assembler, __asm, that uses the
// ebx register together with a medium amount of C++ code around it, the optimizer
// dutifully restructures the emited C++ code to remove all it's ebx references, forgets
// about the __asm ebx references, and thinks it's okay to removes the push/pop ebx 
// from the entry prologue.
//
// Together they are a smoking gun!


PVideoFrame __stdcall CacheMT::GetFrame(int n, IScriptEnvironment* env) 
{ 
  n = min(vi.num_frames-1, max(0,n));  // Inserted to avoid requests beyond framerange.

  __asm {emms} // Protection from rogue filter authors

  if (h_policy == CACHE_NOTHING) { // don't want a cache. Typically filters that only ever seek forward.
    __asm mov ebx,ebx  // Hack! prevent compiler from trusting ebx contents across call
    return childGetFrame(n, env);
  }

    EnterCriticalSection(&cs_cache);
  if (video_frames.next->vfb_locked) {  // release the head vfb if it is locked
	UnlockVFB(video_frames.next);
	_RPT3(0, "CacheMT:%x: unlocking vfb %x for frame %d\n", this, video_frames.next->vfb, video_frames.next->frame_number);
  }

  CachedVideoFrame* cvf=0;

  // look for a cached copy of the frame
  if (n>=minframe && n<=maxframe) { // have we ever seen this frame?
	miss_count = 0; // Start/Reset cache miss counter

	int c=0;
	int imaxframe = -1;
	int iminframe = vi.num_frames;
	bool found = false;

	// Scan the cache for a candidate

	for (CachedVideoFrame* i = video_frames.next; i != &video_frames; i = i->next) {
	  ++c;
	  const int ifn = i->frame_number;

	  // Ahah! Our frame
	  if (ifn == n) {
		found = true;

        if( i->status & CACHE_ST_BEING_GENERATED)  {// Check if the frame is being generated
          InterlockedIncrement(&e_generated_refcount[i->e_generated_index]);	
		  _RPT2(0, "CacheMT:%x: waiting for frame %d to be generated\n", this, n);
          LeaveCriticalSection(&cs_cache);
          WaitForSingleObject(e_generated[i->e_generated_index],INFINITE);
		  InterlockedDecrement(&e_generated_refcount[i->e_generated_index]);	
          ++g_Cache_stats.vfb_found;
          LockVFB(i, env);  //  BuildVideoFrame expect the VFB to be locked
/*		 
		  EnterCriticalSection(&cs_cache);
          PVideoFrame retval=BuildVideoFrame(i, n);
		  LeaveCriticalSection(&cs_cache);
		  */
		  PVideoFrame retval= new VideoFrame(i->vfb, i->offset, i->pitch, i->row_size, i->height, i->offsetU, i->offsetV, i->pitchUV);
          InterlockedDecrement((long*)&retval->refcount);
		  
          return retval;
            }

		// We have a hit make sure cache_limit is at least this wide
		if (cache_limit < c * CACHE_SCALE_FACTOR) cache_limit = c * CACHE_SCALE_FACTOR;

          if (LockVFB(i, env)) {  // LockVFB can only lock the frame if the sequence number hasn't change
		  ++g_Cache_stats.vfb_found;
		  PVideoFrame retval=BuildVideoFrame(i, n); // Success!
            LeaveCriticalSection(&cs_cache);
		  InterlockedDecrement((long*)&retval->refcount);
		  return retval;
		  }

		// Damn! The contents have changed
		// record the details, update the counters
		++i->faults;
		  InterlockedExchangeAdd(&fault_rate,30 + c); // Bias by number of cache entries searched
		  if (100*i->faults > fault_rate) InterlockedExchange(&fault_rate, 100*i->faults);
		  if (fault_rate > 300) InterlockedExchange(&fault_rate, 300);
		_RPT3(0, "CacheMT:%x: stale frame %d, requests %d\n", this, n, i->faults);

		// Modified by a parent
		if (i->sequence_number == i->vfb->GetSequenceNumber()-1) {
		  ++g_Cache_stats.vfb_modified;
		}
		// vfb has been stolen
		else {
		  ++g_Cache_stats.vfb_stolen;
		  _RPT3(0, "CacheMT:%x: stolen vfb %x, frame %d\n", this, i->vfb, n);
		}

		if (i->vfb_protected) UnProtectVFB(i);
		UnlockVFB(i);

		cvf = i; // Remember this entry!
		break;
	  } // if (ifn == n) 

	  if (ifn < iminframe) iminframe = ifn;
	  if (ifn > imaxframe) imaxframe = ifn;

	  // Unprotect any frames out of CACHE_RANGE scope
	  if ((i->vfb_protected) && (abs(ifn-n) >= h_span)) {
		UnProtectVFB(i);
		_RPT3(0, "CacheMT:%x: A: Unprotect vfb %x for frame %d\n", this, i->vfb, ifn);
	  } 

	  if (i->vfb_locked) {  // release the vfb if it is locked
		UnlockVFB(i);
		_RPT3(0, "CacheMT:%x: B. unlock vfb %x for frame %d\n", this, i->vfb, ifn);
	  }
	} // for (CachedVideoFrame* i =

	if (!found) { // Cache miss - accumulate towards extra buffers
	  ++g_Cache_stats.vfb_notfound;
	  int span = 1 + imaxframe-iminframe - cache_limit/CACHE_SCALE_FACTOR;
	  if (span > CACHE_SCALE_FACTOR)
		cache_limit += CACHE_SCALE_FACTOR; // Add upto one whole buffer at a time
	  else if (span >  0)
		cache_limit += span; // Add span 16ths towards another buffer

	  maxframe = imaxframe; // update the limits from what is currently cached
	  minframe = iminframe;
	}

	if (cache_limit > CACHE_SCALE_FACTOR*MAX_CACHED_VIDEO_FRAMES) cache_limit = CACHE_SCALE_FACTOR*MAX_CACHED_VIDEO_FRAMES;

	_RPT4(0, "CacheMT:%x: size %d, limit %d, fault %d\n", this, c, cache_limit, fault_rate);

  } // if (n>=minframe
  else {
	++g_Cache_stats.vfb_never;
	if (++miss_count > MAX_CACHE_MISSES) {
	  ResetCache(env);  // The cache isn't being accessed, reset it!
	  miss_count = 0x80000000; // Hugh negative
	}
  } // if (n>=minframe ... else
  
    if (fault_rate > 0) InterlockedDecrement(&fault_rate);  // decay fault rate

  _RPT4(0, "CacheMT:%x: generating frame %d, cache from %d to %d\n", this, n, minframe, maxframe);

  // not cached; make the filter generate it.
	if (!cvf) cvf=GetACachedVideoFrame();
	if (cvf->vfb_protected) UnProtectVFB(cvf);
    if (cvf->vfb_locked) UnlockVFB(cvf);
	ReturnVideoFrameBuffer(cvf, env); // Maybe return old vfb to vfb pool for early reuse
	Relink(&video_frames, cvf, video_frames.next);

	// update the limits for cached entries
	if (n < minframe) minframe = n;
	if (n > maxframe) maxframe = n;
    // Keep any fault history
    if (cvf->frame_number != n) {
      cvf->frame_number = n;
      cvf->faults = 0;
    }

	int free_event=GetFreeEvent();
	cvf->e_generated_index=free_event;
	ResetEvent(e_generated[free_event]);
	cvf->status=CACHE_ST_BEING_GENERATED;

    LeaveCriticalSection(&cs_cache);
  __asm mov ebx,ebx  // Hack! prevent compiler from trusting ebx contents across call
  PVideoFrame result = childGetFrame(n, env);

	RegisterVideoFrame(cvf, result);

  // When we have the possibility of cacheing, promote
  // the vfb to the head of the LRU list, CACHE_RANGE
  // frames are NOT promoted hence they are fair game
  // for reuse as soon as they are unprotected. This
  // is a fair price to pay for their protection. If
  // a 2nd filter is hiting the cache outside the radius
  // of protection then we do promote protected frames.

  if (cache_limit/CACHE_SCALE_FACTOR > h_span)
	env->ManageCache(MC_PromoteVideoFrameBuffer, result->vfb);

 

  // If this is a CACHE_RANGE frame protect it
  if (h_span) {
	ProtectVFB(cvf, n);
  }
  // If we have asked for a same stale frame twice, lock frames.
  else if (  (fault_rate >  100) // Generated frames are subject to locking at a lower fault rate
	 && (fault_rate != 130) ) {  // Throw an unlocked probing frame at the world occasionally
	                             // Once we start locking frames we cannot tell if locking is
								 // still required. So probing is a cheap way to validate this.
	LockVFB(cvf,  env);          // Increment to be sure this frame isn't modified.
	_RPT3(0, "CacheMT:%x: lock vfb %x, gened frame %d\n", this, cvf->vfb, n);
  }

    cvf->status   = 0;
    SetEvent(e_generated[free_event]);
	InterlockedDecrement(&e_generated_refcount[free_event]);

  return result;
}


VideoFrame* CacheMT::BuildVideoFrame(CachedVideoFrame *i, int n)
{
  Relink(&video_frames, i, video_frames.next);   // move the matching cache entry to the front of the list
  VideoFrame* result = new VideoFrame(i->vfb, i->offset, i->pitch, i->row_size, i->height, i->offsetU, i->offsetV, i->pitchUV);

  // If we have asked for any same stale frame twice, leave frames locked.
  if (  (fault_rate <= 160)     // Reissued frames are not subject to locking at the lower fault rate
     || (fault_rate == 190) ) { // Throw an unlocked probing frame at the world occasionally
	UnlockVFB(i);
	_RPT2(0, "CacheMT:%x: using cached copy of frame %d\n", this, n);
  }
  else {
	_RPT3(0, "CacheMT:%x: lock vfb %x, cached frame %d\n", this, i->vfb, n);
  }
  return result;
}



CacheMT::CachedVideoFrame* CacheMT::GetACachedVideoFrame()
{
  CachedVideoFrame *i, *j;
  int count=0;

  // scan forwards for the last protected CachedVideoFrame
  for (i = video_frames.next; i != &video_frames; i = i->next) {
	count += 1;
	if ((count > h_span) && (count >= cache_limit/CACHE_SCALE_FACTOR)) break;
  }

  // scan backwards for a used CachedVideoFrame
  for (j = video_frames.prev; j != i; j = j->prev) {
    if ((j->status!=CACHE_ST_BEING_GENERATED)&&j->sequence_number != j->vfb->GetSequenceNumber()) return j;
	++count;
  }

  if (count >= MAX_CACHED_VIDEO_FRAMES) return video_frames.prev; // to many entries just steal the oldest CachedVideoFrame

  return new CachedVideoFrame; // need a new one
}


void CacheMT::RegisterVideoFrame(CachedVideoFrame *i, const PVideoFrame& frame) 
{
  // copy all the info
  i->vfb = frame->vfb;
  i->sequence_number = frame->vfb->GetSequenceNumber();
  i->offset = frame->offset;
  i->offsetU = frame->offsetU;
  i->offsetV = frame->offsetV;
  i->pitch = frame->pitch;
  i->pitchUV = frame->pitchUV;
  i->row_size = frame->row_size;
  i->height = frame->height;
  }


bool CacheMT::LockVFB(CachedVideoFrame *i, IScriptEnvironment* env)
{
  bool retval=false;
  env->ManageCache(MC_LockVFBList,0);
  if(i->vfb->sequence_number==i->sequence_number) {
    retval=true;
	if (!!i->vfb && InterlockedCompareExchange(&i->vfb_locked,1,0) == 0) {
	  InterlockedIncrement(&i->vfb->refcount);
	  ++g_Cache_stats.vfb_locks;
    }
  }
  env->ManageCache(MC_UnlockVFBList,0);
  return retval;
}


void CacheMT::UnlockVFB(CachedVideoFrame *i)
{
  if (!!i->vfb && InterlockedCompareExchange(&i->vfb_locked,0,1) == 1) {
	InterlockedDecrement(&i->vfb->refcount);
	--g_Cache_stats.vfb_locks;
  }
}

void CacheMT::ProtectVFB(CachedVideoFrame *i, int n)
{
  CachedVideoFrame* j = video_frames.prev;

  // Unprotect any frames out of CACHE_RANGE scope
  while ((protectcount >= h_span) && (j != &video_frames)){
	if ( (j != i) && (j->vfb_protected) && (abs(n - j->frame_number) >= h_span) ) {
      UnProtectVFB(j);
      _RPT3(0, "CacheMT:%x: B: Unprotect vfb %x for frame %d\n", this, j->vfb, j->frame_number);
	  break;
	}
	j = j->prev;
  }

  if (!!i->vfb && InterlockedCompareExchange(&i->vfb_protected,1,0) == 0) {
	InterlockedIncrement(&protectcount);
	InterlockedIncrement(&i->vfb->refcount);
	++g_Cache_stats.vfb_protects;
  }
}


void CacheMT::UnProtectVFB(CachedVideoFrame *i)
{
  if (!!i->vfb && InterlockedCompareExchange(&i->vfb_protected,0,1) == 1) {
	InterlockedDecrement(&i->vfb->refcount);
	InterlockedDecrement(&protectcount);
	--g_Cache_stats.vfb_protects;
  }
}

/*********** A U D I O   C A C H E ************/

void CacheMT::FillZeros(void* buf, int start_offset, int count) {

    const int bps = vi.BytesPerAudioSample();
    unsigned char* byte_buf = (unsigned char*)buf;
    memset(byte_buf + start_offset * bps, 0, count * bps);
}

void __stdcall CacheMT::GetAudio(void* buf, __int64 start, __int64 count, IScriptEnvironment* env) {
  if (count <= 0) 
    return;

  if ( (!vi.HasAudio()) || (start+count <= 0) || (start >= vi.num_audio_samples)) {
    // Completely skip.
    FillZeros(buf, 0, count);
    return;
  }

  if (start < 0) {  // Partial initial skip
    FillZeros(buf, 0, -start);  // Fill all samples before 0 with silence.
    count += start;  // Subtract start bytes from count.
    buf = ((BYTE*)buf) - (int)(start*vi.BytesPerAudioSample());   
    start = 0;
  }

  if (start+count > vi.num_audio_samples) {  // Partial ending skip
    FillZeros(buf, 0 , count);  // Fill all samples
    count = (vi.num_audio_samples - start);
  }

  if (start < ac_expected_next)
    ac_currentscore-=25;    // revisiting old ground - a cache could help
  else if (start > ac_expected_next)
    ac_currentscore-=5;     // skiping chunks - a cache may not help
  else // (start == ac_expected_next)
    ac_currentscore +=5;    // strict linear reading - why bother with a cache

  ac_currentscore = max(min(ac_currentscore, 450), -10000000);

  if (h_audiopolicy == CACHE_NOTHING && ac_currentscore <=0) {
    SetCacheHints(CACHE_AUDIO, 0);
    _RPT1(0, "CacheAudio:%x: Automatically adding audiocache!\n", this);
  }

  if (h_audiopolicy == CACHE_AUDIO  && (ac_currentscore > 400) ) {
    SetCacheHints(CACHE_AUDIO_NONE, 0);
    _RPT1(0, "CacheAudio:%x: Automatically deleting cache!\n", this);
  }

  ac_expected_next = start + count;

  if (h_audiopolicy == CACHE_NOTHING) {
    child->GetAudio(buf, start, count, env);
    return;  // We are ok to return now!
  }

#ifdef _DEBUG
  char dbgbuf[255];
  sprintf(dbgbuf, "CA:Get st:%.6d co:%.6d .cst:%.6d cco:%.6d, sc:%d\n",
                    int(start), int(count), int(cache_start), int(cache_count), int(ac_currentscore));
  _RPT0(0,dbgbuf);
#endif

  int shiftsamples;

  if (count>maxsamplecount) {    //is cache big enough?
    _RPT1(0, "CA:%x:Cache too small->caching last audio\n", this);
    ac_too_small_count++;

// But the current cache might have 99% of what was requested??

// Populate "buf" with whats available BEFORE any resizing!
// Only GetAudio() the missing bits, worst case the whole lot,
// best case a small chunk at the begining or the end. Then
// repopulate the cache aligned with the end of "buf".

    if (ac_too_small_count > 2 && (maxsamplecount < vi.AudioSamplesFromBytes(4095*1024))) {  // Max size = 4MB!
      //automatically upsize cache!
      int new_size = vi.BytesFromAudioSamples(count)+1024;
      new_size = min(4096*1024, new_size);
      _RPT2(0, "CacheAudio:%x: Autoupsizing buffer to %d bytes!", this, new_size);
      SetCacheHints(CACHE_AUDIO, new_size); // updates maxsamplecount!!
    }

    child->GetAudio(buf, start, count, env);

    cache_count = min(count, maxsamplecount); // Remember maxsamplecount gets updated
    cache_start = start+count-cache_count;
    BYTE *buff=(BYTE *)buf;
    buff += vi.BytesFromAudioSamples(cache_start - start);
    memcpy(cache, buff, vi.BytesFromAudioSamples(cache_count));
    return;
  }

// Maybe :- if ( (start+count<cache_start) || ... i.e. there is no overlap at all

  if ( (start<cache_start) || (start>=(cache_start+cache_count)) ){ //first sample is before or behind cache -> restart cache
    _RPT1(0,"CA:%x: Restart\n", this);

    cache_count = min(count, maxsamplecount);
    cache_start = start;
    child->GetAudio(cache, cache_start, cache_count, env);
  } else {  //at least start sample is in cache
    if ( start + count > cache_start + cache_count ) {//cache is too short. Else all is already in the cache
      if ((start - cache_start + count)>maxsamplecount) {  //cache shifting is necessary
        shiftsamples = start - cache_start + count - maxsamplecount;

// Q. Why this test? - A. To make the most of having to do a memmove
        if ( (start - cache_start)/2 > shiftsamples ) {  //shift half cache if possible
          shiftsamples = (start - cache_start)/2;
        }

        memmove(cache, cache+shiftsamples*samplesize,(cache_count-shiftsamples)*samplesize);

        cache_start = cache_start + shiftsamples;
        cache_count = cache_count - shiftsamples;
      }

// Good read just enough to complete the current request
      //append to cache
      child->GetAudio(cache + cache_count*samplesize, cache_start + cache_count, start+count-(cache_start+cache_count), env);
      cache_count += start+count-(cache_start+cache_count);
    }
  }

  //copy cache to buf
  memcpy(buf,cache + (start - cache_start)*samplesize, count*samplesize);

}

/*********** C A C H E   H I N T S ************/

void __stdcall CacheMT::SetCacheHints(int cachehints,int frame_range) {


  // Hack to detect if we are a cache, respond with our this pointer
  if ((cachehints == GetMyThis) && (frame_range != 0)) {
	*(int *)frame_range = (int)(void *)this;
	return;
  }

  _RPT3(0, "CacheMT:%x: Setting cache hints (hints:%d, range:%d )\n", this, cachehints, frame_range);
//	frame_range+=8;

  if (cachehints == CACHE_AUDIO) {

    if (!vi.HasAudio())
      return;

    // Range means for audio.
    // 0 == Create a default buffer (64kb).
    // Positive. Allocate X bytes for cache.

    if (h_audiopolicy != CACHE_NOTHING && (frame_range == 0))   // We already have a policy - no need for a default one.
      return;

    if (h_audiopolicy != CACHE_NOTHING) 
      delete[] cache;       

    h_audiopolicy = CACHE_AUDIO;

    if (frame_range == 0)
      frame_range=64*1024;

    cache = new char[frame_range];
    samplesize = vi.BytesPerAudioSample();
    maxsamplecount = frame_range/samplesize - 1;
    cache_start=0;
    cache_count=0;  
    ac_too_small_count = 0;
    return;
  }

  if (cachehints == CACHE_AUDIO_NONE) {
    if (h_audiopolicy != CACHE_NOTHING) 
      delete[] cache;
    h_audiopolicy = CACHE_NOTHING;
  }


  if (cachehints == CACHE_ALL) {
	int _cache_limit;

    h_policy = CACHE_ALL;  // This is default operation, a simple LRU cache

    if (frame_range >= MAX_CACHED_VIDEO_FRAMES)
      _cache_limit = CACHE_SCALE_FACTOR * MAX_CACHED_VIDEO_FRAMES;
    else
      _cache_limit = CACHE_SCALE_FACTOR * frame_range;

	if (_cache_limit > cache_limit)  // The max of all requests
	  cache_limit = _cache_limit;

    cache_init  = cache_limit/CACHE_SCALE_FACTOR;
    return;
  }

  if (cachehints == CACHE_NOTHING) {
    cachehints = CACHE_RANGE;
    frame_range = 1;

//    h_policy = CACHE_NOTHING;  // filter requested no caching.
//    return;
  }

  if (cachehints == CACHE_RANGE) {

	if (frame_range < 1) // Dickhead doesn't know what he is doing
	  return;

//	if (frame_range == 2) // Protect dickhead from self
//	  frame_range = 3;

    h_policy = CACHE_RANGE;  // An explicit cache of radius "frame_range" around the current frame, n.

    if (frame_range <= h_span)  // Use the largest size when we have multiple clients
      return;

    h_span = frame_range;
	if (h_span > MAX_CACHE_RANGE) h_span=MAX_CACHE_RANGE;
  }
} 

/*********** C L E A N U P ************/

CacheMT::~CacheMT() {
//ReleaseHintCache();
  if (h_audiopolicy != CACHE_NOTHING)
    delete[] cache;

  CachedVideoFrame *k, *j;
  for (k = video_frames.next; k!=&video_frames;)
  {
	  j = k->next;
	  if (k->vfb_protected) UnProtectVFB(k);
	  if (k->vfb_locked) UnlockVFB(k);
	  delete k;
	  k = j;
  }
  DeleteCriticalSection(&cs_cache);
  for(int i=0;i<threads;i++)
    CloseHandle(e_generated[i]);
  delete[] e_generated;
  delete[] e_generated_refcount;
}

/*********** C R E A T E ************/

AVSValue __cdecl CacheMT::Create_Cache(AVSValue args, void*, IScriptEnvironment* env) 
{
  if(args[0].ArraySize()>1)
	  return new CacheMT2(args[0],env);
  else
	return new CacheMT1(args[0].AsClip(), env);
}

/*************************************/
/************ CacheMT1 ***************/
/*************************************/

CacheMT1::CacheMT1(PClip _child,IScriptEnvironment *env):CacheMT(_child,env),signature('cach'+'eMT'+'1'){}

PVideoFrame CacheMT1::childGetFrame(int n, IScriptEnvironment* env){
	return CacheMT::childGetFrame(n,env);
}

/*************************************/
/************ CacheMT2 ***************/
/*************************************/

CacheMT2::CacheMT2(AVSValue clip_array,IScriptEnvironment *env):CacheMT(clip_array[0].AsClip(),env),signature('cach'+'eMT'+'2'),nfilters(clip_array.ArraySize())
{
	filters=new PClip[nfilters];
	filterstatus=new long[nfilters];
	for(unsigned int i=0;i<nfilters;i++){
		filters[i]=clip_array[i].AsClip();
		filterstatus[i]=0;
	}
}

CacheMT2::~CacheMT2(){
	delete[] filterstatus;
	delete[] filters;
}

PVideoFrame CacheMT2::childGetFrame(int n, IScriptEnvironment* env){
	unsigned int i=0;//filter index
	PVideoFrame retval;
	//search for first filter that is not in use. Note that by using compexchange it is posible to use a lock-free implementation
	while(InterlockedCompareExchange(&filterstatus[i],1,0)!=0)
		if(++i==nfilters)
			i=0;
	retval=filters[i]->GetFrame(n,env);
	InterlockedDecrement(&filterstatus[i]);
	return retval;
}

/*************************************/
/************ CacheMT3 ***************/
/*************************************/

CacheMT3::CacheMT3(PClip _child,Mode3Gate* gate,IScriptEnvironment *env):CacheMT(_child,env),signature('cach'+'eMT'+'3')
{
	InitializeCriticalSectionAndSpinCount(&csFilter,4000);
	if(gate)
		gate->SetCriticalSection(&csFilter);

}

CacheMT3::~CacheMT3(){
	DeleteCriticalSection(&csFilter);
}

PVideoFrame CacheMT3::childGetFrame(int n, IScriptEnvironment* env){
	PVideoFrame retval;
	EnterCriticalSection(&csFilter);
	retval=child->GetFrame(n,env);
	LeaveCriticalSection(&csFilter);
	return retval;
}

/*************************************/
/************ CacheMT4 ***************/
/*************************************/

CacheMT4::CacheMT4(AVSValue clip_array,Mode3Gate* gate,IScriptEnvironment *env):CacheMT(clip_array[0].AsClip(),env),signature('cach'+'eMT'+'4'),nfilters(clip_array.ArraySize())
{
	InitializeCriticalSectionAndSpinCount(&csFilter,4000);
	if(gate)
		gate->SetCriticalSection(&csFilter);
	filters=new PClip[nfilters];
	filterstatus=new long[nfilters];
	for(unsigned int i=0;i<nfilters;i++){
		filters[i]=clip_array[i].AsClip();
		filterstatus[i]=0;
	}
}

PVideoFrame CacheMT4::childGetFrame(int n, IScriptEnvironment* env){
	unsigned int i=0;
	PVideoFrame retval;
	while(InterlockedCompareExchange(&filterstatus[i],1,0)!=0)
		if(++i==nfilters)
			i=0;
	EnterCriticalSection(&csFilter);
	retval=filters[i]->GetFrame(n,env);
	LeaveCriticalSection(&csFilter);
	InterlockedDecrement(&filterstatus[i]);
	return retval;
}

CacheMT4::~CacheMT4(){
	DeleteCriticalSection(&csFilter);
	delete[] filters;
}
	
/*************************************/
/************ CacheMT5 ***************/
/*************************************/

CacheMT5::CacheMT5(PClip _child,IScriptEnvironment *env):CacheMT(_child,env),signature('cach'+'eMT'+'5')
{
	InitializeCriticalSectionAndSpinCount(&csFilter,4000);
  }

CacheMT5::~CacheMT5(){
	DeleteCriticalSection(&csFilter);
}

PVideoFrame CacheMT5::childGetFrame(int n, IScriptEnvironment* env){
	PVideoFrame retval;
	InterlockedIncrement(&Mode5Gate::suspendedthreads);
	EnterCriticalSection(&csFilter);
	InterlockedDecrement(&Mode5Gate::suspendedthreads);
	env->SetVar("Current_n",n);
	retval=child->GetFrame(n,env);
	LeaveCriticalSection(&csFilter);
	return retval;
}
