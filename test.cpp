#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//�������� ���������� ��������
int findpos(int *a, int low, int high)
{
	int val = a[low];
	while(low < high)//low��high��ȵĻ���ֹͣ
	{
		while(low < high && a[high] >= val)  //low��high��ȵĻ���ֹͣ����ֹ�����±�Խ�硣
			high--;
		a[low++] = a[high];//��ʱ��a[high]�൱��С��val�����Ը��Ƹ�a[low]�Ļ��Ͳ��ؽ���С��val���ж���
		while(low < high && a[low] <= val) //low��high��ȵĻ���ֹͣ����ֹ�����±�Խ�硣
			low++;
		a[high--] = a[low];//�������++��ͬ��ġ�
	}
	a[low] = val;  //��ʱ��low �� high �����ȣ���Ϊval��������ȷ�б�š�
	return low; //֮��������val����Ӧ��λ�÷�Ϊ���������У����õݹ�������н�������
}

void quitesort(int *a, int low, int high)
	//low ��ʾ�������Ԫ���±꣬high��ʾ�����βԪ���±�
{
	int pos;
	if( NULL == a || low > high)
	{
		cout<<"��������������Ҫ�󣬳����˳���"<<endl;
		return ;
	}
	if (low < high)//�������䳤�ȴ���1ʱ����Ҫ����
	{
		pos = findpos(a,low,high);
		cout<<"pos = "<<pos<<endl;
		quitesort(a,low,pos-1);
		quitesort(a,pos+1,high);
	}
}



int main()
{
	int a[5] = {0};
	cout<<"<������Ԫ�ؽ��и�ֵ��ʼ��>\n";
	for (int i = 0;i < 5; i++)
	{
		int temp;
		cout<<"a["<<i<<"]"<<" :";
		cin>>temp;
		a[i] = temp;
	}
	cout<<"---------------------------------\n";
	cout<<"����ǰ:";
	for (int i=0; i<5; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	time_t start = clock();
	quitesort(a,0,4);
	time_t end = clock();
	cout<<"�����:";
	for (int i=0; i<5; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	printf("the quicksort running time is : %f\n", double(end -start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
