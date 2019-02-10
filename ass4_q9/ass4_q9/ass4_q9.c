#include<stdio.h>
#include<stdlib.h>
void match(char, char);
int main()
{
	char s1[10], s2[10];
	printf("enter two strings");
	scanf_s("%s", s1);
	scanf_s("%s", s2);
	match(s1, s2);
	getch();
	return 0;
}
void match(char s1[], char s2[])
{
	for (int i = 0; i < strlen(s1); i++)
	{
		for (int j = 0; j < strlen(s2); j++)
		{
			if (s1[i] == s2[j])
			{
				printf("match found at %d", i);
				return;
			}
		}
	}
}