class MTiend;



class MTiend : public GenericVideoFilter {
public:
	 PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
	 MTiend(PClip clip,const char* string,IScriptEnvironment* env);
	 ~MTiend();
	 CRITICAL_SECTION* GetCriticalSection() ;
	 static AVSValue __cdecl Create(AVSValue args, void* user_data, IScriptEnvironment* env);
protected:
	struct WTP{
	unsigned int threadnumber;
	PVideoFrame dst;
	PClip clip;
	MTiend* _this;
};
	int overlap;
	bool vertical;
	bool WasRGB;
	WTP wtp[2];//worker thread pool
	HANDLE thread;
	bool EndThreads;
	IScriptEnvironment* _env;
	int _n;
	HANDLE EventFrameProcessed;
	HANDLE EventProcessFrame;
	CRITICAL_SECTION cs;
	static DWORD WINAPI workerthread(WTP* wtp);
};

class MTistart : public GenericVideoFilter {
public:
	 PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
	 MTistart(PClip clip,bool parity,MTiend* mtend,IScriptEnvironment* env);
protected:
	CRITICAL_SECTION *cs;
	bool parity;
};