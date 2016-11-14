#include <iostream>
using namespace std;
#include <stdlib.h>
#include <deque>
#include <vector>
//输入一颗二叉树和一个整数，打印出二叉树中节点值的和输入整数的所有路径，从树的根节点往下一直到叶节点所经过的结点形成一条路径。
typedef struct bintree
{
	int value;
	bintree *pleft;
	bintree *pright;
}BTREE, *PTREE;

//基本思想：由二叉树的前序遍历首先访问根节点的特性，每当访问到一个结点时，我们将该节点添加到路径上，并在当前和中累加该节点的值，与期望的和进行比较，相等则打印路径；不相等，则判断当前节点是否为叶节点，若为叶节点则删除路径中该节点的值，返回到父节点；若不为叶节点则利用递归继续遍历其子节点。
int find_path_2(PTREE proot, int expectsum, vector<int> path2, int currentsum, int count)
{
	if( NULL == proot)
		return 0;
	int flag = 0;
	int val = proot->value;
	currentsum += val;
	path2.push_back(val);

	//判断当前节点是不是叶节点
	bool is_leaf = false;
	if ( NULL == proot->pleft && NULL == proot->pright )
		is_leaf = true;
	//当前节点为叶节点时，检测currentsum是否为期待的expectsum，若是则打印路径
	if (is_leaf  &&  currentsum == expectsum)
	{
		cout<<"路径<"<<count<<">: ";
		vector<int> :: iterator iter = path2.begin();
		for( ; iter != path2.end(); iter++)
			cout<<(*iter)<<"\t";
		cout<<endl;
		count++;
		flag = 1;
	}

	//当前节点不是叶节点，则继续遍历它的子节点
	if ( proot->pleft != NULL)
		find_path_2(proot->pleft, expectsum, path2, currentsum, count);
	if ( proot->pleft != NULL)
		find_path_2(proot->pright, expectsum, path2, currentsum, count);

	//这一步相当重要，在遍历完子节点返回父节点之前，在路径上删除当前节点的值
	path2.pop_back();
	return flag;
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
	PTREE p8 = create_breenode_right(p3, 20);
	PTREE p9 = create_breenode_left(p4, 16);
	PTREE p10 = create_breenode_right(p4, 20);
	PTREE p11 = create_breenode_left(p5, 23);
	PTREE p12 = create_breenode_right(p5, 25);
	PTREE p13 = create_breenode_left(p6, 45);
	PTREE p14 = create_breenode_right(p6, 5);
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

void test_2(PTREE proot, int expectsum, int count)
{
	int ret;
	int currentsum = 0;
//	int count = 1;
	vector<int> path2;
	cout<<"test_2 测试期望和为："<<expectsum<<endl;
	ret = find_path_2(proot, expectsum, path2, currentsum, count);
//	if (ret == 0)
//		cout<<"没有找到对应和的路径！"<<endl;
}

int main()
{
	PTREE proot = creat_bintree();
	cout<<"二叉树的先序遍历为：";
	pretraverse(proot);
	cout<<endl;
	int count = 1;
	test_2(proot, 34, count);
	test_2(proot, 50, count);
	cout<<endl;
	system("pause");	
	return 0;
}

