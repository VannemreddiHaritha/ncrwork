#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;

};
class stack {
	struct node *start;
public:
	stack();
	void push(int);
	int pop();
	int peek();
	void display();
	~stack();
};
stack::stack()
{
	

}


void stack::push(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
int stack::pop()
{
	int x = -999;
	struct node *temp;
	if (start != NULL)
	{
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else cout << "list empty";
	return x;
}
int stack::peek()
{
	int x = -999;
	if (start!=NULL)
       x = start->data;
	else
		cout << "underflow";
	return x;
}
void stack::display()
{
	struct node*curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}
stack::~stack()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}
int main()
{
	int choice, siz;
	stack s1;
	int n, y;
	cout << "enter n value";
	cin >> n;
	

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
		case 2: y = s1.pop();
			cout << y;
			break;
		case 3: y = s1.peek();
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

