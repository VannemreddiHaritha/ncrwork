#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100],n;
	scanf_s("%d", &n);
	int i;
	for (i = 0;i < n;i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("%d %d %d %d", a, (a + 2), *a, *(a + 2));
	getch();
	return 0;

}