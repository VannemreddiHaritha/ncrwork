#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("enter decimal number");
	scanf_s("%d", &n);
	int b[10], r, i = 0, j;
	while (n != 0)
	{
		r = n % 2;
		b[i] = r;
		n = n / 2;
		i++;
	}
	printf("binary number is ");
	for (j = i - 1;j >= 0;j--)
	{
		printf("%d", b[j]);
	}
	getch();
	return 0;
}

