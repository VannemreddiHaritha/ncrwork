#include<iostream>
using namespace std;
inline void add(int a, int b)
{
	int c;
	c = a + b;
	cout << c << endl;
}
inline int sub(int a, int b)
{
	int c;
	c = a - b;
	cout << c << endl;
}
inline void division(int a, int b)
{
       float c;
	c = a/b;
	cout << c << endl;
}
inline void mul(int a, int b)
{
	long int c;
	c = a - b;
	cout << c << endl;
}
inline void mod(int a, int b)
{
     int c;
	c = a %b;
	cout << c << endl;
}
int main()
{
	add(4, 5);
	mul(4, 5);
	division(10, 5);
     mod(10, 5);
	 system("pause");
	 return 0;
}