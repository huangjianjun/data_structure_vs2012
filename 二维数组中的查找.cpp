#include<iostream>
using namespace std;
#include<stdio.h>

void print_n_postion(int *a,  int rows, int cols, int n)
{
	if(a != NULL && rows > 0 && cols > 0)
	{
		int row = 0;
		int col = cols - 1;
		while(row < rows && col >= 0)
		{
			if(a[row*cols + col] == n)
			{
				cout<<"a["<<row*cols + col<<"] = "<<a[row*cols + col]<<endl;
				cout<<"n = "<<n<<endl;
				break;
			}
			if (a[row*cols + col] > n)
			{
				col--;
			}
			else
			{
				row++;
			}
		}
	}
}

int main()
{
	int a[3][4] = {{6,9,10,15},{7,11,14,18},{8,13,17,21}};
	print_n_postion((int *)a, 3, 4, 13);
	system("pause");
	return 0;
}

//�ܽ᣺����ÿ�ζ���ȡ��������Ͻǵ�ֵ��������ֵ���бȽϣ��ٽ�����Ӧ��������Ҳ����ѡȡ���½ǵ����֡������Ҷ�����ѡȡ���ϽǺ����½ǵ�ֵ����ָoffer 38ҳ��