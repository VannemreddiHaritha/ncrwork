#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,sum=0,t,r;
	scanf_s("%d", &n);
	t = n;
	while(t != 0)
	{
		r = t % 10;
		sum = sum + r;
		t= t / 10;
	}
	printf("sum=%d", sum);
	getch();
	return 0;
}