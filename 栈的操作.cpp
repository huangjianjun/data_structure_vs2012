#include<iostream>
using namespace std;
#include<stdlib.h>

//����ڵ�
typedef struct node
{
	int data;
	int pos;
	struct node* pnext;
}NODE, *PNODE;

//����ջ
typedef struct stack
{
	PNODE ptop;
	PNODE pbottom;
}STACK, *PSTACK;

PSTACK creat()//ʡȥ�˶Դ���ָ��Ϊ�յ��жϣ���
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
	cout<<"������Ҫѹջ��ֵ��";
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
		cout<<"ջΪ�գ�";
		return;
	}
	else
	{
		p = psta->ptop;
		val = p->data;
		n = p->pos;
		q = psta->pbottom->pnext;
		if(p == q)//��ʱ
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
	cout<<"��ջ�Ľڵ�ֵΪ: "<<val<<", �ڵ���Ϊ�� "<<n<<endl;
	return;
}
void traverse(PSTACK psta)
{
	if(psta->pbottom == psta->ptop)
	{
		cout<<"��ʱջΪ�գ�"<<endl;
		system("pause");
		return;
	}
	PNODE p = psta->pbottom->pnext;
	cout<<"��ʱ��ջΪ:";
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
	cout<<"����ģ��ѹջ�����Ĵ�����";
	cin>>n;
	for(int i = 0; i < n; i++ )
	{
		stack_push(phead);
		traverse(phead);
	}
	cout<<"����ģ���ջ�����Ĵ�����";
	cin>>n;
	for(int i = 0; i < n; i++ )
	{
		stack_pop(phead);
		traverse(phead);
	}
	system("pause");
	return 0;
}