#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int len;
	cout<<"��������Ҫ�������ڴ�Ĵ�С��";
	cin>>len;
	int *paddr = (int *)malloc(sizeof(int) * len);//����malloc������̬�����ڴ�
	for (int i = 0;i < len; i ++)
	{
		paddr[i] = i;//���ǿ��԰�paddr����һ����ͨ�������á�
	}
	for (int j = 0; j < len; j ++)
	{
		printf("%d\n",paddr[j]);
	}
	free(paddr);//�ͷŶ�̬������ڴ�
	system("pause");
	return 0;
}