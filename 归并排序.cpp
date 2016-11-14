#include <iostream>
using namespace std;
#include "stdlib.h"

void display(int *array, int n)
{
	if (array == NULL)
	{
		cout<<"��������Ϊ�գ�\n";
		return ;
	}
	for (int i = 0; i < n; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}
//length Ϊ�ȴ��������� arrary�ĳ��ȣ�swap Ϊ��ʱ�Ĵ洢���飬KΪ�鲢�������еĳ��ȣ����鲢�Ĳ�����
void merge(int *array, int length, int *swap, int k)
{
	int i,j,start1,end1,start2,end2;
	int m = 0;
	start1 = 0;
	while(start1 + k <= length - 1)//��֤ʣ�µ�Ԫ���ܹ�������K��������С��2K��
	{
		start2 = start1 + k;
		end1 = start2 - 1;
		end2 = (start2+k-1 <= length-1)?(start2+k-1):(length-1);
		//��󲻹�2K��Ԫ�صģ��ڶ����Ͻ�ֱ��ȡ���
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
	for (i = start1; i < length; i++,m++)//�����ʣ�µĲ���K����Ŀ��Ԫ��ֱ�ӿ�����swap�����С�
		swap[m] = array[i];
}


//��·�鲢�����㷨���£�

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
		cout<<"��"<<++num<<"�ι鲢���<k = "<<k<<">: ";
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
	cout<<"����������У� ";
	display(array, length);
	cout<<"-----------------------------------------------------------------\n";
	int *ret = mergesort(array, length);
	cout<<"��·�鲢�������£�"<<endl;
	display(ret,length);
	system("pause");
	return 0;
}