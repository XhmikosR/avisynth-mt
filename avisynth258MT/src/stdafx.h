#ifndef __Stdafx_H__
#define __Stdafx_H__

#define _WIN32_WINNT 0x0501

#pragma warning (disable:4244)

//C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <io.h>
#include <ctype.h>
#include <wtypes.h>

//windows
#define WIN32_LEAN_AND_MEAN
#include <objbase.h>
#include <vfw.h>
#include <windows.h>
#include <mmsystem.h>
#include <msacm.h>

//STL
#include <vector>
#include <algorithm>

// fast synchronization
#if (_MSC_VER >= 1400)
#include <intrin.h>
#define InterlockedIncrement _InterlockedIncrement
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedExchange _InterlockedExchange
#undef InterlockedExchangePointer
#define InterlockedExchangePointer(a,b) (void*)_InterlockedExchange((volatile long*)(a), (long)(b))
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange
#endif

#endif // __Stdafx_H__
