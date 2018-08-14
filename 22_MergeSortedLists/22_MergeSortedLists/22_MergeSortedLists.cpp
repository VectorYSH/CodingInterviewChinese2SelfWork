// 22_MergeSortedLists.cpp : 定义控制台应用程序的入口点。
//
// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。

#include "stdafx.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if(pHead1 == nullptr)
		return pHead2;
	else if(pHead2 == nullptr)
		return pHead1;

	ListNode* pMergedHead = nullptr;

	if(pHead1->val < pHead2->val)
	{
		pMergedHead = pHead1;
		pMergedHead->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		pMergedHead = pHead2;
		pMergedHead->next = Merge(pHead1, pHead2->next);
	}

	return pMergedHead;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

