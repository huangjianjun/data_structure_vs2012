#include<iostream>
using namespace std;
#include <stdlib.h>
#include<stack>

long int number_of_1_changgui(long int data)
{
	unsigned int flag = 1;
	int count = 0;
	int n = 0;
	while(flag)
	{
		n++; //记录while循环的次数
		if(data&flag)//只要相与的结果不为0，就代表现在相与的位不为0.
			count++;
		flag = flag << 1;
	}
	cout<<"number_of_1_changgui 的循环次数："<<n<<endl;
	return count;
}

long int number_of_1_zuijia(long int data)
{
	int count = 0;
	while(data)
	{
		count++;//既表示1的个数，也代表while循环的次数
		data = data&(data-1);
	}
	cout<<"number_of_1_changgui 的循环次数："<<count<<endl;
	return count;
}
int main()
{
	char ch;
	int remainder;//余数
	long int number;
	long int temp1;
	do{
		long int num_of_1;
		cout<<"请输入十进制数:";
		cin>>number;
		temp1 = number;
		stack<int> stack1;
		int n = 0;//记录转换后的二进制数的实际位数
		int m = 0;//记录需要在前面添加的0的个数
		int val;
		int num = 0;//记录输出的4个一组的组的个数
		while(number != 0)
		{
			remainder = number % 2;
			stack1.push(remainder);
			number = number / 2;
			n += 1;
			if (n % 4 == 0)
				num += 1;
		}
		if ( n % 4 != 0)
		{
			m = 4 - (n - 4 * num);
			for (int i = 0; i < m; i++)
			{
				stack1.push(0);
			}
		}
		cout<<"转换后有效的二进制位(从后数起)："<<n<<endl;
		cout<<"十进制数：<"<<temp1<<"> 转换后的二进制为：";
		stack<int> temp = stack1;
		n = 0;
		while(!temp.empty())
		{
			val = temp.top();
			cout<<val;
			temp.pop();
			n += 1;
			if (n % 4 == 0)
			{
				cout<<" ";
			}
		}
			cout<<endl;
		cout<<"-------------------------------------------\n";
		num_of_1 = number_of_1_changgui(temp1);
		cout<<"转换后的二进制中<1>的个数为："<<num_of_1<<endl;
		cout<<"-------------------------------------------\n";
		num_of_1 = number_of_1_zuijia(temp1);
		cout<<"转换后的二进制中<1>的个数为："<<num_of_1<<endl;
		cout<<"继续?(y/n):";
		cin>>ch;
	}while(ch != 'n');
}