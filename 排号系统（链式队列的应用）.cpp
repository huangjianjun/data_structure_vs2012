#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>//window 下sleep()函数的头文件，使用时sleep()函数的s要大写S，延时单位为毫秒。
#define  MAXNUM  8 //限制队列的长度 
#define N 5 // 定义模拟的时间长度（秒）

//定义链式队列的结点结构
typedef struct node 
{
	int number;
//	char name[MAXSIZE];
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
		cout<<"(初始化)动态创建列表失败！\n";
		exit(-1);
	}
	q->front->next = NULL;
	q->rear = q->front;
	q->front->number = 0;//初始化值为0
	return q;
}

void in_queue( PQUEUE q, int val)
{
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->next = NULL;
	pnew->number = val;
	q->rear->next = pnew;
	q->rear = pnew;
}
bool is_empty_queue(PQUEUE q)
{
	if (q->front == q->rear) return true;
	else return false;
}
int out_queue( PQUEUE q)
{
	int out;
	PNODE temp = NULL;
	if(is_empty_queue(q))
	{
		cout<<"顾客预约人数为空!\n";
		return -1;
	}
	else
	{
		out = q->front->next->number;
		temp = q->front;
		q->front = q->front->next;
		free(temp);
		return out;
	}
}
int get_first_val( PQUEUE q)
{
	int ret = q->front->next->number;
	return ret;

}

void traverse(PQUEUE q)
{
	PNODE p = q->front->next;
	if(is_empty_queue(q))
	{
		cout<<"系统中顾客预约人数为空!\n";
	}
	else
	{
		while( NULL != p)
		{
			cout<<p->number<<"\t";
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
//	cout<<"此时队列长度："<<len<<endl;
	return len;
}
void delay(int s)//延时单位为秒
{
	Sleep(s * 1000);//Sleep()的单位为毫秒
}

void guahao(PQUEUE q, int num)
{
	if(length_queue(q) == MAXNUM)
	{
		cout<<"对不起，今天系统的预处理人数已达上限，请您明天再来挂号预约！\n";
		cout<<"现在在系统中的顾客编号：";
		traverse(q);
		return;
	}
	else
	{
//		num++;
		in_queue(q, num);
		cout<<"编号为："<<num<<" 的顾客已经预约成功，请耐心等待！\n";
		delay(1);
	}
}

int simulation(PQUEUE q,int n)
{
	int n1,n2,out;
	n1 = get_first_val(q);
	cout<<"-----------------------------------------------------------------\n";
	cout<<"请编号为："<<n1<<" 的顾客到前台办理业务!\n";
	out = out_queue(q);
	if( n1 != n)
	{
		n2 = get_first_val(q);
		cout<<"请编号为："<<n2<<" 的顾客做好准备！\n";
	}
	cout<<"顾客编号为："<<out<<" 的业务正在办理！"<<endl;
	cout<<"模拟业务员办理业务......\n";
	for(int i = 0;i < N; i++)
	{
		cout<<N-i<<"\n";
		delay(1);
	}
//	cout<<"\n";
	cout<<"模拟业务员办理业务结束！\n";
	cout<<"-----------------------------------------------\n";
	return n1;
}
int main()
{
	int n,k,m;
	char s;
	PQUEUE q = (PQUEUE)malloc(sizeof(QUEUE));
	q = init_queue(q);
	cout<<"<欢迎您使用挂号系统>\n";
	do
	{
		int num = 0; //变量用于保存顾客的序号
		cout<<"请您输入将要模拟的顾客人数：";
		cin>>k;
		for(int i = 0; i<k; i++)
		{
			num++;
			guahao(q,num);
		}
		cout<<"-----------------------------------------------------------------\n";
		cout<<"顾客编号：";
		traverse(q);
		n = length_queue(q);
		while(1)
		{
			m = simulation(q,n);
			cout<<"顾客编号：";
			traverse(q);
			if( m == n)  break;
		}
		cout<<"是否继续进行模拟?(y/n):";
		cin>>s;
	}while( s != 'n');
	
	system("pause");
	return 0;
}
