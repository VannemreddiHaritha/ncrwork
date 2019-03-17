#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int n, i, j;
	printf("enter number");
	scanf_s("%d", &n);
	for (i = 1;i <= n;i++)
	{
		for (j = n - i;j > 0;j--)
		{
			printf(" ");
		}
		for (j = i;j > 1;j--)
		{
			printf("%d", j);
		}
		for (j = 1;j <= i;j++)
		{
			printf("%d", j);
		}
		printf("\n");
	}
	_getch();
	return 0;
}