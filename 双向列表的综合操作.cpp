#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
//定义双向列表结点
typedef struct node
{
	int data;
	int cnum;
	struct node *pro;
	struct node *pnext;
}NODE , * PNODE;

//创建列表头
PNODE creat_list()
{
	PNODE phead = (PNODE)malloc(sizeof(NODE));
	if (NULL == phead)
	{
		cout<<"头结点创建失败,程序结束!";
		exit(-1);
	}
	cout<<"列表头结点创建成功！\n";
	return phead;
}
//初始化列表
PNODE init_list(PNODE phead)
{
	PNODE p = phead;
	p->pro = NULL;
	p->pnext = NULL;
	p->cnum = 0;
	p->data = -1;
	cout<<"列表初始化完成！\n";
	return p;
}
//列表的遍历
void traverse_list(PNODE phead)
{
	PNODE p = phead->pnext;
	cout<<"链表遍历: ";
	if ( NULL == p)
	{
		cout<<"列表为空！\n";
		return;
	}
	while(NULL != p)
	{
		cout<<p->cnum<<"->"<<p->data<<"   ";
		p = p->pnext;
	}
	cout<<"\n";
}
//在列表的尾部插入结点
PNODE append_list(PNODE phead)
{
	PNODE head = phead;
//	PNODE p = phead->pnext;
	PNODE p = phead;
	PNODE temp = NULL;
	PNODE pindex = NULL;
	int pos, datas;
	cout<<"请输入要添加的元素值：";
	cin>>datas;
	while( NULL != p)
	{
		temp = p;
		p = p->pnext;
	}
	pindex = temp;//此时pindex指针指向末尾结点
	pos = pindex->cnum;
	//创建新节点来存放要插入的结点数据
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->pnext = NULL;
	pnew->pro = pindex;
	pnew->data = datas;
	pnew->cnum = pos + 1;
	pindex->pnext = pnew;
	cout<<"添加元素值: "<<pnew->data<<" 成功!\n";
	traverse_list(phead);
	return head;
}

//在列表的头结点之后插入新节点
PNODE insert_list_started(PNODE phead)
{
	int datas;
	cout<<"请输入要添加的元素值：";
	cin>>datas;
	PNODE head = phead;
	PNODE  pnew = (PNODE)malloc(sizeof(NODE));
	if (NULL == phead->pnext)
	{
		pnew->data = datas;
		pnew->pnext = NULL;
		pnew->pro = phead;
		phead->pnext = pnew;
		pnew->cnum = 1;
		traverse_list(phead);
		return head;
	}
	pnew->data = datas;
	pnew->pnext = phead->pnext;
	pnew->pro = phead;
	phead->pnext->pro = pnew;
	phead->pnext = pnew;
	pnew->cnum = 1;
	PNODE pindex = pnew->pnext;
	while( NULL != pindex)
	{
		pindex->cnum += 1;
		pindex = pindex->pnext;
	}
	cout<<"添加元素值: "<<pnew->data<<" 成功!\n";
	traverse_list(phead);
	return head;
}
//在列表的任意位置i插入新节点
PNODE insert_list_i(PNODE phead)
{
	traverse_list(phead);
	int datas,i;
	cout<<"请输入要添加的结点号：";
	cin>>i;
	cout<<"请输入要添加的元素值：";
	cin>>datas;
	PNODE head = phead;
	PNODE pindex = phead;
	while( NULL != pindex )
	{
		if ( i - 1 == pindex->cnum)
		{
			PNODE temp = pindex->pnext;
			PNODE pnew = (PNODE)malloc(sizeof(NODE));
			pnew->data = datas;
			pnew->cnum = pindex->cnum + 1;
			pnew->pnext = pindex->pnext;
			pnew->pro = pindex;
			pindex->pnext = pnew;
			while( NULL != temp)
			{
				temp->cnum += 1;
				temp = temp->pnext;
			}
			break;
		}
		pindex = pindex->pnext;
	}
	cout<<i<<"结点上添加元素值: "<<datas<<" 成功!\n";
	traverse_list(phead);
	return head;
}

//计算列表的长度(不包括头结点在内)
int get_list_length(PNODE phead)
{
	int count = 0;
	if( NULL == phead->pnext )
	{
		cout<<"列表为空，长度为： 0 \n";
		return 0;
	}
	PNODE p = phead->pnext;
	while( NULL != p)
	{
		count++;
		p = p->pnext;
	}
	cout<<"此时列表的长度: "<<count<<endl;
	traverse_list(phead);
	return count;
}
//判断列表是否为空(不包括头结点在内)
bool list_is_null(PNODE phead)
{
	PNODE p = phead->pnext;
	if (NULL == p)
	{
		cout<<"列表为空！\n";
		return true;
	}
	else
	{
		cout<<"列表不为空！\n";
		return false;
	}
}
//在列表中查找元素datas，若有则返回所在列表标号，否则返回-1并打印提示信息
void list_find(PNODE phead)
{
	traverse_list(phead);
	int datas,len;
	cout<<"请输入要查找的元素值：";
	cin>>datas;
	PNODE p = phead->pnext;
	len = get_list_length(phead);
	while( NULL != p)
	{
		if ( p->data == datas)
		{
			cout<<"元素"<<p->data<<"找到,所在列表标号为:"<<p->cnum<<endl;
			break;
		}
		if (p->data != datas && p ->cnum == len)
		{
			cout<<"对不起，元素"<<datas<<"不在列表中！！！\n";
		}
		p = p->pnext;
	}
}

//清空列表（释放列表结点，只留头结点）
PNODE clear_list(PNODE phead)
{
	PNODE head = phead;
	PNODE temp = NULL;
	PNODE p = phead->pnext;
	cout<<"进行列表清除操作...\n";
	while( NULL != p)
	{
		temp = p;
		p = p->pnext;
		free(temp);
	}
	head = init_list(head);
	cout<<"列表清除操作完成！\n";
	return head;
}

//删除某一个结点
PNODE list_remove(PNODE phead)
{
	traverse_list(phead);
	int i,len;
	cout<<"请输入要删除的列表结点：";
	cin>>i;
	PNODE head = phead;
	PNODE temp = NULL;
	PNODE p = phead;
	if (list_is_null(phead))
	{
		cout<<"列表为空，不能执行此操作！\n";
		return head;
	}
	len = get_list_length(phead);
	if ( i == len)
	{
		while(NULL != p)
		{
			temp = p;
			p = p->pnext;
		}
		temp->pro->pnext = NULL;//很重要！！！删除前要将上一节点的pnext指针悬空，不然会出现指针混乱出错
		free(temp);
		traverse_list(phead);
		return head;
	}
	while( NULL != p)//这里的P应从头结点开始，避免当删除结点1时，找不到结点0 时出错。
	{
		if ( p->cnum == i -1 )//先找到第i-1结点
		{
			temp = p->pnext;
			p->pnext->pnext->pro = p;
			p->pnext = p->pnext->pnext;
			free(temp);
			break;
		}
		p = p->pnext;
	}
	p = p->pnext;
	while( NULL != p)
	{
		p->cnum -= 1;
		p = p->pnext;
	}
	traverse_list(phead);
	return head;
}
//修改列表i结点上的元素值
PNODE list_modify(PNODE phead)
{
	traverse_list(phead);
	int i;
	cout<<"请输入要修改的列表节点号：";
	cin>>i;
	PNODE head = phead;
	int datas;
	PNODE p = phead->pnext;
	while( NULL != p)
	{
		if (p->cnum == i)
		{
			cout<<"请输入"<<i<<"号结点要存储的元素（整数）:";
			cin>>datas;
			p->data = datas;
			cout<<i<<"号结点上的值修改为："<<p->data<<endl;
			break;
		}
		p = p->pnext;
	}
	traverse_list(phead);
	return head;
}
void quit()
{
	cout<<"退出本次程序运行！";
	exit(0);
}
void dispay()
{
	cout<<"-------------------------<双向列表的综合操作>-----------------------------\n\n";
	cout<<"\t1:列表的遍历	\t\t\t2:在列表尾添加元素\n";
	cout<<"\t3:在列表头添加元素  \t\t\t4:在列表任意结点添加元素\n";
	cout<<"\t5:列表元素查找      \t\t\t6:列表结点值修改\n";
	cout<<"\t7:删除列表结点的值   \t\t\t8:获得此时列表的长度\n";
	cout<<"\t9:清除列表          \t\t\t0:判断列表是否为空\n";
	cout<<"-------------------------------------------------------------------------\n";
}
int main()
{
	char s;
	PNODE phead = NULL;
	phead = creat_list(); 
	phead = init_list(phead);
	do{
		int num,n;
		dispay();
		cout<<"请您按键选择(功能对应标号)：";
		cin>>num;
		switch(num) 
		{
//			case 1: phead = creat_list();phead = init_list(phead);break;
			case 1: traverse_list(phead);break;
			case 2: phead = append_list(phead);break;
			case 3: phead = insert_list_started(phead);break;
			case 4: phead = insert_list_i(phead);break;
			case 5: list_find(phead);break;
			case 6: phead = list_modify(phead);break;
			case 7: phead = list_remove(phead);break; //有问题
			case 8: n = get_list_length(phead);break;
			case 9: phead = clear_list(phead);break;
			case 0: list_is_null(phead);break;
			default : cout<<"请您输入对应功能标号！\n"; break;
		}
		cout<<"是否继续进行运行程序?(y/n)";
		cin>>s;
	}while(s != 'n');
	return 0;
}
