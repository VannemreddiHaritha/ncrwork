#include<iostream>
using namespace std;
class point
{
	int x;
	int y;
public:
	point(int i, int j)
	{
		x = i;
		y = j;
	}
	friend void add(point,point);
};
void add(point p1,point p2)
{
	float d = sqrt(pow((p1.x - p2.x),2)+pow((p1.y-p2.y),2));
	cout << d;
}
int main()
{
	point p1(3 , 4), p2(2, 3);
	add(p1, p2);
	system("pause");
	return 0;
}