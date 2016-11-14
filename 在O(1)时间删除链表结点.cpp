#include <iostream>
using namespace std;
#include <stdlib.h>

//����������
typedef struct node
{
	int value;
	struct node* pnext;
}NODE, *PNODE;

PNODE del_node(PNODE phead, PNODE pnode)
{
	PNODE q = phead->pnext;
	PNODE h = pnode->pnext;
	if(q != NULL && h != NULL)//ɾ���Ľ�㲻λ����β�ڵ㴦
	{
		PNODE p = pnode->pnext;
		int m = p->value;
		pnode->value = m;
		pnode->pnext = p->pnext;
		free(p);
	}
	if(q != NULL && h == NULL)//ɾ���Ľ��λ��β�ڵ�
	{
		if(q == pnode)//����ֻ��һ���ڵ�����
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
		cout<<"����Ϊ�գ�"<<endl;
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
		cout<<"������Ҫ����������Ľ����n:";
		cin>>n;
		PNODE phead = (PNODE)malloc(sizeof(NODE));
		// ����ͷ��㣬ͷ��㲻�洢��������
		phead->value = -1;
		phead->pnext = NULL;
		// �������
		PNODE ptail = phead;
		for(int i = 0; i < n; i++)
		{
			PNODE pnew = (PNODE)malloc(sizeof(NODE));
			pnew->value = i+1;
			pnew->pnext = NULL;
			ptail->pnext = pnew;
			ptail = pnew;
		}
		cout<<"�½�������Ϊ��";
		traverse(phead);
		cout<<"������Ҫɾ���Ľ���ֵ��";
		cin>>val;
		tmp = find_node(phead, val);
		del_node(phead, tmp);
		cout<<"ɾ�����������Ϊ��";
		traverse(phead);
		free(phead);
		cout<<"����?(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}