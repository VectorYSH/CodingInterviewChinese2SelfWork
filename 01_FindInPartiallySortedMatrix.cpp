// 01_FindInPartiallySortedMatrix.cpp : �������̨Ӧ�ó������ڵ㡣
//
//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
//	ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
//	����������һ����ά�����һ���������ж��������Ƿ��и�������
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
	public:
	bool Find(int target, vector<vector<int> > array)
	{
		////�����Ͻ������½Ǳ���
		//int column = array.size();//��
		//int row = array[0].size();//��
		//for (int i = 0,j = column -1; i <row && j >= 0;)
		//{
		//	if (target == array[i][j])
		//	{
		//		return true;
		//	}
		//	else if (target < array[i][j])
		//	{
		//		j--;
		//	}
		//	else 
		//	{
		//		i++;
		//	}
		//}

		//�����½������ϽǱ���
		int i;
		int j;
		int row = array.size();
		int column = array[0].size();
		for (i = row - 1, j = 0; i >= 0 && j < column;)
		{
			if (target == array[i][j])
			{
				return true;
			}
			if (target < array[i][j])
			{
				i--;				
			}
			if (target > array[i][j])
			{
				j++;
			}
		}
		return false;
	}
};

int main()
{

	return 0;
}

