#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int val = 0xCAFE;
	int i;
	int count = 0;
	for (i = 0; i < 4; i++)
	{
		if ((int)pow(2, i) & val)
		{
			count++;
		}
	}
	if (count >= 3)
	{
		printf("atleast four out of 3 are ON ");
	}
	else
		printf("OFF");

	getch();
	return 0;
}