#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *a[4];
	int n, i, j;
	int x, y, k;
	for (i = 0;i < 4;i++)
	{
		scanf("%d", n);
		a[i] = (char *)malloc(n * sizeof(char*));
		scanf("%s", a[i]);
		if (a[i] == NULL)
		{
			for (j = i;j >= 0;j--)
			{
				free(a[i]);
			}
			return -1;
		}
		
	}
	for(i=0;i<4;i++)
	printf("%s", a[i]);


	getch();
	return 0;
}
