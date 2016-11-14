#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;//数据域
	struct node *pnext;//指针域
}NODE,* PNODE;//NODE等价于struct node 类型, PNODE等价于struct node *类型

PNODE create_list(void)
{
	int val;
	int len ;//链表节点的个数
	PNODE phead = (PNODE)malloc(sizeof(NODE));//创建头结点，该结点不存储任何有效数据
	if (NULL == phead)
	{
		cout<<"头结点内存分配失败，程序终止！";
		exit(-1);
	}
	PNODE ptail = phead;//定义一个始终指向链表末尾的结点指针ptail
	ptail->pnext = NULL;//避免当len 为0时，没有有效结点个数时，指针域悬空。
	cout<<"请您输入所要创建的非循环单链表的结点个数：";
	cin>>len;
	for (int i = 0; i < len ; i++)
	{
		cout<<"请输入第"<<i+1<<"个链表结点的值(整型)：";
		cin>>val;
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		if (NULL == phead)
		{
			cout<<"结点内存分配失败，程序终止！";
			exit(-1);
		}
		else
		{
			pnew->data = val;
			pnew->pnext = NULL;
			ptail->pnext = pnew;
			ptail = pnew;
		}
	}
	return phead;
}
void traverse_list(PNODE phead)
{
	if (phead == NULL)
		return;
	PNODE pindex = phead->pnext;
	while(pindex != NULL)
	{
		cout<<pindex->data<<"\t";
		pindex = pindex->pnext;
	}
	cout<<"\n链表遍历完成！\n";
	return ;
}
int main()
{
	PNODE phead = NULL;
	phead = create_list();//创建一个循环单链表
	traverse_list(phead);
	system("pause");
	return 0;
}