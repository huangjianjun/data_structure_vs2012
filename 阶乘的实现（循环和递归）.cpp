#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

//����ѭ����ʵ�ֽ׳˵��㷨
void xunhuan_jiecheng()
{
	int mul = 1;
	int value;
	cout<<"������׳���������ѭ��ʵ�֣�:";
	cin>>value;
	if (value == 0)
		cout<<value<<"�Ľ׳�Ϊ:"<<mul<<endl;

	for ( int i = 1; i <= value; i++)
	{
		mul = mul * i;
	}
	cout<<value<<"�Ľ׳�Ϊ:"<<mul<<endl;
}

//���õݹ鷽����ʵ��
int digui_jiecheng(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return digui_jiecheng(n - 1) * n;
}

int main()
{
	int value,re;
	char s;
	do{
		xunhuan_jiecheng();
		cout<<"������׳��������õݹ�ʵ�֣�:";
		cin>>value;
		re = digui_jiecheng(value);
		cout<<value<<"�Ľ׳�Ϊ:"<<re<<endl;
		cout<<"����������?(y/n) : ";
		cin>>s;
		}while(s != 'n');
	
	system("pause");
	return 0;
}
