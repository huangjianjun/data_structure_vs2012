#include<iostream>
using namespace std;
#include<stdlib.h>

/*关于二维矩阵的形参和实参的传递接受问题
可以用二维数组名作为实参或者形参，在被调用函数中对形参数组定义时可以指定所有维数的大小，也可以省略第一维的大小说明，如： 
void Func(int array[3][10]); 
void Func(int array[][10]); 
二者都是合法而且等价，但是不能把第二维或者更高维的大小省略，如下面的定义是不合法的： 
void Func(int array[][]); 
因为从实参传递来的是数组的起始地址，在内存中按数组排列规则存放(按行存放)，而并不区分行和列，如果在形参中不说明列数，则系统无法决定应为多少行多少列，不能只指定一维而不指定第二维。*/
void func_1(int a[2][3],int rows, int columns)
{
	for( int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout<<a[i][j]<<"  ";
		}
	}
	cout<<endl;
}
//可以将二维数组转换成一维去处理
void func_2(int *a, int rows, int columns)
{
	for( int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout<<a[i*columns + j]<<"  ";//转换为一维数组输出。
		}
	}
	cout<<endl;
}

//也可以动态创建二维数组，利用二维指针的办法

void func_3(int **a, int rows, int columns)
{
	for( int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout<<a[i][j]<<"  ";//转换为一维数组输出。
		}
	}
	cout<<endl;
}
void test_3(int rows, int columns)
{
	cout<<"test func_3:"<<endl;
	int **number = new int *[rows];//二维数组来存储一维数组的地址
	for(int i = 0; i < rows; i++)
	{
		number[i] = new int[columns];//二维指针数组中存放着rows个columns长度的一维数组的指针
		for(int j = 0; j < columns; j++)
		{
			number[i][j] = i*columns + j + 1;//给整个二维数组赋值
		}
	}
	func_3(number, rows, columns);
}

void test_1()
{
	int a[2][3] = {{1,2,3},{4,5,6}};
	cout<<"test func_1:"<<endl;
	func_1(a,2,3);
}
void test_2()
{
	int a[2][3] = {{1,2,3},{4,5,6}};
	cout<<"test func_2:"<<endl;
	func_2((int *)a,2,3);
	return;
}
int main()
{
	test_1();
	test_2();
	test_3(4,4);
	system("pause");
	return 0;
}