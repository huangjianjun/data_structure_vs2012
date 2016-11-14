#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;//数据域
	struct node *pnext;//指针域
}NODE,* PNODE;//NODE等价于struct node 类型, PNODE等价于struct node *类型
//函数的申明
void traverse_list(PNODE phead);
PNODE create_list(void);
bool is_empty_list(PNODE phead);
int find_list(PNODE phead, int x);
bool delete_list_ziji(PNODE phead, int pos, int *remove);
bool insert_list_ziji(PNODE phead, int pos, int value);//在 pos节点前插入一个新的结点
bool insert_list_shipin(PNODE phead, int pos, int value);//在 pos节点前插入一个新的结点
int length(PNODE phead);
void sort_list(PNODE phead);

bool is_empty_list(PNODE phead)
{
	if (NULL == phead->pnext)
	{
		cout<<"该链表为空链表！"<<endl;
		return true;
	}
	else
		return false;
}
int length(PNODE phead)
{
	int count = 0;
	PNODE p = phead;
	while(p->pnext != NULL)
	{
		count++;
		p = p->pnext;
	}
	return count;
}
bool insert_list_ziji(PNODE phead, int pos, int value)
{
	cout<<"调用insert_list_ziji函数进行链表插入操作"<<endl;
	if (length(phead) < pos)//判断链表长度与插入位置的关系
	{
		cout<<"插入点位置大于链表的长度，无法插入！"<<endl;
		return false;
	}
	if (pos < 1)//判断链表插入位置pos的值必须大于等于1
	{
		cout<<"pos 的值必须大于等于1！"<<endl;
		return false;
	}
		
	else
	{
		int count = 0;
		PNODE p = phead;
		PNODE p1 = phead;//记录插入位置的前一个结点位置
		PNODE p2 = phead;//记录插入位置的后一个结点位置
		if (pos < 1)
		{
			cout<<"pos 的值给的不正确,程序终止！";
			system("pause");
			exit(-1);

		}
		while(count != pos && pos >=1)
		{
			if (count == pos-1)
			{
				p1 = p;
			}
			p = p->pnext;
			count++;
		}
		p2 = p;
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pnew)
		{
			cout<<"分配插入结点内存时出错，程序终止！";
			exit(-1);
		}
		pnew->data = value;
		//结点的插入操作
		pnew->pnext =  p2;
		p1->pnext = pnew;
		cout<<"插入的结点："<<pos<<"\t"<<"插入的值为："<<value<<endl;
		return true;
	}
	
}
bool insert_list_shipin(PNODE phead, int pos, int value)
{
	cout<<"调用insert_list_shipin函数进行链表插入操作"<<endl;
	int i = 0 ;
	PNODE p = phead;
	if (i > pos - 1 || NULL == p)
		return false;
	while(NULL != p && i < pos - 1)
	{
		p = p -> pnext;
		i ++;
	}
	//循环结束后P指向pos-1结点，下面进行新节点的插入
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pnew)
	{
		cout<<"新节点动态内存分配失败，程序终止！";
		exit(-1);
	}
	pnew->data = value;
	pnew->pnext = p->pnext;
	p->pnext = pnew;
	cout<<"插入的结点位置："<<pos<<"\t"<<"插入的值为："<<value<<endl;
	return true;

}
bool delete_list_ziji(PNODE phead, int pos, int *remove)
{
	if (length(phead) < pos)//判断链表长度与删除位置的关系
	{
		cout<<"删除点位置大于链表的长度，无法删除！";
		return false;
	}
		
	else
	{
		int count = 0;//初始值不同主要用来控制循环次数。
		PNODE p = phead->pnext;
		PNODE p3 = phead;//记录pos结点的位置
		PNODE p1 = phead;//记录插入位置的前一个结点位置
		PNODE p2 = phead;//记录插入位置的后一个结点位置
		//while(count != pos + 1 )
		while(count < pos )
		{
			if (count == pos-2)
			{
				p1 = p;
			}
			if (count == pos-1)
			{
				p3 = p;
			}
			p = p->pnext;
			count++;
		}
		p2 = p;
		PNODE r = p3;
		p1->pnext = p3->pnext;
		remove = (int *)p3;
		cout<<"删除的结点为："<<pos<<endl;
		cout<<"删除结点上储存的值为："<<p3->data<<endl;
		free(r);
		return true;
	}
}
void sort_list(PNODE phead)
{
	PNODE p = phead->pnext;
	int len = length(phead);
	int a[100] = {0};
	int temp;
	
	for (int i = 0; i < len; i ++)
	{
		if (NULL != p)
		{
			a[i] = p->data;
		}
		p = p->pnext;
	}
	
	//对链表进行从大到小排序
	for (int j = 0; j < len; j ++)
	{
		for (int k = j + 1; k < len; k ++)
		{
			if (a[j] <= a[k])
			{
				temp = a[j];
				a[j] = a[k];
				a[k] = temp;
			}
		}
	}
	cout<<"链表从大到小的排列顺序为(总长度为："<<len<<")"<<endl;
	for (int i = 0; i < len; i++ )
		cout<<a[i]<<"\t";
	cout<<"\n";
	return ;

}
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
void traverse_list(PNODE phead)
{
	PNODE pindex = phead->pnext;
	cout<<"链表遍历开始......\n";
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
	int *val = NULL;
	phead = create_list();//创建一个费循环单链表
	if (is_empty_list(phead))
	{
		cout<<"列表为空！";
	}
	traverse_list(phead);

	delete_list_ziji(phead, 3, val);
	traverse_list(phead);
	insert_list_shipin(phead, 2, 800);
	traverse_list(phead);
	insert_list_ziji(phead, 4, 700);
	traverse_list(phead);
	sort_list(phead);
	system("pause");
	return 0;
}