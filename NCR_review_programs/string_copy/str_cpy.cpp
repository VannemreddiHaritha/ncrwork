#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int NoOfBytes;
	int choice;

	char *string1 = NULL;
	printf("enter number of bytes");
	scanf_s("%d", &NoOfBytes);
	printf("the original string is ");
	string1 = (char*)malloc(NoOfBytes * sizeof(char));//dynamic memory allocation for original string
	cin >> string1;
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