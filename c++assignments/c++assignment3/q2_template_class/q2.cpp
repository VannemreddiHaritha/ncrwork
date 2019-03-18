#include<stdio.h>
#include<iostream>
using namespace std;
#define SIZE 100
template<class T>
class Stack
{
   int top;
   T sta[SIZE];
public:
   Stack()
   {
     top = -1;
   }
   void push(T ele)
   {
     if (top == (SIZE - 1))
      {
        cout << "stack is Overflow"<<endl;
      }
	 else
       sta[++top] = ele;
   }
T pop()
{
	if (top == -1)
	{
	cout << "stack is Underflow"<<endl;
	return -1;
	}
	else
	 return sta[top--];
	}
T peek()
{
   if (top == -1)
   {
      cout << "stack is Underflow"<<endl;
      return -1;
   }
   else
     return sta[top];
}
void display()
{
int i;
for (i = 0; i <= top; i++)
   cout << sta[i] << " ";
   cout << endl;
}
};

int main()
{
   Stack<int> s;
  cout << "Integer stack "<<endl;
  int choice;
  while (1) 
  {
	  cout << "1.push" << endl << "2.pop" << endl << "3.peek" << endl << "4.display"<<endl;
	  cout << "enter choice"<<endl;
	  cin >> choice;
	  switch (choice)
	  {

	  case 1:int element;
		  cout << "enter the element into stack"<<endl;
		  cin >> element;
		  s.push(element);
		  break;
	  case 2: cout << s.pop() << endl;
			  break;
	  case 3:cout << s.peek() << endl;
			 break;
	  case 4:s.display();
			 break;
	  case 5:exit(0);
	  }
  }
cout << "Character stack"<<endl;

	Stack<char> s1;
	int choice3;
	while (1)
	{
		cout << "1.push" << endl << "2.pop" << endl << "3.peek" << endl << "4.display" << endl << "5.exit" << endl;
		cout << "enter choice"<<endl;
		cin >> choice3;
		switch (choice3)
		{
		case 1:char element;
			cout << "enter the character into stack";
			cin >> element;
			s1.push(element);
			break;
		case 2:s1.pop();
			break;
		case 3:s1.peek();
			break;
		case 4:
			s1.display();
			break;
		case 5:exit(0);
		}
	}
	cout << "float stack"<<endl;

	Stack<float> s2;
	int choice2;
	cout << "enter choice";
	cin >> choice2;
	switch (choice2)
	{
		cout << "1.push" << endl << "2.pop" << endl << "3.peek" << endl << "4.display";
	case 1:float element;
		cout << "enter the float element into stack";
		cin >> element;
		s2.push(element);
		break;
	case 2:s2.pop();
		break;
	case 3:s2.peek();
		break;
	case 4:
		s2.display();
		break;
	case 5:
		exit(0);
	}
return 0;

}