#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int main()
{
	HANDLE hevent = CreateEvent(NULL, FALSE, FALSE, TEXT("newevent"));
	if (hevent == NULL)
	{
		printf("error in create event");
	}
	else
		printf("event is created");
	//CloseHandle(hevent);
	getchar();
	return 1;
}