// Avisynth v2.6.  Copyright 2002 Ben Rudiak-Gould et al.
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

#include "MT.h"

extern DWORD TlsIndex;  // in main.cpp





AVSFunction MT_filters[] = {
  { "Distributor", "c", Distributor::Create_Distributor },                    
  { 0 }
};

AVSValue __cdecl Distributor::Create_Distributor(AVSValue args, void*, IScriptEnvironment* env){
	return new Distributor(args[0].AsClip(),env);
}

Distributor::Distributor(PClip clip, IScriptEnvironment* env):GenericVideoFilter(clip),thread(0),nthreads(env->GetMTMode(true)),_env(env),lastframe(-1)
{
	TlsSetValue(TlsIndex,0);
	thread=new Thread[nthreads];
	for(unsigned int i=0;i<nthreads;i++)
	{
		thread[i].distributor=this;
		thread[i].thread=CreateThread(NULL,NULL,getframes,&thread[i],NULL,NULL);
	}
}

Distributor::~Distributor()
{
    delete[] thread;
}

DWORD Distributor::getframes(LPVOID param){
	Thread* current_thread=(Thread*)param;
	Distributor* _this=current_thread->distributor;
	IScriptEnvironment** penv=&_this->_env;
	TlsSetValue(TlsIndex,new ScriptEnvironmentTLS());
	while(true)
	{
		WaitForSingleObject(current_thread->begin,INFINITE);
		_RPT2(0,"Thread %d generating frame %d\n",GetCurrentThreadId(),current_thread->n);
		if(current_thread->endthread)
			break;

		current_thread->result=_this->child->GetFrame(current_thread->n,*penv);

		_RPT2(0,"Thread %d finished generating frame %d\n",GetCurrentThreadId(),current_thread->n);
		current_thread->status=Distributor::Thread::idle;
		SetEvent(current_thread->done);
	}
	delete((ScriptEnvironmentTLS*) TlsGetValue(TlsIndex));
	ExitThread(0);
  return 0;
}

/*void Distributor::AssignFramesToThread(int n){
	int nextframe=n;
	for(unsigned int i=0;i<nthreads;i++)
	{
		if(thread[i].n<=n&&thread[i].status==Thread::idle)
			thread[i].n=nextframe++;
	}
}*/

/*
PVideoFrame Distributor::GetFrameForward(int n, IScriptEnvironment* env)
{
PVideoFrame result=0;
	int in=-1;//thread number processing the current frame
	int nmax=n;//Current highest frame number being processed
  unsigned int i;
	for(i=0;i<nthreads;i++)
	{
		if(thread[i].n>nmax)//find highest frame number being processed
			nmax=thread[i].n;
		if(thread[i].n==n)//if the requested frame is being processed by thread i
			if(thread[i].status==Thread::idle){//and it is ready to be used
				result=thread[i].result;//assign it to result 
			}
			else						//else assign in to the thread number
				in=i;
	}
	_RPT2(0,"Distributor status loop1: result:%x, in:%d,\n",result,in);
	int nextframe=nmax+1;
	if(result==0&&in==-1)//if no current thread is working on the requested frame set in to -2
		in=-2;
	
	for(i=0;i<nthreads;++i==in?i++:0)//run though the active threads and skip the thread that works on the requested frame.
	{
		if(thread[i].n<=n&&thread[i].status==Thread::idle){//if the thread is done processing a frame that lies before the current frame 
			WaitForSingleObject(thread[i].done,INFINITE);  //wait for it to be ready to process the next frame 
														   //(as the thread might stale between setting the idle status and setting the 
														   //done event resulting in the thread signaling done even before beginning working on the frame
			thread[i].status=Thread::running;			   
			if(in!=-2)									   //if a thread is assigned to the requested frame 
				thread[i].n=nextframe++;				   //assign it to the next frame
			else{										
				thread[i].n=n;							   //else assign it to the requested frame
				in=i;
			}
			_RPT2(0,"Distributor loop2 Thread %d recruted to generate frame %d\n",i,thread[i].n);
			SetEvent(thread[i].begin);}					   //let the thread begin
		//NOTE: threads that are done working on a frame that is after the current requested frame is not
		//assigned a new frame as the frame will be requested soon. This could be changed as the frame is saved in the cache so it would return quickly.
	}
	_RPT1(0,"Distributor status loop2: in:%d\n",in);
	if(in!=-1)//if the thread creating the requested frame isn't done 
	{
		WaitForSingleObject(thread[in].done,INFINITE); //wait for it to complete processing
		SetEvent(thread[in].done);					   //and signal the thread is done to avoid a deadlock in the loop above
		result=thread[in].result;					   
	}
	_RPT1(0,"Distributor end status: result:%x\n",result);
	return result;
}

PVideoFrame Distributor::GetFrameBackward(int n, IScriptEnvironment* env)
{
	PVideoFrame result=0;
	int in=-1;
	int nmin=n;
  unsigned int i;
	for(i=0;i<nthreads;i++)
	{
		if(thread[i].n<nmin)
			nmin=thread[i].n;
		if(thread[i].n==n)
			if(thread[i].status==Thread::idle){
				result=thread[i].result;
			}
			else
				in=i;
	}
	_RPT2(0,"Distributor status loop1: result:%x, in:%d,\n",result,in);
	int nextframe=nmin-1;
	if(result==0&&in==-1)
		in=-2;
	
	for(i=0;i<nthreads;++i==in?i++:i)
	{
		if(thread[i].n>=n&&thread[i].status==Thread::idle){
			WaitForSingleObject(thread[i].done,INFINITE);
			thread[i].status=Thread::running; 
			if(in!=-2)
				thread[i].n=nextframe--;
			else{
				thread[i].n=n;
				in=i;
			}
			_RPT2(0,"Distributor loop2 Thread %d recruted to generate frame %d\n",i,thread[i].n);
			SetEvent(thread[i].begin);}
	}
	_RPT1(0,"Distributor status loop2: in:%d\n",in);
	if(in!=-1)
	{
		WaitForSingleObject(thread[in].done,INFINITE);
		SetEvent(thread[in].done);
		result=thread[in].result;
	}
	_RPT1(0,"Distributor end status: result:%x\n",result);
	return result;
}
*/

PVideoFrame Distributor::GetFrameX(int n, int last, IScriptEnvironment* env)
{
	PVideoFrame result=0;
	int in=-1;//thread number processing the current frame
	int inb=-1, inf=-1;
	int nmax=n, nmin=n;//Current highest frame number being processed
	unsigned int i;
	for(i=0;i<nthreads;i++)
	{
		if(thread[i].n>nmax && abs(thread[i].n - n) < 32)//find highest frame number being processed
			nmax=thread[i].n;
		if(thread[i].n<nmin && abs(thread[i].n - n) < 32)//find lowest  frame number being processed
			nmin=thread[i].n;
		if (thread[i].n==n-1)
			inb=i;
		if (thread[i].n==n+1)
			inf=i;
		if(thread[i].n==n)//if the requested frame is being processed by thread i
			if(thread[i].status==Thread::idle){//and it is ready to be used
				result=thread[i].result;//assign it to result 
			}
			else						//else assign in to the thread number
				in=i;
	}
	_RPT2(0,"Distributor status loop1: result:%x, in:%d,\n",result,in);
	if(result==0&&in==-1)//if no current thread is working on the requested frame set in to -2
		in=-2;
	int diff=last<=n?1:-1;
	do
	{
		int nextframe=(diff<0?nmin:nmax)+diff;
		int inneighbour=diff<0?inb:inf;

		for(i=0;i<nthreads;++i==in?i++:0)//run though the active threads and skip the thread that works on the requested frame.
		{
			if(thread[i].status==Thread::idle&&(diff<0?thread[i].n>=n||n-thread[i].n>20:thread[i].n<=n||thread[i].n-n>20)){//if the thread is done processing a frame that lies before the current frame 
				WaitForSingleObject(thread[i].done,INFINITE);  //wait for it to be ready to process the next frame 
															   //(as the thread might stale between setting the idle status and setting the 
															   //done event resulting in the thread signaling done even before beginning working on the frame
				thread[i].status=Thread::running;			   
				if(in!=-2)									   //if a thread is assigned to the requested frame
					if(inneighbour==-1)
					{
						inneighbour=i;
						thread[i].n=n+diff;
						if(nextframe==n+diff)
							nextframe+=diff;
					}
					else
					{
						thread[i].n=nextframe;				   //assign it to the next frame
						nextframe+=diff;
					}
				else{										
					thread[i].n=n;							   //else assign it to the requested frame
					in=i;
				}
				_RPT2(0,"Distributor loop2 Thread %d recruted to generate frame %d\n",i,thread[i].n);
				SetEvent(thread[i].begin);}					   //let the thread begin
			//NOTE: threads that are done working on a frame that is after the current requested frame is not
			//assigned a new frame as the frame will be requested soon. This could be changed as the frame is saved in the cache so it would return quickly.
		}
		diff=-diff;
	}
	while(in==-2);
	_RPT1(0,"Distributor status loop2: in:%d\n",in);
	if(in!=-1)//if the thread creating the requested frame isn't done 
	{
		WaitForSingleObject(thread[in].done,INFINITE); //wait for it to complete processing
		SetEvent(thread[in].done);					   //and signal the thread is done to avoid a deadlock in the loop above
		result=thread[in].result;					   
	}
	_RPT1(0,"Distributor end status: result:%x\n",result);
	return result;
}

PVideoFrame Distributor::GetFrame(int n,IScriptEnvironment* env)
{
	_RPT1(0,"Distributor generating frame %d\n",n);
	int prevframe=lastframe;
	lastframe=n;
	//TODO: add support for a delta between lastframe and current frame larger than 1
	return GetFrameX(n,prevframe,env);
// 	if(prevframe<=n)
// 		return GetFrameForward(n,env);
// 	else
// 		return GetFrameBackward(n,env);
	
}

