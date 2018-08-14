// 25_SymmetricalBinaryTree.cpp : 定义控制台应用程序的入口点。
//
// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。
#include "stdafx.h"
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	/*
    //递归版本
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot,pRoot);
	}
     
	bool isSymmetrical(TreeNode* pRoot1,TreeNode* pRoot2)
	{
		if(pRoot1==NULL&&pRoot2==NULL)
			return true;
		if(pRoot1==NULL || pRoot2==NULL)           
			return false;
		if(pRoot1->val!=pRoot2->val)
			return false;
		return isSymmetrical(pRoot1->left,pRoot2->right) && isSymmetrical(pRoot1->right,pRoot2->left);
	}
    */
    //非递归版本
    bool isSymmetrical(TreeNode* root)
    {
        if(root==NULL) return true;
		queue<TreeNode*> q1,q2;
		TreeNode *left,*right;
		q1.push(root->left);
		q2.push(root->right);
		while(!q1.empty() && !q2.empty())
		{
			left = q1.front();
			q1.pop();
			right = q2.front();
			q2.pop();
			//两边都是空
			if(NULL==left && NULL==right)
				continue;
			//只有一边是空
			if(NULL==left||NULL==right)
				return false;
			if (left->val != right->val)
				return false;
			q1.push(left->left);
			q1.push(left->right);
			q2.push(right->right);
			q2.push(right->left);
		}
         
		return true;
    }

};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

