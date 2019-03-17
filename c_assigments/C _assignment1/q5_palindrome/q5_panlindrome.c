#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, rev = 0, r, num;
	printf("enter number");
	scanf_s("%d", &n);
	num = n;
	while (n != 0)
	{
		r = n % 10;
		rev = rev * 10 + r;
		n = n / 10;
	}
	if (num == rev)
		printf("palindrome");
	else
		printf("not  palindrome");

	getch();
	return 0;
}