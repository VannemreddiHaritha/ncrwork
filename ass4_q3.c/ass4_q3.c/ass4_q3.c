#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j,count=0;
	char *s[] = {"we will teach you how to","move a mountain","level a building","erase a past","make a million" };
	for (j = 0;j<5;j++)
	{
		char *a = *(s + j);
		for (i = 0;a[i]!='\0';i++)
			if (a[i] == 'e')
				count++;
	}
	printf("%d", count);
	getch();
	return 0;
}
