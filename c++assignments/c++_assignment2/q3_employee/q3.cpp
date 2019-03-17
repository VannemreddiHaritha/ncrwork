#include<iostream>
using namespace std;
class employee
{
	char name[30];
	int sal;
	int empno;
public:
	employee()
	{
		name[30] = 'NULL';
		sal = 0;
		empno = 0;

	}

	friend  ostream& operator<<(ostream& cout, employee e);
	friend  istream& operator>>(istream& cin, employee &e);

};
istream& operator>>(istream& cin, employee &e)
{
	cout << "Enter employee name" << endl;
	cin >> e.name;
	cout << "Enter employee salary" << endl;
	cin >> e.sal;
	cout << "Enter employee id" << endl;
	cin >> e.empno;
	return cin;
}
ostream& operator<<(ostream& cout, employee e)
{
	cout << "employee name" <<e.name << endl;
	cout << "employee salary"<<e.sal << endl;
	cout << "employee number"<<e.empno << endl;
	return cout;

}

int main()
{
	employee e1[5];
	int i;
	int n;
	cout << "enter number of employee" << endl;
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cout << "Enter details of employee" << i+ 1 << endl;
		cin >> e1[i];

	}
	for (i = 0;i < n;i++)
	{
		cout << endl ;
		cout << e1[i] << endl;
	}
	system("pause");
	return 0;
}
