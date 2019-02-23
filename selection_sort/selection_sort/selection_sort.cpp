#include<iostream>
using namespace std;
int main()
{
	int *array, i, j, size, temp, small;
	cout << "enter thr size of array" << endl;
	cin >> size;
	array = new int[size];
	cout << "enter the elements" << endl;
	for (i = 0;i < size;i++)
	{
		cin >> array[i];
	}
	small = array[0];
	for (i = 0;i <= size - 1;i++)
	{
		for (j = i + 1;j <= size - 1;j++)
		{
			if (small > array[j])
				small = array[j];
		}
		temp = small;
		small = array[i];
		array[i] = temp;
	}
	cout << "sorted array is";
	for (i = 0;i < size;i++)
		cout << array[i] << endl;
	delete[] array;
	system("pause");
	return 0;
}