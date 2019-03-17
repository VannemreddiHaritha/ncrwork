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
	cin >> e.name;
	cin >> e.sal;
	cin >> e.empno;
	return cin;
}
ostream& operator<<(ostream& cout, employee e)
{
	cout << e.name << endl;
	cout << e.sal << endl;
	cout << e.empno << endl;
	return cout;

}

int main()
{
	employee e1[5];
	int i;
	int n;
	cout << "enter n value";
	cin >> n;
	for (i = 0;i < n;i++)
	{

		cin >> e1[i];

	}

	for (i = 0;i < n;i++)
	{
		cout << e1[i] << endl;
	}
	system("pause");
	return 0;
}