#include<iostream>
using namespace std;
class complex
{
	int real;
	int img;
public:
	complex()
	{
		real = 0;
		img = 0;
	}
	complex(int r, int i)
	{
		real = r;
		img = i;
	}

	complex operator+(complex c)
	{
		complex res;
		res.real = c.real + real;
		res.img = c.img + img;
		return res;
	}
	complex operator-(complex c)
	{
		complex res;
		res.real = c.real - real;
		res.img = c.img - img;
		return res;
	}
	complex operator-()
	{
		complex res;
		res.real = -real;
		res.img = -img;
		return res;
	}
	complex operator++()
	{
		complex res;
		res.real = ++real;
		res.img = ++img;
		return res;
	}
	complex operator++(int x)
	{
		complex res;
		res.real = real++;
		res.img = img++;
		return res;
	}
	complex operator=(complex c)
	{
		real = c.real;
		img = c.img;
		return (*this);
	}
	complex operator,(complex c)
	{

		return c;
	}
	complex  *operator->()
	{
		return this;
	}
	void print()
	{
		cout << "The fuction is excuted in arraw overloading";
	}

	friend istream& operator >> (istream &cin, complex &c);
	friend ostream& operator<<(ostream &cout, complex c);
};
istream& operator >> (istream &cin, complex &c)
{
	cin >> c.real;
	cin >> c.img;
	return cin;
}
ostream& operator<<(ostream &cout, complex c)
{
	cout << "real = " << c.real << endl;
	cout << "img= " << c.img << endl;
	return cout;
}
int main()
{
	complex c1, c2, c3, c4, c5, c6, c7, c8, c9(5, 6), c10(7, 8);
	int a = 10;
	cout << "enter the real and img values";
	cin >> c1;
	cout<<"the first obj values are ";
	cout << c1 << endl;
	cout << "enter the real and img values";
	cin >> c2;
	cout << "the second obj values are ";
	cout << c2 << endl;
	c3 = c1 + c2;
	cout << "sum = "<<c1 << endl;
	c4 = c1 - c2;
	cout << "sub = " << c4 << endl;
	c5 = ++c1;
	cout << "inc = " << c5 << endl;
	c6 = c1++;
	cout << "dec= " << c6 << endl;
	c7 = (c1, c2);
	cout << "comma= " << c7 << endl;
	c1->print();
	

	system("pause");
	return 0;


}