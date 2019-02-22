#include<iostream>
using namespace std;
struct node
{
	int coeff;
	int power;
	struct node *next;

};
class poly
{
	struct node *start;
public:
	poly()
	{
		start = NULL;
	}
	void insert_first(int,int);
	void travel_forward();
	void add(poly, poly);

};
void poly::insert_first(int ele1,int ele2)
{
	struct node *temp;
	temp = new node;
	temp->coeff= ele1;
	temp->power = ele2;
	temp->next = start;
	start= temp;
}
void poly::travel_forward()
{
	struct node*curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->coeff<<" ,"<<curr->power<<endl;
		curr = curr->next;
	}

}
void poly::add(poly p1, poly p2)
{
	struct node*curr1,* curr2;
	curr1 = p1.start;
	curr2 = p2.start;
   if (p1.start == NULL && p2.start == NULL)
		cout << "lists are empty ";
	while(curr1!=NULL && curr2!=NULL)
	{
		if (curr1->power == curr2->power)
		{
			insert_first((curr1->coeff) + (curr2->coeff), curr1->power);
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		else if (curr1->power > curr2->power)
		{
			insert_first(curr1->coeff, curr1->power);
			curr1 = curr1->next;
		}
		else if (curr1->power < curr2->power)
		{
			insert_first(curr2->coeff, curr2->power);
			curr2 = curr2->next;
		}

	}
	while (curr1 != NULL) {
		insert_first(curr1->coeff, curr1->power);
		curr1 = curr1->next;
	}
	while (curr2!= NULL) {
		insert_first(curr2->coeff, curr2->power);
		curr2 = curr2->next;
	}


}
int main()
{
	poly p1, p2, p3;
	int choice;
	
	
	while (1)
	{
		cout << "1)add elements poly1" << "2)add elements poly2" << "3)add both polynomials" <<"4)display "<<"5)exit "<< endl;
		cout << "enter choice";
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "enter the coeffient";
			int coeff1;
			cin >> coeff1;
			cout << "enter the power";
			int power1;
			cin >> power1;
			p1.insert_first(coeff1,power1);
			break;
		case 2:cout << "enter the coeffient2";
			int coeff2;
			cin >> coeff2;
			cout << "enter the power2";
			int power2;
			cin >> power2;
			p2.insert_first(coeff2, power2);
			break;
		case 3:p3.add(p1, p2);
			break;
		case 4:cout << "polynomial 1" << endl;
			p1.travel_forward();
			cout << "polynomial 2" << endl;
			p2.travel_forward();
			cout << "polynomial 3" << endl;
			p3.travel_forward();
			break;
		case 5:exit(0);
         }
	}
	system("pause");
	return 0;
}
