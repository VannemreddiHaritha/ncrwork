#include<stdio.h>
void count1()
{
	FILE *fp;
	char ch;
	int alpha = 0, digit = 0, space = 0, sc=0;
	fopen_s(&fp, "count.txt", "r");
	if (fp == NULL)
	{
		printf("invalid file");
	}
	while ((ch = fgetc(fp))!=EOF)
	{
		if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
			alpha++;
		else if (ch >= '0'&&ch <= '9')
			digit++;
		else if (ch ==' ')
			space++;
		else
			sc++;
	}
	fclose(fp);
	printf("%d\n", alpha);
	printf("%d\n", digit);
	printf("%d\n", space);
	printf("%d\n", sc);

}