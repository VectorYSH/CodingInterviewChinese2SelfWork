// 26_PrintMatrix.cpp : 定义控制台应用程序的入口点。
//
// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。


/*解题思路：顺时针打印就是按圈数循环打印，一圈包含两
行或者两列，在打印的时候会出现某一圈中只包含一行，
要判断从左向右打印和从右向左打印的时候是否会出现重复打
印，同样只包含一列时，要判断从上向下打印和从下向上打印
的时候是否会出现重复打印的情况*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) 
    {

		vector<int>res;
		res.clear();
		int row=matrix.size();//行数
		int column=matrix[0].size();//列数
		//计算打印的圈数
		int circle=((row<column?row:column)-1)/2+1;//圈数
		for(int i=0;i<circle;i++)
		{
			//从左向右打印
			for(int j=i;j<column-i;j++)
				res.push_back(matrix[i][j]);         
			//从上往下的每一列数据
			for(int k=i+1;k<row-i;k++)
				res.push_back(matrix[k][column-1-i]);
			//判断是否会重复打印(从右向左的每行数据)
			for(int m=column-i-2;(m>=i)&&(row-i-1!=i);m--)
				res.push_back(matrix[row-i-1][m]);
			//判断是否会重复打印(从下往上的每一列数据)
			for(int n=row-i-2;(n>i)&&(column-i-1!=i);n--)
				res.push_back(matrix[n][i]);
		}
		return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

