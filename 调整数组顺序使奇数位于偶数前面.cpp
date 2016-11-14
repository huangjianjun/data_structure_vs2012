#include <iostream>
using namespace std;
#include <stdlib.h>

void traverse(int * num, int length)
{
	if(length == 0)
		cout<<"数组为空！"<<endl;
	else
	{
		for(int j = 0; j < length; j++)
		{
			cout<<num[j]<<"  ";
		}
	}
	cout<<endl;
}
//基本思想：我们维护两个指针，第一个指针初始化时指向数组的第一个数字，它只向后移动；
//第二个指针初始化时指向数组的最后一个数字，它只向前移动。在两个指针相遇之前，
//第一个指针总是位于第二个指针的前面。如果第一个指针指向的数字为偶数，并且第二个指针指向的数字是奇数，我们就交换这两个数字。
void ji_qian_and_ou_hou(int *num,int length)
{
	int low = 0;
	int tmp;
	int high = length-1;
	while(low < high)
	{
		while(low < high && num[low] % 2 == 1)
			low++;
		while(low < high && num[high] % 2 == 0)
			high--;
		if(low < high && num[low] % 2 == 0 && num[high] % 2 == 1)
		{
			tmp = num[high];
			num[high] = num[low];
			num[low] = tmp;
		}
	}
}
int main()
{
	int n ;
	char ch;
	do{
		cout<<"请输入创建数的长度n:";
		cin>>n;
		int *num = (int *)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
		{
			num[i] = i + 1;
		}
		cout<<"新建的数组为：";
		traverse(num,n);
		ji_qian_and_ou_hou(num,n);
		cout<<"整理后的数组为：";
		traverse(num,n);
		free(num);
		cout<<"继续(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}