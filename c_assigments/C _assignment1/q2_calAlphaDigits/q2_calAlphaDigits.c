#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[81];
	int i, l, space = 0, digit = 0, alpha = 0, tab = 0;
	printf("enter string");
	scanf_s("%[^\n]s", s,strlen(s));
	for (l = 0;s[l];l++);
	for (i = 0;i <= l;i++)
	{
		if (s[i] == 32)
			space = space + 1;
		else if (s[i] >= 48 && s[i] <= 57)
			digit = digit + 1;
		else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
			alpha = alpha + 1;
		else if (s[i] == '\t')
			tab = tab + 1;
	}
	printf("space=%d\ndigit=%d\nalpha=%d\ntab=%d", space, digit, alpha, tab);

	getch();
	return 0;
}
