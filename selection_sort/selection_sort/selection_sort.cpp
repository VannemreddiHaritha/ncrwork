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
	for (i = 0;i <= size - 1;i++)
	{
		small = i;
		j = i + 1;
		{
			while (j <= size - 1 ) {
				if(array[small]>array[j])
				small= j;
				j = j + 1;
			}
		}
		temp = array[small];
		array[small] = array[i];
		array[i] = temp;
	}
	cout << "sorted array is";
	for (i = 0;i < size;i++)
		cout << array[i] << endl;
	delete[] array;
	system("pause");
	return 0;
}