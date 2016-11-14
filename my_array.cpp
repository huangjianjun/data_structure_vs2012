#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
//定义一个结构体的数据类型
struct Arr
{
	int *pbase;//存数数组第一个元素的地址
	int len;//数组所能容纳元素的最大个数
	int cnt;//当前数组有效元素的个数
};
void init_arr(struct Arr *pArr, int length);//初始化
bool append_arr(struct Arr *pArr, int value);//追加
bool insert_arr(struct Arr *pArr, int index , int value);//插入
bool delete_arr(struct Arr *pArr, int index );//删除
bool is_empty(struct Arr *pArr);//是否为空
bool is_full();//是否为满
void sort_arr(struct Arr *pArr);//排序
void show_arr(struct Arr *pArr);//显示打印
//void inversion_arr();//倒置


void init_arr(struct Arr *pArr, int length)
{
	pArr->pbase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pbase)
	{
		cout<<"malloc动态内存分配失败！";
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
		for (int i = 0; i < pArr->len ; i ++)
			pArr->pbase[i] = 0;
	}
	return;
}
bool is_empty(struct Arr *pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}
void show_arr(struct Arr *pArr)
{
	//bool is_empty(struct Arr *pArr);
	//if (is_empty(pArr))
	if (0 == pArr->cnt)
		cout<<"要输出的数组为空！"<<endl;
	else
	{
		for (int i = 0; i < pArr->len; i ++)
			cout<<pArr->pbase[i]<<"\t";
	}
	cout<<"\n";
}
bool append_arr(struct Arr *pArr, int value)
{
	//cout<<pArr->len<<endl;
	//cout<<pArr->cnt<<endl;
	if ( pArr->len == pArr->cnt)
	{
		cout<<"数组长度已满，不能继续追加！";
		return false;
	}
		
	else
	{
		pArr->pbase[pArr->cnt] = value;
		pArr->cnt += 1;
		return true;

	}
}

bool insert_arr(struct Arr *pArr, int index , int value)
{
	if (index >= pArr->len)
	{
		cout<<"索引下标越界！";
		return false;
	}
	else if(pArr->cnt == pArr->len)
	{
		cout<<"数组已满，不能插入元素！";
		return false;
	}
	else
	{
		cout<<"您插入的元素为："<<value<<endl;
		//for (int i = 1 ;i < pArr->len - 1 - index ; i ++)
		for (int i = pArr->len - 1 - index ; i >=1 ; i --)
		{
			pArr->pbase[index + i] = pArr->pbase[index + i - 1];
		}
		pArr->pbase[index] = value;
		pArr->cnt += 1;
		return true;
	}
}
bool delete_arr(struct Arr *pArr, int index )
{
	if (0 == pArr->cnt)
	{
		cout<<"数组为空，不能进行删除操作！"<<endl;
		return false;
	}
	else
	{
		int i = 0;
		cout<<"您删除的元素为："<<pArr->pbase[index]<<endl;
		for (i = 0 ;i < pArr->len - 1 - index ; i ++)
		{
			pArr->pbase[index + i] = pArr->pbase[index + i + 1];
		}
		pArr->pbase[index + i - 1] = 0;
		return true;
	}
	
}
void sort_arr(struct Arr *pArr)
{
	cout<<"数组从大到小排序为："<<endl;
	int i , j , temp;
	for (i = 0; i < pArr->cnt; i ++)
	{
		for (j = i + 1; j < pArr->cnt; j ++)
		{
			if (pArr->pbase[i] <= pArr->pbase[j])
			{
				temp = pArr->pbase[i];
				pArr->pbase[i] = pArr->pbase[j];
				pArr->pbase[j] = temp;
			}
		}
	}
}
int main()
{
	struct Arr arr;
	int length = 10;
	init_arr(&arr,length);
	append_arr(&arr,18);
	append_arr(&arr,20);
	append_arr(&arr,30);
	append_arr(&arr,40);
	show_arr(&arr);
	//insert_arr(&arr,7,50);
	insert_arr(&arr,1,50);
	show_arr(&arr);
	delete_arr(&arr,2);
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	system("pause");
	return 0;
}
