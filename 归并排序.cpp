#include <iostream>
using namespace std;
#include "stdlib.h"

void display(int *array, int n)
{
	if (array == NULL)
	{
		cout<<"遍历序列为空！\n";
		return ;
	}
	for (int i = 0; i < n; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}
//length 为等待排序数组 arrary的长度，swap 为暂时的存储数组，K为归并的子序列的长度，即归并的步长。
void merge(int *array, int length, int *swap, int k)
{
	int i,j,start1,end1,start2,end2;
	int m = 0;
	start1 = 0;
	while(start1 + k <= length - 1)//保证剩下的元素能够至少有K个，但是小于2K个
	{
		start2 = start1 + k;
		end1 = start2 - 1;
		end2 = (start2+k-1 <= length-1)?(start2+k-1):(length-1);
		//最后不够2K个元素的，第二组上界直接取最后。
		for (i = start1, j = start2; i <= end1 && j <= end2; m++)
		{
			if( array[i] <= array[j])
			{
				swap[m] = array[i];
				i++;
			}
			else
			{
				swap[m] = array[j];
				j++;
			}
		}
		while(i <= end1)
		{
			swap[m] = array[i];
			i++;
			m++;
		}
		while(j <= end2)
		{
			swap[m] = array[j];
			j++;
			m++;
		}
		start1 = end2 + 1;
	}
	for (i = start1; i < length; i++,m++)//将最后剩下的不够K个数目的元素直接拷贝到swap数组中。
		swap[m] = array[i];
}


//二路归并排序算法如下：

int *mergesort(int *array, int length)
{
	if(array == NULL || length <= 0)
		return NULL;
	int *swap = (int *)malloc(sizeof(int)*length);
	int k = 1;
	int num = 0;
	while(k < length)
	{
		merge(array, length, swap, k);
		for( int i = 0; i < length; i++)
			array[i] = swap[i];
		cout<<"第"<<++num<<"次归并结果<k = "<<k<<">: ";
		display(array,length);
		k = k*2;
	}
	free(swap);
	return array;
}


int main()
{
	int array[9] = {72,73,71,23,94,16,5,68,64};
	int length = 9;
	cout<<"待排序的序列： ";
	display(array, length);
	cout<<"-----------------------------------------------------------------\n";
	int *ret = mergesort(array, length);
	cout<<"二路归并排序如下："<<endl;
	display(ret,length);
	system("pause");
	return 0;
}