#include<stdio.h>   //header file
#include<ctype.h>
#include<stdlib.h>
#include"count.h"
#include"replace.h"
#include"comments.h"

int main()
{
	count1();//counting the number of characters,digits,spaces
	replace();//replacing tabs with \t
	comment();//removing content in commments
	getch();
	return 0;
};