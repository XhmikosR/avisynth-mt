// MT  Copyright 2005 Tonny S Petersen

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


#include "stdafx.h"
#include "MT.h"
#include "MTi.h"
#include "MTsource.h"
#include "utility.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ulReason, LPVOID lpReserved)
{
	if (ulReason == DLL_PROCESS_ATTACH)
		DisableThreadLibraryCalls(hModule);
	return TRUE;
}


MTend::MTend(PClip clip,const char* string, int nthreads,int overlap,bool _vertical,IScriptEnvironment* env):
GenericVideoFilter(clip),nthreads(nthreads),overlap(overlap),threadsize(0),vertical(_vertical),WasRGB(vi.IsRGB()),EndThreads(false)
{
	int currentMTMode=0;
	try{
		currentMTMode=env->GetMTMode(false);
	}
	catch(...)
	{
		env->ThrowError("Wrong avisynth version. Use avisynth 2.6 or greater or modified avisynth 2.5.6");
	}
	//set the mt mode for the filter evaluated.
	env->SetMTMode(1,0,false);//only one filterclass instance and the simplest cache as MT ensures only one thread access each filter/cache
	const char *cache;
	const char *eval;
	cache="InternalCache";
	eval="Eval";

	// スレッド毎フィルタの実装
	char userFilter[5120];

	InitializeCriticalSection(&cs);
	if(vertical)
	{
		threadsize=vi.width/nthreads;
		threadsize+=threadsize&1;//mod2 width
	}
	else
	{
		threadsize=vi.height/nthreads;
		threadsize+=threadsize&1;//mod2 height
	}
	wtp=new WTP[nthreads];
	thread=new HANDLE[nthreads-1];
	EventFrameProcessed=new HANDLE[nthreads-1];
	EventProcessFrame=new HANDLE[nthreads-1];
	VideoInfo vi2;
	VideoInfo vi_org=vi;

	//top/left
	//MTStart fetch the source frame and crop it
	PClip crop=new MTstart(clip,0,0,vertical?threadsize+overlap:vi_org.width,vertical?vi_org.height:threadsize+overlap,this,env);

	AVSValue up_args[1] = { crop }; 
	//crop = env->Invoke(cache, AVSValue(up_args,1)).AsClip();

	AVSValue prev_last = env->GetVar("last");
	env->SetVar("last",AVSValue(crop));
	AVSValue ret;

	sprintf(userFilter, string, 1);
	try{
		ret=env->Invoke(eval,AVSValue(userFilter));
	} catch(...) {
		char tmp[5120];
		sprintf(tmp, "MT: フィルタの実行に失敗しました。[%s]", userFilter);
		env->ThrowError(tmp);
	}

	//SEtup the first thread parameters
	up_args[0] = ret; 
    //ret = env->Invoke(cache, AVSValue(up_args,1)).AsClip();

	//Check if returned AVSValue is a clip and the width or hight haven't been changed
	if (!ret.IsClip()) 
	{
		env->ThrowError( "MT: Function did not return a video clip!");
	}
	else 
	{
		wtp[0].clip=ret.AsClip();

		vi2 = wtp[0].clip->GetVideoInfo();
		if(vertical)
		{
			if (vi2.width != threadsize+overlap) 
				env->ThrowError("MT: Function changed the width! Try splitvertical=false");
			int v=vi.width;
			vi=vi2;
			vi.width=v;
		}
		else
		{
			if (vi2.height != threadsize+overlap) 
				env->ThrowError("MT: Function changed the height! Try splitvertical=true");
			int h=vi.height;
			vi=vi2;
			vi.height=h;
		}
	}

	
	wtp[0].threadnumber=0;
	wtp[0]._this=this;
	env->SetVar("last",prev_last);
	//if more than two threads setup the rest of the thread parameters except the last one.
	for(int i=1,startsize=threadsize;i<nthreads-1;i++,startsize+=threadsize)
	{
		PClip crop=new MTstart(clip,vertical?startsize-overlap:0,vertical?0:startsize-overlap,vertical?threadsize+2*overlap:vi_org.width,vertical?vi_org.height:threadsize+2*overlap,this,env);

		up_args[0] =  crop; 
		//crop = env->Invoke(cache, AVSValue(up_args,1)).AsClip();

		AVSValue prev_last = env->GetVar("last");
		env->SetVar("last",AVSValue(crop));

		sprintf(userFilter, string, i+1);
		try {
			wtp[i].clip=env->Invoke(eval,AVSValue(userFilter)).AsClip();
		} catch(...) {
			char tmp[5120];
			sprintf(tmp, "MT: フィルタの実行に失敗しました。[%s]", userFilter);
			env->ThrowError(tmp);
		}

		AVSValue up_args[1] = { wtp[i].clip }; 
		//wtp[i].clip = env->Invoke(cache, AVSValue(up_args,1)).AsClip();
		
		wtp[i].threadnumber=i;
		//wtp[i].env=env;//new ScriptEnvironmentMT(env,avisynthTS);
		wtp[i]._this=this;
		env->SetVar("last",prev_last);

	}
	//bottom/right
	//the last thread parameters
	if(nthreads>1)
	{
		PClip crop=new MTstart(clip,vertical?threadsize*(nthreads-1)-overlap:0,vertical?0:threadsize*(nthreads-1)-overlap,vertical?vi_org.width-threadsize*(nthreads-1)+overlap:vi_org.width,vertical?vi_org.height:vi_org.height-threadsize*(nthreads-1)+overlap,this,env);

		up_args[0] = crop ; 
	 //   crop = env->Invoke(cache, AVSValue(up_args,1)).AsClip();

		AVSValue prev_last = env->GetVar("last");
		env->SetVar("last",AVSValue(crop));

		sprintf(userFilter, string, nthreads);
		try {
			wtp[nthreads-1].clip=env->Invoke(eval,AVSValue(userFilter)).AsClip();
		} catch(...) {
			char tmp[5120];
			sprintf(tmp, "MT: フィルタの実行に失敗しました。[%s]", userFilter);
			env->ThrowError(tmp);
		}

		up_args[0] =  wtp[nthreads-1].clip ; 
	    //wtp[nthreads-1].clip = env->Invoke(cache, AVSValue(up_args,1)).AsClip();

		wtp[nthreads-1].threadnumber=nthreads-1;
		wtp[nthreads-1]._this=this;
		env->SetVar("last",prev_last);
	}
	for(int i=1;i<nthreads;i++)
	{
		EventFrameProcessed[i-1]=CreateEvent(NULL,true,false,NULL);
		EventProcessFrame[i-1]=CreateEvent(NULL,false,false,NULL);
		thread[i-1]=CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)workerthread,(LPVOID)&wtp[i],NULL,NULL);
	}
	WaitForMultipleObjects(nthreads-1,EventFrameProcessed,true,INFINITE);
	env->SetMTMode(currentMTMode,0,false);
	env->SetMTMode(5,0,true);//temporary mt mode. This is the mode assigned to the MT filter(must come after the last invoke).
}


PVideoFrame __stdcall MTend::GetFrame(int n, IScriptEnvironment* env)
{
	LOG(std::endl<<"frame "<<n);
	//setups the environment and current frame number to be used by the threads
	_env=env;
	_n=n;
	for(unsigned int i=0;i<nthreads-1;i++){
		ResetEvent(EventFrameProcessed[i]);
		SetEvent(EventProcessFrame[i]);//Tells the threads to wake up and process the current frame
	}
	wtp[0].dst=wtp[0].clip->GetFrame(n,env);//this thread handles the first part of the frame
	//wait on the remaining thread(s)
	if(nthreads==2)
		WaitForSingleObject(EventFrameProcessed[0],INFINITE);
	else
		WaitForMultipleObjects(nthreads-1,EventFrameProcessed,true,INFINITE);
    
	//merge result
	PVideoFrame dst=env->NewVideoFrame(vi);
	if(!vertical)
		MergeFramesHorizontal(dst,env);
	else
		MergeFramesVertical(dst,env);

	return dst;
}

void MTend::MergeFramesHorizontal(PVideoFrame& dst,IScriptEnvironment* env)
{
	
	if(vi.IsYV12())
		for(int plane=PLANAR_Y,o=overlap,th=threadsize,h=vi.height;plane<=PLANAR_V;plane<<=1,o=overlap/2,th=threadsize/2,h=vi.height/2)
		{

			BYTE* dstp=dst->GetWritePtr(plane);
			UINT dst_pitch=dst->GetPitch(plane);
			UINT rowsize=dst->GetRowSize(plane);
			if(WasRGB)
			{
				env->BitBlt(dstp,dst_pitch,wtp[nthreads-1].dst->GetReadPtr(plane),wtp[nthreads-1].dst->GetPitch(plane),rowsize,h-th*(nthreads-1));
				
				dstp+=dst_pitch*th;
				for(unsigned int i=nthreads-2;i>0;i--,dstp+=dst_pitch*th)
				{
					env->BitBlt(dstp,dst_pitch,wtp[i].dst->GetReadPtr(plane)+wtp[i].dst->GetPitch(plane)*o,wtp[i].dst->GetPitch(plane),rowsize,th);
					
				}
				if(nthreads>1)
				{
					env->BitBlt(dstp,dst_pitch,wtp[0].dst->GetReadPtr(plane)+wtp[0].dst->GetPitch(plane)*o,wtp[0].dst->GetPitch(plane),rowsize,th);
					
				}
			}
			else
			{
				env->BitBlt(dstp,dst_pitch,wtp[0].dst->GetReadPtr(plane),wtp[0].dst->GetPitch(plane),rowsize,th);
				

				dstp+=dst_pitch*th;
				for(unsigned int i=1;i<nthreads-1;i++,dstp+=dst_pitch*th)
				{
					env->BitBlt(dstp,dst_pitch,wtp[i].dst->GetReadPtr(plane)+wtp[i].dst->GetPitch(plane)*o,wtp[i].dst->GetPitch(plane),rowsize,th);
					
				}
				if(nthreads>1)
				{
					env->BitBlt(dstp,dst_pitch,wtp[nthreads-1].dst->GetReadPtr(plane)+wtp[nthreads-1].dst->GetPitch(plane)*o,wtp[nthreads-1].dst->GetPitch(plane),rowsize,h-th*(nthreads-1));
					
				}
			}
		}
	else if((vi.IsRGB()||WasRGB)&&!(vi.IsRGB()&&WasRGB))
	{
		BYTE* dstp=dst->GetWritePtr();
		UINT dst_pitch=dst->GetPitch();
		UINT rowsize=dst->GetRowSize();
		env->BitBlt(dstp,dst_pitch,wtp[nthreads-1].dst->GetReadPtr(),wtp[nthreads-1].dst->GetPitch(),rowsize,vi.height-threadsize*(nthreads-1));


		dstp+=dst_pitch*threadsize;
		for(int i=nthreads-2;i>0;i--,dstp+=dst_pitch*threadsize)
		{
			env->BitBlt(dstp,dst_pitch,wtp[i].dst->GetReadPtr()+wtp[i].dst->GetPitch()*overlap,wtp[i].dst->GetPitch(),rowsize,threadsize);

		}
		if(nthreads>1)
		{
			env->BitBlt(dstp,dst_pitch,wtp[0].dst->GetReadPtr()+wtp[0].dst->GetPitch()*overlap,wtp[0].dst->GetPitch(),rowsize,threadsize);

		}
	}
	else
	{
		BYTE* dstp=dst->GetWritePtr();
		UINT dst_pitch=dst->GetPitch();
		UINT rowsize=dst->GetRowSize();
		env->BitBlt(dstp,dst_pitch,wtp[0].dst->GetReadPtr(),wtp[0].dst->GetPitch(),rowsize,threadsize);
	

		dstp+=dst_pitch*threadsize;
		for(unsigned int i=1;i<nthreads-1;i++,dstp+=dst_pitch*threadsize)
		{
			env->BitBlt(dstp,dst_pitch,wtp[i].dst->GetReadPtr()+wtp[i].dst->GetPitch()*overlap,wtp[i].dst->GetPitch(),rowsize,threadsize);
	
		}
		if(nthreads>1)
		{
			env->BitBlt(dstp,dst_pitch,wtp[nthreads-1].dst->GetReadPtr()+wtp[nthreads-1].dst->GetPitch()*overlap,wtp[nthreads-1].dst->GetPitch(),rowsize,vi.height-threadsize*(nthreads-1));
	
		}
	}
}

void MTend::MergeFramesVertical(PVideoFrame& dst,IScriptEnvironment* env)
{

	if(vi.IsYV12())
		for(int plane=PLANAR_Y,o=overlap,th=threadsize,h=vi.height;plane<=PLANAR_V;plane<<=1,o=overlap/2,th=threadsize/2,h=vi.height/2)
		{

			BYTE* dstp=dst->GetWritePtr(plane);
			UINT dst_pitch=dst->GetPitch(plane);
			UINT dst_rowsize=dst->GetRowSize(plane);
			UINT src_rowsize;//=wtp[0].dst->GetRowSize(plane);
			
			
			for(unsigned int i=0;i<nthreads;i++,dstp+=src_rowsize)
			{
				UINT ob=i==0?0:o;//overlap before
				UINT oa=i==nthreads-1?0:o;//overlap after
				src_rowsize=wtp[i].dst->GetRowSize(plane)-(ob+oa);
				env->BitBlt(dstp,dst_pitch/*+dst_rowsize-src_rowsize*/,wtp[i].dst->GetReadPtr(plane)+ob,wtp[i].dst->GetPitch(plane),src_rowsize,h);
			
			}
		}
	else 
	{

		UINT h=vi.height;
		BYTE* dstp=dst->GetWritePtr();
		UINT dst_pitch=dst->GetPitch();
		UINT dst_rowsize=dst->GetRowSize();
		UINT src_rowsize;//=wtp[0].dst->GetRowSize();

		UINT o=overlap*(vi.BitsPerPixel()>>3);

		for(unsigned int i=0;i<nthreads;i++,dstp+=src_rowsize)
		{
			UINT ob=i==0?0:o;//overlap before
			UINT oa=i==nthreads-1?0:o;//overlap after
			src_rowsize=wtp[i].dst->GetRowSize()-(ob+oa);
			env->BitBlt(dstp,dst_pitch,wtp[i].dst->GetReadPtr()+ob,wtp[i].dst->GetPitch(),src_rowsize,h);

		}
	}

}

//this function is executed by each workerthread
DWORD WINAPI MTend::workerthread(WTP* wtp)
{
	char buf[64];
	//WTP* wtp=static_cast<WTP*>(param);
	MTend* _this=wtp->_this;
	//setup events
	HANDLE eventframeprocessed=_this->EventFrameProcessed[wtp->threadnumber-1];
	HANDLE eventprocessframe=_this->EventProcessFrame[wtp->threadnumber-1];
	HANDLE hthread=GetCurrentThread();
	bool *EndThreads=&_this->EndThreads;

	_itoa(wtp->threadnumber,buf,10);
	size_t length=strlen(buf);
	buf[length]='-';

	IScriptEnvironment** penv=&_this->_env; 
	int* n=&_this->_n;

	SignalObjectAndWait(eventframeprocessed,eventprocessframe,INFINITE,false);//signal to tell that the thread is setup and ready to process and wait for order to start
	while(!(*EndThreads))
	{

	_itoa(*n,buf+length+1,10);
	SetThreadName(GetCurrentThreadId(),buf);
	wtp->dst=wtp->clip->GetFrame(*n,*penv);
	//Signal that the processing of the frame is done and wait for the next frame
	SignalObjectAndWait(eventframeprocessed,eventprocessframe,INFINITE,false);
	
	}
	ExitThread(0);
}

CRITICAL_SECTION*  MTend::GetCriticalSection() 
{
	return &cs;
}
MTend::~MTend()
{
	DeleteCriticalSection(&cs);
	EndThreads=true;//set threads to end processing
	//wake up threads so they can end
	for(unsigned int i=0;i<nthreads-1;i++){
		SetEvent(EventProcessFrame[i]);
	}
	//wait for the threads to terminate
	WaitForMultipleObjects(nthreads-1,thread,true,INFINITE);
	//close handles
	for(unsigned int i=0;i<nthreads-1;i++)
	{
		CloseHandle(thread[i]);
		CloseHandle(EventFrameProcessed[i]);
		CloseHandle(EventProcessFrame[i]);
	}

	delete[] thread;
	delete[] EventFrameProcessed;
	delete[] EventProcessFrame;
	delete[] wtp;
}

AVSValue __cdecl MTend::Create(AVSValue args, void* user_data, IScriptEnvironment* env)
{
	int nthreads=args[2].AsInt(2);
	if(nthreads<1)
		nthreads=2;
	int border=args[3].AsInt(0)+1&args[3].AsInt(0);//
	if(border<1)
		border=0;
	return new MTend(args[0].AsClip(),args[1].AsString(),nthreads,border,args[4].AsBool(false),env);

}

//******************************************************************************************************************************************
//MTstart

MTstart::MTstart(PClip clip,UINT _left,UINT _top,UINT _width,UINT _height,MTend* mtend,IScriptEnvironment* env)
:GenericVideoFilter(clip),top(_top),cs(0)
{
	cs=mtend->GetCriticalSection();
	left_bytes=vi.BytesFromPixels(_left);
	vi.width=_width;
	vi.height=_height;

}

MTstart::~MTstart()
{
	//DeleteCriticalSection(&cs);
}

PVideoFrame __stdcall MTstart::GetFrame(int n, IScriptEnvironment* env)
{
	PVideoFrame src;
	PVideoFrame dst;
	EnterCriticalSection(cs);
//need a try block to release the CRITICAL_SECTION if an exception occours
	try
	{
		LOG("MTstart: "<<std::hex<<GetCurrentThreadId()<<std::dec);
		src=child->GetFrame(n,env);
		dst=env->NewVideoFrame(vi);

		if(vi.IsPlanar())
		{
		  env->BitBlt(dst->GetWritePtr(PLANAR_Y), dst->GetPitch(PLANAR_Y),
		  src->GetReadPtr(PLANAR_Y) + top *  src->GetPitch(PLANAR_Y) + left_bytes,
		  src->GetPitch(PLANAR_Y), dst->GetRowSize(PLANAR_Y), dst->GetHeight(PLANAR_Y));

		env->BitBlt(dst->GetWritePtr(PLANAR_U), dst->GetPitch(PLANAR_U),
		  src->GetReadPtr(PLANAR_U) + (top>>1) *  src->GetPitch(PLANAR_U) + (left_bytes>>1),
		  src->GetPitch(PLANAR_U), dst->GetRowSize(PLANAR_U), dst->GetHeight(PLANAR_U));

		env->BitBlt(dst->GetWritePtr(PLANAR_V), dst->GetPitch(PLANAR_V),
		  src->GetReadPtr(PLANAR_V) + (top>>1) *  src->GetPitch(PLANAR_V) + (left_bytes>>1),
		  src->GetPitch(PLANAR_V), dst->GetRowSize(PLANAR_V), dst->GetHeight(PLANAR_V));
		}
		else
		{
		  env->BitBlt(dst->GetWritePtr(), dst->GetPitch(),
		  src->GetReadPtr() + top *  src->GetPitch() + left_bytes,
		  src->GetPitch(), dst->GetRowSize(), dst->GetHeight());
		}
		src=NULL;
	}
	catch(...)
	{
		LeaveCriticalSection(cs);
		throw;
	}
	LeaveCriticalSection(cs);
	return dst;
}


extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit2(IScriptEnvironment* env) {
	env->AddFunction("MT", "c[filter]s[threads]i[overlap]i[splitvertical]b", MTend::Create, 0); 
	env->AddFunction("MTi", "c[filter]s", MTiend::Create, 0); 
	env->AddFunction("MTsource", "[filter]s[delta]i[threads]i[max_fetch]i", MTsource::Create, 0); 
	return "MT 0.7"; 
}