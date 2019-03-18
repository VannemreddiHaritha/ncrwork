#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class Shape
{
   char *color;
public:
   Shape()
    {
     color = NULL;
    }
    Shape(char *string)
     { 
		color = new char[strlen(string)];
        strcpy(color, string);
     }
    void getColor()
    {
		int length;
		cout << "enter length";
		cin >> length;
		cout << "enter color"<<endl;
		color = new char[strlen(color)];
        cin >> color;
     }
    void displayColor()
    {
      cout << "Color = " << color << endl;

	}
  virtual void displayArea()
  {
    cout << "In shape\n";
   }
  ~Shape()
    {
      if (color != NULL)
          delete color;
  }

};

class Triangle :public Shape
{
   int base, height;
public:
   Triangle()
   {
      base = height = 0;
   }
   Triangle(int var)
   {
    base = height = var;
   }
   Triangle(int b, int h)
   {
    base = b;
    height = h;
    }
  void displayArea()
   {
     cout << "Area of triangle = " << 0.5*base*height << endl;
    }
};
class Square :public Shape
{
	int side;
public:
   Square(int s)
   {
    side = s;
   }
  void displayArea()
   {
    cout << "Area of square = " << side * side << endl;
  }
};
class Rectangle :public Shape
{
   int length, breadth;
public:
   Rectangle()
     {
       length = breadth = 0;
      }
    Rectangle(int var)
    {
    length = breadth = var;
    }
   Rectangle(int l, int b)
    {
       length = l;
       breadth = b;
    }
 void displayArea()
  {
   cout << "Area of Rectangle = " << length * breadth << endl;
   }
};
int main()
{
	int length, breadth,base,height;
	cout << "enter base and height";
	cin >> base >> height;
	Triangle triangle(base,height);
	int side;
	cout << "enter side";
	cin >> side;
    Square square(side);
	cout << "enter length and breadth";
	cin >> length >> breadth;
	Rectangle rectangle(length, breadth);
    Shape *shape[3] = { &triangle,&square,&rectangle };
	for (int i = 0; i < 3; i++)
     shape[i]->displayArea();
    return 0;

}