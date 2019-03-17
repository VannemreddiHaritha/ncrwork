#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n1, n2, i, j, count;
	printf("enter n1 and n2 for interval");
	scanf_s("%d%d", &n1, &n2);
	for (i = n1;i <= n2;i++)
	{
		count = 0;
		for (j = 2;j <= i / 2;j++) {
			if (i % j == 0)
			{
				count = 1;
				break;
			}

		}
		if (count == 0)
			printf("%d ", i);
	}
	getch();
	return 0;

}