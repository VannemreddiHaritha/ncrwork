#include <iostream>

using namespace std;

class swapk

{int a;
int b;

public: swapk()

{
 a = b = 0;
}

void get_swap(int x, int y)

	{
       a = x;b = y;

	}
void get_swap()
 {
	cin >> a >> b;

 }

		void swapByvalue(swapk k)

		{

			k.a = k.a + k.b;

			k.b = k.a - k.b;

			k.a = k.a - k.b;

			cout << "swaped values are " << k.a << " " << k.b << endl;

		}

		void swap_ref(swapk &k)

		{k.a = k.a + k.b;
          k.b = k.a - k.b;
		  k.a = k.a - k.b;
		}
void print_swap()
{	cout << a << " " << b << endl;}

};

int main()

{

	int choice = 0;

	swapk input, output_after_swap;
    cout << "Enter two variables" << endl;
     input.get_swap();
	 cout << "1.Call by value" << endl;
   cout << "2. Call by reference" << endl;
  cout << "Enter your choice";
cin >> choice;
cout << "Initial values are ";

	input.print_swap();

	switch (choice)

	{

	case 1: input.swapByvalue(input);
            break;
    case 2: input.swap_ref(input);
       cout << "swaped values are ";
	           input.print_swap();

		break;

	default: cout << "Invalid Option";

		break;

	}

	system("pause");

	return 0;

}