// 9_RobotMove.cpp : 定义控制台应用程序的入口点。
//
// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？


//1.从(0,0)开始走，每成功走一步标记当前位置为true,然后从当前位置往四个方向探索，
//返回1 + 4 个方向的探索值之和。
//2.探索时，判断当前节点是否可达的标准为：
//1）当前节点在矩阵内；
//2）当前节点未被访问过；
//3）当前节点满足limit限制。

#include "stdafx.h"

#include <cstdio>

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);

int movingCount(int threshold, int rows, int cols)
{
	if(threshold < 0 || rows <= 0 || cols <= 0)
		return 0;

	bool *visited = new bool[rows * cols];
	for(int i = 0; i < rows * cols; ++i)
		visited[i] = false;

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;

	return count;
}

//计算最大移动位置
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if(check(threshold, rows, cols, row, col, visited))
	{
		visited[row * cols + col] = true;
		//标记访问过，这个标志flag不需要回溯，因为只要被访问过即可。
		//因为如果能访问，访问过会加1.不能访问，也会标记下访问过。
		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col,	 visited)
				  + movingCountCore(threshold, rows, cols, row,		col - 1, visited)
				  + movingCountCore(threshold, rows, cols, row + 1, col,	 visited)
				  + movingCountCore(threshold, rows, cols, row,		col + 1, visited);
	}

	return count;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if(row >= 0 && row < rows && col >= 0 && col < cols
		&& getDigitSum(row) + getDigitSum(col) <= threshold
		&& !visited[row* cols + col])
		return true;

	return false;
}

int getDigitSum(int number)
{
	int sum = 0;
	while(number > 0)
	{
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

// ====================测试代码====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
	if(testName != nullptr)
		printf("%s begins: ", testName);

	if(movingCount(threshold, rows, cols) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

// 方格多行多列
void test1()
{
	test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
	test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
	test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
	test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
	test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
	test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
	test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
	test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
	test("Test9", -10, 10, 10, 0);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return 0;
}

