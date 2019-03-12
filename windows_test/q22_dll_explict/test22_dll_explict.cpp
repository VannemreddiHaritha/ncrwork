#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<demo.h>
//typedef int (*add1)(int, int);
//typedef int(*sub1)(int, int);
typedef int(*MYPROC)(int, int);
int _tmain()
{
	HMODULE hdll;
	MYPROC ADD, SUB;
	/*add1 ptr1;
	sub1 ptr2;*/
	int variable1 = 10,variable2=5;
	int sum = 0, difference = 0;
	hdll = LoadLibraryEx(TEXT("C:\\Users\\haritha\\source\\repos\\ncrwork\\windows_test\\Debug\\dll.dll"),NULL,NULL);
	if (hdll == NULL)
	{
		printf("hdll failed.....error in %d\n",GetLastError());
		getchar();
		return FALSE;
	}
	ADD = (MYPROC)GetProcAddress(hdll, (LPCSTR)"add");
	if (ADD != NULL)
	{
		sum = ADD(variable1, variable2);
		printf("sum is %d", sum);
	}
	else
	{
		printf("error in ADD...error in%d", GetLastError());
		getchar();
		return FALSE;
	}
	SUB = (MYPROC)GetProcAddress(hdll, (LPCSTR)"sub");
	if (SUB != NULL)
	{
		difference = SUB(variable1, variable2);
		printf("difference is %d", difference);
	}
	else
	{
		printf("error in ADD...error in%d", GetLastError());
		getchar();
		return FALSE;
	}
	FreeLibrary(hdll);

}