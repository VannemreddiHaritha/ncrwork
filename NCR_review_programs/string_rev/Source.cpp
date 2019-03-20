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