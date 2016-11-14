//定义栈以及模仿栈的各种操作
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
//动态栈以链表为内核存储结构
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
		cout<<"头结点动态内存分配失败！";
		system("pause");
	}
	PSTACK psta = (PSTACK)malloc(sizeof(STACK));
	if (NULL == psta)
	{
		cout<<"栈指针内存分配失败！";
		system("pause");
	}
	psta->pbottom = phead;
	psta->ptop = phead;
	//创建新的结点挂到头结点上
	cout<<"请您输入创建结点的个数：";
	cin>>len;
	cout<<"------------------------------\n";
	for (int i = 0;i < len;i ++)
	{
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pnew)
		{
			cout<<"新结点动态内存分配失败！";
			system("pause");
		}
		//栈的存储值默认为0
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
	cout<<"栈区的遍历：";
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
	cout<<"请输入要压栈的值（整型）:";
	cin>>val;
	p->data = val;
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pnew)
	{
		cout<<"压栈操作完创建新节点时出错！";
		system("pause");
		exit(-1);
	}
	pnew->pnext = NULL;
	pnew->data = val;
	pnew->postion = p->postion + 1;
	p->pnext = pnew;
	pstack->ptop = pnew;
	cout<<"压入栈的值为："<<val<<endl;
	return ;

}

void stack_pop(PSTACK pstack)
{
	//后进先出的顺序
	int value;
	cout<<"请输入要出栈的值：";
	cin>>value;
	PNODE p1 = pstack->pbottom->pnext;
	while(NULL != p1)
	{
		if (p1->data == value)
		{
			if (p1->pnext = NULL)//判断在该栈区上是否还有其他值
			{
				cout<<"在该栈区之上没有其他栈区，该栈区的值可以出栈！";
				PNODE p3 = pstack->pbottom->pnext; //寻找p1下面的结点，以便将栈顶指针赋给它
				PNODE ptemp = NULL;
				while( NULL != p3  )
				{
					if(p3->postion = p1->postion - 1)
					{
						ptemp = p3 ;
					}
					p3 = p3 ->pnext;
				}
				pstack->ptop = ptemp;//将栈顶指针赋值为出栈元素下面的结点位置
				free(p1);

			}
			else
			{
				cout<<"在该栈区之上还有其他栈区，该栈区的值不能出栈！<此处强制出栈>\n";
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
					TEMP = p2->pnext;  //将该栈区之上的元素依次出栈。
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
