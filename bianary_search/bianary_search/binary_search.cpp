#include<iostream>
using namespace std;
int main()
{
	int i, j,size,array[50],temp,flag=0;
	cout << "enter the size of array";
	cin >> size;
	cout << "enter the array elements";
	for (i = 0;i < size;i++)
		cin >> array[i];
	for (i = 0;i < size - 1;i++)
	{
		for (j = 0;j < size - i - 1;j++)
		{
			if (array[j] > array[j + 1])

			{
				temp = array[j];
				array[j] = array[j + 1];
                array[j + 1] = temp;
				flag = 1;//flag is used to know whether the element is already sorted or not
			}
			if (flag == 0)
				break;
		}
    }
	cout << "the sorted array";
	for (i = 0;i < size;i++)
		cout<<array[i]<<endl;
	//logic for binary search
	int low, high, mid,element;
	cout<< "enter the element to be found";
	cin >> element;
	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (element < array[mid])
			high = mid - 1;
		else if (element > array[mid])
			low = mid + 1;
		else if (element == array[mid])
		{
			cout << "element found" << mid;
			break;
		}
		
	}
	if (low > high)
		cout << "element not found";
	system("pause");
	return 0;

}