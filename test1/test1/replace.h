#include<stdio.h>
void replace()
{
	FILE *fp1, *fp2;
	char ch1,ch2;
	fopen_s(&fp1, "replace1.txt", "r");
	fopen_s(&fp2, "replace2.txt", "w");
	if (fp1 == NULL || fp2 == NULL)
	{
		printf("invalid file");
	}
	while ((ch1 = fgetc(fp1)) != EOF)
	{
		if (ch1 == '\t')
		{
			ch2 = '\\';
			fputc(ch2, fp2);
			ch2 = 't';
			fputc(ch2, fp2);
		}
		else
			fputc(ch1, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}
