#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//�ٶ��ڴ�����ļ�¼�����У����ڶ��������ͬ�Ĺؼ��ֵļ�¼��������������Щ��¼����Դ��򱣳ֲ��䣬����ԭ�����У�ri=rj����ri��rj֮ǰ�����������������У�ri����rj֮ǰ��������������㷨���ȶ��ģ������Ϊ���ȶ��ġ�

//ð�������������������ֵ���бȽϣ�ֱ����С��ֵð����һ��λ�ã��������ѭ������ʣ�µ�����Ԫ�ص�����
int maopao_sort(int *a, int n)
{
	int temp;
	int m = 0;//��ʾ�����Ĵ���
	bool exchange = false;
	for (int i = 0; i < n-1; i++)
	{
		for(int j = n-1; j >= i; j--)
		{
			if(a[j] < a[j-1])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				m= m + 1;
				exchange = true;
			}
		}
		if(!exchange)
			return m;
	}
	return m;
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
	num = maopao_sort(a, 8);
	time_t end = clock();
	cout<<"�����:";
	for (int i=0; i<8; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	cout<<"�����򹲽�����ֵ����Ϊ��"<<num<<endl;
	printf("the maopao running time is : %f\n", double(end -start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
