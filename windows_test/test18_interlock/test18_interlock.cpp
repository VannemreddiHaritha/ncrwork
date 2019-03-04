#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
long variable = 0;
DWORD WINAPI fun1(LPVOID lparameter)
{
	InterlockedAdd(&variable, 1);
	variable++;
	return 0;
}
DWORD WINAPI fun2(LPVOID lparameter)
{
	InterlockedAdd(&variable, 1);
	variable++;
	return 0;
}
int main()
{
	DWORD threadId1, threadId2;
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
			printf("syncronization problem");
			break;
		}

	}

	CloseHandle(hthread1);
	CloseHandle(hthread2);
	getchar();
	return 0;
}