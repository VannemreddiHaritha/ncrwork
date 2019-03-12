#include<stdio.h>
#include<string.h>

void stringreverse(char *string1)
{
	int length, i, j = 0;
	char *string2 = NULL;
	length = strlen(string1);
	string2 = (char*)malloc(length * sizeof(char));

	for (i = length - 1;i >= 0;i--)
	{
		*(string2 + j) = *(string1 + i);
		j++;
	}
	*(string2 + j) = '\0';
	printf("the reversed string is %s", string2);
	free(string2);
}
//string copy
void stringcopy(char*string1)
{
	char *string2 = NULL;
	int length1, i;
	length1 = strlen(string1);
	string2 = (char*)malloc(length1 * sizeof(char));
	for (i = 0;i < length1;i++)
	{
		*(string2 + i) = *(string1 + i);

	}
	*(string2 + i) = '\0';
	printf("the copied string is %s", string2);
	free(string2);

}
//string camparision
int stringcamp(char*string1)
{
	char *string2 = NULL;
	int NoOfBytes1;
	printf("enter no of bytes for second string");
	scanf_s("%d", &NoOfBytes1);
	string2 = (char*)malloc(NoOfBytes1*sizeof(char));
	printf("enter string2");
	scanf_s("%s", string2, strlen(string2));
   while (*string1 == *string2)
	{
		if (*string1 == '\0')
			return 0;
		string1++;
		string2++;
	}
	if ((*string1) - (*string2) > 0)
		return 1;
	else
		return -1;
	free(string2);
}
void stringcat(char *string1)
{
	char *string2 = NULL;
	int NoOfBytes1, length1, i, j = 0, length2;
	printf("enter no of bytes for second string");
	scanf_s("%d", &NoOfBytes1);
	string2 = (char*)malloc(NoOfBytes1 * sizeof(char));
	printf("enter string2");
	scanf_s("%s", string2, strlen(string2));
	length1 = strlen(string1);
	length2 = strlen(string2);
	string1 = realloc(string1, length2);
	for (i = length1;i < length1 + length2;i++)
	{
		*(string1 + i) = *(string2 + j);
		j++;
	}
	*(string1 + i) = '\0';
	printf("the string cancatenation string is %s", string1);
	free(string2);

}
int main()
{
	int NoOfBytes;
	int choice, CamparisionVal;

	char *string1 = NULL;
	printf("enter number of bytes");
	scanf_s("%d", &NoOfBytes);
	printf("the original string is ");
	string1 = (char*)malloc(NoOfBytes * sizeof(char));//dynamic memory allocation for original string
	scanf_s("%s", string1, strlen(string1));
	while(1)
	{
		printf("\n1.string reverse\n2.stringcopy\n3.string camparision\n4.string cancatenation\n5.exit\n");
		printf("enter choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: {
			stringreverse(string1);
			break;
		}
		case 2:
		{
			stringcopy(string1);
			break;
		}
		case 3: 
		{
			CamparisionVal = stringcamp(string1);
			if (CamparisionVal == 0)
				printf("both strings are equal");
			else if (CamparisionVal == 1)
				printf("both strings are not equal and output is positive ascii value");
			else if (CamparisionVal == -1)
				printf("both strings are not equal and output is negative ascii value");
			break;
		}
		case 4:
		{
			stringcat(string1);
			break;
		}
		case 5:exit(0);
		default:
			printf("entered wrong choice");
		}
	} while (choice != 5);
	free(string1);
	getch();
	return 0;
}