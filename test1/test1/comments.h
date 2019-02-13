void comment()
{
	FILE *fp1, *fp2;
	char ch1, ch2;
	fopen_s(&fp1, "c1.txt", "r");
	fopen_s(&fp2, "c3.txt", "w");
	if (fp1 == NULL || fp2 == NULL)
	{
		printf("invalid file");
	}
	while ((ch1 = fgetc(fp1)) != EOF)
	{
		if (ch1 == '/')
		{
			ch1 = fgetc(fp1);
			if (ch1 == '/')
			{
				while (ch1 != '\n')
					ch1 = fgetc(fp1);
			}
			if (ch1 == '*')
			{
				ch1 = fgetc(fp1);
				while (ch1 != '/')
				{
					ch1 = fgetc(fp1);
					/*if (ch1 == '/')
					{
						ch1 = fgetc(fp1);
						break;
					}*/
				}
			}
		}
		fputc(ch1, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}