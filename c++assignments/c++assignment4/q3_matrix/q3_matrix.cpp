#include<iostream>
using namespace std;
class matrix
{
	double **array;
	int row_size;
	int col_size;
public:
	matrix()
	{
		array =NULL ;
		row_size = 0;
		col_size = 0;
	}
	matrix(double **name, int r_size, int c_size)
	{
		int i,j;
		if (r_size > 0 && c_size > 0) {
			row_size = r_size;
			col_size = c_size;
			array = new double*[row_size];
			for (i = 0;i < row_size;i++)
			{
				array[i] = new double[col_size];
				for (j = 0;j < col_size;j++)
				{
					array[i][j] = name[i][j];
				}
			}
		}
		else
			cout << "negative values are given in the input";
	}
	
	matrix(const matrix &m1)
	{
		int i, j;
		
		
		row_size = m1.row_size;
		col_size = m1.col_size;
		if (array == NULL)
		{
			array = new double*[row_size];
			for (i = 0;i < row_size;i++)
			{
				array[i] = new double[col_size];
			}
		}
		array = m1.array;
	}
	void display()
	{
		int i,j;
		for (i = 0;i < row_size;i++)
		{
			for (j = 0;j < col_size;j++)
			{
				cout << array[i][j]<<" ";
		    }
			cout << endl;

		}

	}
	matrix operator+(const matrix m1)
	{
		try {
			int i, j;
			matrix temp;
			temp.row_size = row_size;
			temp.col_size = col_size;
			temp.array = new double*[temp.row_size];
			if (row_size == m1.row_size&&col_size == m1.col_size)//add if and only if matrices are of same size
			{
				for (i = 0;i < row_size;i++)
				{
					temp.array[i] = new double[temp.col_size];
					for (j = 0;j < col_size;j++)
						temp.array[i][j] = m1.array[i][j] + array[i][j];
				}

			}
			else
			{
				throw 1;
			}
			return temp;
		  }
		catch (...)
		{
			cout << "rows and colums are not equal";
		}
	}
	matrix operator=(const matrix &m)
	{
		if (array != NULL)
		{
			delete[] array;
			array = NULL;
		}
		int i, j;
		if (m.row_size > 0 && m.col_size > 0) {
			row_size = m.row_size;
			col_size = m.col_size;
			array = new double*[row_size];
			for (i = 0;i < row_size;i++)
			{
				array[i] = new double[col_size];
				for (j = 0;j < col_size;j++)
					array[i][j] = m.array[i][j];
			}
			return *this;
		}
		else
			throw "=operation is not performed";
		
	}
	~matrix()
	{
		int i, j;
		if (array != NULL)
		{
			for(i=0;i<row_size;i++)
			delete array[i];
			delete array;
		}
		
		array = NULL;
	}
	friend istream& operator>>(istream&,matrix&);
	friend ostream& operator<<(ostream&, matrix);
};
istream& operator>>(istream& cin, matrix &m1)
{
	int i,j;
	cout << "enter no of rows and coloumns for another matrix";
	cin >> m1.row_size;
	cin >> m1.col_size;
	m1.array = new double*[m1.row_size];
	cout << "enter elements";
	for (i = 0;i < m1.row_size;i++)
	{
		m1.array[i] = new double[m1.col_size];
		for (j = 0;j < m1.col_size;j++)
			cin >> m1.array[i][j];
	}
	return cin;
}
ostream& operator<<(ostream& cout, matrix m1)
{
	int i, j;
	for (i = 0;i < m1.row_size;i++)
	{
		for (j = 0;j < m1.col_size;j++)
			cout<< m1.array[i][j]<<" ";
		cout << endl;
	}
	return cout;
}

int main()
{
	
	int r_size, c_size,i,j;
	double **matrix_ele;
	cout << "enter no of rows and columns";
	cin >> r_size;
	cin >> c_size;
	matrix_ele = new double*[r_size];
	cout << "enter the elements in matrix";
	for (i = 0;i < r_size;i++)
	{
		matrix_ele[i] = new double[c_size];
		for (j = 0;j < c_size;j++)
			cin >> matrix_ele[i][j];
	}
	matrix m1(matrix_ele, r_size, c_size);
	cout << "the matrix is displayed using  paramiterized constructor"<<endl;
	m1.display();
	matrix m2(m1);
	cout << "the matrix is displayed using copy constructor"<<endl;
	m2.display();
	matrix m4;
	cin >> m4;
	cout << "the matrix is scanned and displayed using copy constructor "<<endl;
	cout << m4;
	matrix m3;
	m3 = m1 + m2;
	cout << "addition of two matrices " << endl << m3;
	matrix m5;
	m5 = m3;
	cout << "equal to operator overloading" << endl << m5;
	system("pause");
	return 0;
	
}