#include<iostream>
using namespace std;
#include <stdlib.h>
//基本思想：由二叉搜素树的性质可知数组的最后一个元素为根节点的值，二叉搜索数的所有左子树节点值都小于根节点的值，所有右结点的值都大于根结点的值，[5,7,6,9,11,10,8],8 为根节点值，5,7,6为左子树的节点值，9,11,10为右节点的值。同理，以同样的方式再去验证左子树中的结点，5,7,6中 6 为根节点，则5为左子树结点，7为右子树结点，依次类推，其实就是一个递归过程。
bool is_postorder_of_bst_1(int *arry, int length,bool flag)
{
	int sum = 0;//解决右边数据赋值时的下标问题
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
	int *p2 = right;//非要重要，解决递归完左子树时，右子树的值被修改，这里保存。
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
	if((end + 1) == 1)//数组的长度
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
	cout<<"is_postorder_of_bst_1 预期值-->0, 实际值-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_2(a1, 0, 6,flag);
	cout<<"is_postorder_of_bst_2 预期值-->0, 实际值-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_1(a2, 7, flag);
	cout<<"is_postorder_of_bst_1 预期值-->1, 实际值-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_2(a2, 0, 6, flag);
	cout<<"is_postorder_of_bst_2 预期值-->1, 实际值-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_1(a3, 4, flag);
	cout<<"is_postorder_of_bst_1 预期值-->0, 实际值-->"<<yn<<endl;
	flag = false;
	yn = is_postorder_of_bst_2(a3, 0, 3,flag);
	cout<<"is_postorder_of_bst_2 预期值-->0, 实际值-->"<<yn<<endl;
	system("pause");
	return 0;
}

//总结：函数1采用动态分配数组来存放拆分开的左右子树，递归函数传递的参数只有数组合数组长度；
//最好的办法，函数2，不用分配数组直接在原数组的基础上进行处理，不过这时递归函数传递的参数为：源数组、数组起始位置，数组结束位置。