#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
class deque_
{
	struct node *start;
public:
	deque_();
	void insert_front(int);
	void insert_rear(int);
	int delete_front();
	int delete_rear();
	void travel_forward();
	~deque_();
};
deque_::deque_()
{
	start = NULL;
}
void deque_::insert_front(int ele)//this function represents  inserting a element at front
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->prev = NULL;
	temp->next = start;
	if (start != NULL)
	{
		start->prev = temp;
	}
	start = temp;
}
void deque_::insert_rear(int ele)
{
	struct node *temp,*curr;
	temp = new node;
	temp->data = ele;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		temp->prev = curr;
		curr->next = temp;
     }
	else
	{
		temp->prev = NULL;
		start = temp;
	}
	temp->next = NULL;
}
int deque_::delete_front()
{
	int x = -999;
	struct node *temp;

	if (start != NULL)
	{
		temp = start;
		start = temp->next;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		x = temp->data;
		delete temp;
	}
	else
		cout << "list is empty";
	return x;

}
int deque_ ::delete_rear()
{
	int x = -999;
	struct node *curr;
	if (start != NULL)
	{
		curr = start;
		while (curr->next!= NULL)
			curr = curr->next;
		x = curr->data;
		if (curr->prev != NULL)
			curr->prev->next = NULL;
		else
		     start = NULL;
		
		delete curr;
		return x;
		
	}
}
void deque_::travel_forward()
{
	struct node*curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}

}
deque_::~deque_()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}
class stack:private deque_
{
public:
	  void push(int);
	  int pop();
	  void travese_front();

};
void stack::push(int ele)
{
	insert_front(ele);
}
int stack::pop()
{
	int x;
	x = delete_front();
	return x;
}
void stack::travese_front()
{
	travel_forward();
}

class queue:private deque_
{
public:void enque(int);
	   int deque();
	   void travese_queue();
};
void queue::enque(int ele)
{
	
	insert_rear(ele);
}
int queue::deque()
{
	int x;
	x = delete_front();
	return x;
}
void queue::travese_queue()
{
	travel_forward();
}
int main()
{
	int choice;
	queue q_obj;
	stack s_obj;
	deque_ d1;
	while (1)
	{
		cout << "enter choice" << endl;
		cout << "1.stack" << "2.queue" << "3.double ennded queue" << endl;
		cin >> choice;
		switch (choice)
		{

		case 1:
		{

			int choice_stack;
			while (1)
			{
				cout << "enter choice for stack" << endl;
				cout << "1.push" << "2.pop" << "3.display" << "4.exit" << endl;
				cin >> choice_stack;
				switch (choice_stack)
				{
				case 1:int element;
					cout << "enter element to be pushed";
					cin >> element;
					s_obj.push(element);
					break;
				case 2:int pop_ele;
					pop_ele = s_obj.pop();
					cout << pop_ele;
					break;
				case 3:s_obj.travese_front();
					break;
				case 4:exit(0);
					break;
				default:cout << "invalid option for stack";
				}
			}
			break;
		}


		case 2:
		{

			int choice_queue;
			while (1)
			{
				cout << "enter choice for queue" << endl;
				cout << "1.enque" << "2.deque" << "3.display" << "4.exit" << endl;
				cin >> choice_queue;
				switch (choice_queue)
				{
				case 1:int element;
					cout << "enter element to be enqued";
					cin >> element;
					q_obj.enque(element);
					break;
				case 2:int deque_ele;
					deque_ele = q_obj.deque();
					cout << deque_ele;
					break;
				case 3:q_obj.travese_queue();
					break;
				case 4:exit(0);
					break;
				default:cout << "invalid option for queue";
				}

			}
			break;
		}
		case 3:
		{

			int i;

			while (1)
			{
				cout << "1.insert_front" << "2.insert_rear" << "3.delete_front" << "4.delete_rear" << "5.travel forward";
				cout << "enter choice";
				cin >> i;
				switch (i)
				{
				case 1:int ele;
					cout << "enter element ";
					cin >> ele;
					d1.insert_front(ele);
					break;
				case 2:int ele1;
					cout << "enter element";
					cin >> ele1;
					d1.insert_rear(ele1);
					break;
				case 3:int x1;
					x1 = d1.delete_front();
					cout << x1;
					break;
				case 4:int x2;
					x2 = d1.delete_rear();
					cout << x2;
					break;
				case 5:d1.travel_forward();
					break;
				case 6:exit(0);
					break;
				}

			}
			break;
		}
		    case 4:exit(0);
			   break;
		    default:cout << "invalid option";
		
		}
		
    }
}
