#include <iostream>
#include "C:\Users\haritha\source\repos\ncrwork\windows_test\test23_staticlibrary\mathfun.h"
using namespace std;

int main()
{
	int a = 100;
	int b = 99;

	cout << "a + b = " << MathFuncs::MyMathFuncs::Add(a, b) << endl;
	cout << "a - b = " <<MathFuncs::MyMathFuncs::Sub(a, b) << endl;
	return 0;
}