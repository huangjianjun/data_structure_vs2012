#include<iostream>
using namespace std;
#include <stdlib.h>
//����˼�룺�ɶ��������������ʿ�֪��������һ��Ԫ��Ϊ���ڵ��ֵ�������������������������ڵ�ֵ��С�ڸ��ڵ��ֵ�������ҽ���ֵ�����ڸ�����ֵ��[5,7,6,9,11,10,8],8 Ϊ���ڵ�ֵ��5,7,6Ϊ�������Ľڵ�ֵ��9,11,10Ϊ�ҽڵ��ֵ��ͬ����ͬ���ķ�ʽ��ȥ��֤�������еĽ�㣬5,7,6�� 6 Ϊ���ڵ㣬��5Ϊ��������㣬7Ϊ��������㣬�������ƣ���ʵ����һ���ݹ���̡�
bool is_postorder_of_bst_1(int *arry, int length,bool flag)
{
	int sum = 0;//����ұ����ݸ�ֵʱ���±�����
	int index = 0;
	if(NULL == arry || length < 0)
		return false;
	if(length == 1)
		return flag;
	int root = arry[length-1];
	for( int i = length - 2; i >= 0; i--)
	{
		if (arry[i] <= root)
		{
			index = i;
			break;
		}
	}
	int *left = (int *)malloc(sizeof(int)*(index + 1));
	int *right = (int *)malloc(sizeof(int)*(length - index- 2));
	for (int i = index + 1; i <= length - 2; i++)
		right[sum++] = arry[i];
	for (int i = 0; i <= index; i++)
	{
		if( arry[i] < root)
			left[i] = arry[i];
		else
		{
			return false;
		}
	}
	flag = true;
	int *p2 = right;//��Ҫ��Ҫ������ݹ���������ʱ����������ֵ���޸ģ����ﱣ�档
	is_postorder_of_bst_1(left, index + 1, flag);
	is_postorder_of_bst_1(p2, length - index- 2, flag);
	free(left);
	free(right);
	return flag;
}

bool is_postorder_of_bst_2(int *arry, int start, int end, bool flag)
{
	int index = 0;
	if(NULL == arry || end < 0)
		return false;
	if((end + 1) == 1)//����ĳ���
		return flag;
	int root = arry[end];
	for( int i = end - 1; i >= 0; i--)
	{
		if (arry[i] <= root)
		{
			index = i;
			break;
		}
	}
	for (int i = 0; i <= index; i++)
	{
		if( arry[i] > root)
		{
			return false;
		}
	}
	flag = true;
	is_postorder_of_bst_2(arry, 0, index, flag);
	is_postorder_of_bst_2(arry, index+1, end-1, flag);
	return flag;
}
int main()
{
	bool flag = false;
	bool yn;
	int a1[7] = {5,20,6,9,11,10,8};// false
	int a2[7] = {5,7,6,9,11,10,8};//true
	int a3[4] = {7,4,6,5};//false
	yn = is_postorder_of_bst_1(a1, 7, flag);
	cout<<"is_postorder_of_bst_1 Ԥ��ֵ-->0, ʵ��ֵ-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_2(a1, 0, 6,flag);
	cout<<"is_postorder_of_bst_2 Ԥ��ֵ-->0, ʵ��ֵ-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_1(a2, 7, flag);
	cout<<"is_postorder_of_bst_1 Ԥ��ֵ-->1, ʵ��ֵ-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_2(a2, 0, 6, flag);
	cout<<"is_postorder_of_bst_2 Ԥ��ֵ-->1, ʵ��ֵ-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_1(a3, 4, flag);
	cout<<"is_postorder_of_bst_1 Ԥ��ֵ-->0, ʵ��ֵ-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_2(a3, 0, 3,flag);
	cout<<"is_postorder_of_bst_2 Ԥ��ֵ-->0, ʵ��ֵ-->"<<yn<<endl;
	system("pause");
	return 0;
}

//�ܽ᣺����1���ö�̬������������Ų�ֿ��������������ݹ麯�����ݵĲ���ֻ����������鳤�ȣ�
//��õİ취������2�����÷�������ֱ����ԭ����Ļ����Ͻ��д���������ʱ�ݹ麯�����ݵĲ���Ϊ��Դ���顢������ʼλ�ã��������λ�á�