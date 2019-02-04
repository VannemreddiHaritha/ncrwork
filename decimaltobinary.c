/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


    #include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	
	scanf_s("%d", &n);
	int b[10],r,i=0,j;
	while (n != 0)
	{
		r = n % 2;
		b[i] = r;
		n = n / 2;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		printf("%d", b[j]);
	}
	getch();
	return 0;
}

	


