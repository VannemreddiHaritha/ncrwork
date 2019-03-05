#include<iostream>
#include<string.h>
using namespace std;
struct stack__
{
	int top;
	char *s;
	int size;
};
class stack {
	char *exp;
	int len;
	struct stack__ sta;
public:
	stack();
	void getsize(int);
	void push(char);
	char pop();
	char peek();
	bool IsEmpty();
	bool IsFull();
	void display();
	~stack();
	void balanceEq(char *);
//	void string_s(char *);
};
stack::stack()
{
	sta.top = -1;
	sta.size = 0;
	strcpy(sta.s, "");
}
void stack::getsize(int n)
{
	sta.size = n;
	sta.s = new char[n];
}
bool stack::IsEmpty()
{
	return(sta.top == -1);
}
bool stack::IsFull()
{
	return(sta.top == (sta.size - 1));
}

void stack::push(char ele)
{
	if (!IsFull())
		sta.s[++sta.top] = ele;
	else
		cout << "overflow";
}
char stack::pop()
{
	char x = '\0';
	if (!IsEmpty())

		x = sta.s[sta.top--];

	else
		cout << "underflow";
	return x;
}
char stack::peek()
{
	char x = '\0';
	if (!IsEmpty())

		x = sta.s[sta.top];
	else
		cout << "underflow";
	return x;
}
void stack::display()
{
	for (int i = 0;i <= sta.top;i++)
		cout << sta.s[i];
}
/*void stack:: string_s( char *name)
{
	 len = strlen(name);
	exp = new char[len + 1];
	strcpy(exp, name);
}*/
void stack::balanceEq(char *name)
{
	int flag = 0;
	char ch,r;
	for (int i = 0;name[i]!='\0';i++)
	{
		 ch = name[i];
		switch(ch)
		{
			case '(':
			case '[':
			case '{':push(ch);
				     break;
			case ')':
			case ']':
			case '}':if (!IsEmpty())
			{
				if ((ch == ')'&&peek() == '(') || (ch == ']'&&peek() == '[') || (ch == '}'&&peek() == '{'))
				{
					r=pop();
					break;
				}
				else {
					flag = 1;
					break;
				}
			}
			 else
			{
				flag = 1;
				break;
			}
		}
		
	}
	if (flag == 1 || !IsEmpty())
	{
		cout << "unbalanced";
	}
	else
		cout<<("balanced");
}
stack::~stack()
{
	delete sta.s;
}
int main()
{
	int  siz;
	stack s1;

	cout << "enter size";
	cin >> siz;
	s1.getsize(siz);
	char name[30];
	cout << "enter string";
	cin >> name;
	s1.balanceEq(name);
	

	system("system pause");
	return 0;
}