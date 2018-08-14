// 7_Fibonacci.cpp : �������̨Ӧ�ó������ڵ㡣
//
//��Ҷ�֪��쳲��������У�����Ҫ������һ������n��
//�������쳲��������еĵ�n�
//n<=39

//������Iteration�� VS �ݹ飨Recursion��
//���ڶ�̬�滮���������������ӽṹ���޺�Ч�ԡ��������ص���Щ�Ͳ�̸��

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

