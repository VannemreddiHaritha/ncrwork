#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	long fact = 1;
	printf("enter number");
	scanf_s("%ld", &n);
	int i;
	if (n > 0)
	{
		for (i = 1;i <= n;i++)
			fact = fact * i;
	}
	if (n == 0)
		fact = 1;
	printf("factorial is %ld", fact);
	getch();
	return 0;
}