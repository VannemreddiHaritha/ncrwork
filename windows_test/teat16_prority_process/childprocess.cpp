#include<Windows.h>
#include<thread>
#include<stdio.h>
#include<stdlib.h>
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	printf("in function...... thread process\n");
	return 0;
}
int main()
{
	printf("before setting the prority%d\n",GetPriorityClass(GetCurrentProcess()));
	SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
	printf("after setting the prority%d\n",GetPriorityClass(GetCurrentProcess()));
	DWORD threadId;
	HANDLE hthread;
	hthread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &threadId);
	if (hthread != NULL)
		printf("created thread\n");
	else
		printf("thread is not created\n");
	BOOL ret = SetThreadPriority(hthread, THREAD_PRIORITY_LOWEST);
	if (ret != 0)
	{
		printf("prority is set to lowest and value is %ld\n", GetThreadPriority(hthread));
	}
	else
	{
		printf("Set priority of thread failed %d\n", GetLastError());
		return 0;
	}


	getchar();
	CloseHandle(hthread);
}