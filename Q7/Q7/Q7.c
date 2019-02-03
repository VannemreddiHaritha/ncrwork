#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100],i,j=0,b[100];
	for (i = 0;i <= 5;i++)
		scanf_s("%d",&a[i]);
	int min, max, count = 0, sum = 0;
	for (i = 0;i <= 5;i++)
	{
		if (a[i] > 0)
		{
		
			sum = sum + a[i];
			count++;
			b[j] = a[i];
			j++;
		}
		else
			break;
	}
	max = b[0];
	min = b[0];
	for(i=0;i<=5;i++)
	{
			if (max < b[i])
				max = b[i];
			if (min > b[i])
				min = b[i];
	
	}
	printf("sum%dcount%dmin%dmax%d", sum, count, min, max);
	getch();
	return 0;
}