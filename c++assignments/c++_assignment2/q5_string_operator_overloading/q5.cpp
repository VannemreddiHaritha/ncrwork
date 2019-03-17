#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class String
{
char *string;
int len;
public:
	//default constructor
   String()
     {
      string = NULL;
      len = 0;
     }
   //one parameterized constructor....deep copying is done
    String(char *string1)
    {
       len = strlen(string1);
       string = new char[len];
       strcpy(string, string1);
    }
	//two parameterized constructor
    String(char *string1, int length1)
    {
      len = length1;
	  string = new char[len];
      strcpy(string, string1);
    }
	//copy constructor....shallow coying is done
    String(const String &str_copy)
    {
      len = str_copy.len;
      string = new char[len];
      strcpy(string, str_copy.string);
     }
	//+ overloading i.e concatenation of two strings
	String operator+(String s2)
    {
      String str_obj;
      str_obj.len = len + s2.len;
      if (str_obj.string == NULL)
               str_obj.string = new char[str_obj.len];
      strcpy(str_obj.string, string);
      strcat(str_obj.string, s2.string);
      return str_obj;
     }
	//= operator overloading
    String operator=(String s2)
     {
      if (string == NULL)
             string = new char[strlen(s2.string)];
      strcpy(string, s2.string);
     len = s2.len;
     return *(this);
	}
    char& operator[](int i)
	{
    return string[i];
     }
	//destructor
    ~String()
    {
        if (string != NULL)
               delete string;
	}
   friend istream& operator>>(istream&, String&);
   friend ostream& operator<<(ostream&, String);

};
istream& operator>>(istream& cin, String &s)
{
char str[50];
cout << "enter string" << endl;
cin >> str;
if (s.string == NULL)
       s.string = new char[strlen(str) + 1];
 strcpy(s.string, str);
s.len = strlen(s.string);
return cin;
}
ostream& operator<<(ostream& cout, String c)
{
cout << "String = " << c.string << endl;
return cout;
}
int main()
{
	String s1, s2, s3;
	cin >> s1 >> s2;
	s3 = s1 + s2;
	cout << "concatenation of strings is done using +operator " << endl;
	cout << s3;
	cout << "equal to symbol overloading by making string2[3]=string1[2]" << endl;
    s2[3] = s1[2];
    cout << "the value of string2[3] = " << s2[3] << endl << "the value of string1[2] = " << s1[2] << endl;
    cout << "the value of string1[3] = " << s1[3] << endl;
	return 0;

}