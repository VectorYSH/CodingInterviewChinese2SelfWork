// 15_DeleteNodeInList.cpp : 定义控制台应用程序的入口点。
//
// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。

// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。
#include "stdafx.h"
#include <cstdio>

struct ListNode
{
	int       m_nValue;
	ListNode* m_pNext;
};

struct ListNode2 {
	int val;
	struct ListNode2 *next;
	ListNode2(int x) :
	val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode2* deleteDuplication2(ListNode2* pHead)
	{
		if(pHead==NULL||pHead->next==NULL) return pHead;
		else
		{
				//新建一个节点，防止头结点要被删除
				ListNode2* newHead=new ListNode2(-1);
				newHead->next=pHead;
				ListNode2* pre=newHead;
				ListNode2* p=pHead;
				ListNode2* next=NULL;
				while(p!=NULL && p->next!=NULL)
				{
					next=p->next;
					if(p->val==next->val)//如果当前节点的值和下一个节点的值相等
					{
						while(next!=NULL && next->val==p->val)//向后重复查找
								next=next->next;
						pre->next=next;//指针赋值，就相当于删除
						p=next;
					}
					else//如果当前节点和下一个节点值不等，则向后移动一位
					{
						pre=p;
						p=p->next;
					}
				}
				return newHead->next;//返回头结点的下一个节点							                  
		}
	}
};


ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);


void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted);
void Test(ListNode* pListHead, ListNode* pNode);
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();


void DeleteDuplication(ListNode** pHead);

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;

	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if(pCurrent == nullptr)
	{
		printf("Error to connect two nodes.\n");
		//exit(1);
	}

	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{ 
	if(pNode == nullptr)
	{
		printf("The node is nullptr\n");
	}
	else
	{
		printf("The key in node is %d.\n", pNode->m_nValue);
	}
}

void PrintList(ListNode* pHead)
{
	printf("PrintList starts.\n");

	ListNode* pNode = pHead;
	while(pNode != nullptr)
	{
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while(pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if(*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != nullptr)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if(pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pToBeDeleted = nullptr;
	if((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;

		if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if(pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}


void DeleteDuplication(ListNode** pHead)
{
	if(pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while(pNode != nullptr)
	{
		ListNode *pNext = pNode->m_pNext;
		bool needDelete = false;
		if(pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;

		if(!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_nValue;
			ListNode* pToBeDel = pNode;
			while(pToBeDel != nullptr && pToBeDel->m_nValue == value)
			{
				pNext = pToBeDel->m_pNext;

				delete pToBeDel;
				pToBeDel = nullptr;

				pToBeDel = pNext;
			}

			if(pPreNode == nullptr)
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode = pNext;
		}
	}
}









void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if(!pListHead || !pToBeDeleted)
		return;

	// 要删除的结点不是尾结点
	if(pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}
	// 链表只有一个结点，删除头结点（也是尾结点）
	else if(*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}
	// 链表中有多个结点，删除尾结点
	else
	{
		ListNode* pNode = *pListHead;
		while(pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;            
		}

		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode)
{
	printf("The original list is: \n");
	PrintList(pListHead);

	printf("The node to be deleted is: \n");
	PrintListNode(pNode);

	DeleteNode(&pListHead, pNode);

	printf("The result list is: \n");
	PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode3);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode5);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode1);

	DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
	Test(nullptr, nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}


