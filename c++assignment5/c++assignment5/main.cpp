#include<iostream>
#include"q1_add_sub.cpp"//including file name as a header file
#include"q1_absolute_add_sub.cpp"
using namespace std;
using namespace add_sub;
using namespace absolute_add_sub;
int main()
{
	absolute_add_sub::c_absolute_add_sub abs_add_sub_obj;
	add_sub::c_add_sub add_sub;
	double x, y, z,w;
	double num1, num2;
	int choice;
	while (1) {
		cout << "1.absolute add" << endl << "2.absolute sub" << endl << "3.add" << endl << "4.sub"<<endl;
		cout << "enter choice" << endl;
		cin >> choice;
		cout << "enter the numbers";
		cin >> num1 >> num2;
		switch (choice)
		{
		case 1:x=abs_add_sub_obj.add(num1,num2);
			cout << "absoulte addition is " << x << endl;
			break;
		case 2:y=abs_add_sub_obj.sub(num1,num2);
			cout << "absoulte subtraction  is " << y << endl;
			break;
		case 3:z=add_sub.add(num1,num2);
			cout << "addition is " << z << endl;
			break;
		case 4:w=add_sub.sub(num1,num2);
			cout << "subtraction  is " << w<< endl;
			break;
		case 5:exit(0);
			break;
		default:cout << "invalid option";
		}
	}
}
