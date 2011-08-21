#include "stdafx.h"
#include "MTi.h"
#include "utility.h"

MTiend::MTiend(PClip clip,const char* string,IScriptEnvironment* env):
GenericVideoFilter(clip),WasRGB(vi.IsRGB()),EndThreads(false)
{
	int currentMTMode=0;
	try{
		currentMTMode=env->GetMTMode(false);
	}
	catch(...)
	{
		env->ThrowError("Wrong avisynth version. Use avisynth 2.6 or greater or avisynth 2.5.7 MT version");
	}
	//set the mt mode for the filter evaluated.
	if(currentMTMode!=-1)
		env->SetMTMode(1,0,false);//only one filterclass instance and the simplest cache as MT ensures only one thread access each filter/cache
	const char *cache;
	const char *eval;
	cache="InternalCache";
	eval="Eval";

	// スレッド毎フィルタの実装
	char userFilter[5120];

	InitializeCriticalSection(&cs);
	
	VideoInfo vi2;
	VideoInfo vi_org=vi;

	
	//MTistart fetch the source frame and split the fields for each thread
	PClip crop=new MTistart(clip,false,this,env);

	AVSValue up_args[1] = { crop }; 
	
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

	//Setup the first thread parameters
	up_args[0] = ret; 
    
	//Check if returned AVSValue is a clip
	if (!ret.IsClip()) 
	{
		env->ThrowError( "MT: Function did not return a video clip!");
	}
	else 
	{
		wtp[0].clip=ret.AsClip();

		vi2 = wtp[0].clip->GetVideoInfo();
		vi=vi2;
		vi.height=vi.height*2;
	}

	
	wtp[0].threadnumber=0;
	wtp[0]._this=this;
	env->SetVar("last",prev_last);
	//the last thread parameters
	crop=new MTistart(clip,true,this,env);
	up_args[0] = crop ; 
	prev_last = env->GetVar("last");
	env->SetVar("last",AVSValue(crop));

	sprintf(userFilter, string, 2);
	try {
		wtp[1].clip=env->Invoke(eval,AVSValue(userFilter)).AsClip();
	} catch(...) {
		char tmp[5120];
		sprintf(tmp, "MT: フィルタの実行に失敗しました。[%s]", userFilter);
		env->ThrowError(tmp);
	}

	up_args[0] =  wtp[1].clip ; 
	wtp[1].threadnumber=1;
	wtp[1]._this=this;
	env->SetVar("last",prev_last);

	EventFrameProcessed=CreateEvent(NULL,true,false,NULL);
	EventProcessFrame=CreateEvent(NULL,false,false,NULL);
	thread=CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)workerthread,(LPVOID)&wtp[1],NULL,NULL);

	WaitForSingleObject(EventFrameProcessed,INFINITE);
	env->SetMTMode(currentMTMode,0,false);
	env->SetMTMode(5,0,true);//temporary mt mode. This is the mode assigned to the MT filter(must come after the last invoke).
	
}


PVideoFrame __stdcall MTiend::GetFrame(int n, IScriptEnvironment* env)
{
	LOG(std::endl<<"frame "<<n);
	//setups the environment and current frame number to be used by the threads
	_env=env;
	_n=n;
	ResetEvent(EventFrameProcessed);
	SetEvent(EventProcessFrame);//Tells the threads to wake up and process the current frame
	wtp[0].dst=wtp[0].clip->GetFrame(n,env);//this thread handles the first part of the frame
	//wait on the remaining thread
	WaitForSingleObject(EventFrameProcessed,INFINITE);
	
	//merge result
	PVideoFrame dst=env->NewVideoFrame(vi);
	
	for(int plane=PLANAR_Y,end_plane=vi.IsPlanar()?PLANAR_V:PLANAR_Y;plane<=end_plane;plane<<=1)
	{
			env->BitBlt(dst->GetWritePtr(plane),dst->GetPitch(plane)*2,wtp[0].dst->GetReadPtr(plane),wtp[0].dst->GetPitch(plane),wtp[0].dst->GetRowSize(plane),wtp[0].dst->GetHeight(plane));
			env->BitBlt(dst->GetWritePtr(plane)+dst->GetPitch(plane),dst->GetPitch(plane)*2,wtp[1].dst->GetReadPtr(plane),wtp[1].dst->GetPitch(plane),wtp[1].dst->GetRowSize(plane),wtp[1].dst->GetHeight(plane));
	}
	
	return dst;
}

//this function is executed by each workerthread
DWORD WINAPI MTiend::workerthread(WTP* wtp)
{
	char buf[64];
	MTiend* _this=wtp->_this;
	
	//setup events
	HANDLE eventframeprocessed=_this->EventFrameProcessed;
	HANDLE eventprocessframe=_this->EventProcessFrame;
	HANDLE hthread=GetCurrentThread();
	bool &EndThreads=_this->EndThreads;

	_itoa(wtp->threadnumber,buf,10);
	size_t length=strlen(buf);
	buf[length]='-';

	IScriptEnvironment** penv=&_this->_env; 
	int* n=&_this->_n;

	SignalObjectAndWait(eventframeprocessed,eventprocessframe,INFINITE,false);//signal to tell that the thread is setup and ready to process and wait for order to start
	while(!EndThreads)
	{

	_itoa(*n,buf+length+1,10);
	SetThreadName(GetCurrentThreadId(),buf);
	wtp->dst=wtp->clip->GetFrame(*n,*penv);
	//Signal that the processing of the frame is done and wait for the next frame
	SignalObjectAndWait(eventframeprocessed,eventprocessframe,INFINITE,false);
	
	}
	ExitThread(0);
}

CRITICAL_SECTION*  MTiend::GetCriticalSection() 
{
	return &cs;
}

MTiend::~MTiend()
{
	DeleteCriticalSection(&cs);
	EndThreads=true;//set threads to end processing
	//wake up thread so it can end
	SetEvent(EventProcessFrame);
	
	//wait for the threads to terminate
	WaitForSingleObject(thread,INFINITE);
	//close handles
	CloseHandle(thread);
	CloseHandle(EventFrameProcessed);
	CloseHandle(EventProcessFrame);
	
}

AVSValue __cdecl MTiend::Create(AVSValue args, void* user_data, IScriptEnvironment* env)
{
	return new MTiend(args[0].AsClip(),args[1].AsString(),env);

}

//******************************************************************************************************************************************
//MTstart

MTistart::MTistart(PClip clip,bool parity,MTiend* mtend,IScriptEnvironment* env)
:GenericVideoFilter(clip),parity(parity),cs(0)
{
	cs=mtend->GetCriticalSection();
	vi.height=vi.height/2;
}



PVideoFrame __stdcall MTistart::GetFrame(int n, IScriptEnvironment* env)
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
	
	for(int plane=PLANAR_Y,end_plane=vi.IsPlanar()?PLANAR_V:PLANAR_Y;plane<=end_plane;plane<<=1)
	{
		BYTE* dstp=dst->GetWritePtr(plane);
		int offset=parity?src->GetPitch(plane):0;
		const BYTE* srcp=src->GetReadPtr(plane)+offset;
		int src_pitch=src->GetPitch(plane)*2;
		int row_size=src->GetRowSize(plane);
		int height=dst->GetHeight(plane);

		//env->BitBlt(dst->GetWritePtr(plane),dst->GetPitch(plane),src->GetReadPtr(plane)+parity?0:(const BYTE*)src->GetPitch(plane),src->GetPitch(plane)*2,src->GetRowSize(plane),dst->GetHeight(plane));
		env->BitBlt(dstp,dst->GetPitch(plane),srcp,src_pitch,row_size,height);
	}
	src=0;
	}
	catch(...)
	{
	LeaveCriticalSection(cs);
	throw;
	}
	LeaveCriticalSection(cs);
	return dst;
}
