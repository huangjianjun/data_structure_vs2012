#include<iostream>
using namespace std;
#include<stdlib.h>
#include <time.h>

int shell_sort(int *a, int n)
{
	int d ;
	int k;
	int temp;
	for(d = n/2; d > 0; d /= 2)  //ȷ��ϣ������Ĳ�����������ֵ
	{
		for(int i = 0; i < d; i++) //���ݲ���ֵ���з���
		{
			for(int j = i + d; j < n; j += d)//ÿ��� d ������ȡһ��Ԫ�����һ�飬��{a[0],a[0+d],a[2d]...}
			{
				if(a[j] < a[j-d])//ÿ�����ڽ��в�������,Ѱ��Ҫ�����ֵa[j]
				{
					temp = a[j];//��¼��ǰ�ҵ���Ҫ�����ֵ��Ĭ���������У�
					for( k = j; a[k-d] > temp && k >= 0; k -= d)//
					{
						a[k] = a[k-d];
					}
					a[k] = temp;
				}
			}
		}
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
	shell_sort(a,8);
	time_t end = clock();
	cout<<"�����:";
	for (int i=0; i<8; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	printf("the ϣ������ running time is : %f\n", double(end -start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}