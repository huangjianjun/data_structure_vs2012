#include<iostream>
using namespace std;
#include<stdlib.h>

/*���ڶ�ά������βκ�ʵ�εĴ��ݽ�������
�����ö�ά��������Ϊʵ�λ����βΣ��ڱ����ú����ж��β����鶨��ʱ����ָ������ά���Ĵ�С��Ҳ����ʡ�Ե�һά�Ĵ�С˵�����磺 
void Func(int array[3][10]); 
void Func(int array[][10]); 
���߶��ǺϷ����ҵȼۣ����ǲ��ܰѵڶ�ά���߸���ά�Ĵ�Сʡ�ԣ�������Ķ����ǲ��Ϸ��ģ� 
void Func(int array[][]); 
��Ϊ��ʵ�δ����������������ʼ��ַ�����ڴ��а��������й�����(���д��)�������������к��У�������β��в�˵����������ϵͳ�޷�����ӦΪ�����ж����У�����ָֻ��һά����ָ���ڶ�ά��*/
void func_1(int a[2][3],int rows, int columns)
{
	for( int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout<<a[i][j]<<"  ";
		}
	}
	cout<<endl;
}
//���Խ���ά����ת����һάȥ����
void func_2(int *a, int rows, int columns)
{
	for( int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout<<a[i*columns + j]<<"  ";//ת��Ϊһά���������
		}
	}
	cout<<endl;
}

//Ҳ���Զ�̬������ά���飬���ö�άָ��İ취

void func_3(int **a, int rows, int columns)
{
	for( int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout<<a[i][j]<<"  ";//ת��Ϊһά���������
		}
	}
	cout<<endl;
}
void test_3(int rows, int columns)
{
	cout<<"test func_3:"<<endl;
	int **number = new int *[rows];//��ά�������洢һά����ĵ�ַ
	for(int i = 0; i < rows; i++)
	{
		number[i] = new int[columns];//��άָ�������д����rows��columns���ȵ�һά�����ָ��
		for(int j = 0; j < columns; j++)
		{
			number[i][j] = i*columns + j + 1;//��������ά���鸳ֵ
		}
	}
	func_3(number, rows, columns);
}

void test_1()
{
	int a[2][3] = {{1,2,3},{4,5,6}};
	cout<<"test func_1:"<<endl;
	func_1(a,2,3);
}
void test_2()
{
	int a[2][3] = {{1,2,3},{4,5,6}};
	cout<<"test func_2:"<<endl;
	func_2((int *)a,2,3);
	return;
}
int main()
{
	test_1();
	test_2();
	test_3(4,4);
	system("pause");
	return 0;
}