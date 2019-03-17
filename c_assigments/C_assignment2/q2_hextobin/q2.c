#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[100] = "";
	char s[100];
	int i = 0;
	printf("enter hexa");
	scanf_s("%s", s);
	while (s[i] != '\0')
	{
		switch (s[i])
		{
		case('0'): {strcat_s(a, strlen(a), "0000");break;}
		case('1'): {strcat_s(a, strlen(a), "0001");break;}
		case('3'): {strcat_s(a, strlen(a), "0011");break;}
		case('4'): {strcat_s(a, strlen(a), "0100");break;}
		case('5'): {strcat_s(a, strlen(a), "0101");break; }
		case('6'): {strcat_s(a, strlen(a), "0110");break; }
		case('7'): {strcat_s(a, strlen(a), "0111");break;}
		case('8'): { strcat_s(a, strlen(a), "1000");break;}
		case('9'): { strcat_s(a, strlen(a), "1001");break;}
		case('a'): { strcat_s(a, strlen(a), "1010");break;}
		case('b'): { strcat_s(a, strlen(a), "1011");break; }
		case('c'): { strcat_s(a, strlen(a), "1100");break;}
		case('d'): { strcat_s(a, strlen(a), "1101");break;}
		case('e'): { strcat_s(a, strlen(a), "1110");break;}
		case('f'): {strcat_s(a, strlen(a), "1111");break; }
		}
		i++;
	}
	printf("%s", a);
	getch();
	return 0;
}