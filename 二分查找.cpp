/* ���ֲ���
 * �㷨˼�룺1������������(��С����)��2��ÿ�θ��м����mid�Ƚϣ������ȿ���ֱ�ӷ��أ�
 * �����mid����������Ҵ��һ�ߣ������������С��һ�ߡ�

  ���룺����õ����� - sSource[]�������С - array_size�����ҵ�ֵ - key
  ���أ��ҵ�������Ӧ��λ�ã����򷵻�-1
*/
#include<iostream>
using namespace std;
#include<stdlib.h>
//�ǵݹ�ʵ�ַ���
int BinSearch_1(int sSource[], int array_size, int key)
{	
	if (sSource == NULL  || array_size <= 0)
	{
		cout<<"�������������Ҫ�󣬳����˳���"<<endl;
		system("pause");
		return -1;
	}
	int low = 0, high = array_size - 1, mid;
	while (low <= high)//����ѭ��
	{		
		mid = (low + high) / 2;//��ȡ�м��λ��
		
		if (sSource[mid] == key)			
			return mid;	//�ҵ��򷵻���Ӧ��λ��
		if (sSource[mid] > key)			
			high = mid - 1;	//�����key�������͵�λ�ò���
		else
			low = mid + 1;	//�����keyС�������ߵ�λ�ò���
	}	
	return -1;	
}

//�ݹ�ʵ�ַ���
int BinSearch_2(int sSource[], int low, int high, int key)
{
	int mid;
	if (sSource == NULL  || low > high)
	{
		cout<<"�������������Ҫ�󣬳����˳���"<<endl;
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
		cout<<"�Բ���û���ҵ���ֵ��"<<endl;
		return -1;
	}
	return mid;
}

void display( int *array,int length)
{
	if (array == NULL || length <= 0)
	{
		cout<<"�������������Ҫ�󣬳����˳���"<<endl;
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
	cout<<"���õݹ�ʵ�ֵĺ��� BinSearch_1 "<<endl;
	pos = BinSearch_1(array, 10, 60);
	cout<<"������pos -> 5"<<"\t"<<"ʵ������pos -> "<<pos<<endl;
	
	cout<<"���÷ǵݹ�ʵ�ֵĺ��� BinSearch_2 "<<endl;
	pos = BinSearch_2(array, 0, 9, 60);
	cout<<"������pos -> 5"<<"\t"<<"ʵ������pos -> "<<pos<<endl;
//���Դ���ָ������
	pos = BinSearch_2(b, 0, 9, 60);
	system("pause");
	return 0;
}