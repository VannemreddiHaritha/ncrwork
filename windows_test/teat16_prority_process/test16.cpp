#include<Windows.h>
#include<stdio.h>
#include<tchar.h>

int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si1, si2;
	PROCESS_INFORMATION pi1, pi2;

	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
	// Start the child process. 
	if (CreateProcess(NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		HIGH_PRIORITY_CLASS,
		NULL,
		NULL,
		&si1,
		&pi1))
		printf("process1 created\n");
	else {
		printf("Creating Process1 failed (%d)\n", GetLastError());
		return FALSE;
	}
	/*BOOL return_value = SetPriorityClass(pi1.hProcess, HIGH_PRIORITY_CLASS);
	if (return_value = 0)
		printf("priority is not set\n");
	else
		printf("priority is set\n");*/

	//CloseHandle(pi1.hProcess);
	//CloseHandle(pi1.hThread);
}