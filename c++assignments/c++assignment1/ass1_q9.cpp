#include<iostream>
using namespace std;
//void swap_v(int, int);
//void swap_r(int, int);
//void getswap();
class Swap
{
public:
	int a,b;
//public:
	void getswap()
	{
		cin >> a >> b;
	}
	void swap_v(int i,int j)
	{
		i = i + j;
		i = i - j;
		i = i - j;
		cout << i << j;
	}
	void swap_r(Swap &k)
	{
		k.a = k.a + k.b;
		k.b = k.a - k.b;
		k.a = k.a - k.b;
	
	}

};
int main()
{
	int choice;
	Swap c,c1;
	c.getswap();
	cin >> choice;
	switch(choice)
	{
	case 1:c1.swap_v(3,7);
		break;
	case 2:c1.swap_r(c);
		break;
	}
	cout << c.a <<" " << c.b;
	system("pause");
	return 0;
}