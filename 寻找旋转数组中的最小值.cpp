#include <iostream>
using namespace std;
#include <stdlib.h>

//实现旋转数组中寻找最小值
//旋转数组：把一个数组最开始的若干个元素搬到数组的末尾
//如：{3,4,5,1,2} 为{1,2,3,4,5}的旋转数组，将开始的1，2移到数组的末尾。

//算法的实现利用二分查找的思想，以及旋转数组的特征。设置两个指针分别指向数组的头和尾(low ,high)，计算中间值与两个指针比较，因为旋转数组前后两个子数组任然有序，假设为递增序，
//若中间值大于low所指向的值（说明中间值在前面的递增数组中），则将中间值的下标号赋值给low;
//若中间值小于high所指向的值（说明中间值在后面的递增数组中），则将中间值的下标号赋值给high;

int *increase_find_min(int *a, int length, int *result) //只适合于递增数组的旋转数组
{
	int low  = 0;
	int high = length - 1;
	int mid = (low + high) / 2;
	//检测将递增数组前面的0位搬到数组的末尾处，数组未变，最小值为a[low],最大值为a[high]
	if ( a[low] < a[high]) 
	{
		result[0] = a[low];
		result[1] = a[high];
		return result;
	}
	while(high - low != 1 )
	{
//判断{0,1,1,1,1}旋转成的{1,0,1,1,1}和{1,1,1,0,1}情况，没法通过移动low和high来缩小查找范围，只能进行顺序查找。
		if( a[low] == a[high] && a[high] == a[mid])
		{
			int min = a[low];
			int max = a[low];
			for (int i = low+1; i <= high; i++)
			{
				if (min >a[i])
					min = a[i];
				if (max < a[i])
					max = a[i];
			}
			result[0] = min;
			result[1] = max;
			return result;
		}
		if( a[mid] >= a[low])
			low = mid;
		if( a[mid] <= a[high])
			high = mid;
		mid = (low + high) / 2;
	}
	result[0] = a[high];
	result[1] = a[low];
	return result;
}

int  *decrease_find_min(int *a, int length, int *result)//只适合于递减数组的旋转数组
{
	int low  = 0;
	int high = length - 1;
	int mid = (low + high) / 2;
	if ( a[low] > a[high]) //同上面的递增数组的情况类似
	{
		result[0] = a[high];
		result[1] = a[low];
		return result;
	}
	if( a[low] == a[high] && a[high] == a[mid])
	{
		int min = a[low];
		int max = a[low];
		for (int i = low+1; i <= high; i++)
		{
			if (min >a[i])
				min = a[i];
			if (max < a[i])
				max = a[i];
		}
		result[0] = min;
		result[1] = max;
		return result;
	}
	while(high - low != 1 )
	{
		if( a[mid] >= a[high])
			high = mid;
		if( a[mid] <= a[low])
			low = mid;
		mid = (low + high) / 2;
	}
	result[0] = a[low];
	result[1] = a[high];
	return result;
}

void traverse(int *a)
{
	for(int i = 0; i < 5; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void test_a(int *a, int length, int *result)
{
	cout<<"递增的旋转数组为：";
	traverse(a);
	result = increase_find_min(a, length, result);
	cout<<"最小值为： "<<result[0]<<endl;
	cout<<"最大值为： "<<result[1]<<endl;
}

void test_b(int *a, int length, int *result)
{
	cout<<"递减的旋转数组为：";
	traverse(a);
	result = decrease_find_min(a, length, result);
	cout<<"最小值为： "<<result[0]<<endl;
	cout<<"最大值为： "<<result[1]<<endl;
}
int main()
{
	int *result = (int *)malloc(sizeof(int) * 2);
	int a1[5] = {1,0,1,1,1};
	int a2[5] = {1,2,3,4,5};
	int a3[5] = {3,4,5,1,2};
	int a4[5] = {20};
	test_a(a1,5,result);
	test_a(a2,5,result);
	test_a(a3,5,result);
	test_a(a4,5,result);
	int b1[5] = {1,1,1,0,1};
	int b2[5] = {5,4,3,2,1};
	int b3[5] = {8,7,6,10,9};
	test_b(b1,5,result);
	test_b(b2,5,result);
	test_b(b3,5,result);
	free(result);
	system("pause");
	return 0;
}