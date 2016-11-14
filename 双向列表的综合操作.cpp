#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
//����˫���б���
typedef struct node
{
	int data;
	int cnum;
	struct node *pro;
	struct node *pnext;
}NODE , * PNODE;

//�����б�ͷ
PNODE creat_list()
{
	PNODE phead = (PNODE)malloc(sizeof(NODE));
	if (NULL == phead)
	{
		cout<<"ͷ��㴴��ʧ��,�������!";
		exit(-1);
	}
	cout<<"�б�ͷ��㴴���ɹ���\n";
	return phead;
}
//��ʼ���б�
PNODE init_list(PNODE phead)
{
	PNODE p = phead;
	p->pro = NULL;
	p->pnext = NULL;
	p->cnum = 0;
	p->data = -1;
	cout<<"�б��ʼ����ɣ�\n";
	return p;
}
//�б�ı���
void traverse_list(PNODE phead)
{
	PNODE p = phead->pnext;
	cout<<"�������: ";
	if ( NULL == p)
	{
		cout<<"�б�Ϊ�գ�\n";
		return;
	}
	while(NULL != p)
	{
		cout<<p->cnum<<"->"<<p->data<<"   ";
		p = p->pnext;
	}
	cout<<"\n";
}
//���б��β��������
PNODE append_list(PNODE phead)
{
	PNODE head = phead;
//	PNODE p = phead->pnext;
	PNODE p = phead;
	PNODE temp = NULL;
	PNODE pindex = NULL;
	int pos, datas;
	cout<<"������Ҫ��ӵ�Ԫ��ֵ��";
	cin>>datas;
	while( NULL != p)
	{
		temp = p;
		p = p->pnext;
	}
	pindex = temp;//��ʱpindexָ��ָ��ĩβ���
	pos = pindex->cnum;
	//�����½ڵ������Ҫ����Ľ������
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->pnext = NULL;
	pnew->pro = pindex;
	pnew->data = datas;
	pnew->cnum = pos + 1;
	pindex->pnext = pnew;
	cout<<"���Ԫ��ֵ: "<<pnew->data<<" �ɹ�!\n";
	traverse_list(phead);
	return head;
}

//���б��ͷ���֮������½ڵ�
PNODE insert_list_started(PNODE phead)
{
	int datas;
	cout<<"������Ҫ��ӵ�Ԫ��ֵ��";
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
	cout<<"���Ԫ��ֵ: "<<pnew->data<<" �ɹ�!\n";
	traverse_list(phead);
	return head;
}
//���б������λ��i�����½ڵ�
PNODE insert_list_i(PNODE phead)
{
	traverse_list(phead);
	int datas,i;
	cout<<"������Ҫ��ӵĽ��ţ�";
	cin>>i;
	cout<<"������Ҫ��ӵ�Ԫ��ֵ��";
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
	cout<<i<<"��������Ԫ��ֵ: "<<datas<<" �ɹ�!\n";
	traverse_list(phead);
	return head;
}

//�����б�ĳ���(������ͷ�������)
int get_list_length(PNODE phead)
{
	int count = 0;
	if( NULL == phead->pnext )
	{
		cout<<"�б�Ϊ�գ�����Ϊ�� 0 \n";
		return 0;
	}
	PNODE p = phead->pnext;
	while( NULL != p)
	{
		count++;
		p = p->pnext;
	}
	cout<<"��ʱ�б�ĳ���: "<<count<<endl;
	traverse_list(phead);
	return count;
}
//�ж��б��Ƿ�Ϊ��(������ͷ�������)
bool list_is_null(PNODE phead)
{
	PNODE p = phead->pnext;
	if (NULL == p)
	{
		cout<<"�б�Ϊ�գ�\n";
		return true;
	}
	else
	{
		cout<<"�б�Ϊ�գ�\n";
		return false;
	}
}
//���б��в���Ԫ��datas�������򷵻������б��ţ����򷵻�-1����ӡ��ʾ��Ϣ
void list_find(PNODE phead)
{
	traverse_list(phead);
	int datas,len;
	cout<<"������Ҫ���ҵ�Ԫ��ֵ��";
	cin>>datas;
	PNODE p = phead->pnext;
	len = get_list_length(phead);
	while( NULL != p)
	{
		if ( p->data == datas)
		{
			cout<<"Ԫ��"<<p->data<<"�ҵ�,�����б���Ϊ:"<<p->cnum<<endl;
			break;
		}
		if (p->data != datas && p ->cnum == len)
		{
			cout<<"�Բ���Ԫ��"<<datas<<"�����б��У�����\n";
		}
		p = p->pnext;
	}
}

//����б��ͷ��б��㣬ֻ��ͷ��㣩
PNODE clear_list(PNODE phead)
{
	PNODE head = phead;
	PNODE temp = NULL;
	PNODE p = phead->pnext;
	cout<<"�����б��������...\n";
	while( NULL != p)
	{
		temp = p;
		p = p->pnext;
		free(temp);
	}
	head = init_list(head);
	cout<<"�б����������ɣ�\n";
	return head;
}

//ɾ��ĳһ�����
PNODE list_remove(PNODE phead)
{
	traverse_list(phead);
	int i,len;
	cout<<"������Ҫɾ�����б��㣺";
	cin>>i;
	PNODE head = phead;
	PNODE temp = NULL;
	PNODE p = phead;
	if (list_is_null(phead))
	{
		cout<<"�б�Ϊ�գ�����ִ�д˲�����\n";
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
		temp->pro->pnext = NULL;//����Ҫ������ɾ��ǰҪ����һ�ڵ��pnextָ�����գ���Ȼ�����ָ����ҳ���
		free(temp);
		traverse_list(phead);
		return head;
	}
	while( NULL != p)//�����PӦ��ͷ��㿪ʼ�����⵱ɾ�����1ʱ���Ҳ������0 ʱ����
	{
		if ( p->cnum == i -1 )//���ҵ���i-1���
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
//�޸��б�i����ϵ�Ԫ��ֵ
PNODE list_modify(PNODE phead)
{
	traverse_list(phead);
	int i;
	cout<<"������Ҫ�޸ĵ��б�ڵ�ţ�";
	cin>>i;
	PNODE head = phead;
	int datas;
	PNODE p = phead->pnext;
	while( NULL != p)
	{
		if (p->cnum == i)
		{
			cout<<"������"<<i<<"�Ž��Ҫ�洢��Ԫ�أ�������:";
			cin>>datas;
			p->data = datas;
			cout<<i<<"�Ž���ϵ�ֵ�޸�Ϊ��"<<p->data<<endl;
			break;
		}
		p = p->pnext;
	}
	traverse_list(phead);
	return head;
}
void quit()
{
	cout<<"�˳����γ������У�";
	exit(0);
}
void dispay()
{
	cout<<"-------------------------<˫���б���ۺϲ���>-----------------------------\n\n";
	cout<<"\t1:�б�ı���	\t\t\t2:���б�β���Ԫ��\n";
	cout<<"\t3:���б�ͷ���Ԫ��  \t\t\t4:���б����������Ԫ��\n";
	cout<<"\t5:�б�Ԫ�ز���      \t\t\t6:�б���ֵ�޸�\n";
	cout<<"\t7:ɾ���б����ֵ   \t\t\t8:��ô�ʱ�б�ĳ���\n";
	cout<<"\t9:����б�          \t\t\t0:�ж��б��Ƿ�Ϊ��\n";
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
		cout<<"��������ѡ��(���ܶ�Ӧ���)��";
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
			case 7: phead = list_remove(phead);break; //������
			case 8: n = get_list_length(phead);break;
			case 9: phead = clear_list(phead);break;
			case 0: list_is_null(phead);break;
			default : cout<<"���������Ӧ���ܱ�ţ�\n"; break;
		}
		cout<<"�Ƿ�����������г���?(y/n)";
		cin>>s;
	}while(s != 'n');
	return 0;
}
