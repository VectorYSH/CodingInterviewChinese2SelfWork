// 21_ReverseList.cpp : �������̨Ӧ�ó������ڵ㡣
//
// ������24����ת����
// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
// ͷ��㡣
#include "stdafx.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};


//�ݹ�
//ListNode* ReverseList(ListNode* pHead) 
//{
//	//�������Ϊ�ջ���������ֻ��һ��Ԫ��
//	if(pHead==NULL||pHead->next==NULL) return pHead;       
//	//�ȷ�ת����������ߵ������ĩ�˽��
//	ListNode* pReverseNode=ReverseList(pHead->next);         
//	//�ٽ���ǰ�ڵ�����Ϊ����ڵ�ĺ����ڵ�
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

