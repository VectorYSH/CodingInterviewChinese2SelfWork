// 11_Power.cpp : 定义控制台应用程序的入口点。
//
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>



double Power(double base, int exponent)
{
	long long p = abs((long long)exponent);
	double r = 1.0;
	while(p){
		if(p & 1) 
			r *= base;
		base *= base;
		p >>= 1;
	}
	return exponent < 0 ? 1/ r : r;   
}
	/**
	* 1.全面考察指数的正负、底数是否为零等情况。
	* 2.写出指数的二进制表达，例如13表达为二进制1101。
	* 3.举例:10^1101 = 10^0001*10^0100*10^1000。
	* 4.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。
	*/

double PowerTest(double base, int n)
{
	double res = 1,curr = base;
	int exponent;
	if(n>0)
	{
		exponent = n;
	}
	else if(n<0)
	{
		if(base==0)
		//throw new RuntimeException("分母不能为0"); 
		exponent = -n;
	}
	else
	{// n==0		        
		return 1;// 0的0次方
	}
	while(exponent!=0)
	{
		if((exponent&1)==1)
		res*=curr;
		curr*=curr;// 翻倍
		exponent>>=1;// 右移一位
	}
	return n>=0?res:(1/res);
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

