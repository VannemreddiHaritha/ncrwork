#include<stdio.h>
#include<stdlib.h>
int main()
{

	int number, t, r, result = 0;


	scanf_s("%d", &number);

	t= number;

	while (t!= 0)
	{
		r= t%10;
		result += r*r*r;
		t/= 10;
	}

	if (result == number)
		printf("%d is an Armstrong number.", number);
	else
		printf("%d is not an Armstrong number.", number);

	return 0;

}