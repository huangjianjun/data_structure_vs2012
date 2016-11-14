#include<iostream>
using namespace std;
#include<stdlib.h>

//每次打印一圈分为四步：
//1、从左向右打印 2、从上到下打印 3、从右向左打印 4、从下到上打印
//最后一圈的打印可能会退化为只有一行、只有一列、甚至只有一个数字，因此打印这样的一圈不在需要四步，所以我们要在每步打印前做条件判定。
void print_matrix_circle(int **matrix, int rows, int columns, int start)
{
	int endx = columns - 1 - start;
	int endy =  rows- 1 - start;
	//1、从左向右打印
	for(int i = start; i <= endx; i++)
	{
		int number = matrix[start][i];
		cout<<number<<"  ";
	}
	cout<<"#<1>";
	//2、从上向下打印
	if (start < endy)
	{
		for(int i = start + 1; i <= endy; i++)
		{
			int number = matrix[i][endx];
			cout<<number<<"  ";
		}
		cout<<"#<2>";
	}
	//3、从右向左打印
	if( start < endx && start < endy)
	{
		for(int i = endx - 1; i >= start; i--)
		{
			int number = matrix[endy][i];
			cout<<number<<"  ";
		}
		cout<<"#<3>";
	}
	//4、从下向上打印
	if( start < endx && start + 1 < endy)//至少三行两列
	{
		for(int i = endy - 1; i >= start + 1; i--)
		{
			int number = matrix[i][start];
			cout<<number<<"  ";
		}
		cout<<"#<4>";
	}
	return ;
}
void print_matrix_clockwisely(int **matrix, int rows, int columns)
{
	if(matrix == NULL && rows < 0 && columns < 0)
	{
		cout<<"非法的输入！"<<endl;
		return ;
	}
	int start = 0;
	while(rows > start * 2  && columns > start * 2)//一圈一圈打印数的循环条件
	{
		print_matrix_circle(matrix, rows, columns, start);//每次打印以（start,start）开始的一圈
		start++;
	}
	return;
}
void Test(int rows, int columns)
{
	printf("Test Begin: %d rows, %d columns.\n", rows, columns);

	if(columns < 1 || rows < 1)
		return;

	int** numbers = new int*[rows];
	for(int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		for(int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i * columns + j + 1;
		}
	}

	//print_matrix_clockwisely(numbers, rows, columns);
	cout<<endl;
	for(int i = 0; i < rows; ++i)
		delete[] (int*)numbers[i];
	delete[] numbers;
}

int main()
{
//	int t1[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//	print_matrix_clockwisely((int **)t1,4,4);
	Test(4,4);
	Test(1,0);
	Test(0,1);
	Test(1,5);
	Test(5,1);
	system("pause");
	return 0;
}