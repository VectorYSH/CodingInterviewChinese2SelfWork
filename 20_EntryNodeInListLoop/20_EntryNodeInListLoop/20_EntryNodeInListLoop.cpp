// 20_EntryNodeInListLoop.cpp : 定义控制台应用程序的入口点。
//
// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

//左神讲的
//先说个定理：两个指针一个fast、一个slow同时从一个链表的头部出发
//fast一次走2步，slow一次走一步，如果该链表有环，两个指针必然在环内相遇
//此时只需要把其中的一个指针重新指向链表头部，另一个不变（还在环内），
//这次两个指针一次走一步，相遇的地方就是入口节点。

#include "stdafx.h"


///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) :
//        val(x), next(NULL) {
//    }
//};
//*/
//class Solution {
//public:
//    ListNode* EntryNodeOfLoop(ListNode* pHead)
//    {
//        ListNode *fast = pHead;
//        ListNode *slow = pHead;
//        while(fast != NULL && fast->next !=NULL)
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//            if(fast == slow)
//                break;
//        }
//        if(fast == NULL || fast->next == NULL)
//            return NULL;
//        fast = pHead;
//        while(fast != slow)
//        {
//            fast = fast->next;
//            slow = slow->next;
//        }
//        return fast;
//    }
//};

struct ListNode {
	int val;
	struct ListNode *m_pNext;
	ListNode(int x) :
	val(x), m_pNext(NULL) {
	}
};


ListNode* MeetingNode(ListNode* pHead)
{
	if(pHead == nullptr)
		return nullptr;

	ListNode* pSlow = pHead->m_pNext;
	if(pSlow == nullptr)
		return nullptr;

	ListNode* pFast = pSlow->m_pNext;
	while(pFast != nullptr && pSlow != nullptr)
	{
		if(pFast == pSlow)
			return pFast;

		pSlow = pSlow->m_pNext;

		pFast = pFast->m_pNext;
		if(pFast != nullptr)
			pFast = pFast->m_pNext;
	}

	return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if(meetingNode == nullptr)
		return nullptr;

	// 得到环中结点的数目
	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;
	while(pNode1->m_pNext != meetingNode)
	{
		pNode1 = pNode1->m_pNext;
		++nodesInLoop;
	}

	// 先移动pNode1，次数为环中结点的数目
	pNode1 = pHead;
	for(int i = 0; i < nodesInLoop; ++i)
		pNode1 = pNode1->m_pNext;

	// 再移动pNode1和pNode2
	ListNode* pNode2 = pHead;
	while(pNode1 != pNode2)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}

	return pNode1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

