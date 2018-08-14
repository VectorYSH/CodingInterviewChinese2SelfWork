// 10_CuttingRope.cpp : �������̨Ӧ�ó������ڵ㡣
//
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������14��������
// ��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
// ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
// ���Ƕ��٣����統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
// ʱ�õ����ĳ˻�18��

#include "stdafx.h"
#include <iostream>
#include <cmath>


// ====================��̬�滮====================
int maxProductAfterCutting_solution1(int length)
{
	if(length < 2)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;

	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for(int i = 4; i <= length; ++i)
	{
		max = 0;
		for(int j = 1; j <= i / 2; ++j)
		{
			int product = products[j] * products[i - j];
			if(max < product)
				max = product;

			products[i] = max;
		}
	}

	max =  [length];
	delete[] products;

	return max;
}

// ====================̰���㷨====================
int maxProductAfterCutting_solution2(int length)
{
	if(length < 2)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;

	// �����ܶ�ؼ�ȥ����Ϊ3�����Ӷ�
	int timesOf3 = length / 3;

	// ���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�����ӶΡ�
	// ��ʱ���õķ����ǰ����Ӽ��ɳ���Ϊ2�����Σ���Ϊ2*2 > 3*1��
	if(length - timesOf3 * 3 == 1)
		timesOf3 -= 1;

	int timesOf2 = (length - timesOf3 * 3) / 2;

	return (int) (pow(3, timesOf3)) * (int) (pow(2, timesOf2));
}

// ====================���Դ���====================
void test(const char* testName, int length, int expected)
{
	int result1 = maxProductAfterCutting_solution1(length);
	if(result1 == expected)
		std::cout << "Solution1 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

	int result2 = maxProductAfterCutting_solution2(length);
	if(result2 == expected)
		std::cout << "Solution2 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

