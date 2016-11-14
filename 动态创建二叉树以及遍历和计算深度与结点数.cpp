#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<stack>

typedef struct bnode
{
	char data;
	struct bnode *plchild;
	struct bnode *prchild;
}BNODE , * PBNODE;
//定义一个节点指针root，另它代表二叉树的根节点。
typedef struct btree
{
	struct bnode * root;//root结点指针代表根节点的地址，
}BTree;


PBNODE newnode()
{
	PBNODE pnew = (PBNODE)malloc(sizeof(BNODE));
	if (NULL == pnew)
	{
		cout<<"新结点创建，动态内存分配失败！";
		system("pause");
		exit(-1);
	}
	return pnew;
}

void create_void_tree(BTree *p)
{
	p->root = NULL;
}

void create_tree(BTree * bt ,char x, BTree * lt, BTree * rt)
{
	PBNODE p = newnode();
	p->data = x;
	p->plchild = lt->root;//传参时lt代表左子树的根节点的地址,lt->root代表根节点的地址。
	p->prchild = rt->root;//传参时rt代表左子树的根节点的地址,rt->root代表根节点的地址。
	lt->root = rt->root = NULL;
	bt->root = p;
}

//递归的调用访问
void pretraverse(PBNODE pt)
{
	/* 先序遍历伪算法
	先访问根结点的值
	再先序遍历左子树
	再先序遍历右子树
	*/
	//cout<<pt<<endl;
	if (pt != NULL)
	{
		cout<<pt->data<<"  ";
		pretraverse(pt->plchild);
		pretraverse(pt->prchild);
	}
}

void intraverse(PBNODE pt)
{
/*  中序遍历伪算法
	先中序遍历左子树
	访问根结点
	再中序遍历右子树
*/
	//cout<<pt<<endl;
	if (pt != NULL)
	{
		intraverse(pt->plchild);
		cout<<pt->data<<"  ";
		intraverse(pt->prchild);
	}
}

void posttraverse(PBNODE pt)
{
/*  后序遍历伪算法
	先后序遍历左子树	
	再后序遍历右子树
	访问根结点
*/
	//cout<<pt<<endl;
	if(pt != NULL)
	{
		posttraverse(pt->plchild);
		posttraverse(pt->prchild);
		cout<<pt->data<<"  ";
	}
}


//下面定义先序遍历的非递归算法
/**/

//计算二叉树的结点个数
int size_of_btree(PBNODE bt)
{
	PBNODE p = bt;
	int s,s1,s2;
	if (!p) return 0;
	//else return size_of_btree(p->plchild) + size_of_btree(p->prchild) + 1;
	else
	{
		s1 = size_of_btree(p->plchild);
		s2 = size_of_btree(p->prchild);
		s = s1 + s2 + 1;
		return s;
	}

}

//计算二叉树的深度
int depth(PBNODE p)
{
	int s,s1,s2;
	if (!p) return 0;
	//else return max(depth(p->plchild) + depth(p->prchild)) + 1;
	else
	{
		s1 = depth(p->plchild);
		s2 = depth(p->prchild);
		s = max(s1,s2)+ 1;
		return s;
	}
}

//二叉树的复制< 采用先序遍历，bt指向被复制的二叉树的根节点>
PBNODE copy(BTree *bt)
{
	PBNODE q = NULL;
	q = newnode();
	q->data = bt->root->data;
	q->plchild = bt->root->plchild;
	q->prchild = bt->root->prchild;
	return q;
}
PBNODE copy_tree(BTree *bt)
{
	PBNODE a;
	a = copy(bt);
	return a;
}

//实现二叉树的结点值的查找
PBNODE btree_find(PBNODE p, char val )
{
	PBNODE q = p;
	if (q == NULL)
	{
		//cout<<"该二叉树为空树！\n";
		return NULL;
	}
	else
	{
		if (q->data == val)
		{
			//cout<<"所查找的结点元素值:"<<val<<"存在于二叉树中！\n";
			//cout<<"结点地址指针为：0x"<<q<<endl;
			//cout<<"其左子树结点的值为："<<q->plchild->data<<endl;
			//cout<<"其右子树结点的值为："<<q->prchild->data<<endl;
			return p;
		}
		else
		{
			//利用递归分别进入左右子树进行查询
			if ( q = btree_find(p->plchild, val))
				{
					//cout<<"所查找的结点元素值:"<<val<<"存在于二叉树中！\n";
					//cout<<"结点地址指针为：0x"<<q<<endl;
					//cout<<"其左子树结点的值为："<<q->plchild->data<<endl;
					//cout<<"其右子树结点的值为："<<q->prchild->data<<endl;
					return q;
				}
			else if ( q = btree_find(p->prchild, val))
				{
					//cout<<"所查找的结点元素值:"<<val<<"存在于二叉树中！\n";
					//cout<<"结点地址指针为：0x"<<q<<endl;
					//cout<<"其左子树结点的值为："<<q->plchild->data<<endl;
					//cout<<"其右子树结点的值为："<<q->prchild->data<<endl;
					return q;
				}
			else
			{
				//cout<<"所查询的结点值不在该二叉树中!\n";
				return NULL;
			}
		}
	}
	
}

int main()
{
	BTree A,B,C,D,E,F,L,N,M;
	BTree tree_of_copy;
	PBNODE p = NULL;
	char val;
	int n , deep;
	create_void_tree(&A);
	create_void_tree(&B);
	create_void_tree(&C);
	create_void_tree(&D);
	create_void_tree(&E);
	create_void_tree(&F);
	create_void_tree(&L);
	create_void_tree(&M);
	create_void_tree(&N);
	create_tree(&L,'L',&A,&A);
	create_tree(&M,'M',&A,&A);
	create_tree(&F,'F',&L,&M);
	create_tree(&N,'N',&A,&A);
	create_tree(&D,'D',&A,&A);
	create_tree(&E,'E',&N,&A);
	create_tree(&C,'C',&D,&E);
	create_tree(&B,'B',&F,&A);
	create_tree(&A,'A',&B,&C);
	deep = depth(A.root);
	n = size_of_btree(A.root);
	cout<<"创建的二叉树的深度："<<deep<<endl;
	cout<<"创建的二叉树的结点个数："<<n<<endl;
	cout<<"先序遍历：";
	pretraverse(A.root);
	cout<<endl;
	cout<<"中序遍历：";
	intraverse(A.root);
	cout<<endl;
	cout<<"后序遍历：";
	posttraverse(A.root);
	cout<<endl;
	cout<<"请输入要查询的节点的值：";
	cin>>val;
	p = btree_find(A.root, val );
	cout<<"所查询的结点值的地址为：0x"<<p<<endl;
	cout<<"-----------------------------------------------\n";
	tree_of_copy.root = copy_tree(&A);
	cout<<"通过复制函数复制的二叉树\n";
	cout<<"先序遍历：";
	pretraverse(tree_of_copy.root);
	//pretraverse_feidigui(&A);
	cout<<endl;
	cout<<"中序遍历：";
	intraverse(tree_of_copy.root);
	cout<<endl;
	cout<<"后序遍历：";
	posttraverse(tree_of_copy.root);
	cout<<endl;
//	traverse_pre_level(q, A.root);
	system("pause");
	return 0;
}





