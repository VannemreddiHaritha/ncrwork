#include<Windows.h>
#include<stdio.h>
#include<tchar.h>

int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si1,si2;
	PROCESS_INFORMATION pi1,pi2;

	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
    // Start the child process. 
	if (CreateProcess(NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si1,
		&pi1))
		printf("process1 created\n");
	else {
		printf("Creating Process1 failed (%d)\n", GetLastError());
		return FALSE;
	}
	printf("handle of process1 is %d\n", pi1.hProcess);
	printf(" process1 id is %d\n", pi1.dwProcessId);
		WaitForSingleObject(pi1.hProcess,5000);
		CloseHandle(pi1.hProcess);
		CloseHandle(pi1.hThread);

	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));
	// Start the child process2. 
	if (CreateProcess(NULL,
		argv[2],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si2,
		&pi2))
		printf("process2 created\n");
	else
	{
		printf("Creating Process2 failed (%d)\n", GetLastError());
		return FALSE;
	}
	printf("handle of process1 is %d\n", pi2.hProcess);
	printf(" process1 id is %d\n", pi2.dwProcessId);
	WaitForSingleObject(pi2.hProcess, 5000);
	CloseHandle(pi2.hProcess);
	CloseHandle(pi2.hThread);
	getchar();
	return 0;
}

