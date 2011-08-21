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

#include "utility.h"
dostream cerrwin;

#ifdef WRITELOG
std::ofstream outfile("MT_log.txt");
#endif

typedef struct tagTHREADNAME_INFO
{
   DWORD dwType; // must be 0x1000
   LPCSTR szName; // pointer to name (in user addr space)
   DWORD dwThreadID; // thread ID (-1=caller thread)
   DWORD dwFlags; // reserved for future use, must be zero
} THREADNAME_INFO;

void SetThreadName( DWORD dwThreadID, LPCSTR szThreadName)
{
   THREADNAME_INFO info;
   info.dwType = 0x1000;
   info.szName = szThreadName;
   info.dwThreadID = dwThreadID;
   info.dwFlags = 0;
   LOG("create thread "<<std::hex<<dwThreadID<<std::dec<<" name:"<<szThreadName)
/*
  __try
  {
    RaiseException( 0x406D1388, 0, sizeof(info)/sizeof(DWORD), (DWORD*)&info );

  }
  __except (EXCEPTION_CONTINUE_EXECUTION)
  {
  }
*/
}

int Split(const char* src, char separator, char** dest)
{
	int j = 0;
	int k = 0;

	for (unsigned int i=0; i<strlen(src); i++)
	{
		dest[k][j  ] = src[i];
		dest[k][j+1] = '\0';
		if (dest[k][j] == separator){
			dest[k][j] = '\0';
			k++;
			j = 0;
		} else {
			j++;
		}
	}
	return k;
}

