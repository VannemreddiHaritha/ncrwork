#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;

};
class link
{
	struct node *start;
public:
	link()
	{
		start = NULL;
	}
	void insert_first(int);
	void travel_forward();
	void merge(link, link);

};//give the elements in decending order
void link::insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void link::travel_forward()
{
	struct node*curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data  << endl;
		curr = curr->next;
	}

}
void link::merge(link l1,link l2)
{
	struct node*curr1, *curr2;
	curr1 = l1.start;
	curr2 = l2.start;
	if (l1.start == NULL && l2.start == NULL)
		cout << "lists are empty ";
	while (curr1 != NULL && curr2 != NULL)//
	{
		
	  if(curr1->data > curr2->data)
		{
			insert_first(curr2->data);
			curr2 = curr2->next;
		}
		else if(curr1->data <= curr2->data)
		{
			insert_first(curr1->data);
			curr1 = curr1->next;
		}

	}
	while (curr1 != NULL) {
		insert_first(curr1->data);
		curr1 = curr1->next;
	}
	while (curr2 != NULL) {
		insert_first(curr2->data);
		curr2 = curr2->next;
	}


}
int main()
{
	link l1,l2,l3;
	int choice;


	while (1)
	{
		cout << "1)add elements poly1" << "2)add elements poly2" << "3)add both polynomials" << "4)display " << "5)exit " << endl;
		cout << "enter choice";
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "enter the data1";
			int data;
			cin >> data;
			
			l1.insert_first(data);
			break;
		case 2:cout << "enter data2";
			int data2;
			cin >> data2;
			
			l2.insert_first(data2);
			break;
		case 3:l3.merge(l1, l2);
			break;
		case 4:cout << "list 1" << endl;
			l1.travel_forward();
			cout << "list 2" << endl;
			l2.travel_forward();
			cout << "list 3" << endl;
			l3.travel_forward();
			break;
		case 5:exit(0);
		}
	}
	system("pause");
	return 0;
}
