// 21_ReverseList.cpp : 定义控制台应用程序的入口点。
//
// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。
#include "stdafx.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};


//递归
//ListNode* ReverseList(ListNode* pHead) 
//{
//	//如果链表为空或者链表中只有一个元素
//	if(pHead==NULL||pHead->next==NULL) return pHead;       
//	//先反转后面的链表，走到链表的末端结点
//	ListNode* pReverseNode=ReverseList(pHead->next);         
//	//再将当前节点设置为后面节点的后续节点
//	pHead->next->next=pHead;
//	pHead->next=NULL; 
//	return pReverseNode;
//}

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReversedHead = nullptr;
	ListNode* pNode = pHead;
	ListNode* pPrev = nullptr;
	while(pNode != nullptr)
	{
		ListNode* pNext = pNode->next;

		if(pNext == nullptr)
			pReversedHead = pNode;

		pNode->next = pPrev;

		pPrev = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

