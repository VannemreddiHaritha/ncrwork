#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long int n;
	int B = 0, i = 0, r;
	scanf_s("%ld", &n);
	while (n != 0)
	{
		r = n % 10;
		B = r * pow(2, i) + B;
		n = n / 10;
		i++;
	}
	printf("%x", B);

	getch();
	return 0;
}