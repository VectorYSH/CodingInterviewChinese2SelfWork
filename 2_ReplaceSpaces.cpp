// 2_ReplaceSpaces.cpp : 定义控制台应用程序的入口点。
//
//请实现一个函数，将一个字符串中的空格替换成“%20”。
//例如，当字符串为We Are Happy.
//则经过替换之后的字符串为We%20Are%20Happy。

#include "stdafx.h"
#include <string>
#include <iostream>

class Solution
{
	public:
	void replaceSpace(char *str, int length)
	{
		//通过计算空格次数，将指针直接指向加长后字符串后的末尾，从后往前添加
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

