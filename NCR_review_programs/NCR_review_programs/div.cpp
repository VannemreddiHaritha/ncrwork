#include<iostream>
using namespace std;
int divi(int a, int b)throw(int)
{
	
		if (b == 0)
			throw 90;
		else 
			return a / b;
    

	
}