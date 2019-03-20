#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char*expansion(char*, char*);
int main()
{
	char *inputstring = NULL;
	char *outputstring = NULL;
	int NoOfBytes = 0, NoOfBytes2 = 0;
	printf("\nenter no of bytes");//for string1
	scanf_s("%d", &NoOfBytes);
	inputstring = (char*)malloc(NoOfBytes * sizeof(char));
	printf("\nenter input string");
	scanf_s("%s", inputstring, strlen(inputstring));
	printf("\nenter no of bytes of output string "); //for output string
	scanf_s("%d", &NoOfBytes2);

	outputstring = (char*)malloc(NoOfBytes2 * sizeof(char));
	outputstring = expansion(inputstring, outputstring);
	if (outputstring[0] != '\0')
	{
		printf("the output string is %s", outputstring);
	}
	system("pause");
	return 0;
}
char* expansion(char*inputstring, char*outputstring)
{
	int index1 = 0, index2 = 0, k = 0;
	for (index1 = 0; inputstring[index1] != '\0'; index1++)
	{
		if (inputstring[index1] == '-')
		{//for invalid expression
			if (inputstring[index1 + 1] == '-')
				printf("invalid expression....they are two  '-'s at a time");
			if (inputstring[index1 - 1] > inputstring[index1 + 1])
			{
				printf("\nInvalid expression");
				outputstring[0] = '\0';
				return outputstring;
			}
			else
			{

				for (k = inputstring[index1 - 1] + 1; k < inputstring[index1 + 1]; k++)
				{
					outputstring[index2] = k;//copying each element 
					index2++;
				}
			}
		}
		else
		{
			outputstring[index2] = inputstring[index1];
			index2++;
		}
	}
	outputstring[index2] = '\0';
	return outputstring;
}
