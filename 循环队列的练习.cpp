#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int *pbase;//指向整型数组的指针
	int front;//指向数组的下标
	int rear;//指向数组的下标
}QUEUE,* PQUEUE;

int init_queue(PQUEUE queue, int n)//返回数组的长度
{
	cout<<"请输入要创建循环队列的数组的长度：";
	cin>>n;
	queue->pbase = (int *)malloc(sizeof(int) * n);
	queue->front = 0;
	queue->rear = 0;
	return n;
}

bool is_empty_queue(PQUEUE queue)
{
	if (queue->rear == queue->front)
		return true;
	else
		return false;
}
bool is_full_queue(PQUEUE queue, int n)
{
	if ((queue->rear + 1) % n == queue->front)
		return true;
	else
		return false;
}


void in_queue(PQUEUE queue, int value,int n)
{
	cout<<"执行入队操作,"<<"入队的值："<<value<<endl;
	if (is_full_queue( queue, n))
	{
		cout<<"队列已满，不能指向入队操作!\n";
	}
	else
	{
		//cout<<"queue->rear :"<<queue->rear<<endl;
		queue->pbase[queue->rear] = value;
		queue->rear = (queue->rear + 1) % n;
	}
}

void out_queue(PQUEUE queue,int n)
{
	int r ;//用于存放出队的值
	cout<<"执行出队操作,";
	if (is_empty_queue(queue))
		cout<<"队列为空，不能执行出队操作！\n";
	else
	{	
		r = queue->pbase[queue->front] ;
		queue->front = (queue->front + 1) % n;
		cout<<"出队的元素值:"<<r<<endl;
	}
	return ;
}

void forced_out_queue(PQUEUE queue,int n)
{
	int r ;//用于存放出队的值
	cout<<"请输入强行出队的值：";
	cin>>r;
	cout<<"执行强行出队操作,";
	if (is_empty_queue(queue))
		cout<<"队列为空，不能执行出队操作！\n";
	else
	{	
		int i = queue->front;
		while(queue->pbase[i] != r)
		{

			i = (i + 1) % n;
		}
		queue->front = (i + 1) % n;
		
		cout<<"出队的元素值:"<<r<<endl;
	}
	return ;
}
void traverse_queue(PQUEUE queue,int n)
{
	cout<<"遍历队列:";
	if (is_empty_queue(queue))
	{
		cout<<"队列为空!";
	}

	int i = queue->front;
	while(i != queue->rear)
	{
		//cout<<"queue->front :"<<queue->front<<endl;
		cout<<queue->pbase[i]<<"    ";
		i = (i + 1) % n;
	}
	cout<<"\n";
	return ;
}

int main()
{
	QUEUE queue;
	int n = -1;
	n = init_queue(&queue, n);
	cout<<"n :"<<n<<endl;
	in_queue(&queue,200,n);
	traverse_queue(&queue,n);
	in_queue(&queue,400,n);
	traverse_queue(&queue,n);
	in_queue(&queue,500,n);
	traverse_queue(&queue,n);
	in_queue(&queue,300,n);
	traverse_queue(&queue,n);
	out_queue(&queue, n);
	traverse_queue(&queue,n);
	forced_out_queue(&queue,n);
	traverse_queue(&queue,n);
	system("pause");
	return 0;
}

