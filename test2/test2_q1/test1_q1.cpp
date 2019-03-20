
#include<string.h>
#include<iostream>
using namespace std;
class String
{
	char *string_name;
	int len;
public:
	//default constructor
	String()
	{
		string_name = NULL;
		len = 0;
	}
	// parameterized constructor....deep copying is done
	String(char *string1)
	{
		len = strlen(string1);
		string_name = new char[len];
		strcpy(string_name, string1);
	}
	//copy constructor where shallow coying is done
	String(const String &s)
	{
		len = s.len;
		string_name = new char[len+1];
		strcpy(string_name, s.string_name);
	}
	// overloading of two strings + operator with concatenation of two strings
	String operator+(String s)
	{
		String temp;
		temp.len = len + s.len;
		if (temp.string_name == NULL)
			temp.string_name = new char[temp.len+1];
		strcpy(temp.string_name, string_name);
		strcat(temp.string_name, s.string_name);
		return temp;
	}
	//operator overloading of equal to
	String operator=(String s)
	{
		if (string_name == NULL)
			string_name = new char[strlen(s.string_name)];
		strcpy(string_name, s.string_name);
		len = s.len;
		return (*this);
	}
	
	//destructor
	~String()
	{
		if (string_name != NULL)
			delete string_name;
	}
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, String);

};
istream& operator>>(istream& cin, String &s)
{
	char *s_1;
	s_1 = new char[strlen(s_1)];
	cout << "enter the string name" ;
	cin >> s_1;
	if (s.string_name == NULL)
		s.string_name = new char[strlen(s_1)];
	strcpy(s.string_name, s_1);
	s.len = strlen(s.string_name);
	return cin;
}
ostream& operator<<(ostream& cout, String s)
{
	cout << "String name is " << s.string_name << endl;
	return cout;
}

int main()
{
	String s1, s2, s3;
	cin >> s1 >> s2;
	cout << "equal to symbol overloading by making string2=string1............" << endl;
	s2 = s1;
	cout << "overloading index and the value of string2 = string1" << s2 << endl;
	s3 = s1 + s2;
	cout << "concatenating strings by overloading +operator............. " << endl;
	cout << s3;
	return 0;
}

