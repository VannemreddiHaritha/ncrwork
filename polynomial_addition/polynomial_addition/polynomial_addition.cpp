#include<iostream>
using namespace std;
struct node1
{
	int data1;
	int coeff1;
	struct node1 *next;

};
struct node2
{
	int data2;
	int coeff2;
	struct node2 *next;

};
struct node3
{
	int data3;
	int coeff3;
	struct node3 *next;

};
class poly 
{
	struct node1 *start1;
	struct node2 *start2;
	struct node3 *node;
	void insert_first1(int, int);
	void insert_first2(int, int);
	void travel_forward1();
	void travel_forward2();
	void travel_forward2();
	void travel_forward3();
};
void poly::insert_first1(int ele,int coeff)
{
	struct node1 *temp;
	temp = new node1;
	temp->data1 = ele;
	temp->coeff1 = coeff;
	temp->next = start1;
	start1 = temp;
}
void poly::insert_first2(int ele, int coeff)
{
	struct node2 *temp;
	temp = new node2;
	temp->data2 = ele;
	temp->coeff2= coeff;
	temp->next = start2;
	start2 = temp;
}
void poly::travel_forward1()
{
	struct node1*curr;
	curr = start1;
	while (curr != NULL)
	{
		cout << curr->data1<<" ";
		cout << curr->coeff1 << endl;
		curr = curr->next;
	}

}
void poly::travel_forward2()
{
	struct node2*curr;
	curr = start2;
	while (curr != NULL)
	{
		cout << curr->data2 << " ";
		cout << curr->coeff2<< endl;
		curr = curr->next;
	}

}
void poly::travel_forward3()
{
	struct node3*curr;
	curr = start3;
	while (curr != NULL)
	{
		cout << curr->data3 << " ";
		cout << curr->coeff3<< endl;
		curr = curr->next;
	}

}




