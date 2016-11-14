#include<stdio.h>
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

int main()
{
	vector<string> vec;
	vector<string>::iterator it;
	int i,num;
	char *str[10] = {"huang","jian","jun","vector","test"};
	for(i = 0; i < strlen(*str); i++)
	{
		vec.push_back(*(str+i));
	}
	//利用下标索引来访问vector
	num = vec.size();
	cout<<"利用索引访问vector:\n";
	for(i= 0; i < num; i++)
	{
		cout<<vec[i]<<"\t";
	}
	cout<<endl;
	//利用迭代器来访问vector
	cout<<"利用迭代器来访问vector:\n";
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;
	
	
	//在指定的位置插入元素
	vec.insert(vec.begin() + 3, "love");//在第3个位置上插入
	vec.push_back("success!");// 在尾部插入元素
	cout<<"插入元素后vector: \n";
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;
	
	//测试删除元素
	cout<<"删除元素后vector: \n";
	vec.erase(vec.begin()+3);
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;

	//测试元素反转，必须包含<algorithm>文件
	reverse(vec.begin(), vec.end());
	cout<<"vector 中元素翻转： \n";
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;
	//测试元素排序，必须包含<algorithm>文件
	sort(vec.begin(), vec.end());
	cout<<"vector排序后：\n";
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;

	//测试清空vector操作
	vec.clear();
	//测试empty函数
	if(vec.empty())
		cout<<"null"<<endl;
	else
		cout<<"no null"<<endl;
	system("pause");
	return 0;
}