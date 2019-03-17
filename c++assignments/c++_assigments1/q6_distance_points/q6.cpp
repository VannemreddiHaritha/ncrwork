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
	friend void add(point, point);
};
void add(point p1, point p2)
{
	float d = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
	cout << d;
}
int main()
{
	int x1_cor, y1_cor, x2_cor, y2_cor;
	cout << "enter x1 ,y1,x2,y2";
	cin>> x1_cor>> y1_cor>>x2_cor>> y2_cor;
	point p1(x1_cor,y1_cor), p2(x2_cor,y2_cor);
	cout << "distance between points is";
	add(p1, p2);
	system("pause");
	return 0;
}