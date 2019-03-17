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
		real = i;
		img = i;
	}
	complex(float r, float i)
	{
		real = r;
		img = i;
	}
	void print_comp()
	{
		cout << real << "+i" << img << endl;

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
	int real1 = 0, img1 = 0, real2 = 0, img2 = 0;
	cout << "enter real1,img1.real2,img2";
	cin >> real1 >> img1 >> real2 >> img2;
	complex comp_obj1, comp_obj2(real1,img1), comp_obj3(real2, img2), comp_obj5, comp_obj6;
	cout << "addtion of two complex numbers is ";
   comp_obj5 = complex_add(comp_obj2, comp_obj3);
	comp_obj5.print_comp();
	cout << "multiplication of two complex numbers is ";
	comp_obj6 = complex_mul(comp_obj2, comp_obj3);
	comp_obj6.print_comp();
	system("pause");
	return 0;


}