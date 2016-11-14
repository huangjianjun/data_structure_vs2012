#include <iostream>
using namespace std;
#include<stdlib.h>

char* shifting(char *a, int n)
{
	int m = strlen(a);
	int d = m - n;
	char *b = (char *)malloc(m*sizeof(char)+1);//最后一个位置存储'\0'
	*(b+m) = '\0';//将字符串空间最后一位设置为结束标志'\0'
	char *temp = (char *)malloc((n+1)*sizeof(char));
	char *p = temp;
	for(int j = d; j < m; j++)//将向右移位的n位字符保存到动态开辟的数组中。
	{
		*temp++ = a[j];
	}
	*temp = '\0';

	for(int i = d-1; i >= 0; i--)
		{
			b[i+n] = a[i];
		}
		for(int k = 0; k < n; k++)
		{
			b[k] = *p++;
		}
		return b;
	 
	 
}


int main()
{
	int n;
	char *q = NULL;
	char *s = "123456789";
	char ch;
	do{
		cout<<"将要移位的字符串为："<<s<<endl;
		cout<<"请输入移位的位数:";
		cin>>n;
		q = shifting(s,n);
		cout<<"移位之后的字符串为："<<q<<endl;
		cout<<"继续？（Y/N）:";
		cin>>ch;
	}while(ch != 'n');
	system("pause");
	return 0;
}