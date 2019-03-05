#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;

};
class list_
{
	struct node *start;
public:
	list_();
	void insert_first(int);
	void travel_forward();
	~list_();
	void self(int);
};
list_::list_()
{
	start = NULL;
}
void list_::insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void list_::travel_forward()
{
	struct node*curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data<<"->";
		curr = curr->next;
	}
	cout << "NULL\n";

}
void list_::self(int e)
{
	struct node *temp, *curr;

	if (start != NULL)

	{

		if (start->data != e)

		{

			curr = start;

			while (curr->next != NULL && curr->next->data != e)

				curr = curr->next;

			if (curr->next != NULL)

			{

				temp = curr->next;

				curr->next = temp->next;

				delete temp;

				insert_first(e);

			}

			else

				cout << "Element is not found";

		}

	}

	else

		cout << "List is empty";

}
	

list_::~list_()
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
	list_ l1;
	int choice, n;
	while(1)
	{
		cout << "enter choice";
		cout << "1) add element at first " << "3) self adusting " << "2) forward travel" << "4) exit";
		cin >> choice;
		switch (choice)
		{
		case 1:int a;
			cout << "enter a value";
			cin >> a;
			l1.insert_first(a);
			break;
		case 2:l1.travel_forward();
			break;
		case 3: {int n;
			cout << "enter a value";
			cin >> n;
			l1.self(n);
			break;
		}
		case 4: exit(0);
		}
	}
	system("pause");
	return 0;

}