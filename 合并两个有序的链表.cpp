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
	cout<<"请您输入所要创建单链表的结点个数：";
	cin>>len;
	for (int i = 0; i < len ; i++)
	{
		cout<<"请输入第"<<i+1<<"个链表结点的值(整型)：";
		cin>>val;
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pnew)
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

PNODE creat_newnode_copy(PNODE p, PNODE pnode)
{
	PNODE ptail = p;
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->pnext = NULL;
	pnew->data = pnode->data;
	ptail->pnext = pnew;
	ptail = pnew;
	return ptail;
}

PNODE merge(PNODE phead1, PNODE phead2,PNODE pmerge_head)//合并两个有序的链表
{
	PNODE p1 = phead1->pnext;
	PNODE p2 = phead2->pnext;
	PNODE ptail = pmerge_head;
	ptail->pnext = NULL;
	if(p1 == NULL && p2 == NULL) return NULL;//只是返回不代表节点值的头指针。
	if(p1 == NULL) return phead2;
	if(p2 == NULL) return phead1;
	while(p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			ptail = creat_newnode_copy(ptail, p1);
			p1 = p1->pnext;	
		}
		else
		{
			ptail = creat_newnode_copy(ptail, p2);
			p2 = p2->pnext;
		}	
	}
	if (p1 == NULL)  //检验while循环退出后链表剩余的情况
	{
		while(p2 != NULL)
		{
			ptail = creat_newnode_copy(ptail, p2);
			p2 = p2->pnext;
		}
	}
	if (p2 == NULL)
	{
		while(p1 != NULL)
		{
			ptail = creat_newnode_copy(ptail, p1);
			p1 = p1->pnext;
		}
	}
	if(p1 == NULL && p2 == NULL)
		return pmerge_head;
	return pmerge_head;
}
void traverse_list(PNODE phead)
{
	if(phead == NULL)
	{
		cout<<"链表为空！"<<endl;
		return ;
	}
	if(phead->pnext == NULL)
	{
		cout<<"链表为空！"<<endl;
		return ;
	}
	PNODE pindex = phead->pnext;
	while(pindex != NULL)
	{
		cout<<pindex->data<<"  ";
		pindex = pindex->pnext;
	}
	cout<<endl;
}
int main()
{
	char ch;
	do{
		PNODE pmerge_head = (PNODE)malloc(sizeof(NODE));
		pmerge_head->pnext = NULL;
		pmerge_head->data = -1;
		PNODE phead1 = create_list();
		cout<<"创建的第一个有序链表：";
		traverse_list(phead1);
		PNODE phead2 = create_list();
		cout<<"创建的第二个有序链表：";
		traverse_list(phead2);
		PNODE phead = merge(phead1, phead2, pmerge_head);
		cout<<"合并之后的有序链表：";
		traverse_list(phead);
		free(phead);
		cout<<"继续？（y/n）:";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}
//总结：两个有序链表合并，采用分别取两个链表的节点值进行比较，升序中将节点值小的连接到新建的链表中，以此类推；
//若某一个链表遍历完后另一个链表仍有剩余，则将剩余的结点值直接拷贝到合并链表的尾部，因为提前结束的那个链表的所有结点值都已经与没有结束的那个链表的已经遍历过的结点值进行了比较，因为均为有序链表，所以剩余节点值可以直接拷贝到合并链表的尾部。
//若某一个链表为空，则直接返回另一个链表。