#include "iostream"
using namespace std;
#include"stdlib.h"

int find_only_1(int num, int *arrary)
{
	int temp;
	int sum = 0;
	int count = 0;
	while( num != 0)
	{
		temp = num % 10;
		num = num / 10;
		arrary[count++] = temp;
	}
	for (int i = 0; i < count; i++)
		sum = sum + arrary[i];
	if (sum >= 0 && sum <= 9)
		return sum;
	else
		find_only_1(sum, arrary);
}
int main()
{
	char ch;
	int num ;
	do{
		int a[10] = {0};
		cout<<"请输入num: ";
		cin>>num;
		int ret = find_only_1(num, a);
		cout<<"返回的结果："<<ret<<endl;
		cout<<"继续（y/n）: ";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}