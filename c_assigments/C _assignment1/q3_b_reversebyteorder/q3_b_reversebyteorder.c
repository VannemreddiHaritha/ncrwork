#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0XCAFE;
	int r;
	while (n != 0)
	{
		r = n % (pow(10, 8));
		printf("%x", r);
		n = n / (pow(10, 8));
	}
	getch();
	return 0;
}