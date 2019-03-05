/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


    #include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long int n;
	int B=0, i = 0, r;
	scanf("%ld", &n);
	while (n != 0)
	{
		r = n % 10;
		B = r * pow(2 , i) + B;
		n = n / 10;
		i++;
	}
	printf("%d", B);

	return 0;
}


