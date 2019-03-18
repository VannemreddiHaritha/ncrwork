#include<iostream>
using namespace std;
class A
{
	int private_num_a;
public: int public_num_a;
		A()
		{
			private_num_a = public_num_a = 0;
		}
		A(int i, int j)
		{
			private_num_a = i;
			public_num_a = j;
		}
		void print_A()
		{
			cout << "Private number in class a is " << private_num_a << endl << "Public number in class a is " << public_num_a << endl;
		}
};
class B : private A
{
	int private_num_b;
public: int public_num_b;
		B()
		{
			private_num_b = public_num_b = 0;
		}
		B(int i, int j)
		{
			private_num_b = i;
			public_num_b = j;
		}
		void print_B()
		{
			cout << "Private num in class b is " << private_num_b << endl << "Public num in class b is " << public_num_b << endl;
		}
};
int main()
{
	A a_object(2, 3);
	B b_object(4, 5);
	cout << endl;
	//cout << "Private number in class a through b_obj " << b_object.private_a << endl;
	//cout << "Private number of class b through b_obj " << b_object.private_b << endl;
	//cout << "Public number of class a through b_obj " << b_object.public_num_a << endl;
	cout << "Public number of class b through b_obj " << b_object.public_num_b << endl;
	cout << endl;
	//b_object.print_A();
	cout << endl;
	b_object.print_B();
	cout << endl;
	system("pause");
	return 0;
}