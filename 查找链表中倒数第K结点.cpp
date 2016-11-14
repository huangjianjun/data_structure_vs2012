#include <iostream>
using namespace std;
#include <stdlib.h>
//����˼�룺������K����㣬���������ΪN��������Ϊ��N-K+1�����
//Ҫ��ֻ�ܱ���һ�ε�����£������������ָ��p1  p2
//��ʼ����p1��ͷ��������ƶ�k-1����p2���ֲ�����p1��p2֮�����k-1������p1�ߵ�β�ڵ㣨N��ʱ��p2���ڵ�λ��Ϊ
//N-(K-1)��N-K+1��ֱ������ýڵ�ֵ��

//����������
typedef struct node
{
	int value;
	struct node* pnext;
}NODE, *PNODE;

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

PNODE find_node(PNODE phead, int k)
{
	PNODE p1 = phead->pnext;
	PNODE p2 = NULL;
	if(phead == NULL || p1 == NULL || k <= 0)
		return phead;
	for(int i = 0; i < k-1; i++)
	{
		if(p1->pnext != NULL)//��p1ָ��ǰǰ��k-1λ
			p1 = p1->pnext;
		else //�������Kֵ��������ĳ���ʱ�����ز��Ա��ı�洢��ͷ���
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
		cout<<"������Ҫ���ҵĵ�����K���ڵ� k��";
		cin>>k;
		tmp = find_node(phead, k);
		cout<<"������<"<<k<<">�����ֵΪ��"<<tmp->value<<endl;
		free(phead);
		cout<<"����?(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}