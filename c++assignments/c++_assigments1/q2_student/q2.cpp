#include<iostream>
using namespace std;
class student
{
public:
	char *name;
	char grade;
	int mark1, mark2, mark3;
};
class college {
public:
	student s1;
	float avg;

	void set_data(char *s, char g, int m1, int m2, int m3)
	{
		int len = strlen(s);
		s1.name = (char*)malloc(sizeof(char)*(len));
		strcpy(s1.name, s);
		s1.grade = g;
		s1.mark1 = m1;
		s1.mark2 = m2;
		s1.mark3 = m3;
		cout << s1.name << endl;
	}
	void computemarks()
	{
		avg = s1.mark1 + s1.mark2 + s1.mark3;
		cout << "total marks" << avg << endl;
	}
	void  grade()
	{
		if (avg >= 60)
			cout << "first class";
		else if (avg < 60 && avg >= 50)
			cout << "second class";
		else if (avg < 50 && avg >= 40)
			cout << "third class";
	}

};
int main()
{
	college c1, c2;
	c1.set_data("hari", 'A', 60, 60, 54);
	c1.computemarks();
	c1.grade();
}
