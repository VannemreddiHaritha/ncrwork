#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;

};
class queue {
	struct node *start;
public:
	queue();
	void enque(int ele);
	int deque();
	void display();
	~queue();
};
queue::queue() {
	start = NULL;
}

void queue::enque(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = NULL;
		start = temp;
	}
}
int queue::deque()
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

void queue::display()
{
	struct node*curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}

}
queue::~queue()
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
	queue q1;
	int  y, choice;

	cout << "enter y val";
	cin >> y;
	int z;

	for (int i = 0; i < y; i++)
	{
		cout << "enter choice";
		cout << "1.add element" << "2.pop" << "3.display";
		cin >> choice;
		switch (choice)
		{
		case 1:int a;
			cout << "enter a value";
			cin >> a;
			cout << endl;
			q1.enque(a);
			break;
		case 2: z = q1.deque();
			cout << z;
			cout << endl;
			break;

		case 3:q1.display();
			cout << endl;
			break;
		default:cout << "invalid ";
			break;
		}
	}
	system("system pause");
	return 0;
}