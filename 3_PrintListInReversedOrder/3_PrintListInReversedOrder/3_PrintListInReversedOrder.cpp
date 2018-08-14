// 3_PrintListInReversedOrder.cpp : 定义控制台应用程序的入口点。
//
//输入一个链表，从尾到头打印链表每个节点的值。

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

typedef struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

class Solution
{
public:
	//1.递归方式
	vector<int> dev;
	vector<int> printListFromToHead(ListNode *head)
	{
		if (head !=NULL)
		{
			if (head->next != NULL)
			{
				dev = printListFromToHead(head->next);
			}
			dev.push_back(head->val);
		}
		return dev;
	}

	//2.链表自翻转然后输出
	vector<int> printListFromToHead(ListNode *head)
	{
		vector<int> vec;
		ListNode* buff = head;
		ListNode* pre = buff;
		if (head == NULL)
		{
			return vec;
		}
		while(head->next != NULL)
		{
			buff = head->next;
			head->next = buff->next;
			buff->next = pre;
			pre = buff;
		}
		while (buff)
		{
			vec.push_back(buff->val);
			buff = buff->next;
		}
		return vec;
	}
	//3.用库函数，每次扫描一个节点，将该结点数据存入vector中，
	//如果该节点有下一节点，将下一节点数据直接插入vector最前面，
	//直至遍历完，或者直接加在最后，最后调用reverse
	vector<int> printListFromTailToHead(struct ListNode* head) 
	{
		vector<int> value;
		if(head != NULL)
		{
			value.insert(value.begin(),head->val);
			while(head->next != NULL)
			{
				value.insert(value.begin(),head->next->val);
				head = head->next;
			}         

		}
		return value;
	}
};

int main()
{
	return 0;
}

