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
	//�����±�����������vector
	num = vec.size();
	cout<<"������������vector:\n";
	for(i= 0; i < num; i++)
	{
		cout<<vec[i]<<"\t";
	}
	cout<<endl;
	//���õ�����������vector
	cout<<"���õ�����������vector:\n";
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;
	
	
	//��ָ����λ�ò���Ԫ��
	vec.insert(vec.begin() + 3, "love");//�ڵ�3��λ���ϲ���
	vec.push_back("success!");// ��β������Ԫ��
	cout<<"����Ԫ�غ�vector: \n";
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;
	
	//����ɾ��Ԫ��
	cout<<"ɾ��Ԫ�غ�vector: \n";
	vec.erase(vec.begin()+3);
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;

	//����Ԫ�ط�ת���������<algorithm>�ļ�
	reverse(vec.begin(), vec.end());
	cout<<"vector ��Ԫ�ط�ת�� \n";
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;
	//����Ԫ�����򣬱������<algorithm>�ļ�
	sort(vec.begin(), vec.end());
	cout<<"vector�����\n";
	for( it = vec.begin(); it != vec.end(); it++)
		cout<<*it<<"\t";
	cout<<endl;

	//�������vector����
	vec.clear();
	//����empty����
	if(vec.empty())
		cout<<"null"<<endl;
	else
		cout<<"no null"<<endl;
	system("pause");
	return 0;
}