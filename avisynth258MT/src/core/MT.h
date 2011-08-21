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

#ifndef __MT_H__
#define __MT_H__

#include "../internal.h"

class VarTable;

class ScriptEnvironmentTLS {
public:
	VarTable* vartable;
	ScriptEnvironmentTLS():vartable(0){}
	~ScriptEnvironmentTLS();//destructor is defined in avisynth.cpp
};

class Distributor : public GenericVideoFilter{
public:
	Distributor(PClip clip, IScriptEnvironment* env);
	~Distributor();
	PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
	static AVSValue __cdecl Create_Distributor(AVSValue args, void*, IScriptEnvironment* env);
protected:
	struct Thread
	{
	public:
		int n;
		volatile enum{running,idle} status;
		volatile bool endthread;
		PVideoFrame result;
		HANDLE done;
		HANDLE begin;
		HANDLE thread;
		Distributor* distributor;
		Thread():n(-1),status(idle),done(CreateEvent(NULL,false,true,NULL)),begin(CreateEvent(NULL,false,false,NULL)),result(0),distributor(0),endthread(false){}
		~Thread(){
			endthread=true;
			SetEvent(begin);
			if(WAIT_TIMEOUT==WaitForSingleObject(thread,6000))
				TerminateThread(thread,1);
			CloseHandle(thread);
			CloseHandle(done);
			CloseHandle(begin);}
	} *thread;
	int lastframe;
	unsigned int nthreads;
    IScriptEnvironment* _env;
// 	PVideoFrame GetFrameForward(int n, IScriptEnvironment* env);
// 	PVideoFrame GetFrameBackward(int n, IScriptEnvironment* env);
	PVideoFrame GetFrameX(int n, int last, IScriptEnvironment* env);
	static DWORD WINAPI getframes(LPVOID param);
	//void AssignFramesToThread(int n);
	
};

#endif