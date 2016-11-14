#include <iostream>
using namespace std;
#include<stdlib.h>
#include <string>
#include <time.h>
//剑指offer 94页。
char * create_number(int n)//n表示最大数的位数。
{
	char *number = (char *)malloc(sizeof(char) * (n + 1));
	for(int i = 0; i < n; i++)
		number[i] = '0';
	number[n] = '\0';
	return number;
}
bool increase_number( char *number)
{
	int length  = strlen(number);
	int takeover = 0;
	bool isoverflow = false;
	for (int i = length-1; i >= 0; i--)
	{
		int num = number[i] - '0' + takeover;
		if ( i == length-1)
			num++;
		if( num >= 10)
		{
			if( 0 == i)
				isoverflow = true;
			else
			{
				num -= 10;
				number[i] = '0' + num;
				takeover = 1;
			}
		}
		else
		{
			number[i] = num + '0';
			break;
		}
	}
	return isoverflow;
}

void print_number(char *number)
{
	int n = strlen(number);
	bool isbegin_0 = false;
	for(int i = 0; i< n; i++)
	{
		if ((!isbegin_0) && (number[i] != '0'))
			isbegin_0 = true;
		if (isbegin_0)
		{
			cout<<number[i];
		}		    
	}
	cout<<"\t";
}

int main()
{
	int n = 0;
	char ch;
	do{
		int count = 0;
		cout<<"-------<测试打印1到最大的n位数>---------------\n";
		cout<<"请输入N的值：";
		cin>>n;
		while( n <= 0)
		{
			cout<<"输入的n的值有误！"<<endl;
			cout<<"请输入N的值：";
			cin>>n;
		}
		char* number = create_number(n);
		cout<<"打印结果如下：\n";
		clock_t start_time=clock();
		while(!increase_number(number))
		{
			print_number(number);
			count++;
			if( count % 10 == 0)
				cout<<endl;
		}
		cout<<endl;
		clock_t end_time=clock();
		//输出运行时间
		cout<< "程序运行时间: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<" ms"<<"\t"<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC<<" s"<<endl;
		free(number);
		cout<<"继续？(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}
//涉及到大数问题，我们一般采用字符串和数组来解决。
//首先我们把字符串中的每一个字符初始化为‘0’，然后每一次为字符串表示的数字加1，再打印出来。我们只需要做两件事：
//一:在字符串表示的数字上模拟加法，
//二：把字符串表达的数字打印出来。