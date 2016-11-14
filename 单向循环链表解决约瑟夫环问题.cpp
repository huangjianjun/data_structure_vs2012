#include<iostream>
using namespace std;
#include<stdlib.h>
//问题描述：
//已知N个人（编号依次为1，2，~~~,N）围坐在一张圆桌周围，从编号为k的人开始报数，输到m的那个人出列，
//它的下一个人有从k开始报数，数到m 的那个人在出列，以此类推，直到圆桌上的人全部出列。
//该问题典型的采用循环链表来模仿整个过程。

typedef struct node
{
	int data;
	struct node *pnext;
}NODE,*PNODE;
//首先创建一个循环链表
PNODE creat()
{
	int n;
	PNODE phead = (PNODE)malloc(sizeof(NODE));
	phead->pnext = NULL;
	PNODE p = phead;
	phead->data = 1;
	cout<<"输入创建的循环链表的长度（即人数）：";
	cin>>n;
	for(int i = 2; i <= n; i++)
	{
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		pnew->data = i;
		p->pnext = pnew;
		pnew->pnext = NULL;
		p = p->pnext;
	}
	p->pnext = phead;
	return phead;
}

void resule_process(PNODE phead,int k, int m)
{
	PNODE temp = NULL;//辅助指针，指向k的前一个结点
	PNODE p = phead;
	while(k != p->data)
	{
		p = p->pnext;
	}
	while(p->pnext != p)//判断链表是否只剩一个节点的情况
	{
		for(int i = 0; i < m-1; i++)
		{
			temp = p;
			p = p->pnext;
		}
		cout<<"出列的值为："<<p->data<<endl;
		temp->pnext = p->pnext;
		free(p);
		p = temp->pnext;
	}
		
	cout<<"出列的值为："<<p->data<<endl;
	free(p);
}


int main()
{
	PNODE phead = creat();
	resule_process(phead,1,2);
	system("pause");
	return 0;
}

