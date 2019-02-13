#include<stdio.h>
#include<stdio.h>
#include<string.h>
int main()
{
   char *arr[60];
   int n;

	printf("enter number of strings");

	scanf("%d", &n);

	char name[10];

	for (int i = 0; i < n; i++)

	{

		printf("\n enter %d string ", i);

		scanf("%s", name);

		//printf("%s", name);

		int len = strlen(name);

		arr[i] = (char *)malloc((len + 1) * sizeof(char*));



		if (arr[i] == NULL)

		{

			for (int j = i; j >= 0; j--)

			{

				free(arr[j]);

			}

			return -1;

		}

		strcpy(arr[i], name);

	}

	for (int x = 0; x < n - 1; x++)



	{

		for (int y = 0; y < n - x - 1; y++)

      	if( (strcmp(arr[y], arr[y + 1]) > 0))

			{

				char *temp1;

				temp1 = arr[y];

				arr[y] = arr[y + 1];

				arr[y + 1] = temp1;

			}

	}



	for (int k = 0; k < n; k++)

	{

		printf("the order is%s ", arr[k]);

	}

}