#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char*expansion(char*, char*);
int main()
{
	char *inputstring ;
	char *outputstring = NULL;
    int NoOfBytes, NoOfBytes2;
	printf("enter no of bytes");
	scanf_s("%d", &NoOfBytes);
	inputstring = (char*)malloc(NoOfBytes * sizeof(char));
    printf("enter input string");
	scanf_s("%s", inputstring,strlen(inputstring));
	printf("enter no of bytes of output string ");
	scanf_s("%d", &NoOfBytes2);
	outputstring = (char*)malloc(NoOfBytes2*sizeof(char));
	outputstring = expansion(inputstring, outputstring);
	printf("the output string is %s", outputstring);
	getch();
	return 0;
}
char* expansion(char*inputstring, char*outputstring) 
{
	int index1, index2 = 0, k;
	for (index1 = 0;inputstring[index1] != '\0';index1++)
	{
		if (inputstring[index1] == '-')
		{
			for (k = inputstring[index1 - 1] + 1;k < inputstring[index1 + 1];k++)
			{
				outputstring[index2] = k;
				//printf("%c", k);
				index2++;
			}
		}
		else
		{
			outputstring[index2] = inputstring[index1];
			//printf("%c", inputstring[index1]);
			index2++;
		}
	}
	outputstring[index2] = '\0';
	return outputstring;
}