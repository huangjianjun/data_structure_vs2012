#include <iostream>
using namespace std;
#include <stdlib.h>
#include <deque>//deque容器类与vector类似，支持随机访问和快速插入删除，它在容器中某一位置上的操作所花费的是线性时间。与vector不同的是，deque还支持从开始端插入数据：push_front()。双向列表。

typedef struct bintree
{
	int value;
	bintree *pleft;
	bintree *pright;
}BTREE, *PTREE;
//基本思想：利用STL里面的deque类似双向队列，既可以在尾部插入，也可以在头部插入，
//首先，将该结点插到队列的尾部，之后，将该结点从头部出队列，打印节点值，同时，判断该结点的左右子节点，
//若不为空，则将节点值插到队列的尾部，节点值的插入队列按照从左到右的顺序，利用循环去遍历整个队列，
//直到队列为空为止。<剑指offer> p138页。
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
	cout<<"二叉树的先序遍历为：";
	pretraverse(proot);
	cout<<endl;
	cout<<"从上到下打印二叉树：";
	from_top_to_bottom_print_tree(proot);
	cout<<endl;
	system("pause");	
	return 0;
}