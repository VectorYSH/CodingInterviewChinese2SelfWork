// 5_QueueWithTwoStacks.cpp : 定义控制台应用程序的入口点。
//
//用两个栈来实现一个队列，
//完成队列的Push和Pop操作。
//队列中的元素为int类型。

//<分析>：
//入队：将元素进栈A
//出队：判断栈B是否为空，如果为空，则将栈A中所有元素pop，并push进栈B，栈B出栈；
//	 如果不为空，栈B直接出栈。
//用两个队列实现一个栈的功能?要求给出算法和思路!
//<分析>：
//入栈：将元素进队列A
//出栈：判断队列A中元素的个数是否为1，如果等于1，则出队列，否则将队列A中的元素   以此出队列并放入队列B，直到队列A中的元素留下一个，然后队列A出队列，再把   队列B中的元素出队列以此放入队列A中。
#include "stdafx.h"
#include <stack>
#include <queue>
using namespace std;
class Solution
{
private:
	stack<int> stack1;
	stack<int> stack2;
public:
	void push(int node)
	{
		stack1.push(node);
	}
	int pop()
	{
		int a;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				a = stack1.top();
				stack2.push(a);
				stack1.pop();
			}
		}
		a = stack2.top();
		stack2.pop();
		return a;
	}
};

int main()
{
	return 0;
}

