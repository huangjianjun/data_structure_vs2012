#include<stdio.h>
void show_array(int array[] , int n)
{
	printf("\n");
	printf("��������ʽ�������飺");
	for (int i = 0;i <n;i ++)
	{
		printf("%d\t",array[i]);
	}
}
void show_array_point(int * p , int len)
{
	printf("\n");
	printf("ָ����ʽ�������飺");
	for (int i = 0;i <len;i ++)
	{
		printf("%d\t",*(p + i)); 
	}
}
int main()
{
	int a[5] = {6,2,3,4,5};//������ڴ浥Ԫ�������ġ�
	//a[3] == *(a + 3) a�����һ��Ԫ�صĵ�ַ��a+3 ���Կ�����3��intƫ������
	printf("a ���ڴ��ַΪ��%p\n",a);
	printf("a+1 ���ڴ��ַΪ��%p\n",a+1);
	printf("a+2 ���ڴ��ַΪ��%p\n",a+2);
	printf("a+3 ���ڴ��ַΪ��%p\n",a+3);
	printf("a+4 ���ڴ��ַΪ��%p\n",a+4);
	printf("*(a+3) = %d\n",*(a+3));
	printf("*a +3 = %d\n",*a +3);//�ȼ���a[0] + 3
	show_array(a , 5);
	show_array_point(a,5);
	getchar();
	return 0;
}
//ͨ�������޸ı�����ֵֻ�ܴ����ַ���ú���������