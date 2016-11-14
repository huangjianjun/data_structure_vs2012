#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//定义一个双向链表的结点
typedef struct Snode
{
	int data;
	struct Snode * previous;
	struct Snode * next;
	int position;
}SNODE,*PSNODE;

PSNODE create_slist_ziji(void)
{
	int len;
	int value;
	int count = 0;
	//首先建立一个头结点
	PSNODE phead = (PSNODE)malloc(sizeof(SNODE));
	if (NULL == phead)
	{
		cout<<"头结点动态内存分配失败，程序终止！";
		exit(-1);
	}
	phead->previous = NULL;
	PSNODE p = phead;
	
	//创建新的结点挂到头结点上
	cout<<"请您输入创建结点的个数：";
	cin>>len;
	cout<<"------------------------------\n";
	for (int i = 0;i < len;i ++)
	{
		cout<<"第"<<i+1<<"个结点的值(整型值)：";
		cin>>value;
		PSNODE pnew = (PSNODE)malloc(sizeof(SNODE));
		if (NULL == pnew)
		{
			cout<<"新结点动态内存分配失败，程序终止！";
			exit(-1);
		}
		pnew->next = NULL;//双向链表的为节点的指针没有指向
		pnew->data = value;
		pnew->position = i + 1;
		p->next = pnew;
		pnew->previous = p;
		p = p->next;
		count++;
	}
	cout<<"所建链表的长度为："<<count<<endl<<endl;
	return phead;

}
void traverse_list(PSNODE phead)
{
	PSNODE pindex = phead->next;
	cout<<"链表遍历开始......\n";
	while(pindex != NULL)
	{
		cout<<pindex->data<<"\t";
		pindex = pindex->next;
	}
	cout<<"\n链表遍历完成！\n";
	return ;
}
int is_length(PSNODE phead)
{
	int len = 0;
	PSNODE p = phead->next;
	while (NULL != p)
	{
		len++;
		p = p ->next;
	}
	return len;
}
//在pos结点上插入一个节点，其余结点向后移动
bool insert_list_ziji(PSNODE phead, int pos, int val)
{
	if (pos <= 0 || pos > is_length(phead))
	{
		cout<<"输入的插入结点位置不合要求,插入失败！\n";
		system("pause");
		return false;
	}
	PSNODE p = phead;
	int i = 0;
	while(NULL != p && i < pos - 1)// 循环结束后P指向pos-1结点
	{
		p = p->next;
		i ++;
	}
	PSNODE pnew = (PSNODE)malloc(sizeof(SNODE));
	if (NULL == pnew)
	{
		cout<<"新结点动态内存分配失败，程序终止！";
		return false;
		exit(-1);
		system("pause");
	}
	pnew->data = val;
	pnew->next = p->next;
	p->next->previous = pnew;
	pnew->previous = p;
	p->next = pnew;
	cout<<"插入结点的位置："<<pos<<"\t"<<"插入值："<<pnew->data<<endl;
	return true;
}


int main()
{
	PSNODE phead;
	phead = create_slist_ziji();
	traverse_list(phead);
//	insert_list_ziji(phead,2,800);
//	traverse_list(phead);
	system("pause");
	return 0;
}
