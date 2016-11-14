#include<iostream>
using namespace std;
#include <stdlib.h>

//斐波那契数列的非递归实现，采用从下向上计算的顺序避免从上到下计算中的重复计算

long long fei_squeue(int n)
{
	if(n == 0 || n == 1)
		return n;
	long long one = 0;
	long long two = 1;
	long long mN = 0;
	for (int i = 2; i <= n; i++)
	{
		mN = one + two;
		one = two;
		two = mN;
	}
	return mN;
}

int main()
{
	char ch;
	int n;
	long long result = 0;
	do{
		cout<<"请输入斐波那契数列的n:";
		cin>>n;
		result = fei_squeue(n);
		cout<<"结果为："<<result<<endl;
		cout<<"继续（y/n）:";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}