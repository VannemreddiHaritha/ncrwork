#include<Windows.h>
#include<stdio.h>
#include"demo.h"
BOOL WINAPI Dllmain(HANDLE hand, DWORD msg, LPVOID res)
{
	switch (msg)
	{
		case DLL_PROCESS_ATTACH : printf("DLL is attached\n");
			break;
		case DLL_PROCESS_DETACH: printf("DLL is detached\n");
			break;

	}
	return TRUE;
}