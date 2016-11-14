#include <iostream>
using namespace std;
#include <stdlib.h>

//判断一个数是否为2的整数次方
//方法：若为2的整数次方，则其二进制中有且仅有一位是1；

bool is_2_n_cifang(long int number)
{
	int flag = 0;
	int count = 0;
	while(number)
	{
		count++;
		flag = 1;
		number = number&(number - 1);
	}
	if ((flag == 1) && (count == 1) )
		return true;
	else
		return false;
}

//两个整数m,n 计算要改变m的二进制表示中的多少位才能得到n
//方法：首先将m,n两个数异或（二进制表示中不同的位运算为1），最后统计异或结果中的1的个数，即为要改变的位数
int num_of_change(long int m, long int n)
{
	long int temp ;
	int count = 0;
	temp = m^n;
	while(temp)
	{
		count++;
		temp = temp&(temp-1);
	}
	return count;
}

int main()
{
	long int m,n;
	char ch;
	do{
		int k;
		cout<<"请输入整数(long int):\n";
		cout<<"m = ";
		cin>>m;
		cout<<"n = ";
		cin>>n;
		if(is_2_n_cifang(m))
			cout<<"m = "<<m<<" 是2的整数次方"<<endl;
		else
			cout<<"m = "<<m<<" 不是2的整数次方"<<endl;
		if(is_2_n_cifang(n))
			cout<<"n = "<<n<<" 是2的整数次方"<<endl;
		else
			cout<<"n = "<<n<<" 不是2的整数次方"<<endl;
		k = num_of_change(m,n);
		cout<<"二进制表示中 m->n 需要改变的位数："<<k<<endl;
		cout<<"继续?(y/n):";
		cin>>ch;

	}while('n' != ch);
	return 0;
}