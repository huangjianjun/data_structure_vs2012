#include<iostream>
using namespace std;
#include <stdlib.h>
char * Cstr(void)
{
	char b[10] = "like";
	printf("%p\n", b);
	return b;	//���ؾֲ�����b,�Ӻ������н������b�����Ŀռ䱻�ͷţ�
}

int main(void) 
{ 
	char *a=Cstr();//ָ��a��ֵΪb��һ������ֵ����ʱ��b�Ѿ���Ч�ˣ�������a��������鱻�ͷŵĿռ��ǷǷ��ģ��ÿ��ڴ��Ѿ�������ϵͳ���Ϊδʹ�ã����Ա���������ʹ�ã�����δ����������ռ��ǰ�������������Ȼ��b�����ֵ��
	printf("%p\n", a);
	printf("%c\n",*(a+1));
	printf("%c\n",*(a+2));
	system("pause");
	return 0; 
} 
