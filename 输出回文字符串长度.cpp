#include <iostream>
using namespace std;
#include<string>

//������Ļ����ַ�������,�磺abcdeba,��abbaΪ���ַ����е�������ַ���������Ϊ4

int maxnum_huiwen(string &str)
{
	int length = str.length();
	int start,end,count;
	int flag = 0;
	int num_max = 0;
	for (int i = 0; i < length; i++)
	{
		start = 0;
		count = 0;
		end = length -1 - i;
		while(start < end)
		{
			if(str[start] == str[end])
			{
				flag = 1;
				count++;
				start++;
				end--;
				int temp_start = start;
				int temp_end = end;
				int len = end - start + 1;
				for(int j = 0; j < len; j++)
				{
					start = temp_start;
					end = temp_end - j;
					while(start < end)
					{
						if(str[start] == str[end])
						{
							flag = 1;
							count++;
							start++;
							end--;
						}
						else
							start++;
					}
				}
			}
			else
				start++;
		}
		if(num_max <= count)
			num_max = count;
	}
	if(length == 1 || flag == 0)
		return 1;
	else
		return num_max;	
}

int main()
{
	string str;
	char ch;
	int num = 0;
	do{
		cout<<"�������ַ�����";
		cin>>str;
		num = maxnum_huiwen(str);
		if(num == 1)
			cout<<"�������ַ����ĳ���Ϊ��"<<num<<endl;
		else
			cout<<"�������ַ����ĳ���Ϊ��"<<2*num<<endl;
		cout<<"����?(y/n):";
		cin>>ch;
	}while(ch != 'n');
	system("pause");
	return 0;
}