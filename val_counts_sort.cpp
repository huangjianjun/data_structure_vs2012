#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#include<vector>
#define N 65535
typedef struct node
{
	int val;
	int count;
	struct node * pnext;
}NODE,*PNODE;

void fun(int *arry, int length)
{
	int i, j, pos, counts = 0;
	int hash[N];
	vector<PNODE> vec;
	for(i = 0; i < N; i++)
		hash[i] = 0;
	PNODE p = (PNODE)malloc(sizeof(NODE));
	p->val = -1;
	p->count = -1;
	p->pnext = NULL;
	PNODE pt = p;
	for(i = 0; i < length; i++)
		hash[arry[i]]++;
	for(i = 0; i < N; i++)
	{
		if(hash[i] != 0)
		{
			PNODE pnew = (PNODE)malloc(sizeof(NODE));
			pnew->val = i;
			pnew->count = hash[i];
			pnew->pnext = NULL;
			p->pnext = pnew;
			p = pnew;
		}
	}
	//按出现次数从大到小对单链表值进行输出
	PNODE q = pt->pnext;
	while(q)
	{
		vec.push_back(q);
		q = q->pnext;
	}
	vector<PNODE>::iterator it;
	while(vec.size() != 0)
	{
		for(i = 0; i < vec.size(); i++)
		{	
			if(vec[i]->count > counts)
			{
				counts = vec[i]->count;
				pos = i;
			}
		}
		for(j = 0; j < vec[pos]->count; j++)
			printf("%d  ", vec[pos]->val);
		it = vec.erase(vec.begin()+pos);
		counts = -1;
	}
	printf("\n");
	return ;
}
int main()
{
	int arry[19] = {1,2,2,3,3,3,4,4,5,5,5,5,6,6,6,7,8,9,10};
	fun(arry, 19);
	return 0;
}
