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
class ScriptEnvironmentMT;
class MTend;




class MTend : public GenericVideoFilter {
public:
	 PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
	 //MTend(PClip clip,const char* string,int nthreads,int overlap,IScriptEnvironment* env);
	 MTend(PClip clip,const char* string,int nthreads,int overlap,bool vertical,IScriptEnvironment* env);
	 ~MTend();
	 CRITICAL_SECTION* GetCriticalSection() ;
	 static AVSValue __cdecl Create(AVSValue args, void* user_data, IScriptEnvironment* env);
protected:
	struct WTP{
	unsigned int threadnumber;
	PVideoFrame dst;
	PClip clip;

	MTend* _this;
};
	void MergeFramesHorizontal(PVideoFrame& dst, IScriptEnvironment* env);
	void MergeFramesVertical(PVideoFrame& dst, IScriptEnvironment* env);
	unsigned int nthreads;
	int threadsize;//width/height that each thread process
	int overlap;
	bool vertical;
	bool WasRGB;
	WTP *wtp;//worker thread pool
	HANDLE* thread;
	bool EndThreads;
	IScriptEnvironment* _env;
	int _n;
	HANDLE* EventFrameProcessed;
	HANDLE* EventProcessFrame;
	CRITICAL_SECTION cs;
	//PClip *workerclips;
	static DWORD WINAPI workerthread(WTP* wtp);
};

class MTstart : public GenericVideoFilter {
public:
	 PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
	 MTstart(PClip clip,UINT _left,UINT _top,UINT _width,UINT _height,MTend* mtend,IScriptEnvironment* env);
	 ~MTstart();
	 //static AVSValue __cdecl Create(AVSValue args, void* user_data, IScriptEnvironment* env);
protected:
	CRITICAL_SECTION *cs;
	UINT left_bytes;
	UINT top;
};