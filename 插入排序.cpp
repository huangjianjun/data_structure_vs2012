#include<iostream>
using namespace std;
#include<stdlib.h>
#include <time.h>

//��������Ļ���˼�룺ͨ�������������У�����δ�������ݣ��������������дӺ���ǰɨ�裬�ҵ���Ӧ��λ�ò����롣
//��������ǳ����������˿���,�ڿ�ʼ����ʱ�������ǿյģ����泯�·������ϡ����ţ�һ�δ���������һ���ƣ����������뵽����һ�����е���ȷλ���ϡ�Ϊ���ҵ������Ƶ���ȷλ�ã�Ҫ�������������е��ƴ��ҵ���ؽ��бȽϡ�����ʲôʱ�������е��ƶ����ź���ġ�

int charu_sort(int *a ,int n)
{
	int j;
	int temp;//��ʱ�洢a[i]��ֵ��
	//��a[0]�Զ������������У�ѭ����1��n-1����ʣ�µ�n-1�������β��뵽ǰ�����������a[0]��a[i-1]��
	for(int i = 1; i < n; i++)
	{
		temp = a[i];
		for(j = i; j >=0 && a[j-1] > temp; j--) //�����i��Ԫ���㵽���ڼ�a[0]��a[i]���в�������
		{
			a[j] = a[j-1];
		}
		a[j] = temp;
	}
	return 0;
}

int main()
{
	int num = 0;
	int a[8] = {0};
	cout<<"<������Ԫ�ؽ��и�ֵ��ʼ��>\n";
	for (int i = 0;i < 8; i++)
	{
		int temp;
		cout<<"a["<<i<<"]"<<" :";
		cin>>temp;
		a[i] = temp;
	}
	cout<<"---------------------------------\n";
	cout<<"����ǰ:";
	for (int i=0; i<8; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	time_t start = clock();
	charu_sort(a,8);
	time_t end = clock();
	cout<<"�����:";
	for (int i=0; i<8; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	printf("the charusort running time is : %f\n", double(end -start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}