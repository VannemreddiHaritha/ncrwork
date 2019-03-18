#include<iostream>
using namespace std;
class A
{
	int private_num_a;
protected:int protected_num_a;
public: int public_num_a;
		A()
		{
			private_num_a = public_num_a=protected_num_a = 0;
		}
		A(int i, int j,int k)
		{
			private_num_a = i;
			public_num_a = j;
			protected_num_a = k;
		}
		void print_A()
		{
			cout << "Private number in class a is " << private_num_a << endl << "Public number in class a is " << public_num_a << endl<<"Protected number in class a is " << protected_num_a << endl;
		}
};
class B : protected A
{
	int private_num_b;
protected:int protected_num_b;
public: int public_num_b;
		B()
		{
			private_num_b = public_num_b = protected_num_b=0;
		}
		B(int i, int j,int k):A(9,10,11)
		{
		
			private_num_b = i;
			public_num_b = j;
			protected_num_b = k;
		}
		void print_B()
		{
			cout << "Private num in class b is " << private_num_b << endl << "Public num in class b is " << public_num_b << endl << "Protected num in class b is " << protected_num_b << endl;
			cout << "protected num in class a in function is " << protected_num_a << endl;
			//cout << "private num in class a in function is " << private_num_a << endl;

		}
};
int main()
{
	A a_object(2, 3,6);
	B b_object(4, 5,7);
	cout << endl;
	//cout << "Private number in class a through b_obj " << b_object.private_a << endl;
	//cout << "Private number of class b through b_obj " << b_object.private_b << endl;
	//cout << "Public number of class a through b_obj " << b_object.public_num_a << endl;
	//cout << "Protected number of class a through b_obj " << b_object.protected_num_a << endl;
	//cout << "Protected number of class b through b_obj " << b_object.protected_num_b << endl;
	cout << "Public number of class b through b_obj " << b_object.public_num_b << endl;
	cout << endl;
	//b_object.print_A();
	cout << endl;
	b_object.print_B();
	cout << endl;
	system("pause");
	return 0;
}