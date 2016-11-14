#include<iostream>
using namespace std;
#include<stdlib.h>

//基本思路：1、直接对所给的数组进行排序，这样输出前K个数即可，但是时间复杂度为一般为 O（nlogn）
//		   2、我们利用快速排序的思想，基于数组的第K个数字进行调整，使得比大K个数字小的数字都位于数组的左边,
//		     比第K个数大的数字位于数组的右边，这样调整后，位于数组中左边的K个数字就是最小的K个数字
//			（这K个数字不一定是排好序的）,这种做法改变了原来的数组array。

int partition(int *array, int length, int start, int end)
{
	int index;
	int val = array[start];//默认随机取得的数为数组的开始元素
	while(start < end)
	{
		while(start < end && array[end] >= val)
			end--;
		array[start] = array[end];
		while(start < end && array[start] <= val)
			start++;
		array[end] = array[start];
	}
	array[start] = val;
	index = start;//这个时候start 与 end相等，循环结束，返回val的真实索引。
	return index;
}

void display(int *array, int length)
{
	if(array == NULL || length <= 0)
	{
		cout<<"输入参数有误，程序结束！"<<endl;
		return ;
	}
	for(int i = 0; i < length; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}

void get_start_k_numbers(int *array, int length, int k)
{
	int start = 0;
	int end = length - 1;
	if( array == NULL || length <= 0)
	{
		cout<<"输入的参数有误，程序退出！"<<endl;
		return ;
	}
	int index = partition(array, length, start, end);
	while(index != k-1)//索引不是所要的索引的时候
	{
		if(index > k-1)
		{
			end = index -1;
			index = partition(array, length, start, end);
		}
		if(index < k-1)
		{
			start = index + 1;
			index = partition(array, length, start, end);
		}
	}
	//打印这时的array数组
	display(array, length);
	//这时 index == k-1
	for( int i = 0; i < k; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}

void test(int *array, int length)
{
	int k;
	cout<<"输入的数组为： ";
	display(array, length);
	cout<<"请输入K = ";
	cin>>k;
	get_start_k_numbers(array, length, k);
	return ;
}

int main()
{
	int a[7] = {5,2,6,8,4,3,7};
	int b[5] = {45,22,36,48,25};
	test(a,7);
	test(b,5);
	system("pause");
	return 0;
}