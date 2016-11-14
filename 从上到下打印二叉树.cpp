#include <iostream>
using namespace std;
#include <stdlib.h>
#include <deque>//deque��������vector���ƣ�֧��������ʺͿ��ٲ���ɾ��������������ĳһλ���ϵĲ��������ѵ�������ʱ�䡣��vector��ͬ���ǣ�deque��֧�ִӿ�ʼ�˲������ݣ�push_front()��˫���б�

typedef struct bintree
{
	int value;
	bintree *pleft;
	bintree *pright;
}BTREE, *PTREE;
//����˼�룺����STL�����deque����˫����У��ȿ�����β�����룬Ҳ������ͷ�����룬
//���ȣ����ý��嵽���е�β����֮�󣬽��ý���ͷ�������У���ӡ�ڵ�ֵ��ͬʱ���жϸý��������ӽڵ㣬
//����Ϊ�գ��򽫽ڵ�ֵ�嵽���е�β�����ڵ�ֵ�Ĳ�����а��մ����ҵ�˳������ѭ��ȥ�����������У�
//ֱ������Ϊ��Ϊֹ��<��ָoffer> p138ҳ��
void from_top_to_bottom_print_tree(PTREE proot)
{
	deque<PTREE> dequetreenode;
	if ( NULL == proot)
		return ;
	dequetreenode.push_back(proot);
	while(dequetreenode.size() != 0)
	{
		PTREE pnode = dequetreenode.front();
		dequetreenode.pop_front();
		cout<<pnode->value<<"  ";
		if ( NULL != pnode->pleft)
			dequetreenode.push_back(pnode->pleft);
		if ( NULL != pnode->pright)
			dequetreenode.push_back(pnode->pright);
	}
}

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
	proot->value = 8;
	PTREE p1 = create_breenode_left(proot, 6);
	PTREE p2 = create_breenode_right(proot, 10);
	PTREE p3 = create_breenode_left(p1, 5);
	PTREE p4 = create_breenode_right(p1, 7);
	PTREE p5 = create_breenode_left(p2, 9);
	PTREE p6 = create_breenode_right(p2, 11);
	PTREE p7 = create_breenode_left(p3, 15);
//	PTREE p8 = create_breenode_right(p3, 20);
// 	PTREE p9 = create_breenode_left(p4, 16);
	PTREE p10 = create_breenode_right(p4, 20);
	PTREE p11 = create_breenode_left(p5, 23);
	PTREE p12 = create_breenode_right(p5, 25);
//	PTREE p13 = create_breenode_left(p6, 45);
	PTREE p14 = create_breenode_right(p6, 30);
	return proot;
}

void pretraverse(PTREE pt)
{
	if (pt != NULL)
	{
		cout<<pt->value<<"  ";
		pretraverse(pt->pleft);
		pretraverse(pt->pright);
	}
}

int main()
{
	PTREE proot = creat_bintree();
	cout<<"���������������Ϊ��";
	pretraverse(proot);
	cout<<endl;
	cout<<"���ϵ��´�ӡ��������";
	from_top_to_bottom_print_tree(proot);
	cout<<endl;
	system("pause");	
	return 0;
}