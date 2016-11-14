#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[6] = {23,54,12,89,65,4};
	int temp = 0;
	cout<<"ÅÅÐòÇ°£º";
	for (int m=0; m<6; m++)
	{
		cout<<a[m]<<"\t";
	}
	cout<<endl;
	for ( int i=0; i<6; i++)
	{
		for (int j=i; j<6; j++)
		{
			if (a[i] >= a[j])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	cout<<"ÅÅÐòºó£º";
	for (int k=0; k<6; k++)
	{
		cout<<a[k]<<"\t";
	}
	cout<<endl;
	system("pause");
	return 0;
}
