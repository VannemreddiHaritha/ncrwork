#include<iostream>
using namespace std;
int partition(int array[],int low,int  high)
{
	int pivot = array[low];
	int i, j,temp;
	i = low + 1;
	j = high;
	while (low < high)
	{


		while (i <= high && array[i] < pivot)
			i++;
		while (j >= low && array[j] > pivot)
			j--;
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		else break;
	}
	
	temp = array[j];
	array[j] = array[low];
	array[low] = temp;
	return j;
}
void quick(int array[], int low, int high)
{
	int j;
	if (low<high)
	{
		j = partition(array, low, high);
		quick(array, low, j);
		quick(array, j+1,high);
     }

}
int main()
{
	int *array, i, j, size, temp;
	cout << "enter thr size of array" << endl;
	cin >> size;
	array = new int[size];
	cout << "enter the elements" << endl;
	for (i = 0;i < size;i++)
	{
		cin >> array[i];
	}
	quick(array, 0, size - 1);
	cout << "sorted array is";
	for (i = 0;i < size;i++)
		cout << array[i] << endl;
	delete[] array;
	system("pause");
	return 0;

}