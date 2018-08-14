// 22_MergeSortedLists.cpp : �������̨Ӧ�ó������ڵ㡣
//
// ������25���ϲ��������������
// ��Ŀ������������������������ϲ�����������ʹ�������еĽ����Ȼ�ǰ�
// �յ�������ġ���������ͼ3.11�е�����1������2����ϲ�֮���������������
// ��3��ʾ��

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

