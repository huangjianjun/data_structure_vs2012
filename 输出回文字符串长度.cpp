#include <iostream>
using namespace std;
#include<string>

//输出最大的回文字符串长度,如：abcdeba,则abba为该字符串中的最长回文字符串，长度为4

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
		cout<<"请输入字符串：";
		cin>>str;
		num = maxnum_huiwen(str);
		if(num == 1)
			cout<<"最大回文字符串的长度为："<<num<<endl;
		else
			cout<<"最大回文字符串的长度为："<<2*num<<endl;
		cout<<"继续?(y/n):";
		cin>>ch;
	}while(ch != 'n');
	system("pause");
	return 0;
}