#include<Windows.h>
#include<thread>
#include<stdio.h>
#include<stdlib.h>
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	for (int i = 0;i < 10;i++) {
		printf("%d\n", i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD threadId;
	HANDLE hthread;
	hthread = CreateThread(NULL, 0, ThreadProc, NULL, CREATE_SUSPENDED, &threadId);
	if (hthread != NULL)
		printf("created thread\n");
	else
		printf("thread is not created\n");
	Sleep(5000);
	ResumeThread(hthread);


	getchar();
	CloseHandle(hthread);
}