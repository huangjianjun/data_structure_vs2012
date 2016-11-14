#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
struct times
{
	int years;
	int month;
	int day;
};

int find(struct times * p)
{
	int s[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int days = 0;
	int i = 0;
	while (i < p->month - 1)
	{
		days += s[i];
		++i;
	}
	days += p->day;
	if (p->month >2)
	{
		if ((p->years % 4 == 0 && p->years % 100 != 0) || p->years % 400 == 0)
			days += 1;
	}
	return days;
}

int main()
{
	struct times data;
	char s ;
	int ret;
	int num;
	int m;
	do{
		printf("-------------------------------------------------------\n");
		printf("请输入日期（XX年XX月XX日）\n");
		printf("年：");
		cin>>m;
		data.years = m;
		printf("月：");
		cin>>m;
		data.month = m;
		printf("日：");
		cin>>m;
		data.day = m;
		ret = find(&data);
		num = ret % 7;
		num -= num;
		num = ret / 7;
		printf("这是%d年的第%d天,第%d周！\n",data.years ,ret,num);
		printf("-------------------------------------------------------\n");
		printf("是否继续进行查询?(y/n):");
		cin>>s;
	}while( s != 'n');
	printf("程序退出!\n");
	system("pause");
	return 0;

}

