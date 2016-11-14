#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
//����һ���ṹ�����������
struct Arr
{
	int *pbase;//���������һ��Ԫ�صĵ�ַ
	int len;//������������Ԫ�ص�������
	int cnt;//��ǰ������ЧԪ�صĸ���
};
void init_arr(struct Arr *pArr, int length);//��ʼ��
bool append_arr(struct Arr *pArr, int value);//׷��
bool insert_arr(struct Arr *pArr, int index , int value);//����
bool delete_arr(struct Arr *pArr, int index );//ɾ��
bool is_empty(struct Arr *pArr);//�Ƿ�Ϊ��
bool is_full();//�Ƿ�Ϊ��
void sort_arr(struct Arr *pArr);//����
void show_arr(struct Arr *pArr);//��ʾ��ӡ
//void inversion_arr();//����


void init_arr(struct Arr *pArr, int length)
{
	pArr->pbase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pbase)
	{
		cout<<"malloc��̬�ڴ����ʧ�ܣ�";
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
		for (int i = 0; i < pArr->len ; i ++)
			pArr->pbase[i] = 0;
	}
	return;
}
bool is_empty(struct Arr *pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}
void show_arr(struct Arr *pArr)
{
	//bool is_empty(struct Arr *pArr);
	//if (is_empty(pArr))
	if (0 == pArr->cnt)
		cout<<"Ҫ���������Ϊ�գ�"<<endl;
	else
	{
		for (int i = 0; i < pArr->len; i ++)
			cout<<pArr->pbase[i]<<"\t";
	}
	cout<<"\n";
}
bool append_arr(struct Arr *pArr, int value)
{
	//cout<<pArr->len<<endl;
	//cout<<pArr->cnt<<endl;
	if ( pArr->len == pArr->cnt)
	{
		cout<<"���鳤�����������ܼ���׷�ӣ�";
		return false;
	}
		
	else
	{
		pArr->pbase[pArr->cnt] = value;
		pArr->cnt += 1;
		return true;

	}
}

bool insert_arr(struct Arr *pArr, int index , int value)
{
	if (index >= pArr->len)
	{
		cout<<"�����±�Խ�磡";
		return false;
	}
	else if(pArr->cnt == pArr->len)
	{
		cout<<"�������������ܲ���Ԫ�أ�";
		return false;
	}
	else
	{
		cout<<"�������Ԫ��Ϊ��"<<value<<endl;
		//for (int i = 1 ;i < pArr->len - 1 - index ; i ++)
		for (int i = pArr->len - 1 - index ; i >=1 ; i --)
		{
			pArr->pbase[index + i] = pArr->pbase[index + i - 1];
		}
		pArr->pbase[index] = value;
		pArr->cnt += 1;
		return true;
	}
}
bool delete_arr(struct Arr *pArr, int index )
{
	if (0 == pArr->cnt)
	{
		cout<<"����Ϊ�գ����ܽ���ɾ��������"<<endl;
		return false;
	}
	else
	{
		int i = 0;
		cout<<"��ɾ����Ԫ��Ϊ��"<<pArr->pbase[index]<<endl;
		for (i = 0 ;i < pArr->len - 1 - index ; i ++)
		{
			pArr->pbase[index + i] = pArr->pbase[index + i + 1];
		}
		pArr->pbase[index + i - 1] = 0;
		return true;
	}
	
}
void sort_arr(struct Arr *pArr)
{
	cout<<"����Ӵ�С����Ϊ��"<<endl;
	int i , j , temp;
	for (i = 0; i < pArr->cnt; i ++)
	{
		for (j = i + 1; j < pArr->cnt; j ++)
		{
			if (pArr->pbase[i] <= pArr->pbase[j])
			{
				temp = pArr->pbase[i];
				pArr->pbase[i] = pArr->pbase[j];
				pArr->pbase[j] = temp;
			}
		}
	}
}
int main()
{
	struct Arr arr;
	int length = 10;
	init_arr(&arr,length);
	append_arr(&arr,18);
	append_arr(&arr,20);
	append_arr(&arr,30);
	append_arr(&arr,40);
	show_arr(&arr);
	//insert_arr(&arr,7,50);
	insert_arr(&arr,1,50);
	show_arr(&arr);
	delete_arr(&arr,2);
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	system("pause");
	return 0;
}
