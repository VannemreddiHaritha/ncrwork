#include<iostream>
using namespace std;
struct stack__
{
	int top;
	char *s;
	int size;
};
class stack {
	struct stack__ sta;
public:
	stack();
	void getsize(int);
	void push(int);
	int pop();
	int peek();
	bool IsEmpty();
	bool IsFull();
	void display();
	void eval(char*);
	~stack();
};
stack::stack()
{
	sta.top = -1;
	sta.size = 0;
	sta.s = NULL;
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

void stack::push(int ele)
{
	if (!IsFull())
		sta.s[++sta.top] = ele;
	else
		cout << "overflow";
}
int stack::pop()
{
	int x = -999;
	if (!IsEmpty())

		x = sta.s[sta.top--];

	else
		cout << "underflow";
	return x;
}
int  stack::peek()
{
	int x = -999;
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
void stack::eval(char *name)
{
	for (int i = 0;name[i] != '\0';i++)
	{
		char ch = name[i];

		if (isdigit(ch))
		{
			ch = ch - '0';
			push(ch);
		}
		else 
		{
			int op1=pop();
			int op2 = pop();
			int res;
			switch (ch)
			{
			case '*':res=op1*op2;break;
			case '-':res = op2-op1;break;
			case '+':res = op1+op2;break;
			case '/':res = op2/op1;break;
			}
			push(res);
		}

	}
	int x = pop();
	cout << x;
}
stack::~stack()
{
	delete sta.s;
}
int main()
{
	int choice, siz;
	cout << "siz";
	cin >> siz;
	
	stack s1;
	char nam[10];
	cout << "enter string";
	cin >> nam;
	s1.getsize(siz);
	s1.eval(nam);
	system("pause");
	return 0;
}