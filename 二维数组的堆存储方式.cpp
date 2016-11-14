#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef char datatype;

typedef struct arry
{
	datatype **data;
	int row;
	int col;
};

datatype ** init_arry(arry &a, int row, int col, datatype p[][4])
{
	a.data = (datatype **)malloc(sizeof(datatype *) * row);

	for(int i = 0; i < row; i++)
		a.data[i] = (datatype *)malloc(sizeof(datatype) * col);
	a.row = row;
	a.col = col;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			a.data[i][j] = p[i][j];
	return a.data;
}
void print_arry_1(arry *p)
{
	for(int i = 0; i < p->row; i++)
		for(int j = 0; j < p->col; j++)
			cout<<p->data[i][j]<<"\t";
	cout<<endl;
}

void print_arry_2(datatype **p, int row, int col)//直接传递二维数组的指针
{
	cout<<"传递的二维数组的指针进行遍历：\n";
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			cout<<p[i][j]<<"\t";
	cout<<endl;
}
int main()
{
	arry my_arry;
	datatype a[3][4] = {'h', 'u','a','n','g','j','i','a','n','j','u','n'};
	datatype **new_arry = init_arry(my_arry, 3, 4, a);
	print_arry_1(&my_arry);
	print_arry_2(new_arry, 3, 4);
	system("pause");
	return 0;
}