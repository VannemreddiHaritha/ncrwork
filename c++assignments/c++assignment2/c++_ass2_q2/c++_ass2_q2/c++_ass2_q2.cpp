#include<iostream>
using namespace std;
class student
{
	char name[30];
	int roll;
	int m1;
	int m2, m3, marks;
	char grade;
public:
	friend  ostream& operator<<(ostream& cout, student s);
	friend  istream& operator>>(istream& cin, student &s);
	friend void get_result(student[], int);
};
istream& operator>>(istream& cin, student &s)
{
	cin >> s.name;
	cin >> s.roll;
	cin >> s.m1 >> s.m2 >> s.m3;
	return cin;
}
ostream& operator<<(ostream& cout, student s)
{
	cout << s.name<<endl;
	cout << s.roll<<endl;
	cout << s.m1 << endl << s.m2 << endl <<s.m3 << endl;
	cout << s.marks<<endl;
	cout << s.grade << endl;
	return cout;

}
void get_result(student s[], int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		s[i].marks = s[i].m1 + s[i].m2 + s[i].m3;
		if (s[i].marks/3 <=40)
			s[i].grade = 'f';
		else if (s[i].marks/3 > 40&&s[i].marks/3<60)
			s[i].grade = 'b';
		else if (s[i].marks/3 >60 )
			s[i].grade = 'a';
	}
}
int main()
{
	student s1[5];
	int i;
	int n;
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cin >> s1[i];
	
	}
	get_result(s1, n);
	for (i = 0;i < n;i++)
	{
		cout << s1[i] << endl;
	}
	system("pause");
	return 0;
}