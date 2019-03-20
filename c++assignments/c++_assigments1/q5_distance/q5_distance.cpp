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
	int dis_meters, dis_centi, dis_sum;
	dis_meters = d1.meter + 0.308*d2.feet;//convert to meters
	dis_centi = d1.centi + 12.5*d2.inch;//covert to centimeters
	dis_sum = dis_meters+100*dis_centi;
	cout << dis_sum;
}
int main()
{
	int dis_meter, dis_centi, dis_inch, dis_feet;
	cout << "enter distance in meters,centimeters,feet and inches";
	cin >> dis_meter >> dis_centi >> dis_feet >> dis_inch;
	distance1 d1(dis_meter, dis_centi);
	distance2 d2(dis_feet , dis_inch);
	cout<<"total distance is ";
	add(d1, d2);
	system("pause");
	return 0;

}