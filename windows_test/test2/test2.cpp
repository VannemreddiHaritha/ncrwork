#include<iostream>
using namespace std;
#include<Windows.h>
int _cdecl main()
{
	LPWSTR *arglist;
	int nargs, i;
   arglist = CommandLineToArgvW(GetCommandLine(), &nargs);
   if (arglist == NULL)
	   cout << "command line argument failed" << endl;
   else
	   for (i = 0;i < nargs;i++)
		   wcout << " " << arglist[i] << endl;
   system("pause");
   return 0;
}