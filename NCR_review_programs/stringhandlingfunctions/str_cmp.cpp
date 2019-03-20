#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

//string camparision
int stringcamp(char*string1)
{
	char *string2 = NULL;
	int NoOfBytes1;
	printf("enter no of bytes for second string");
	scanf_s("%d", &NoOfBytes1);
	string2 = (char*)malloc(NoOfBytes1 * sizeof(char));
	printf("enter string2");
	scanf_s("%s", string2, NoOfBytes1);
	while (*string1 == *string2)
	{
		if (*string1 == '\0')//if the string is completed
			return 0;
		string1++;
		string2++;
	}
	//if strings are not equal
	if ((*string1) - (*string2) > 0)
		return 1;
	else
		return -1;
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
	cin >> string1;
	
			CamparisionVal = stringcamp(string1);
			if (CamparisionVal == 0)
				printf("both strings are equal");
			else if (CamparisionVal == 1)
				printf("both strings are not equal and output is positive ascii value");
			else if (CamparisionVal == -1)
				printf("both strings are not equal and output is negative ascii value");
		
	
		
	free(string1);
	system("pause");
	return 0;
}