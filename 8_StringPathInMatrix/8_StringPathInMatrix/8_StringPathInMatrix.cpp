// 8_StringPathInMatrix.cpp : 定义控制台应用程序的入口点。
//
// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H


//回溯
//基本思想：
//0.根据给定数组，初始化一个标志位数组，初始化为false，表示未走过，true表示已经走过，不能走第二次
//1.根据行数和列数，遍历数组，先找到一个与str字符串的第一个元素相匹配的矩阵元素，进入judge
//2.根据i和j先确定一维数组的位置，因为给定的matrix是一个一维数组
//3.确定递归终止条件：越界，当前找到的矩阵值不等于数组对应位置的值，已经走过的，这三类情况，都直接false，说明这条路不通
//4.若k，就是待判定的字符串str的索引已经判断到了最后一位，此时说明是匹配成功的
//5.下面就是本题的精髓，递归不断地寻找周围四个格子是否符合条件，只要有一个格子符合条件，就继续再找这个符合条件的格子的四周是否存在符合条件的格子，直到k到达末尾或者不满足递归条件就停止。
//6.走到这一步，说明本次是不成功的，我们要还原一下标志位数组index处的标志位，进入下一轮的判断。
//

#include "stdafx.h"
#include <string.h>


class Solution 
{
public:
	/*
	大家好，我是yishuihan，这个题目是回溯法的典型题目；
	还有八皇后问题也是经典的回溯法例题，大家可以参考;在《剑指offer》书中也给出了八皇后问题的思路；
	不过，那个是在全排列问题中引出来的。其实回溯法也是全排列的一种方案，在本题中，也就是尝试了
	matrix矩阵中所有点作为起点的方法，然后依据这个点进行向四个方向的递归；
	在递归中，不满足题目的会自动出栈回到上一个状态；
	*/
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if(matrix == NULL || rows < 1 || cols < 1 || str == NULL) return false;
		bool *flag = new bool[rows * cols];
		memset(flag,false,rows * cols);
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(haha(matrix, rows, cols, i, j, str, 0, flag))
				{
					return true;
				}
			}
		}
		delete[] flag;
		return false;
	}
	/*参数说明*/
	bool haha(char* matrix, int rows, int cols, int i, int j, char* str, int k, bool* flag)
	{
		//因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
		int index = i * cols + j;
		//flag[index]==true,说明被访问过了，那么也返回true;
		if(i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == true)
			return false;
		//字符串已经查找结束，说明找到该路径了
		if(str[k + 1] == '\0') return true;
		//向四个方向进行递归查找,向左，向右，向上，向下查找
		flag[index] = true;//标记访问过
		if(	  haha(matrix, rows, cols, i - 1,	j,		str, k + 1, flag)
		   || haha(matrix, rows, cols, i + 1,	j,		str, k + 1, flag)
		   || haha(matrix, rows, cols, i,		j - 1,	str, k + 1, flag)
		   || haha(matrix, rows, cols, i,		j + 1,	str, k + 1, flag))
		{
			return true;
		}
		flag[index] = false;
		return false;
	}
};


int main()
{
	return 0;
}

