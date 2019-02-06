#include<stdio.h>
int main() 
{
	int a[100];
	int n, j, sum1, sum,i;
	scanf_s("%d%d", &n, &sum);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		sum1 = a[i];
		for (j = i + 1; j <= n; j++)
		{
			if (sum1 == sum)
			{
				printf("sum is found at %d and %d", i, j-1);
			}
			sum1 = sum1 + a[j];
		}
    }
	getch();
	return 0;

}