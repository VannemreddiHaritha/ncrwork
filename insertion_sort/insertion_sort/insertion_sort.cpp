#include<iostream>
using namespace std;
int main()
{
	int *array,i,j,size,temp;
	cout << "enter thr size of array"<<endl;
	cin >> size;
	array = new int[size];
	cout << "enter the elements" << endl;
	for (i = 0;i < size;i++) 
	{
		cin >> array[i];
	}

   for (i = 1;i <= size - 1;i++)
	{
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > temp) 
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		
		array[j + 1] = temp;

	}
	cout << "sorted array is";
	for (i = 0;i < size;i++)
		cout  << array[i] << endl;
	delete[] array;
	system("pause");
	return 0;
}