//����ջ�Լ�ģ��ջ�ĸ��ֲ���
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
//��̬ջ������Ϊ�ں˴洢�ṹ
typedef struct node
{
	int data;
	int postion;
	struct node *pnext;
}NODE,* PNODE;

typedef struct stack
{
	PNODE ptop;
	PNODE pbottom;
}STACK, * PSTACK;

PSTACK create_stack(void)
{
	int len;
	PNODE phead = (PNODE)malloc(sizeof(NODE));
	phead->pnext = NULL;
	phead->postion = 0;
	if (NULL == phead)
	{
		cout<<"ͷ��㶯̬�ڴ����ʧ�ܣ�";
		system("pause");
	}
	PSTACK psta = (PSTACK)malloc(sizeof(STACK));
	if (NULL == psta)
	{
		cout<<"ջָ���ڴ����ʧ�ܣ�";
		system("pause");
	}
	psta->pbottom = phead;
	psta->ptop = phead;
	//�����µĽ��ҵ�ͷ�����
	cout<<"�������봴�����ĸ�����";
	cin>>len;
	cout<<"------------------------------\n";
	for (int i = 0;i < len;i ++)
	{
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pnew)
		{
			cout<<"�½�㶯̬�ڴ����ʧ�ܣ�";
			system("pause");
		}
		//ջ�Ĵ洢ֵĬ��Ϊ0
		pnew->data = 0;
		pnew->pnext = NULL;
		pnew->postion= i + 1;
		psta->ptop->pnext = pnew;
		psta->ptop = pnew;
		cout<<psta->ptop->postion<<endl;
	}
	return psta;
}

void traverse_stack(PSTACK pstack)
{
	PNODE p = pstack->pbottom->pnext;
	cout<<"ջ���ı�����";
	while(NULL != p)
	{
		cout<<p->data<<"\t";
		p = p->pnext;
	}
	cout<<"\n";
	return ;
}

void stack_push(PSTACK pstack)
{
	int val;
	PNODE p = pstack->ptop;
	cout<<"������Ҫѹջ��ֵ�����ͣ�:";
	cin>>val;
	p->data = val;
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pnew)
	{
		cout<<"ѹջ�����괴���½ڵ�ʱ����";
		system("pause");
		exit(-1);
	}
	pnew->pnext = NULL;
	pnew->data = val;
	pnew->postion = p->postion + 1;
	p->pnext = pnew;
	pstack->ptop = pnew;
	cout<<"ѹ��ջ��ֵΪ��"<<val<<endl;
	return ;

}

void stack_pop(PSTACK pstack)
{
	//����ȳ���˳��
	int value;
	cout<<"������Ҫ��ջ��ֵ��";
	cin>>value;
	PNODE p1 = pstack->pbottom->pnext;
	while(NULL != p1)
	{
		if (p1->data == value)
		{
			if (p1->pnext = NULL)//�ж��ڸ�ջ�����Ƿ�������ֵ
			{
				cout<<"�ڸ�ջ��֮��û������ջ������ջ����ֵ���Գ�ջ��";
				PNODE p3 = pstack->pbottom->pnext; //Ѱ��p1����Ľ�㣬�Ա㽫ջ��ָ�븳����
				PNODE ptemp = NULL;
				while( NULL != p3  )
				{
					if(p3->postion = p1->postion - 1)
					{
						ptemp = p3 ;
					}
					p3 = p3 ->pnext;
				}
				pstack->ptop = ptemp;//��ջ��ָ�븳ֵΪ��ջԪ������Ľ��λ��
				free(p1);

			}
			else
			{
				cout<<"�ڸ�ջ��֮�ϻ�������ջ������ջ����ֵ���ܳ�ջ��<�˴�ǿ�Ƴ�ջ>\n";
				PNODE p = NULL;
				int pos;
				pos = p1->postion;
				/*free(p1);
				while(NULL != p1->pnext)
				{
					free(p1);
					p1 = p1->pnext;
				}*/

				PNODE p2 = pstack->pbottom->pnext;
				PNODE TEMP = NULL;
				while( NULL != p2  )
				{
					if(p2->postion = p1->postion - 1)
					{
						p = p2;
					}
					TEMP = p2->pnext;  //����ջ��֮�ϵ�Ԫ�����γ�ջ��
					free(p2);
					p2 = TEMP;
					
				}
				pstack->ptop = p;
			}
		}
		p1 = p1->pnext;
	}
	
}

int main()
{
	PSTACK stackhead;
	stackhead = create_stack();
	stack_push(stackhead);
	traverse_stack(stackhead);
	stack_push(stackhead);
	traverse_stack(stackhead);
	stack_push(stackhead);
	traverse_stack(stackhead);
	stack_pop(stackhead);
	traverse_stack(stackhead);
	system("pause");
	return 0;
}
