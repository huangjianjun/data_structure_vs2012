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
//����һ���ڵ�ָ��root����������������ĸ��ڵ㡣
typedef struct btree
{
	struct bnode * root;//root���ָ�������ڵ�ĵ�ַ��
}BTree;


PBNODE newnode()
{
	PBNODE pnew = (PBNODE)malloc(sizeof(BNODE));
	if (NULL == pnew)
	{
		cout<<"�½�㴴������̬�ڴ����ʧ�ܣ�";
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
	p->plchild = lt->root;//����ʱlt�����������ĸ��ڵ�ĵ�ַ,lt->root������ڵ�ĵ�ַ��
	p->prchild = rt->root;//����ʱrt�����������ĸ��ڵ�ĵ�ַ,rt->root������ڵ�ĵ�ַ��
	lt->root = rt->root = NULL;
	bt->root = p;
}

//�ݹ�ĵ��÷���
void pretraverse(PBNODE pt)
{
	/* �������α�㷨
	�ȷ��ʸ�����ֵ
	���������������
	���������������
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
/*  �������α�㷨
	���������������
	���ʸ����
	���������������
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
/*  �������α�㷨
	�Ⱥ������������	
	�ٺ������������
	���ʸ����
*/
	//cout<<pt<<endl;
	if(pt != NULL)
	{
		posttraverse(pt->plchild);
		posttraverse(pt->prchild);
		cout<<pt->data<<"  ";
	}
}


//���涨����������ķǵݹ��㷨
/**/

//����������Ľ�����
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

//��������������
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

//�������ĸ���< �������������btָ�򱻸��ƵĶ������ĸ��ڵ�>
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

//ʵ�ֶ������Ľ��ֵ�Ĳ���
PBNODE btree_find(PBNODE p, char val )
{
	PBNODE q = p;
	if (q == NULL)
	{
		//cout<<"�ö�����Ϊ������\n";
		return NULL;
	}
	else
	{
		if (q->data == val)
		{
			//cout<<"�����ҵĽ��Ԫ��ֵ:"<<val<<"�����ڶ������У�\n";
			//cout<<"����ַָ��Ϊ��0x"<<q<<endl;
			//cout<<"������������ֵΪ��"<<q->plchild->data<<endl;
			//cout<<"������������ֵΪ��"<<q->prchild->data<<endl;
			return p;
		}
		else
		{
			//���õݹ�ֱ���������������в�ѯ
			if ( q = btree_find(p->plchild, val))
				{
					//cout<<"�����ҵĽ��Ԫ��ֵ:"<<val<<"�����ڶ������У�\n";
					//cout<<"����ַָ��Ϊ��0x"<<q<<endl;
					//cout<<"������������ֵΪ��"<<q->plchild->data<<endl;
					//cout<<"������������ֵΪ��"<<q->prchild->data<<endl;
					return q;
				}
			else if ( q = btree_find(p->prchild, val))
				{
					//cout<<"�����ҵĽ��Ԫ��ֵ:"<<val<<"�����ڶ������У�\n";
					//cout<<"����ַָ��Ϊ��0x"<<q<<endl;
					//cout<<"������������ֵΪ��"<<q->plchild->data<<endl;
					//cout<<"������������ֵΪ��"<<q->prchild->data<<endl;
					return q;
				}
			else
			{
				//cout<<"����ѯ�Ľ��ֵ���ڸö�������!\n";
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
	cout<<"�����Ķ���������ȣ�"<<deep<<endl;
	cout<<"�����Ķ������Ľ�������"<<n<<endl;
	cout<<"���������";
	pretraverse(A.root);
	cout<<endl;
	cout<<"���������";
	intraverse(A.root);
	cout<<endl;
	cout<<"���������";
	posttraverse(A.root);
	cout<<endl;
	cout<<"������Ҫ��ѯ�Ľڵ��ֵ��";
	cin>>val;
	p = btree_find(A.root, val );
	cout<<"����ѯ�Ľ��ֵ�ĵ�ַΪ��0x"<<p<<endl;
	cout<<"-----------------------------------------------\n";
	tree_of_copy.root = copy_tree(&A);
	cout<<"ͨ�����ƺ������ƵĶ�����\n";
	cout<<"���������";
	pretraverse(tree_of_copy.root);
	//pretraverse_feidigui(&A);
	cout<<endl;
	cout<<"���������";
	intraverse(tree_of_copy.root);
	cout<<endl;
	cout<<"���������";
	posttraverse(tree_of_copy.root);
	cout<<endl;
//	traverse_pre_level(q, A.root);
	system("pause");
	return 0;
}





