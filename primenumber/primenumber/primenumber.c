#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n1, n2,i;
	scanf_s("%d%d", &n1, &n2);
	for(i=n1;i<=n2;i++)
	{
		if (i % 2 != 0)
		{
			printf("%d", i);
		}
	}
	getch();
	return 0;

}