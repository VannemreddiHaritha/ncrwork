#include<iostream>
using namespace std;
//construction of node
struct node 
{
	int data;
	struct node *next;

};
class linked_list
{
	struct node *start;
public:
	linked_list();
	void insert_first(int);
	void insert_n(int,int );
	void delete_ele(int);
	void traverse_forward();
	void traverse_backward();
	void rev();
	~linked_list();
};
//constructor
linked_list::linked_list()
{
	start = NULL;
}
//inserting at begining
void linked_list::insert_first(int ele)
{
	struct node*temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}

//insertion at specific position
void linked_list::insert_n(int element, int specific_position)
{
	int pos = 1;
	struct node *curr, *temp;
	temp = new node;
	temp->data = element;
	if (start != NULL) 
	{
		curr = start;
		while (curr->next!= NULL && pos != specific_position-1)
		{
			curr = curr->next;
			pos++;
		}
		if (curr->next != NULL)
		{
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "position not found";
	}
	cout << "list is empty";
}
//delete at specific value
void linked_list::delete_ele(int ele)
{
	struct node *temp;
	if (start != NULL)
	{
		if (start->data == ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next != NULL && curr->next->data != ele)
			{
				curr = curr->next;
			}
			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "element not found";
		}
	}
	else
	  cout << "list empty";
}
//travel forward
void linked_list::traverse_forward()
{
	struct node*curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data<<endl;
		curr = curr->next;
	}

}
//travel backward
void print(struct node*curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << curr->data<<endl;
	}
}
void linked_list::traverse_backward()
{
	if (start != NULL)
		print(start);
}
//travel in reverse direction
void linked_list::rev()
{
	struct node *temp, *rev;
	rev = NULL;
	if (start != NULL || start->next != NULL)
	{
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			temp->next = rev;
			rev = temp;
		}
		start = rev;
	}
}
//destructor
linked_list::~linked_list()
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
	linked_list l1;
	int choice, n;
	cout << "enter n value";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout << "enter choice";
		cout << "1.insert element at first" << endl <<  "2.insert at nth position"  << endl << "3.delete at specific element" << endl << "4.travel forward" << endl << "5.travel backward" << endl << "6.rev";
		cin >> choice;
		switch (choice)
		{
		case 1:int ele;
			cout << "enter a value";
			cin >> ele;
			l1.insert_first(ele);
			break;
		case 2:int pos;
			cout << "enter position value";
			cin >> pos;
			int ele1;
			cout << "enter a value";
			cin >> ele1;
			l1.insert_n(ele1,pos);
			break;
	
		
		case 3:int k;
			cout << "enter a valuethe element to be deleted";
			cin >> k;
			l1.delete_ele(k);
			break;
		case 4:
			l1.traverse_forward();
			break;
		case 5:
			l1.traverse_backward();
			break;
		case 6:
			l1.rev();
			break;
		default:cout << "invalid ";
			break;
		}
	}
	system("pause");
	return 0;
}














