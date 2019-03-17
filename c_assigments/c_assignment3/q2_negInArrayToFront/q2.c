#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100], n, j = 0, i, b[100], k;
	printf("enter number of elements");
	scanf_s("%d", &n);
	printf("enter elements");
	for (i = 0;i < n;i++)
		scanf_s("%d", &a[i]);
	for (i = 0;i < n;i++)
	{
		if (a[i] < 0)
		{
			b[j] = a[i];
			j = j + 1;
		}
	}
	k = j
		;
	for (i = 0;i < n;i++)
	{
		if (a[i] >= 0)
		{
			b[k] = a[i];
			k++;
		}
	}
	printf("output array");
	for (j = 0;j < n;j++)
		printf("%d ", b[j]);
	getch();
	return 0;
}
