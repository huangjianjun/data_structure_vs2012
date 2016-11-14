#include <iostream>
using namespace std;
#include <stdlib.h>
//基本思想：倒数第K个结点，若结点总数为N，则正向为第N-K+1个结点
//要求只能遍历一次的情况下，采用两个标记指针p1  p2
//开始先让p1从头结点正向移动k-1步，p2保持不动；p1和p2之间相差k-1步，当p1走到尾节点（N）时，p2所在的位置为
//N-(K-1)即N-K+1，直接输出该节点值。

//定义链表结点
typedef struct node
{
	int value;
	struct node* pnext;
}NODE, *PNODE;

void traverse(PNODE phead)
{
	PNODE p = phead->pnext;
	if(NULL == p)
		cout<<"链表为空！"<<endl;
	else
	{
		while(p)
		{
			cout<<p->value<<"  ";
			p = p->pnext;
		}
		cout<<endl;
	}
}

PNODE find_node(PNODE phead, int k)
{
	PNODE p1 = phead->pnext;
	PNODE p2 = NULL;
	if(phead == NULL || p1 == NULL || k <= 0)
		return phead;
	for(int i = 0; i < k-1; i++)
	{
		if(p1->pnext != NULL)//让p1指针前前进k-1位
			p1 = p1->pnext;
		else //当输入的K值大于链表的长度时，返回不对表聊表存储的头结点
		{
			return phead;
		}
	}
	p2 = phead->pnext;
	while(p1->pnext != NULL)
	{
		p1 = p1->pnext;
		p2 = p2->pnext;
	}
	return p2;
}
int main()
{
	int n;
	int k;
	char ch;
	do{
		PNODE tmp = NULL;
		cout<<"请输入要创建的链表的结点数n:";
		cin>>n;
		PNODE phead = (PNODE)malloc(sizeof(NODE));
		// 设置头结点，头结点不存储链表数据
		phead->value = -1;
		phead->pnext = NULL;
		// 填充链表
		PNODE ptail = phead;
		for(int i = 0; i < n; i++)
		{
			PNODE pnew = (PNODE)malloc(sizeof(NODE));
			pnew->value = i+1;
			pnew->pnext = NULL;
			ptail->pnext = pnew;
			ptail = pnew;
		}
		cout<<"新建的链表为：";
		traverse(phead);
		cout<<"请输入要查找的倒数第K个节点 k：";
		cin>>k;
		tmp = find_node(phead, k);
		cout<<"倒数第<"<<k<<">个结点值为："<<tmp->value<<endl;
		free(phead);
		cout<<"继续?(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}