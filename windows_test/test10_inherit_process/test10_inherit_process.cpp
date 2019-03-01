#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	_SECURITY_ATTRIBUTES sa1;
	ZeroMemory(&sa1, sizeof(sa1));
	sa1.nLength = sizeof(sa1);
	 HANDLE hevent = CreateEvent(&sa1, FALSE, FALSE, TEXT("newevent"));
	sa1.lpSecurityDescriptor = NULL;
	sa1.bInheritHandle = TRUE;
	if (hevent == NULL)
		printf("error in create event\n");
	else
		printf("event is created\n");
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
		TRUE,
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
}