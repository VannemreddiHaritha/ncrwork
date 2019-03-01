#include<Windows.h>
#include<stdio.h>
#include<tchar.h>

int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	// Start the child process. 
	if (CreateProcess(NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi))
		printf("process1 created\n");
	else {
		printf("Creating Process1 failed (%d)\n", GetLastError());
		return FALSE;
	}
	printf("handle of process1 is %d\n", pi.hProcess);
	printf(" process1 id is %d\n", pi.dwProcessId);
	WaitForSingleObject(pi.hProcess, 5000);
	printf("process identifier of calling processis%ld\n" ,GetCurrentProcessId());//gives the process identifier
	printf("thread identifier of calling threadis %ld\n", GetCurrentThreadId());//gives thread identifier of calling thread
	printf("process identifier of specified process%ld\n", GetProcessId(pi.hProcess));
	printf(" thread identifier of specified thread%ld\n", GetThreadId(pi.hThread));
	printf("process identifier of specified thread%ld\n", GetProcessIdOfThread(pi.hThread));
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}