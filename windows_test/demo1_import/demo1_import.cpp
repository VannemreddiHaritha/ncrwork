#include<Windows.h>
#include<stdio.h>
#include"demo.h"
int main()
{
	int variable1=10;int variable2=5;
	int sum = 0, difference = 0;
	sum = add(variable1, variable2);
	difference = sub(variable1, variable2);
	printf("sum is %d\n", sum);
	printf("difference is%d\n", difference);
	getchar();
	return 0;
}