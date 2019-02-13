#include<iostream>
using namespace std;
class time
{
	int hour;
	int min;
	int sec;
public:
	time()
	{
		hour = 0;
		min = 0;
		sec = 0;
	}
	time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	
	void print_time()
	{
		cout << hour << ':' << min << ':' << sec;
	}
	void add_time(time &t2,time &t3)
	{
		sec = t2.sec + t3.sec;
		min = t2.min + t3.min;
		hour = t2.hour + t3.hour;
		 if (sec >= 60)
		{
			 min++;
			sec = sec - 60;
		}
		 if (min >= 60)
		 {
			 hour++;
			 min = 60 - min;
		}

	}
};
int main()
{
	time t1, t2(3,50,45),t3(4,5,49);
	t2.print_time();
	t1.add_time(t2, t3);
	t1.print_time();
	system("pause");
	return 0;
}