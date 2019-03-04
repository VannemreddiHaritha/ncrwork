#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
DWORD Exitcode;
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	for (int i = 0;i < 10;i++) {
		printf("i=%d\n", i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD threadId;
	HANDLE hthread;
	hthread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &threadId);
	if (hthread != NULL)
		printf("created thread\n");
	else
		printf("thread is not created\n");
	WaitForSingleObject(hthread, 6000);
	TerminateThread(hthread, Exitcode);
	GetExitCodeThread(hthread, &Exitcode);
	printf("exit code is%ld\n", Exitcode);

	getchar();
	CloseHandle(hthread);
	return 0;
}