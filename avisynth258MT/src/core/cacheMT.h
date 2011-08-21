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

#ifndef __CacheMT_H__
#define __CacheMT_H__

#include "../internal.h"
#include "MT.h"


class Mode3Gate : public GenericVideoFilter{
public:
	Mode3Gate(PClip clip,Mode3Gate* last,IScriptEnvironment *env);
	PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
	void SetCriticalSection(CRITICAL_SECTION* csmode3);
protected:
	CRITICAL_SECTION* cs;
	Mode3Gate* last;
};

class Mode5Gate : public GenericVideoFilter{
public:
	Mode5Gate(PClip clip,IScriptEnvironment *env);
	~Mode5Gate();
	PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);


	static long suspendedthreads;

protected:
	static HANDLE WorkQueue;
	static HANDLE* workerthreads;
	static long refcount;
	static int nthreads;
	int last_n;
	int last_nn;
	int delta;
	static DWORD WINAPI workerthread(HANDLE WorkQueue);
};
/********************************************************************
********************************************************************/



class CacheMT : public GenericVideoFilter 
/**
  * Manages a video frame cache
 **/
{
public:
  CacheMT(PClip _child, IScriptEnvironment* env);
  virtual ~CacheMT();
  PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
  virtual void __stdcall SetCacheHints(int cachehints,int frame_range);
  static AVSValue __cdecl Create_Cache(AVSValue args, void*, IScriptEnvironment* env);
  void __stdcall GetAudio(void* buf, __int64 start, __int64 count, IScriptEnvironment* env);

  enum {GetMyThis = 0x8666 };

protected:
  struct CachedVideoFrame;
  void RegisterVideoFrame(CachedVideoFrame *i, const PVideoFrame& frame);
  void FillZeros(void* buf, int start_offset, int count);
  void ResetCache(IScriptEnvironment* env);
  void ReturnVideoFrameBuffer(CachedVideoFrame *i, IScriptEnvironment* env);
  CachedVideoFrame* GetACachedVideoFrame();
  VideoFrame* BuildVideoFrame(CachedVideoFrame *i, int n);
  bool LockVFB(CachedVideoFrame *i, IScriptEnvironment* env);
  void UnlockVFB(CachedVideoFrame *i);
  void ProtectVFB(CachedVideoFrame *i, int n);
  void UnProtectVFB(CachedVideoFrame *i);
  virtual PVideoFrame __stdcall childGetFrame(int n, IScriptEnvironment* env);
  long GetFreeEvent();

  struct CachedVideoFrame 
  {
    CachedVideoFrame *prev, *next;
    VideoFrameBuffer* vfb;
    int sequence_number;
    int offset, pitch, row_size, height, offsetU, offsetV, pitchUV,pixel_type, row_sizeUV, heightUV;
    int frame_number;
	int faults;  // the number of times this frame was requested and found to be stale(modified)
	volatile long vfb_locked;
	volatile long vfb_protected;
    int status;
	int e_generated_index;

	CachedVideoFrame() : 
		vfb(0), 
		frame_number(-1), 
		vfb_locked(false),
		vfb_protected(false),
		status(0),
		e_generated_index(0)
		{
next=prev=this;
}
  };
  CachedVideoFrame video_frames;

  // Video cache
  int h_policy;
  int h_span;
  long protectcount;

  CRITICAL_SECTION cs_cache;
  long* e_generated_refcount;
  HANDLE* e_generated;
  int threads;

// Audio cache:
  int h_audiopolicy;
  int h_audioSize;
	char * cache;
	int samplesize;
	int maxsamplecount;
	__int64 cache_start;
	__int64 cache_count;

  // For audio cache prediction
  __int64 ac_expected_next;
  int ac_currentscore;
  int ac_too_small_count;

  // Cached range limits
  int minframe, maxframe;
  int cache_init;   // The Initial cache size
  int cache_limit;  // 16 time the current maximum number of CachedVideoFrame entries
  long fault_rate;   // A decaying average of 100 times the peak fault count, used to control vfb auto-locking
  int miss_count;   // Count of consecutive cache misses
  
  enum {CACHE_ST_USED = 1<<0,
        CACHE_ST_DELETEME = 1<<1,
        CACHE_ST_BEING_GENERATED = 1<<2,
        CACHE_ST_HAS_BEEN_RELEASED = 1<<3
  };

};

class CacheMT1 : public CacheMT
{
public:
	CacheMT1(PClip _child, IScriptEnvironment* env);
	PVideoFrame __stdcall childGetFrame(int n, IScriptEnvironment* env);
protected:
	const unsigned int signature;
};

class CacheMT2 : public CacheMT
{
public:
	CacheMT2(AVSValue clip_array, IScriptEnvironment* env);
	~CacheMT2();
protected:
	const unsigned int signature;
	PClip* filters;
	unsigned int nfilters;
	long* filterstatus;

	PVideoFrame __stdcall childGetFrame(int n, IScriptEnvironment* env);
};

class CacheMT3 : public CacheMT
{
public:
	CacheMT3(PClip _child,Mode3Gate* gate,IScriptEnvironment* env);
	~CacheMT3();
protected:
	const unsigned int signature;
	CRITICAL_SECTION csFilter;

	PVideoFrame __stdcall childGetFrame(int n, IScriptEnvironment* env);
};

class CacheMT4 : public CacheMT
{
public:
	CacheMT4(AVSValue clip_array, Mode3Gate* gate,IScriptEnvironment* env);
	~CacheMT4();
protected:
	const unsigned int signature;
	CRITICAL_SECTION csFilter;
	PClip* filters;
	unsigned int nfilters;
	long* filterstatus;

	PVideoFrame __stdcall childGetFrame(int n, IScriptEnvironment* env);
};

class CacheMT5 : public CacheMT
{
public:
	CacheMT5(PClip _child,IScriptEnvironment* env);
	~CacheMT5();
	const unsigned int signature;
protected:
	
	CRITICAL_SECTION csFilter;

	PVideoFrame __stdcall childGetFrame(int n, IScriptEnvironment* env);
};


#endif  // __Cache_H__
