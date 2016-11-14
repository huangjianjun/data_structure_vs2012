//����ջ�Լ�ģ��ջ�ĸ��ֲ���
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
//��̬ջ������Ϊ�ں˴洢�ṹ
typedef struct node
{
	int data;
	struct node *pnext;
}NODE,* PNODE;

typedef struct stack
{
	PNODE ptop;
	PNODE pbottom;
}STACK, * PSTACK;

void init(PSTACK pst)
{
	pst->ptop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pst->ptop)
	{
		cout<<"�½ڵ��ڴ����ʧ�ܣ�";
		system("pause");
	}
	pst->pbottom = pst->ptop;
	pst->ptop->pnext = NULL;
}

bool is_empty_stack(PSTACK pst)
{
	if (pst->ptop == pst->pbottom)
		return true;
	else
		return false;
}

void push(PSTACK pst, int val)//ջΪ����ָ�򣬼�����ջ�Ľ��ָ��֮ǰ��ջ��λ�á�
{
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pnew)
	{
		cout<<"�½ڵ��ڴ����ʧ�ܣ�";
		system("pause");
	}

	pnew->data = val;
	pnew->pnext = pst->ptop;//�½ڵ��ָ��ָ��ԭ����ջ��λ��
	pst->ptop = pnew;//��ջ����λ���޸�Ϊ�½ڵ�ĵ�ֵַ
}
//ÿ�ν�ջ��Ԫ�س�ջ����ջԪ�ص�ֵ��������value
bool pop(PSTACK pst, int value)
{
	if (is_empty_stack(pst))
	{
		cout<<"ջΪ�գ���ջ����ʧ�ܣ�\n";
		return false;
	}
	else
	{
		PNODE r = pst->ptop;
		value = r->data;
		pst->ptop = r->pnext; //�޸�ջ��ptop��ֵ
		free(r);
		cout<<"��ջ�ɹ�����ջ��Ԫ�أ�"<<value<<endl;
		return true;
	}
}

bool forced_pop(PSTACK pst)// �ڸó�ջֵ֮ǰ��ǰȫ����ջ
{
	int value;
	if (is_empty_stack(pst))
	{
		cout<<"ջΪ�գ���ջ����ʧ�ܣ�\n";
		return false;
	}
	else
	{
		PNODE r = pst->ptop;
		PNODE temp = NULL;
		cout<<"������Ҫǿ�Ƴ�ջ��ֵ:";
		cin>>value;
		while(r != pst->pbottom)
		{
			if (r->data == value)
			{
				pst->ptop = r->pnext;
				break;
			}
			temp = r->pnext;
			free(r);
			r = temp;
		}
		cout<<"ǿ�Ƴ�ջ�ɹ�����ջ��Ԫ�أ�"<<value<<endl;
		return true;
	}
}

void traverse(PSTACK pst)
{
	cout<<"��ջ���б���:";
	PNODE p = pst->ptop;
	if(p == pst->pbottom)
	{
		cout<<"ջΪ�գ�\n";
	}
	else
	{
		while(pst->pbottom != p)
		{
			cout<<p->data<<"    ";
			p = p->pnext;
		}
		cout<<"\n";
	}


}
void clear_stack(PSTACK pst)//ջ���ڣ�ֻ�����е����ݱ�����ˣ��൱�ڶ�ջ���г�ʼ������
{
	if (is_empty_stack(pst))
	{
		cout<<"����Ϊ�գ����ý���clear������\n";
	}
	else
	{
		PNODE p = pst->ptop;
		PNODE q = NULL;
		while(p != pst->pbottom)
		{
			q = p->pnext;
			free(p);
			p = q;
		}
		pst->ptop = pst->pbottom;
	}	
}


int main()
{
	STACK s;
	int re = 0 ;
	cout<<"ջ�ĳ�ʼ��������һ����ջ\n";
	init(&s);
	traverse(&s);
	cout<<"����ѹջ����\n";
	push(&s,23);
	push(&s,245);
	push(&s,456);
	push(&s,100);
	push(&s,12);
	traverse(&s);
	cout<<"���г�ջ����\n";
	pop(&s,re);
	traverse(&s);
	cout<<"����ǿ�Ƴ�ջ����\n";
	forced_pop(&s);
	traverse(&s);
	cout<<"����ջ����ղ���\n";
	clear_stack(&s);
	traverse(&s);
	system("pause");
	return 0;
}

