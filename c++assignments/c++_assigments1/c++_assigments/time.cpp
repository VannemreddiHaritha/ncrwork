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
		cout << hour << ':' << min << ':' << sec << endl;
	}
	void add_time(time &t2, time &t3)
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
	int hr1 = 0, min1 = 0, sec1 = 0 ,hr2 = 0, min2 = 0, sec2 = 0;
     cout << "Enter the hours, minutes and seconds";
     cin >> hr1 >> min1 >> sec1;
	 cout << "Enter the hours, minutes and seconds";
     cin >> hr2 >> min2 >> sec2;
	 time t1, t2(hr1,min1,sec1), t3(hr2,min2,sec2);
	cout << "print time t2 "<<endl;
	t2.print_time();
	cout << "print time t3 " << endl;;
	t3.print_time();
	cout << "add time "<<endl;
	t1.add_time(t2, t3);
	t1.print_time();

	system("pause");
	return 0;
}