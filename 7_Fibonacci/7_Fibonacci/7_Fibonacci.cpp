// 7_Fibonacci.cpp : 定义控制台应用程序的入口点。
//
//大家都知道斐波那契数列，现在要求输入一个整数n，
//请你输出斐波那契数列的第n项。
//n<=39

//迭代（Iteration） VS 递归（Recursion）
//关于动态规划三个条件：最优子结构、无后效性、子问题重叠这些就不谈了

#include "stdafx.h"
#include <iostream>
using namespace std;

class Soultion 
{
public:
	int Fibonacci(int n)
	{
		if (n > 39)
		{
			return false;
		}
		int f = 0;
		int g = 1;
		while (n--)
		{
			f += g;
			g = f - g;
		}
		return f;
	}
};

int main()
{
	int n, m;
	Soultion result;
	cin >> n;
	m = result.Fibonacci(n);
	cout << m <<endl;

	return 0;
}

