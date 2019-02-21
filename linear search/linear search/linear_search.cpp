#include<iostream>
using namespace std;
int main()
{
	int array[100],i,size,element,flag;
	cout << "enter array size";
	cin >> size;
	cout << "enter element to be found";
	cin >> element;
	cout << "enter array elements";
	for (i = 0;i < size;i++)
		cin >> array[i];
	for (i = 0;i < size;i++)
	{
		if (array[i] == element)
		{
			flag = 1;//flag is used to tell the status of the searching element
			break;
		}
		else
			flag = 0;
	}
	if (flag == 1)
		cout << "the element is found";
	else
		if (flag == 0)
			cout << "the elment is not found";
	system("pause");
	return 0;
}