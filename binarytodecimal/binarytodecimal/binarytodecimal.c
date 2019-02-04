#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n, B=0, i = 0, r;
	scanf_s("%d", &n);
	while (n != 0)
	{
		r = n % 10;
		n = n / 10;
		B = r * pow(2 , i) + B;
		i++;
	}
	printf("%d", B);
	getch();
	return 0;
}