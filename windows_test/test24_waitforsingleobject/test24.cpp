#include<Windows.h>
#include<thread>
#include<stdio.h>
#include<stdlib.h>
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	for (int i = 0;i < 10;i++) {
		printf("%d\n", i);
		//Sleep(2000);
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
	//DWORD dw = WaitForSingleObject(hthread, INFINITE);
	DWORD dw = WaitForSingleObject(hthread, 1000);
	
	switch (dw)
	{
	case WAIT_OBJECT_0:
		printf("thread is terminated");
		break;
	case WAIT_TIMEOUT:
		printf("time interval expired");
		break;
	case WAIT_FAILED:
		printf("wait failed");
		break;
	}

	getchar();
	CloseHandle(hthread);
}