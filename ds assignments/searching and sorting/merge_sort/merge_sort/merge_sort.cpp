#include<iostream>
using namespace std;
void merge(int[], int, int, int);
int* merge_sort(int[], int, int);
int* merge_sort(int array[], int low, int high)
{
	if (low < high)
	{
		int mid;
		mid = (low + high) / 2;
		merge_sort(array, low, mid);
		merge_sort(array, mid + 1, high);
		merge(array, low, mid, high);
	}
	return array;
}
void merge(int array[], int list_start1, int list_end1, int list_end2)
{
	int i, j, k;
	int list_start2 = list_end1 + 1;
	i = list_start1;
	j = list_start2;
	k = 0;
	int *list3;
	list3 = new int[list_end2 - list_start1 + 1];
	while (i <= list_end1 && j <= list_end2)
	{
		if (array[i] > array[j])
			list3[k++] = array[j++];
		else
			list3[k++] = array[i++];
	}
	while (i <= list_end1)
		list3[k++] = array[i++];
	while (j <= list_end2)
		list3[k++] = array[j++];
	while (list_end2 >= list_start1)
		array[list_end2--] = list3[--k];

	delete list3;
}
//main program
int main()
{
	int *array, i,  size;
	cout << "enter thr size of array" << endl;
	cin >> size;
	array = new int[size];
	cout << "enter the elements" << endl;
	for (i = 0;i < size;i++)
	{
		cin >> array[i];
	}
	array=merge_sort(array, 0, size - 1);
	cout << "sorted array is";
	for (i = 0;i < size;i++)
		cout << array[i] << endl;
	delete[] array;
	system("pause");
	return 0;
}