#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int NoOfBytes;

	char *string1 = NULL;
	printf("enter number of bytes");
	scanf_s("%d", &NoOfBytes);
	printf("the original string is ");
	string1 = (char*)malloc(NoOfBytes * sizeof(char));//dynamic memory allocation for original string
	cin >> string1;
	char *string2;
	int NoOfBytes1, length1, i, j = 0, length2;
	printf("enter no of bytes for second string");
	scanf_s("%d", &NoOfBytes1);
	string2 = (char*)malloc(NoOfBytes1 * sizeof(char));//dynamic memory allocation of second string
	printf("enter string2");
	cin >> string2;
	length1 = strlen(string1);
	length2 = strlen(string2);
	realloc(string1,sizeof(char)*(length1 + length2 + 1));
	for (i = length1;i < (length1 + length2+1);i++)
	{
		*(string1 + i) = *(string2 + j);
		j++;
	}
	*(string1 + i) = '\0';
	printf("the string cancatenation string is %s", string1);
	free(string2);
	system("pause");
}