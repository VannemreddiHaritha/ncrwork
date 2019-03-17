#include<stdio.h>
int main()
{
	int a[100];
	int n, j, sum1, sum, i,count;
	printf("enter no of elements and sum");
	scanf_s("%d%d", &n, &sum);
	printf("enter elements");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		
		sum1 = a[i];
		for (j = i + 1; j <= n; j++)
		{
			count = 0;
			if (sum1 == sum)
			{
				count = 1;
				printf("sum is found at %d and %d", i, j - 1);
			}
			sum1 = sum1 + a[j];
		}
	}
	if (count == 0)
		printf("sum is not found");
	
	getch();
	return 0;

}