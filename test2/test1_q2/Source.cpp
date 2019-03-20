#include<string.h>
#include<iostream>
using namespace std;
class String
{
	
	int len;
public:
	char *string_name;
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
		string_name = new char[len];
		strcpy(string_name, s.string_name);
	}
	
	String operator=(String s)
	{
		if (string_name == NULL)
			string_name = new char[strlen(s.string_name)];
		strcpy(string_name, s.string_name);
		len = s.len;
		return (*this);
	}
	//overloading index
	char& operator[](int i)
	{
		return string_name[i];
	}
	//destructor
	~String()
	{
		if (string_name != NULL)
			delete string_name;
	}
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, String);
	friend void bubble();

};
istream& operator>>(istream& cin, String &s)
{
	char *s_1;
	s_1 = new char[strlen(s_1)];
	cout << "enter the string name";
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

void bubble(String s1[])
{
   
	

	int i,j;
	for (i = 0;i < 5;i++)
	{
		
		for (j = i+1;j < 5 - i - 1;j++)
		{
			if (strcmp(s1[i].string_name, s1[j].string_name) > 0)
			{
				char*temp;
				temp = new char[strlen(temp) + 1];
				strcpy(temp, s1[j].string_name);
				strcpy( s1[j].string_name, s1[i].string_name);
				strcpy(s1[j].string_name,temp);
			}
		}
		cout << "the sorted array is " << s1[i];
	}
}
int main()
{
	String s1[5];
	int i;
	char *name;
	for (i = 0;i < 5;i++) {
		int len;
		cout << "enter length";
		cin >> len;
		cout << "enter name";
        name = new char[len+1];
		cin >> name;
		strcpy(s1[i].string_name, name);
	}
bubble(s1);
}


	