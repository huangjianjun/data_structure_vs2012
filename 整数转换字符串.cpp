#include <iostream>
using namespace std;
#include <stdlib.h>

char exchange(int m)//将1到9的数字转换成对应的字符型“1”到“9”
{
	char ch;
	ch = m + '0'; //"0"的ASCII值为48.
	return ch;
}

int main()
{
	char ch;
	int num,temp,k;
	int i = 10;
	while(i >= 0)
	{
		int j = 0;
		cout<<"请输入整数(5位)：";
		cin>>num;
		temp = num;
		char result[5] = {'0','0','0','0','0'};
		while(num)
		{
			k = num % 10;
			ch = exchange(k);
			result[j] = ch;
			num = num / 10;
			j++;
		}
		cout<<"整数"<<temp<<"转换后的字符串为：";
		for(int m = 4; m >= 0; m--)
		{
			cout<<result[m]<<" ";
		}
		i--;
		cout<<endl;
	}
	system("pause");
	return 0;
}