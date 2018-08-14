// 3_PrintListInReversedOrder.cpp : �������̨Ӧ�ó������ڵ㡣
//
//����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��

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
	//1.�ݹ鷽ʽ
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

	//2.�����Է�תȻ�����
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
	//3.�ÿ⺯����ÿ��ɨ��һ���ڵ㣬���ý�����ݴ���vector�У�
	//����ýڵ�����һ�ڵ㣬����һ�ڵ�����ֱ�Ӳ���vector��ǰ�棬
	//ֱ�������꣬����ֱ�Ӽ������������reverse
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

