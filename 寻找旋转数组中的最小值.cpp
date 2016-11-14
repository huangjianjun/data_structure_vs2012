#include <iostream>
using namespace std;
#include <stdlib.h>

//ʵ����ת������Ѱ����Сֵ
//��ת���飺��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ
//�磺{3,4,5,1,2} Ϊ{1,2,3,4,5}����ת���飬����ʼ��1��2�Ƶ������ĩβ��

//�㷨��ʵ�����ö��ֲ��ҵ�˼�룬�Լ���ת�������������������ָ��ֱ�ָ�������ͷ��β(low ,high)�������м�ֵ������ָ��Ƚϣ���Ϊ��ת����ǰ��������������Ȼ���򣬼���Ϊ������
//���м�ֵ����low��ָ���ֵ��˵���м�ֵ��ǰ��ĵ��������У������м�ֵ���±�Ÿ�ֵ��low;
//���м�ֵС��high��ָ���ֵ��˵���м�ֵ�ں���ĵ��������У������м�ֵ���±�Ÿ�ֵ��high;

int *increase_find_min(int *a, int length, int *result) //ֻ�ʺ��ڵ����������ת����
{
	int low  = 0;
	int high = length - 1;
	int mid = (low + high) / 2;
	//��⽫��������ǰ���0λ�ᵽ�����ĩβ��������δ�䣬��СֵΪa[low],���ֵΪa[high]
	if ( a[low] < a[high]) 
	{
		result[0] = a[low];
		result[1] = a[high];
		return result;
	}
	while(high - low != 1 )
	{
//�ж�{0,1,1,1,1}��ת�ɵ�{1,0,1,1,1}��{1,1,1,0,1}�����û��ͨ���ƶ�low��high����С���ҷ�Χ��ֻ�ܽ���˳����ҡ�
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

int  *decrease_find_min(int *a, int length, int *result)//ֻ�ʺ��ڵݼ��������ת����
{
	int low  = 0;
	int high = length - 1;
	int mid = (low + high) / 2;
	if ( a[low] > a[high]) //ͬ����ĵ���������������
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
	cout<<"��������ת����Ϊ��";
	traverse(a);
	result = increase_find_min(a, length, result);
	cout<<"��СֵΪ�� "<<result[0]<<endl;
	cout<<"���ֵΪ�� "<<result[1]<<endl;
}

void test_b(int *a, int length, int *result)
{
	cout<<"�ݼ�����ת����Ϊ��";
	traverse(a);
	result = decrease_find_min(a, length, result);
	cout<<"��СֵΪ�� "<<result[0]<<endl;
	cout<<"���ֵΪ�� "<<result[1]<<endl;
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