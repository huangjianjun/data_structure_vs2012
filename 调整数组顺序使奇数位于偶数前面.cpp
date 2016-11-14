#include <iostream>
using namespace std;
#include <stdlib.h>

void traverse(int * num, int length)
{
	if(length == 0)
		cout<<"����Ϊ�գ�"<<endl;
	else
	{
		for(int j = 0; j < length; j++)
		{
			cout<<num[j]<<"  ";
		}
	}
	cout<<endl;
}
//����˼�룺����ά������ָ�룬��һ��ָ���ʼ��ʱָ������ĵ�һ�����֣���ֻ����ƶ���
//�ڶ���ָ���ʼ��ʱָ����������һ�����֣���ֻ��ǰ�ƶ���������ָ������֮ǰ��
//��һ��ָ������λ�ڵڶ���ָ���ǰ�档�����һ��ָ��ָ�������Ϊż�������ҵڶ���ָ��ָ������������������Ǿͽ������������֡�
void ji_qian_and_ou_hou(int *num,int length)
{
	int low = 0;
	int tmp;
	int high = length-1;
	while(low < high)
	{
		while(low < high && num[low] % 2 == 1)
			low++;
		while(low < high && num[high] % 2 == 0)
			high--;
		if(low < high && num[low] % 2 == 0 && num[high] % 2 == 1)
		{
			tmp = num[high];
			num[high] = num[low];
			num[low] = tmp;
		}
	}
}
int main()
{
	int n ;
	char ch;
	do{
		cout<<"�����봴�����ĳ���n:";
		cin>>n;
		int *num = (int *)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
		{
			num[i] = i + 1;
		}
		cout<<"�½�������Ϊ��";
		traverse(num,n);
		ji_qian_and_ou_hou(num,n);
		cout<<"����������Ϊ��";
		traverse(num,n);
		free(num);
		cout<<"����(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}