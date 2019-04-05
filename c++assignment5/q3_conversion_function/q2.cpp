#include<iostream>
#include<stdlib.h>
using namespace std;
class pwr 
{
	double val;
	int exp;
	double base;
public:
	//default constructor
	pwr()
	{
		val = 1;
		base = 0;
		exp = 0;
	}
	//parameterized constructor
	pwr(int e, int b)
	{
		exp = e;
		base = b;
		
	}
	//to print the values
	void get_val()
	{
		int i;
		val = 1;
		for (i = 1;i <= exp;i++)
			val = base * val;
		cout << "the value is " << val<<endl;
	}
	//+ operator overloading
	pwr operator+(pwr p)
	{
		pwr temp;
		temp.val = val + p.val;
		return temp;
	}
	//conversion function to convert variables into double
	operator double()
	{
		cout << "the value for conversion function is" << endl;
		return val;
	}

};
int main()
{
	double exponential1=0, base1=0, exponential2=0, base2=0;
	cout << "enter exponential and base value" << endl;
	cin >> exponential1 >> base1;
	cout << "enter exponential and base value" << endl;
	cin >> exponential2 >> base2;
	pwr p_obj3,p_obj(exponential1, base1), p_obj1(exponential2, base2);
	p_obj1.get_val();
	p_obj.get_val();
	p_obj3 = p_obj1 + p_obj;
	//p_obj3.get_val();
	
	system("pause");
	return 0;
}
