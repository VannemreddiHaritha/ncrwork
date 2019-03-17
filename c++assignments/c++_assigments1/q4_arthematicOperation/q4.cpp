#include<iostream>
using namespace std;
inline void add(int a, int b)
{
	int c;
	c = a + b;
	cout <<"sum is " <<c << endl;
}
inline int sub(int a, int b)
{
	int c;
	c = a - b;
	cout <<"difference is "<< c << endl;
}
inline void division(int a, int b)
{
	float c;
	c = a / b;
	cout << "division is "<<c << endl;
}
inline void mul(int a, int b)
{
	long int c;
	c = a * b;
	cout <<"product is "<< c << endl;
}
inline void mod(int a, int b)
{
	int c;
	c = a % b;
	cout <<"remainder is "<< c << endl;
}
int main()
{
	int num1, num2;
	cout << "enter two numbers";
	cin >> num1 >> num2;
	add(num1,num2);
	mul(num1,num2);
	division(num1,num2);
	mod(num1,num2);
	system("pause");
	return 0;
}