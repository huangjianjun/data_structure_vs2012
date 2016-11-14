#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

//采用循环来实现阶乘的算法
void xunhuan_jiecheng()
{
	int mul = 1;
	int value;
	cout<<"请输入阶乘数（采用循环实现）:";
	cin>>value;
	if (value == 0)
		cout<<value<<"的阶乘为:"<<mul<<endl;

	for ( int i = 1; i <= value; i++)
	{
		mul = mul * i;
	}
	cout<<value<<"的阶乘为:"<<mul<<endl;
}

//采用递归方法来实现
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
		cout<<"请输入阶乘数（采用递归实现）:";
		cin>>value;
		re = digui_jiecheng(value);
		cout<<value<<"的阶乘为:"<<re<<endl;
		cout<<"继续计算吗?(y/n) : ";
		cin>>s;
		}while(s != 'n');
	
	system("pause");
	return 0;
}
