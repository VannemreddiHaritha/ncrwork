#include<iostream>
using namespace std;
class polar
{
	float angle;
	int radius;

public:
	static int count;
	void get_data(float a, int r)
	{
		angle = a;
		radius = r;
	}
	static void data()
	{
		count++;
		cout << "count is"<<count<<endl;
	}

};

int polar::count = 0;
int main()
{
	float angle_1 = 0, radius_1 = 0, angle_2 = 0, radius_2 = 0;
    cout << "Enter the angle and radius" << endl;
   cin >> angle_1 >> radius_1;
	polar p1, p2;
   p1.get_data(angle_1,radius_1);
	polar::data();
	cout << "Enter the angle and radius" << endl;
     cin >> angle_2 >> radius_2;
	p1.get_data(angle_2, radius_2);
	polar::data();
	system("pause");
	return 0;
}