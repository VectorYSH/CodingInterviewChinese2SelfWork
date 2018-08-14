// 24_MirrorOfBinaryTree.cpp : 定义控制台应用程序的入口点。
//

// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
/* 先前序遍历这棵树的每个结点，如果遍历到的结点有子结点，就交换它的两个子节点，
当交换完所有的非叶子结点的左右子结点之后，就得到了树的镜像 */

#include "stdafx.h"
#include <stack>

using namespace std;

struct BinaryTreeNode 
{
	int                    m_nValue; 
	BinaryTreeNode*        m_pLeft;  
	BinaryTreeNode*        m_pRight; 
};

//非递归实现中，交换的左右子树后再用栈分别push交换后，
//的左子树和右子树依照上面程序代码是先push左再push右，
//然后再出栈，根据栈的定义先进后出，首先出来的是交换后的右子树


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
    void Mirror(TreeNode *pRoot) 
    {
        //递归实现
		/*if(pRoot==NULL)
            return;
        TreeNode *ptemp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=ptemp;
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);*/
		//非递归实现
		if(pRoot==NULL)
			return;
		stack<TreeNode*> stackNode;
		stackNode.push(pRoot);
		while(stackNode.size())
        {
			TreeNode* tree=stackNode.top();
			stackNode.pop();
			if(tree->left!=NULL || tree->right!=NULL)
            {
				TreeNode *ptemp=tree->left;
				tree->left=tree->right;
				tree->right=ptemp;
			}
			if(tree->left)
				stackNode.push(tree->left);
			if(tree->right)
				stackNode.push(tree->right);
		}
    }
};





void MirrorRecursively(BinaryTreeNode *pNode)
{
	if((pNode == nullptr) || (pNode->m_pLeft == nullptr && pNode->m_pRight))
		return;

	BinaryTreeNode *pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;

	if(pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);  

	if(pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight); 
}

void MirrorIteratively(BinaryTreeNode* pRoot)
{
	if(pRoot == nullptr)
		return;

	std::stack<BinaryTreeNode*> stackTreeNode;
	stackTreeNode.push(pRoot);

	while(stackTreeNode.size() > 0)
	{
		BinaryTreeNode *pNode = stackTreeNode.top();
		stackTreeNode.pop();

		BinaryTreeNode *pTemp = pNode->m_pLeft;
		pNode->m_pLeft = pNode->m_pRight;
		pNode->m_pRight = pTemp;

		if(pNode->m_pLeft)
			stackTreeNode.push(pNode->m_pLeft);

		if(pNode->m_pRight)
			stackTreeNode.push(pNode->m_pRight);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

