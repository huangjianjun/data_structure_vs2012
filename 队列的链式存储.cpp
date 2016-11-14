#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>//window ��sleep()������ͷ�ļ���ʹ��ʱsleep()������sҪ��дS����ʱ��λΪ���롣
//������ʽ���еĽ��ṹ
typedef struct node 
{
	int data;
	struct node *next;
}NODE, *PNODE;

typedef struct linkqueue
{
	PNODE front;
	PNODE rear;
}QUEUE, *PQUEUE;

PQUEUE init_queue( PQUEUE q)
{
	q->front = (PNODE)malloc(sizeof(NODE));
	if (NULL == q->front)
	{
		cout<<"(��ʼ��)��̬�����б�ʧ�ܣ�\n";
		exit(-1);
	}
	q->rear = q->front;
	q->front->data = -1;//��ʼ��ֵΪ-1
	return q;
}

void in_queue( PQUEUE q, int val)
{
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->data = val;
	pnew->next = NULL;
	q->rear->next = pnew;
	q->rear = pnew;
}
bool is_empty_queue(PQUEUE q)
{
	if (q->front == q->rear) return true;
	else return false;
}
void out_queue( PQUEUE q)
{
	int out;
	PNODE temp = NULL;
	if(is_empty_queue(q))
	{
		cout<<"��ʽ����Ϊ��!\n";
		exit(-1);
	}
	else
	{
		out = q->front->next->data;
		temp = q->front;
		q->front = q->front->next;
		free(temp);
		cout<<"���Ӳ��� -->"<<"���ӵ�Ԫ��Ϊ��"<<out<<endl;
	}
}
int get_first_val( PQUEUE q)
{
	int ret = q->front->next->data;
	return ret;

}
void traverse(PQUEUE q)
{
	PNODE p = q->front->next;
	if(is_empty_queue(q))
	{
		cout<<"��ʽ����Ϊ��!\n";
	}
	else
	{
		cout<<"���б�����";
		while( NULL != p)
		{
			cout<<p->data<<"\t";
			p = p->next;
		}
		cout<<"\n";
	}
}

int length_queue( PQUEUE q)
{
	int len = 0;
	PNODE p = q->front->next;
	while( NULL != p)
	{
		len++;
		p = p->next;
	}
	cout<<"��ʱ���г��ȣ�"<<len<<endl;
	return len;
}

int main()
{
	PQUEUE q = (PQUEUE)malloc(sizeof(QUEUE));
	int length, first;
	q = init_queue(q);
	in_queue( q, 45);
	in_queue( q, 55);
	in_queue( q, 65);
	in_queue( q, 75);
	in_queue( q, 85);
	in_queue( q, 95);
	length = length_queue(q);
	traverse(q);
	first = get_first_val( q);
	getchar();
	Sleep(5000);//Sleep()�ĵ�λΪ����
	cout<<"������Ԫ�أ�"<<first<<endl;
	out_queue(q);
	out_queue(q);
	out_queue(q);
	length = length_queue(q);
	traverse(q);
	first = get_first_val( q);
	getchar();
	Sleep(5000);//Sleep()�ĵ�λΪ����
	cout<<"������Ԫ�أ�"<<first<<endl;
	system("pause");
	return 0;
}
