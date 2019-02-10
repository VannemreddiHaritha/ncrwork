#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s1[100], s2[100];
	char c;
	scanf_s("%s", s1);
	scanf_s("%s", s2);
	int l1 = 0, l2 = 0;
	while (s1[l1] != '\0')
	{
		l1++;
	}
	while (s2[l2] != '\0')
	{
		l2++;
	}
	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			if (s1[i] == s2[j])
			{
				c = s2[j];
			}
			for (int i = 0; i < l1; i++)
			{
				if (s1[i] == c)
				{
					l1 = l1 - 1;
					for (j = i; j < l1; j++)
					{
						s1[j] = s1[j + 1];
					}
				}
			}
		}
	}
	
	for (int i = 0; i < l1; i++)
	{
		printf("%c", s1[i]);
	}
	getch();
	return 0;
}
