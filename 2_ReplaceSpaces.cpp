// 2_ReplaceSpaces.cpp : �������̨Ӧ�ó������ڵ㡣
//
//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
//���磬���ַ���ΪWe Are Happy.
//�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

#include "stdafx.h"
#include <string>
#include <iostream>

class Solution
{
	public:
	void replaceSpace(char *str, int length)
	{
		//ͨ������ո��������ָ��ֱ��ָ��ӳ����ַ������ĩβ���Ӻ���ǰ���
		int count = 0;
		for (int i = 0; i< length; i++)
		{
			if (str[i] == ' ')
			{
				count++;
			}
		}
		int newLength = length + count * 2;
		for (int i =length; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				str[newLength--] = '0';
				str[newLength--] = '2';
				str[newLength--] = '%';
			}
			else
			{
				str[newLength--] = str[i];
			}
		}
	}
};


int main()
{
	return 0;
}

