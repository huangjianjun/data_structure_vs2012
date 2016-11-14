#include<iostream>
using namespace std;
#include<stdlib.h>

//����˼·��1��ֱ�Ӷ�������������������������ǰK�������ɣ�����ʱ�临�Ӷ�Ϊһ��Ϊ O��nlogn��
//		   2���������ÿ��������˼�룬��������ĵ�K�����ֽ��е�����ʹ�ñȴ�K������С�����ֶ�λ����������,
//		     �ȵ�K�����������λ��������ұߣ�����������λ����������ߵ�K�����־�����С��K������
//			����K�����ֲ�һ�����ź���ģ�,���������ı���ԭ��������array��

int partition(int *array, int length, int start, int end)
{
	int index;
	int val = array[start];//Ĭ�����ȡ�õ���Ϊ����Ŀ�ʼԪ��
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
	index = start;//���ʱ��start �� end��ȣ�ѭ������������val����ʵ������
	return index;
}

void display(int *array, int length)
{
	if(array == NULL || length <= 0)
	{
		cout<<"����������󣬳��������"<<endl;
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
		cout<<"����Ĳ������󣬳����˳���"<<endl;
		return ;
	}
	int index = partition(array, length, start, end);
	while(index != k-1)//����������Ҫ��������ʱ��
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
	//��ӡ��ʱ��array����
	display(array, length);
	//��ʱ index == k-1
	for( int i = 0; i < k; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}

void test(int *array, int length)
{
	int k;
	cout<<"���������Ϊ�� ";
	display(array, length);
	cout<<"������K = ";
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