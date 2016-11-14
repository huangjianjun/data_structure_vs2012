#include<iostream>
using namespace std;
#include<stdlib.h>

//基本思想：一个数的出现次数超过了数组长度的一半，也就是说它出现的次数比其他所有数字出现次数的总和还要多，
//因此，我们遍历数组的时候保存两个值：1、遍历的值 2、times（次数）
//首先，规定result = a[0];, times = 0; 利用for循环i = 0开始遍历数组，
//若所遍历的值与上一个数字相同，则times++; 若所遍历的值与上一个数字不同，则timrs--;
//如果次数times减到0时，我们将下个遍历的值a[i]赋值给result,且将times的值设置为1；
//由于我们要找的数字出现的次数比其他所有数字出现的次数之和还要多，
//那么我们要找的数字肯定就是最后一次将times设置为1 所对应的数字.

bool check_more_half(int *array, int length, int result)
{
	bool flag = false;
	int sum = length / 2;
	int count = 0;
	for(int i = 0; i < length; i++)
	{
		if( array[i] == result)
			count++;
	}
	if(count > sum)
		flag = true;
	return flag;
}

int more_than_half_array(int *array, int length)
{
	if(array == NULL || length <= 0)
		return -1;
	int times = 0;
	int result = array[0];
	for(int i = 0; i < length; i++)
	{
		if(times == 0)
		{
			result = array[i];
			times = 1;
			continue;
		}
		if(array[i] == result)
			times++;
		else
			times--;
	}
	if(!check_more_half(array, length, result))
		return -2;
	return result;
}
void display(int *array, int length)
{
	if(array == NULL || length <= 0)
	{
		cout<<"输入参数有误，程序结束！"<<endl;
		return ;
	}
	for(int i = 0; i < length; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}
void test(int *array, int length)
{
	cout<<"输入的数组为： ";
	display(array,length);
	int ret = more_than_half_array(array, length);
	cout<<"测试的结果值： "<<ret<<endl;
}

int main()
{
	int a[11] = {1,2,3,2,2,4,5,2,2,6,2};// 2 出现的次数大于数组长度的一半
	int b[3] = {5,5,6};
	int c[18] = {8,8,8,8,8,8,8,8,5,5,5,5,5,5,5,5,5,5};
	int d[10] = {11,3,5,9,5,4,5,5,8,6};// 5 出现的次数小于数组长度的一半
	cout<<"----------<输出数组中出现次数超过数组长度一半的元素>----------\n\n";
	test(a,11);
	cout<<"\n-----------------------------------------------------\n";
	test(b,3);
	cout<<"\n-----------------------------------------------------\n";
	test(c,18);
	cout<<"\n-----------------------------------------------------\n";
	test(d,10);
	cout<<"\n-----------------------------------------------------\n";
	test(NULL, 3);
	cout<<"\n-----------------------------------------------------\n";
	system("pause");
	return 0;
}