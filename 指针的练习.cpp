#include<stdio.h>
int f1(int * p)//��������ַ�����β�
{
	*p = 100;
	return 0;
}
int f2(int p)
{
	p = 100;
	return 0;
}
int main()
{
	int i = 99;
	f2(i);//�޸�ʧ�ܣ���ΪiΪ�ֲ�������
	//f1(&i);//�޸ĳɹ�����ַ������ڴ���Ψһ��
	printf("i = %d\n",i);
	getchar();

}