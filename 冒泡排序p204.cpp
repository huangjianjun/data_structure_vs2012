#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//假定在待排序的记录序列中，存在多个具有相同的关键字的记录，若经过排序，这些记录的相对次序保持不变，即在原序列中，ri=rj，且ri在rj之前，而在排序后的序列中，ri仍在rj之前，则称这种排序算法是稳定的；否则称为不稳定的。

//冒泡排序采用相邻两个数值进行比较，直到最小的值冒到第一个位置，完后依次循环进行剩下的无序元素的排序
int maopao_sort(int *a, int n)
{
	int temp;
	int m = 0;//表示交换的次数
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
	cout<<"<对数组元素进行赋值初始化>\n";
	for (int i = 0;i < 8; i++)
	{
		int temp;
		cout<<"a["<<i<<"]"<<" :";
		cin>>temp;
		a[i] = temp;
	}
	cout<<"---------------------------------\n";
	cout<<"排序前:";
	for (int i=0; i<8; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	time_t start = clock();
	num = maopao_sort(a, 8);
	time_t end = clock();
	cout<<"排序后:";
	for (int i=0; i<8; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	cout<<"此排序共交换数值次数为："<<num<<endl;
	printf("the maopao running time is : %f\n", double(end -start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
