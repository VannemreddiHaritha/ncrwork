#include<iostream>
using namespace std;
class distance2;
class distance1
{
	float meter;
	float centi;
public:
	distance1(float m, float c)
	{
		meter = m;
		centi = c;

    }
	friend void add(distance1, distance2);
		
};
class distance2
{
	float inch;
	float feet;
public:
	distance2(float f, float i)
	{
		feet = f;
		inch = i;
	}
	friend void add(distance1, distance2);
};
void add(distance1 d1, distance2 d2)
{
	int t,s,k;
	t = d1.meter + 0.308*d2.feet;//convert to meters
	s = d1.centi + 12.5*d2.inch;//covert to centimeters
	k = t + 100 * s;
	cout << k;
}
int main()
{
	distance1 d1(3,5);
	distance2 d2(4,7);
	add(d1, d2);
	system("pause");
	return 0;

}