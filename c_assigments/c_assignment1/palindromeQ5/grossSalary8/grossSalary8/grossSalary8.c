#include<stdio.h>
#include<stdlib.h>
int main()
{
	int b,da,hra;
	float gross;
	scanf_s("%d", &b);
	if (b >= 1 && b <= 4000)
	{
		da = b * 50 / 100;
		hra = b * 10 / 100;
	}
	else if(b>=4001&&b<=8000)
	{
		da = b * 60 / 100;
		hra = b * 20 / 100;
	}
	else if (b >= 8001 && b <= 12000)
	{
		da = b * 70 / 100;
		hra = b * 25 / 100;
	}
	else if (b >= 12001)
	{
		da = b * 80 / 100;
		hra = b * 30 / 100;
	}
	gross = b + hra + da;
	printf("%f", gross);
	getch();
	return 0;


}