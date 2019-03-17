#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("enter number");
	scanf_s("%d", &n);
	int b[10], r, i = 0, j, count = 0;
	while (n != 0)
	{
		r = n % 2;
		b[i] = r;
		n = n / 2;
		i++;
	}
	printf("binary nyumber is");
	for (j = i - 1;j >= 0;j--)
	{
		printf("%d", b[j]);
		if (b[j] == 1)
			count++;
	}
	printf("\ncount of 1's is %d\n", count);
	getch();
	return 0;

}