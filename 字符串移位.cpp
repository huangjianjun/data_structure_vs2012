#include <iostream>
using namespace std;
#include<stdlib.h>

char* shifting(char *a, int n)
{
	int m = strlen(a);
	int d = m - n;
	char *b = (char *)malloc(m*sizeof(char)+1);//���һ��λ�ô洢'\0'
	*(b+m) = '\0';//���ַ����ռ����һλ����Ϊ������־'\0'
	char *temp = (char *)malloc((n+1)*sizeof(char));
	char *p = temp;
	for(int j = d; j < m; j++)//��������λ��nλ�ַ����浽��̬���ٵ������С�
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
		cout<<"��Ҫ��λ���ַ���Ϊ��"<<s<<endl;
		cout<<"��������λ��λ��:";
		cin>>n;
		q = shifting(s,n);
		cout<<"��λ֮����ַ���Ϊ��"<<q<<endl;
		cout<<"��������Y/N��:";
		cin>>ch;
	}while(ch != 'n');
	system("pause");
	return 0;
}