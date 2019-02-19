#include<iostream>
using namespace std;
struct queue_ {
	int rear;
	int front;
	int size;
	int *q;
};
class queue {
	struct queue_ que;
public:
	queue();
	void getsize(int n);
	void enque(int ele);
	int deque();
	int peek();
	bool Underflow();
	bool overflow();
	void display();
	~queue();
};
queue::queue() {
	que.rear = -1;
	que.front = -1;
	que.size = 0;
}
void queue::getsize(int n)
{
	que.size = n;
	que.q = new int[n];
}
bool queue::Underflow()
{
	return(que.rear == -1 && que.front == -1);
}
bool queue::overflow()
{
	return(que.rear == (que.size - 1));
}
void queue::enque(int ele)
{
	if (!overflow())
	{
		if (que.rear == -1 && que.front == -1)
		{
			que.front = 0;
		}
		que.q[++que.rear] = ele;

	}
	else
		cout << "overflow";
}
int queue::deque()
{
	if (!Underflow())
	{
		if (que.rear == que.front) {
			que.rear = -1;
			que.front = -1;
		}
		int x = que.q[que.front--];
		return x;
	}
	else
		cout << "underflow";
}
int queue::peek()
{
	if (!Underflow())
	{
		if (que.rear == que.front) {
			que.rear = -1;
			que.front = -1;
		}
		int x = que.q[que.front];
		return x;
	}
	else
		cout << "underflow";
}
void queue::display()
{
	for (int i = que.front;i <= que.rear;i++)
		cout << que.q[i];
}
queue::~queue()
{
	delete que.q;
}
int main()
{
	queue q1;
	int n, y, choice;
	cout << "enter n val";
	cin >> n;
	cout << "enter y val";
	cin >> y;
	int z;
	q1.getsize(n);
	for (int i = 0;i < y;i++)
	{
		cout << "enter choice";
		cout << "1.add element" << "2.pop" << "3.peek" << "4.display";
		cin >> choice;
		switch (choice)
		{
		case 1:int a;
			cout << "enter a value";
			cin >> a;
			q1.enque(a);
			break;
		case 2: z = q1.deque();
			cout << z;
			break;
		case 3: z = q1.peek();
			cout << z;
			break;
		case 4:q1.display();
			break;
		default:cout << "invalid ";
			break;
		}
	}
	system("system pause");
	return 0;
}