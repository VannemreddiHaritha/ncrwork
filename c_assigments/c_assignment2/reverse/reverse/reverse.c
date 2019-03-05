#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, r, sum = 0;
	scanf_s("%d", &n);
	while(n!=0)
	{
		r = n % 10;
		sum = sum * 10 + r;
		n = n / 10;
	}
	printf("%d", sum);
	getch();
	return 0;
}