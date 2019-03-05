#include<stdio.h>
#include<stdlib.h>
int compliment();
int masking();
int shifting();

int main()
{
	int choice;
	scanf_s("%d", &choice);
	int a;
	scanf("%x", &a);
	do
	{
		printf("menu");
		printf("1.1s compliment");
		printf("2.masking");
		printf("3.shifting");
		printf("4.exit");
		switch (choice)
		{
		case 1:compliment(a);
			break;
		case 2:masking(a);
			break;
		case 3:shifting(a);
			break;
		case 4:break;
		default:printf("wrong choice");

		}
		
	} while (choice != 4)
		getch();
	return 0;
}



