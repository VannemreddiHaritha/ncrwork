#include<Windows.h>
#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
#define QSIZE 5
SRWLOCK srwLock;
CONDITION_VARIABLE cvReadyToProduce;
CONDITION_VARIABLE cvReadyToConsume;
struct object
{
	int threadNumber;
	int element;
};
queue<object> SharedQ;
DWORD WINAPI WriteThread(LPVOID lparamater)
{
	int threadNumber = PtrToUlong(lparamater);
	for (int element =1 ; element <= 10; element++)
	{
		object obj = { threadNumber,element };
		AcquireSRWLockExclusive(&srwLock);
		if (SharedQ.size() >= QSIZE)
		{
			cout << "Write Thread...thread number is " << threadNumber <<endl<< " Queue is full....cannot be able to produce at element " << element << "\n";
			SleepConditionVariableSRW(&cvReadyToProduce, &srwLock, INFINITE, 0);
		}
		else
		{
			SharedQ.push(obj);
			cout << "Write thread ...thread number is" << threadNumber<<endl << " can be produced at element" << element << "\n";
			ReleaseSRWLockExclusive(&srwLock);
			WakeAllConditionVariable(&cvReadyToConsume);
			Sleep(1500);
		}
	}
	return 0;
}
DWORD WINAPI ReadThread(LPVOID lparamater)
{
	int threadNumber = PtrToUlong(lparamater);
	for (int element = 1; element <= 10; element++)
	{
		//object obj = { threadno,ele };
		AcquireSRWLockShared(&srwLock);
		if (SharedQ.size() <= 0)
		{
			cout << "Read thread..."<<threadNumber<<endl<<" can't read.Queue is empty\n"<<element<<endl;
			SleepConditionVariableSRW(&cvReadyToConsume, &srwLock, INFINITE, 0);
		}
		else
		{
			object obj = SharedQ.front();
			cout << "Reader thread consumed..."<<endl;
			SharedQ.pop();
			ReleaseSRWLockShared(&srwLock);
			WakeAllConditionVariable(&cvReadyToProduce);
			Sleep(1500);
		}
	}
	return 0;
}
int main()
{
	HANDLE g_hThread[10];
	DWORD dwThreadId;
	InitializeSRWLock(&srwLock);
	InitializeConditionVariable(&cvReadyToConsume);
	InitializeConditionVariable(&cvReadyToProduce);
	int i;
	for (i = 0; i < 4; i++)
	{
		g_hThread[i] = CreateThread(NULL,
			0,
			WriteThread,
			(PVOID)(INT_PTR)i,//the integer is converted to pointer
			0,
			&dwThreadId
		);
	}
	for (i = 0; i < 2; i++)
	{
		g_hThread[i] = CreateThread(NULL,
			0,
			ReadThread,
			(PVOID)(INT_PTR)i,
			0,
			&dwThreadId
		);
	}
	WaitForMultipleObjects(4, g_hThread, TRUE, 50000);
	for (i = 0; i < 4; i++)
		CloseHandle(g_hThread[i]);
	return 0;
}
