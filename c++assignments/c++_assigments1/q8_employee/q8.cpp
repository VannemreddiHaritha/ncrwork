#include<iostream>
#include<string.h>
using namespace std;

class employee
{
	char name[30];
	int salary;
public:
	employee()
	{
		strcpy(name, "\0");
		salary = 0;
		cout << "default constructor " << endl;
	}
	employee(int s)
	{
		salary = s;
		cout << "parameterized constructor" << endl;

	}
	employee(char *n, int s)
	{
		salary = s;
		strcpy_s(name, 5, n);
		cout << "parameterized constructor with two arguments" << endl;
	}
	employee(employee &e)
	{
		salary = e.salary;
		strcpy(name, e.name);
		cout << "copy contrustor";
	}
	~employee()
	{
		cout << "destryctor" << endl;
	}
};

int main()
{

	employee e1, e2(1000), e3("hari", 1000), e4(e3);
	int i, j;
	i = sizeof(e3);
	j = sizeof(e4);
	cout << "value of i" << i << endl << "value of j" << j;
	system("pause");
	return 0;

}