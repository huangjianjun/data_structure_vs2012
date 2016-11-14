/* 二分查找
 * 算法思想：1、将数组排序(从小到大)；2、每次跟中间的数mid比较，如果相等可以直接返回，
 * 如果比mid大则继续查找大的一边，否则继续查找小的一边。

  输入：排序好的数组 - sSource[]，数组大小 - array_size，查找的值 - key
  返回：找到返回相应的位置，否则返回-1
*/
#include<iostream>
using namespace std;
#include<stdlib.h>
//非递归实现方法
int BinSearch_1(int sSource[], int array_size, int key)
{	
	if (sSource == NULL  || array_size <= 0)
	{
		cout<<"输入参数不满足要求，程序退出！"<<endl;
		system("pause");
		return -1;
	}
	int low = 0, high = array_size - 1, mid;
	while (low <= high)//采用循环
	{		
		mid = (low + high) / 2;//获取中间的位置
		
		if (sSource[mid] == key)			
			return mid;	//找到则返回相应的位置
		if (sSource[mid] > key)			
			high = mid - 1;	//如果比key大，则往低的位置查找
		else
			low = mid + 1;	//如果比key小，则往高的位置查找
	}	
	return -1;	
}

//递归实现方法
int BinSearch_2(int sSource[], int low, int high, int key)
{
	int mid;
	if (sSource == NULL  || low > high)
	{
		cout<<"输入参数不满足要求，程序退出！"<<endl;
		system("pause");
		return -1;
	}
	if (low < high)
	{
		mid = (low + high) / 2;
		if (sSource[mid] == key)
			return mid;
		else if (sSource[mid] > key)
			mid = BinSearch_2(sSource, low, mid-1, key);
		else if (sSource[mid] < key)
			mid = BinSearch_2(sSource, mid+1, high, key);	
	}
	else
	{
		cout<<"对不起，没有找到该值！"<<endl;
		return -1;
	}
	return mid;
}

void display( int *array,int length)
{
	if (array == NULL || length <= 0)
	{
		cout<<"输入参数不满足要求，程序退出！"<<endl;
		exit(-1);
	}
	for ( int i = 0; i < length; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}
int main()
{
	int pos ;
	int array[10] = {10,20,30,40,50,60,70,80,90,100};
	int *b = NULL;
	display(array, 10);
	cout<<"调用递归实现的函数 BinSearch_1 "<<endl;
	pos = BinSearch_1(array, 10, 60);
	cout<<"期望的pos -> 5"<<"\t"<<"实际运行pos -> "<<pos<<endl;
	
	cout<<"调用非递归实现的函数 BinSearch_2 "<<endl;
	pos = BinSearch_2(array, 0, 9, 60);
	cout<<"期望的pos -> 5"<<"\t"<<"实际运行pos -> "<<pos<<endl;
//测试传入指针的情况
	pos = BinSearch_2(b, 0, 9, 60);
	system("pause");
	return 0;
}