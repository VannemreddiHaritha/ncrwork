#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
	struct node*prev;
};
class list_
{
	struct node *start;
public:
	list_();
	void insert_first(int);
	void insert_last(int);
	void insert_after(int, int);
	void insert_before(int, int);
	int delete_first();
	int delete_last();
	void delete_spec(int);
	void travel_forward();
	void travel_back();
	~list_();
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
	temp->prev=NULL;
	temp->next = start;
	if(start!=NULL)
	start->prev = temp;
	start = temp;
}
void list_::insert_last(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		temp->prev = curr;
		curr->next = temp;
	}
	else{
		temp->prev=NULL;
	start = temp;}
}
void list_::insert_after(int sel, int ele)
{
	if (start != NULL) {
		struct node*curr;
		curr = new node;
		curr = start;
		while (curr != NULL && curr->data != sel)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			temp->prev = curr;
			if (curr->next != NULL)
				curr->next->prev = temp;
			curr->next = temp;
		}
		else
			cout << "elemnt not found";
	}
	cout << "list is empty";
}
void list_::insert_before(int sel, int ele)
{
	if (start != NULL)
	{
			struct node *curr;
			curr = start;
			while (curr != NULL && curr->data != sel)
				curr = curr->next;
			if (curr != NULL) {
				struct node *temp;
				temp = new node;
				temp->data = ele;
				temp->next = curr;
				temp->prev = curr->prev;
				if (curr->prev != NULL)
					curr->prev->next = temp;
				else
					start = temp;
				curr->prev = temp;
			}
			else
				cout << "element not found";
		}
	cout << "list empty";
}
int list_::delete_first()
{
	int x = -999;
	struct node *temp;
	if (start != NULL)
	{
		temp = start;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else cout << "list empty";
	return x;
}

int list_::delete_last()
{
	int x = -999;
	if (start != NULL)
	{
		struct node*curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		x = curr->data;
		if (curr->prev != NULL)
			curr->prev->next = NULL;
		else
			start = NULL;
		delete curr;
	}
	cout << "list empty";
	return x;
}
void list_::delete_spec(int ele)
{
	struct node *temp;
	if (start != NULL)
	{
			struct node *curr;
			curr = start;
			while (curr != NULL && curr->data != ele)
				curr = curr->next;
			if(curr!=NULL)
			{
				if (curr->prev != NULL)
					curr->prev->next = curr->next;
				else
					start = curr->next;
				if (curr->next != NULL)
					curr->next->prev = curr->prev;
				delete curr;
			}
			else
		       cout << "element not found";
	}
	cout << "list empty";
}
void list_::travel_forward()
{
	struct node*curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}

}

void list_::travel_back()
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		while (curr != NULL)
		{
			cout << curr->data;
			curr = curr->prev;
		}
	}
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
	cout << "enter n value";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout << "enter choice";
		cout << "1.add element at first" << endl << "2.add element at end" << endl << "3.insert after" << endl << "4.insert before" << endl << "5.delete first" << endl << "6.delete last" << endl << "7.delete spec" << endl << "8.travel forward" << endl << "9.travel backward" << endl << "10.rev";
		cin >> choice;
		switch (choice)
		{
		case 1:int a;
			cout << "enter a value";
			cin >> a;
			l1.insert_first(a);
			break;
		case 2:int b;
			cout << "enter a value";
			cin >> b;
			l1.insert_last(b);
			break;
		case 3:int c, d;
			cout << "enter c valuethe element to be added";
			cin >> c;
			cout << "enter d value the element to be found";
			cin >> d;
			l1.insert_after(d, c);
			break;
		case 4:int e, f;
			cout << "enter a valuethe element to be added";
			cin >> e;
			cout << "enter n value the element to be found";
			cin >> f;
			l1.insert_before(f, e);
			break;
		case 5:int g;
			g = l1.delete_first();
			break;
		case 6:int h;
			h = l1.delete_last();
			break;
		case 7:int k;
			cout << "enter a valuethe element to be deleted";
			cin >> k;
			l1.delete_spec(k);
			break;
		case 8:
			l1.travel_forward();
			break;
		case 9:
			l1.travel_back();
			break;
		default:cout << "invalid ";
			break;
		}
	}
	system("pause");
	return 0;
}
