
#ifndef _MY_DEBUG_H
#define _MY_DEBUG_H 1

#ifdef _DEBUG
#include <stdio.h>	 /* vsprintf */
#include <windows.h>
#define DPRINTF_BUF_SZ  10240
static void SENDSTR(char *cMsg){
	HWND hTgWnd1 = FindWindow("Notepad", "–³‘è - ƒƒ‚’ ");
	hTgWnd1 = GetWindow(hTgWnd1, GW_CHILD);
  
	if(hTgWnd1 > 0){
		SendMessage(hTgWnd1, EM_REPLACESEL, NULL, (LPARAM)cMsg);
	}
}
static void DUMP(char *tablename, LPBYTE data, DWORD size){
	char buf1[60]	= {'\0'};
	char *buf2		= (char*)calloc(1, size * 60);
	int i;

	//sprintf(buf2, "------ DUMP %s ------\r\n", tablename);
	//for (int y=0; y<(size/16); y++){
	//	sprintf(buf1, "%08X: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n"
	//		, data[y*16 + 0], data[y*16 + 1], data[y*16 + 2], data[y*16 + 3], data[y*16 + 4], data[y*16 + 5], data[y*16 + 6], data[y*16 + 7]
	//		, data[y*16 + 8], data[y*16 + 9], data[y*16 +10], data[y*16 +11], data[y*16 +12], data[y*16 +13], data[y*16 +14], data[y*16 +15]
	//		);
	//	strcat(buf2, buf1);
	//}

	_snprintf(buf2, size * 60, "------ DUMP %s ------", tablename);
	for (i=0; i<size; i++){
		if ((i % 16) == 0){
			sprintf(buf1, "\r\n%02X", data[i]);
		}else{
			sprintf(buf1, " %02X", data[i]);
		}
		strcat(buf2, buf1);
	}
	strcat(buf2, "\r\n\r\n");
	SENDSTR(buf2);
	free(buf2);
}
static void DPRINTLN(char *fmt, ...)
{
	va_list args;
	char *buf1 = (char*)calloc(DPRINTF_BUF_SZ, sizeof(char));
	char *buf2 = (char*)calloc(DPRINTF_BUF_SZ, sizeof(char));

	va_start(args, fmt);
	_vsnprintf(buf1, DPRINTF_BUF_SZ, fmt, args);
	va_end(args);
	_snprintf(buf2, DPRINTF_BUF_SZ, "[0x%08X]\t%s\r\n" ,GetCurrentThreadId(), buf1);
	//strcat(buf, "\r\n");
	//OutputDebugString(buf);
	//FILE *fp = fopen("_debug.txt", "ab");
	//fwrite(buf, strlen(buf), 1, fp);
	//fclose(fp);
	SENDSTR(buf2);

	free(buf1);
	free(buf2);
}
static void DPRINTF(char *fmt, ...)
{
	va_list args;
	char *buf1 = (char*)calloc(DPRINTF_BUF_SZ, sizeof(char));

	va_start(args, fmt);
	_vsnprintf(buf1, DPRINTF_BUF_SZ, fmt, args);
	va_end(args);

	//OutputDebugString(buf);
	//FILE *fp = fopen("_debug.txt", "ab");
	//fwrite(buf, strlen(buf), 1, fp);
	//fclose(fp);
	SENDSTR(buf1);

	free(buf1);
}
#else
static __inline void DPRINTLN(char *fmt, ...) { }
static __inline void DPRINTF(char *fmt, ...) { }
static __inline void DUMP(char *tablename, char* data, unsigned long size){ }
#endif //_DEBUG

#endif //_MY_DEBUG_H