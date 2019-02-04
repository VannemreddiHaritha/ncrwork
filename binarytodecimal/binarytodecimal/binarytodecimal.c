#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n, b=0, i = 0, r;
	scanf_s("%d", &n);
	while (n != 0)
	{
		r = n % 10;
		n = n / 10;
		b = r * pow(2 , i) + b;
		i++;
	}
	printf("%d", b);
	getch();
	return 0;
}