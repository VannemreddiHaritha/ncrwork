#include<iostream>
using namespace std;
int main()
{
	int i, j, size, array[50], temp, flag ;
	cout << "enter the size of array";
	cin >> size;
	cout << "enter the array elements";
	for (i = 0;i < size;i++)
		cin >> array[i];
	for (i = 0;i < size - 1;i++)
	{
		flag = 0;
		for (j = 0;j < size - i - 1;j++)
		{
			if (array[j] > array[j + 1])

			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;//flag is used to know whether the element is already sorted or not
			}
		}
			if (flag == 0)
				break;
		
	}
	cout << "the sorted array";
	for (i = 0;i < size;i++)
		cout << array[i] << endl;
	system("pause");
	return 0;
}