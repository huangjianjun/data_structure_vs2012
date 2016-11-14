#include <iostream>
using namespace std;
#include <stdlib.h>

typedef struct bintree
{
	int value;
	bintree *pleft;
	bintree *pright;
}BTREE, *PTREE;

PTREE create_breenode_left(PTREE pnode, int value)
{
	PTREE pnewnode = (PTREE)malloc(sizeof(BTREE));
	pnewnode->value = value;
	pnewnode->pleft = NULL;
	pnewnode->pright = NULL;
	pnode->pleft = pnewnode;
	return pnewnode;
}

PTREE create_breenode_right(PTREE pnode, int value)
{
	PTREE pnewnode = (PTREE)malloc(sizeof(BTREE));
	pnewnode->value = value;
	pnewnode->pleft = NULL;
	pnewnode->pright = NULL;
	pnode->pright = pnewnode;
	return pnewnode;
}
PTREE creat_bintree()
{
	PTREE proot = (PTREE)malloc(sizeof(BTREE));
	proot->pleft = NULL;
	proot->pright = NULL;
	proot->value = 10;
	PTREE p1 = create_breenode_left(proot, 5);
	PTREE p2 = create_breenode_right(proot, 12);
	PTREE p3 = create_breenode_left(p1, 4);
	PTREE p4 = create_breenode_right(p1, 7);
	return proot;
}

void insertraverse(PTREE pt)
{
	if (pt != NULL)
	{
		insertraverse(pt->pleft);
		cout<<pt->value<<"  ";
		insertraverse(pt->pright);
	}
}

//�������������˳����ʵ����ֻ��Ҫ�������һ�¶�������ͬʱ������ǰ��������һ��ָ��listend���Լ���ǰָ��pcurrent��ÿ����һ���ڵ����һ�����ߵ�ֵ��������Ҫ��������������ĺ���

void convert_node(PTREE pnode, PTREE *listend)
{
	if(pnode == NULL)
		return ;
	PTREE pcurrent = pnode;
	if( pcurrent->pleft != NULL)
		convert_node(pcurrent->pleft, listend);
	//����Ĵ���Ϊ���Ĵ��룬�״ν��ʱ��*listendΪ�գ�֮�󲻶ϸ���ֵ��
	pcurrent->pleft = *listend;
	if ( *listend != NULL)
		(*listend)->pright = pcurrent;

	*listend = pcurrent; 

	if(pcurrent->pright != NULL)
		convert_node(pcurrent->pright, listend); 
}

PTREE convert(PTREE proot)
{
	PTREE list_end = NULL;//ʼ��ָ���б�������
	PTREE list_start = NULL;
	if (NULL == proot)
		return proot;
	convert_node(proot, &list_end);
	list_start = list_end;
	while( list_start != NULL  && list_start->pleft != NULL)//�����б��ͷ���
		list_start = list_start->pleft;
	return list_start;
}
void traverse(PTREE p)
{
	while( NULL != p)
	{
		cout<<p->value<<"  ";
		p = p->pright;
	}
	cout<<endl;
}

int main()
{
	PTREE proot = creat_bintree();
	PTREE listhead = NULL;
	cout<<"���������������������";
	insertraverse(proot);
	cout<<"\n----------------------------\n";
	listhead = convert(proot);
	cout<<"ת�����˫���б�Ϊ��";
	traverse(listhead);
	system("pause");
	return 0;
}