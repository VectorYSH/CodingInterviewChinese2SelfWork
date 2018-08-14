// 01_FindInPartiallySortedMatrix.cpp : 定义控制台应用程序的入口点。
//
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，
//	每一列都按照从上到下递增的顺序排序。请完成一个函数，
//	输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
	public:
	bool Find(int target, vector<vector<int> > array)
	{
		////从右上角往左下角遍历
		//int column = array.size();//列
		//int row = array[0].size();//行
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

		//从左下角往右上角遍历
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

