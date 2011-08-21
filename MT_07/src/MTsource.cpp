#include "stdafx.h"
#include "MTsource.h"
#include "utility.h"

MTsource::MTsource(const char* string,int delta,int nthreads,int max_fetch,IScriptEnvironment* env):
nthreads(nthreads),EndThreads(false),delta(delta),nmax(0),max_fetch(max_fetch)
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
	cache="InternalCacheMT";
	eval="Eval";

	wtp=new WTP[nthreads];
	thread=new HANDLE[nthreads];
	EventFrameProcessed=new HANDLE[nthreads];
	EventProcessFrame=new HANDLE[nthreads];
	
	PClip *sourceclips=new PClip[nthreads+1];
	AVSValue retval;
	try{
			retval=env->Invoke(eval,AVSValue(string));
	}
	catch(...)
	{
			throw;
	}
	if(!retval.IsClip())
		env->ThrowError("filter must return a clip");
	sourceclips[0]=retval.AsClip();
	vi=sourceclips[0]->GetVideoInfo();

	for(int i=1;i<nthreads+1;i++)
	{
		try{
			sourceclips[i]=env->Invoke(eval,AVSValue(string)).AsClip();
		}
		catch(...)
		{
			throw;
		}
	}
	AVSValue* val=new AVSValue[nthreads+1];
	for(int i=0;i<nthreads+1;i++)
		val[i]=sourceclips[i];
	child=env->Invoke(cache,AVSValue(val,nthreads+1)).AsClip();
	
	for(int i=0;i<nthreads;i++)
	{
		wtp[i]._this=this;
		wtp[i].threadnumber=i;
		wtp[i].running=false;
		wtp[i].n=-1;
	}

	for(int i=0;i<nthreads;i++)
	{
		
		EventFrameProcessed[i]=CreateEvent(NULL,true,false,NULL);
		EventProcessFrame[i]=CreateEvent(NULL,false,false,NULL);
		thread[i]=CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)workerthread,(LPVOID)&wtp[i],NULL,NULL);
	}
	WaitForMultipleObjects(nthreads-1,EventFrameProcessed,true,INFINITE);
	if(currentMTMode!=-1){
		env->SetMTMode(currentMTMode,0,false);
		env->SetMTMode(5,0,true);//temporary mt mode. This is the mode assigned to the MT filter(must come after the last invoke).
	}
}



PVideoFrame __stdcall MTsource::GetFrame(int n, IScriptEnvironment* env)
{
	LOG(std::endl<<"frame "<<n);
	//setups the environment and current frame number to be used by the threads
	_env=env;
	
	_RPT1(0,"MT source requesting frame %i\n",n);  
	for(unsigned int i=0;i<nthreads;i++){
		int nextframe=delta>0?max(n,nmax)+delta:min(n,nmax)+delta;
		if(nextframe>=n+max_fetch*delta)//We don't want to fetch too many frames ahead
			continue;
		nmax=nextframe;
		if(!wtp[i].running)
		{
			WaitForSingleObject(EventFrameProcessed[i],INFINITE);
			wtp[i].running=true;
			wtp[i].n=nextframe;
			_RPT2(0,"MT source assigning frame %i to thread %u\n",nextframe,wtp[i].threadnumber);
			
		}
		ResetEvent(EventFrameProcessed[i]);
		SetEvent(EventProcessFrame[i]);//Tells the threads to wake up and process the current frame
	}
	PVideoFrame dst=child->GetFrame(n,env);//this thread gets the requested frame from the cache
	return dst;
}



//this function is executed by each workerthread
DWORD WINAPI MTsource::workerthread(WTP* wtp)
{
	char buf[64];
	//WTP* wtp=static_cast<WTP*>(param);
	MTsource* _this=wtp->_this;
	//setup events
	HANDLE eventframeprocessed=_this->EventFrameProcessed[wtp->threadnumber];
	HANDLE eventprocessframe=_this->EventProcessFrame[wtp->threadnumber];
	HANDLE hthread=GetCurrentThread();
	bool &EndThreads=_this->EndThreads;

	_itoa(wtp->threadnumber,buf,10);
	size_t length=strlen(buf);
	buf[length]='-';

	IScriptEnvironment* &env=_this->_env; 
	int &n=wtp->n;


	SignalObjectAndWait(eventframeprocessed,eventprocessframe,INFINITE,false);//signal to tell that the thread is setup and ready to process and wait for order to start
	while(!EndThreads)
	{

	_itoa(n,buf+length+1,10);
	SetThreadName(GetCurrentThreadId(),buf);
	wtp->dst=_this->child->GetFrame(n,env);
	wtp->running=false;
	//Signal that the processing of the frame is done and wait for the next frame
	SignalObjectAndWait(eventframeprocessed,eventprocessframe,INFINITE,false);
	
	}
	ExitThread(0);
}


MTsource::~MTsource()
{
	EndThreads=true;//set threads to end processing
	//wake up threads so they can end
	for(unsigned int i=0;i<nthreads;i++){
		SetEvent(EventProcessFrame[i]);
	}
	//wait for the threads to terminate
	WaitForMultipleObjects(nthreads,thread,true,INFINITE);
	//close handles
	for(unsigned int i=0;i<nthreads;i++)
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

AVSValue __cdecl MTsource::Create(AVSValue args, void* user_data, IScriptEnvironment* env)
{
	int nthreads=args[2].AsInt(2);
	if(nthreads<1)
		nthreads=2;
	return new MTsource(args[0].AsString(),args[1].AsInt(1),nthreads,args[3].AsInt(30),env);

}