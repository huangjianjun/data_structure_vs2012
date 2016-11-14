#include <iostream>
using namespace std;
#include <stdlib.h>
#include <deque>
#include <vector>
//����һ�Ŷ�������һ����������ӡ���������нڵ�ֵ�ĺ���������������·���������ĸ��ڵ�����һֱ��Ҷ�ڵ��������Ľ���γ�һ��·����
typedef struct bintree
{
	int value;
	bintree *pleft;
	bintree *pright;
}BTREE, *PTREE;

//����˼�룺�ɶ�������ǰ��������ȷ��ʸ��ڵ�����ԣ�ÿ�����ʵ�һ�����ʱ�����ǽ��ýڵ���ӵ�·���ϣ����ڵ�ǰ�����ۼӸýڵ��ֵ���������ĺͽ��бȽϣ�������ӡ·��������ȣ����жϵ�ǰ�ڵ��Ƿ�ΪҶ�ڵ㣬��ΪҶ�ڵ���ɾ��·���иýڵ��ֵ�����ص����ڵ㣻����ΪҶ�ڵ������õݹ�����������ӽڵ㡣
int find_path_2(PTREE proot, int expectsum, vector<int> path2, int currentsum, int count)
{
	if( NULL == proot)
		return 0;
	int flag = 0;
	int val = proot->value;
	currentsum += val;
	path2.push_back(val);

	//�жϵ�ǰ�ڵ��ǲ���Ҷ�ڵ�
	bool is_leaf = false;
	if ( NULL == proot->pleft && NULL == proot->pright )
		is_leaf = true;
	//��ǰ�ڵ�ΪҶ�ڵ�ʱ�����currentsum�Ƿ�Ϊ�ڴ���expectsum���������ӡ·��
	if (is_leaf  &&  currentsum == expectsum)
	{
		cout<<"·��<"<<count<<">: ";
		vector<int> :: iterator iter = path2.begin();
		for( ; iter != path2.end(); iter++)
			cout<<(*iter)<<"\t";
		cout<<endl;
		count++;
		flag = 1;
	}

	//��ǰ�ڵ㲻��Ҷ�ڵ㣬��������������ӽڵ�
	if ( proot->pleft != NULL)
		find_path_2(proot->pleft, expectsum, path2, currentsum, count);
	if ( proot->pleft != NULL)
		find_path_2(proot->pright, expectsum, path2, currentsum, count);

	//��һ���൱��Ҫ���ڱ������ӽڵ㷵�ظ��ڵ�֮ǰ����·����ɾ����ǰ�ڵ��ֵ
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
	cout<<"test_2 ����������Ϊ��"<<expectsum<<endl;
	ret = find_path_2(proot, expectsum, path2, currentsum, count);
//	if (ret == 0)
//		cout<<"û���ҵ���Ӧ�͵�·����"<<endl;
}

int main()
{
	PTREE proot = creat_bintree();
	cout<<"���������������Ϊ��";
	pretraverse(proot);
	cout<<endl;
	int count = 1;
	test_2(proot, 34, count);
	test_2(proot, 50, count);
	cout<<endl;
	system("pause");	
	return 0;
}

