//定义栈以及模仿栈的各种操作
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
//动态栈以链表为内核存储结构
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
		cout<<"新节点内存分配失败！";
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

void push(PSTACK pst, int val)//栈为向下指向，即新入栈的结点指向之前的栈顶位置。
{
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pnew)
	{
		cout<<"新节点内存分配失败！";
		system("pause");
	}

	pnew->data = val;
	pnew->pnext = pst->ptop;//新节点的指针指向原来的栈顶位置
	pst->ptop = pnew;//将栈顶的位置修改为新节点的地址值
}
//每次将栈顶元素出栈，出栈元素的值赋给变量value
bool pop(PSTACK pst, int value)
{
	if (is_empty_stack(pst))
	{
		cout<<"栈为空，出栈操作失败！\n";
		return false;
	}
	else
	{
		PNODE r = pst->ptop;
		value = r->data;
		pst->ptop = r->pnext; //修改栈顶ptop的值
		free(r);
		cout<<"出栈成功，出栈的元素："<<value<<endl;
		return true;
	}
}

bool forced_pop(PSTACK pst)// 在该出栈值之前的前全部出栈
{
	int value;
	if (is_empty_stack(pst))
	{
		cout<<"栈为空，出栈操作失败！\n";
		return false;
	}
	else
	{
		PNODE r = pst->ptop;
		PNODE temp = NULL;
		cout<<"请输入要强制出栈的值:";
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
		cout<<"强制出栈成功，出栈的元素："<<value<<endl;
		return true;
	}
}

void traverse(PSTACK pst)
{
	cout<<"对栈进行遍历:";
	PNODE p = pst->ptop;
	if(p == pst->pbottom)
	{
		cout<<"栈为空！\n";
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
void clear_stack(PSTACK pst)//栈还在，只是其中的数据被清空了，相当于对栈进行初始化操作
{
	if (is_empty_stack(pst))
	{
		cout<<"链表为空，不用进行clear操作！\n";
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
	cout<<"栈的初始化，建立一个空栈\n";
	init(&s);
	traverse(&s);
	cout<<"进行压栈操作\n";
	push(&s,23);
	push(&s,245);
	push(&s,456);
	push(&s,100);
	push(&s,12);
	traverse(&s);
	cout<<"进行出栈操作\n";
	pop(&s,re);
	traverse(&s);
	cout<<"进行强制出栈操作\n";
	forced_pop(&s);
	traverse(&s);
	cout<<"进行栈的清空操作\n";
	clear_stack(&s);
	traverse(&s);
	system("pause");
	return 0;
}

