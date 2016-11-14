#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int len;
	cout<<"请输入您要创建的内存的大小：";
	cin>>len;
	int *paddr = (int *)malloc(sizeof(int) * len);//利用malloc函数动态分配内存
	for (int i = 0;i < len; i ++)
	{
		paddr[i] = i;//我们可以吧paddr当做一个普通数组来用。
	}
	for (int j = 0; j < len; j ++)
	{
		printf("%d\n",paddr[j]);
	}
	free(paddr);//释放动态分配的内存
	system("pause");
	return 0;
}