#include<iostream>
using namespace std;
#include<stdlib.h>

//定义节点
typedef struct node
{
	int data;
	int pos;
	struct node* pnext;
}NODE, *PNODE;

//定义栈
typedef struct stack
{
	PNODE ptop;
	PNODE pbottom;
}STACK, *PSTACK;

PSTACK creat()//省去了对创建指针为空的判断！！
{
	PSTACK psta = (PSTACK)malloc(sizeof(STACK));
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->data = -100;
	pnew->pos = 0;
	pnew->pnext = NULL;
	psta->ptop = pnew;
	psta->pbottom = pnew;
	return psta;
}

void stack_push(PSTACK psta)
{
	int val;
	cout<<"请输入要压栈的值：";
	cin>>val;
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->data = val;
	pnew->pos = psta->ptop->pos + 1;
	pnew->pnext = NULL;
	psta->ptop->pnext = pnew;
	psta->ptop = pnew;
}
void stack_pop(PSTACK psta)
{
	int n;
	int val;
	PNODE p = NULL;
	PNODE q = NULL;
	if(psta->ptop == psta->pbottom)
	{
		cout<<"栈为空！";
		return;
	}
	else
	{
		p = psta->ptop;
		val = p->data;
		n = p->pos;
		q = psta->pbottom->pnext;
		if(p == q)//此时
		{
			val = p->data;
			psta->pbottom = psta->ptop = NULL;
			free(p);
		}
		else
		{
			while(NULL != q && q->pos != n - 1)
			{
				q = q->pnext;
			}
			q->pnext = NULL;
			psta->ptop = q;
			free(p);
		}	
	}
	cout<<"出栈的节点值为: "<<val<<", 节点编号为： "<<n<<endl;
	return;
}
void traverse(PSTACK psta)
{
	if(psta->pbottom == psta->ptop)
	{
		cout<<"此时栈为空！"<<endl;
		system("pause");
		return;
	}
	PNODE p = psta->pbottom->pnext;
	cout<<"此时的栈为:";
	while(NULL != p)
	{
		cout<<p->data<<"	";
		p = p->pnext;
	}
	cout<<endl;
	return ;
}
int main()
{
	int n;
	PSTACK phead = creat();
	cout<<"输入模拟压栈操作的次数：";
	cin>>n;
	for(int i = 0; i < n; i++ )
	{
		stack_push(phead);
		traverse(phead);
	}
	cout<<"输入模拟出栈操作的次数：";
	cin>>n;
	for(int i = 0; i < n; i++ )
	{
		stack_pop(phead);
		traverse(phead);
	}
	system("pause");
	return 0;
}