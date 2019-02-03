/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    char s[81];
    int i,l,space=0,digit=0,alpha=0,tab=0;
    scanf("%[^\n]s",s);
    for(l=0;s[l];l++);
    for(i=0;i<=l;i++)
    {
        if(s[i]==32)
           space=space+1;
       else if(s[i]>=48&&s[i]<=57)
            digit=digit+1;
       else if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))    
             alpha=alpha+1;
         else if(s[i]=='\t')     
            tab=tab+1;
    }
    printf("space=%ddigit=%dalpha=%dtab=%d",space,digit,alpha,tab);
    

    return 0;
}
