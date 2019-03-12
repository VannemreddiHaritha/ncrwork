#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
long variable = 0;
int COUNT = 50;
CRITICAL_SECTION var_cs;
DWORD WINAPI fun1(LPVOID lparameter)
{
	EnterCriticalSection(&var_cs);
    variable++;
	LeaveCriticalSection(&var_cs);
	return variable;
}
DWORD WINAPI fun2(LPVOID lparameter)
{

	EnterCriticalSection(&var_cs);
	variable++;
	LeaveCriticalSection(&var_cs);
	return variable;
}
int main()
{
	DWORD threadId1, threadId2;
	InitializeCriticalSection(&var_cs);
   HANDLE hthread1, hthread2, array[2];
	while (1)
	{
        variable = 0;
		hthread1 = CreateThread(NULL, 0, fun1, NULL, 0, &threadId1);
		if (hthread1 != NULL)
			printf("created thread1\n");
		else
			printf("thread1 is not created\n");

		hthread2 = CreateThread(NULL, 0, fun2, NULL, 0, &threadId2);
		if (hthread2 != NULL)
			printf("created thread2\n");
		else
			printf("thread2 is not created\n");
		array[0] = hthread1;
		array[1] = hthread2;
		WaitForMultipleObjects(2, array, TRUE, INFINITE);
		printf("variable=%d\n", variable);
		if (variable == 1)
		{
			break;
		}

	}

	CloseHandle(hthread1);
	CloseHandle(hthread2);
	getchar();
	return 0;
}