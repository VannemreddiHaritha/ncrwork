#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
//template<> function
template<class T>
int linear_search(T array[], int no_ele, T ele_search)
{
    int i;
    for (i = 0; i < no_ele; i++)
    if (array[i] == ele_search)
              return 1;
	return 0;
}
int linear_search(char *array[], int no_ele, char *ele_search);
int linear_search(char *array[], int no_ele, char *ele_search)
{
   int i;
    for (i = 0; i < no_ele; i++)
    if (strcmp(array[i], ele_search) == 0)
           return 1;
       return 0;
}
int main()
{
    int i; 
	int *array,no_of_ele_int;
	cout << "enter no of elements of int type"<<endl;
	cin >> no_of_ele_int;
	array = new int[no_of_ele_int];
	cout << "enter elements"<<endl;
	for (i = 0;i < no_of_ele_int;i++)
		cin>>array[i];
	int ele_to_search;
	cout << "enter element to br searched"<<endl;
	cin >> ele_to_search;
   if (linear_search(array, no_of_ele_int, ele_to_search))
           cout << "element is  found" << endl;
    else
           cout << "element is not found" << endl;
   float *float_array;
   int no_of_ele_float;
   cout << "enter no of elements of float type" << endl;
   cin >> no_of_ele_float;
   float_array = new float[no_of_ele_float];
   cout << "enter elements of float type" << endl;
   for (i = 0;i < no_of_ele_float;i++)
	   cin>> float_array[i];
   float ele_to_search_in_float;
   cout << "enter element to be searched" << endl;
   cin >> ele_to_search_in_float;
   if (linear_search(float_array, no_of_ele_float, ele_to_search_in_float))
      cout << "element found" << endl;
   else
     cout << "elemet is  not found" << endl;
   char *name;
   char **arr;
   int no_of_rows;
   cout << "enter no of rows";
   cin >> no_of_rows;
   arr = new char*[no_of_rows];
    for (i = 0; i <no_of_rows; i++)
    {
		int length = 0;
		cout << "enter the length of the name";
		cin >> length;
		name = new char[length];
      cout<<("enter name\n");
       cin >> name;
      arr[i] = new char[strlen(name) + 1];
      strcpy(arr[i], name);
     }
     cout<<("enter name to be searched\n");
     cin >> name;
    if (linear_search(arr, no_of_rows, name))
        cout << "element is found" << endl;
    else
      cout << "elemebt not found" << endl;
	return 0;

}