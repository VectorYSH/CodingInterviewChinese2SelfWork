﻿// 27_MinInStack.cpp : 定义控制台应用程序的入口点。
//
// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

#include "stdafx.h"
#include "StackWithMin.h"

using namespace std;


//应用一个辅助栈，压的时候，如果A栈的压入比B栈压入大，
//B栈不压，，，，小于等于，AB栈同时压入，出栈，
//如果，AB栈顶元素不等，A出，B不出。
class Solution {
public:
	stack<int> stack1,stack2;
     
	void push(int value) 
    {
		stack1.push(value);
		if(stack2.empty())
			stack2.push(value);
		else if(value<=stack2.top())
		{
			stack2.push(value);
		}
	}
     
	void pop() 
    {
		if(stack1.top()==stack2.top())
			stack2.pop();
		stack1.pop();     
	}
     
	int top() 
    {
		return stack1.top();       
	}

	int min() 
    {
		return stack2.top();
	}
};

void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
	if(testName != nullptr)
		printf("%s begins: ", testName);

	if(stack.min() == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

int main(int argc, char* argv[])
{
	StackWithMin<int> stack;

	stack.push(3);
	Test("Test1", stack, 3);

	stack.push(4);
	Test("Test2", stack, 3);

	stack.push(2);
	Test("Test3", stack, 2);

	stack.push(3);
	Test("Test4", stack, 2);

	stack.pop();
	Test("Test5", stack, 2);

	stack.pop();
	Test("Test6", stack, 3);

	stack.pop();
	Test("Test7", stack, 3);

	stack.push(0);
	Test("Test8", stack, 0);

	return 0;
}