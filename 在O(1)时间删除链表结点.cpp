#include <iostream>
using namespace std;
#include <stdlib.h>

//定义链表结点
typedef struct node
{
	int value;
	struct node* pnext;
}NODE, *PNODE;

PNODE del_node(PNODE phead, PNODE pnode)
{
	PNODE q = phead->pnext;
	PNODE h = pnode->pnext;
	if(q != NULL && h != NULL)//删除的结点不位于首尾节点处
	{
		PNODE p = pnode->pnext;
		int m = p->value;
		pnode->value = m;
		pnode->pnext = p->pnext;
		free(p);
	}
	if(q != NULL && h == NULL)//删除的结点位于尾节点
	{
		if(q == pnode)//链表只有一个节点的情况
		{
			free(pnode);
			phead->pnext = NULL;
		}
		else
		{
			while(q)
			{
				if( q->pnext  == pnode)
				{
					q->pnext = pnode->pnext;
					free(pnode);
				}
				q = q->pnext;
			}
		}
	}
	return phead;
}

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
PNODE find_node(PNODE phead, int value)
{
	PNODE p = phead->pnext;
	while(p)
	{
		if(p->value == value)
			break;
		p = p->pnext;
	}
	return p;
}
int main()
{
	int n;
	int val;
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
		cout<<"请输入要删除的结点的值：";
		cin>>val;
		tmp = find_node(phead, val);
		del_node(phead, tmp);
		cout<<"删除结点后的链表为：";
		traverse(phead);
		free(phead);
		cout<<"继续?(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}