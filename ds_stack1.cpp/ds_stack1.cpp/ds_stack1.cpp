#include<iostream>
using namespace std;
struct stack__
{
	int top;
	int *s;
	int size;
};
class stack{
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
	sta.s = new int[n];
}
bool stack::IsEmpty()
{
	return(sta.top == -1);
}
bool stack::IsFull()
{
	return(sta.top == (sta.size-1));
}

void stack::push(int ele)
{
	if (!IsFull())
		sta.s[++sta.top] = ele;
	else
		cout <<"overflow";
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
int stack::peek()
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
stack::~stack()
{
	delete sta.s;
}
int main()
{
	int choice,siz;
	stack s1;
	int n,y;
	cout << "enter n value";
	cin >> n;
	cout << "enter size";
	cin >> siz;
	s1.getsize(siz);

	for (int i = 0;i < n;i++)
	{
		cout << "enter choice";
		cout << "1.add element" << "2.pop" << "3.peek" << "4.display";
		cin >> choice;
		switch (choice)
		{
		case 1:int a;
			cout << "enter a value";
			cin >> a;
			s1.push(a);
			break;
		case 2: y=s1.pop();
			cout << y;
			break;
		case 3: y=s1.peek();
			cout << y;
			break;
		case 4:s1.display();
			break;
		default:cout << "invalid ";
			break;
		}
	}
	system("system pause");
	return 0;
}

