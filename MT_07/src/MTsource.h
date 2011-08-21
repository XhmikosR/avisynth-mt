
class MTsource : public IClip {

protected:
	struct WTP{
	unsigned int threadnumber;
	PVideoFrame dst;
	bool running;
	MTsource* _this;
	int n;
};
	PClip child;
	 VideoInfo vi;
	unsigned int nthreads;
	WTP *wtp;//worker thread pool
	HANDLE* thread;
	bool EndThreads;
	IScriptEnvironment* _env;
	int nmax;
	int delta;
	int max_fetch;
	HANDLE* EventFrameProcessed;
	HANDLE* EventProcessFrame;
	static DWORD WINAPI workerthread(WTP* wtp);
public:
	 PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
	 void __stdcall GetAudio(void* buf, __int64 start, __int64 count, IScriptEnvironment* env) { child->GetAudio(buf, start, count, env); }
	const VideoInfo& __stdcall GetVideoInfo() { return vi; }
    bool __stdcall GetParity(int n) { return child->GetParity(n); }
    void __stdcall SetCacheHints(int cachehints,int frame_range) { } ;

	 MTsource(const char* string,int delta,int nthreads,int max_fetch,IScriptEnvironment* env);
	 ~MTsource();
	 static AVSValue __cdecl Create(AVSValue args, void* user_data, IScriptEnvironment* env);
};