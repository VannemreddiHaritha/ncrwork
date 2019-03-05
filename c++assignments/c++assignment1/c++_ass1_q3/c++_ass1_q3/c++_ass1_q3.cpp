#include<iostream>
using namespace std;
class complex
{
	float real;
	float img;
public:
	complex()
	{
		real = 0;
		img = 0;
	}
	complex(float i)
	{
		real =i;
		img = i;
	}
	complex(float r, float i)
	{
		real = r;
		img = i;
	}
	void print_comp()
	{
		cout << real<<"+i"<<img<<endl;
		
	}
	friend complex complex_add(complex, complex);
	friend complex complex_mul(complex, complex);
};
complex complex_add(complex c1, complex c2)
{
	complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	return temp;
}
complex complex_mul(complex c1, complex c2)
{
	complex temp;
	temp.real = c1.real*c2.real - c1.img*c2.img;
	temp.img = c1.real*c2.img + c1.img*c1.real;
	return temp;
}
int main()
{
	complex c1, c2(5), c3(3, 5),c5,c6;
	c5 = complex_add(c2, c3);
	c5.print_comp();
	c6 = complex_mul(c2, c3);
	c6.print_comp();
	system("pause");
	return 0;
	

}