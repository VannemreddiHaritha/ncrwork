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
	cout << "Enter the name" << endl;
	cin >> s.name;
	cout << "enter rollno" << endl;
	cin >> s.roll;
	cout << "enter three subject marks" << endl;
	cin >> s.m1 >> s.m2 >> s.m3;
	return cin;
}
ostream& operator<<(ostream& cout, student s)
{
	cout <<"student name "<< s.name << endl;
	cout <<"roll no " <<s.roll << endl;
	cout << " the three subject marks are "<<s.m1 << endl << s.m2 << endl << s.m3 << endl;
	cout <<"total marks " <<s.marks << endl;
	cout << "grade is "<<s.grade << endl;
	return cout;

}
void get_result(student s[], int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		s[i].marks = s[i].m1 + s[i].m2 + s[i].m3;
		if (s[i].marks / 3 <= 40)
			s[i].grade = 'f';
		else if (s[i].marks / 3 > 40 && s[i].marks / 3 < 60)
			s[i].grade = 'b';
		else if (s[i].marks / 3 > 60)
			s[i].grade = 'a';
	}
}
int main()
{
	student s1[5];
	int i;
	int n;
	cout << "Enter the number";
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cout << "Enter details of Student" << i + 1 << endl;
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