// 4_ConstructBinaryTree.cpp : 定义控制台应用程序的入口点。
//
//输入某二叉树的前序遍历和中序遍历的结果，
//请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
//则重建二叉树并返回。



//递归思想，每次将左右两棵子树当成新的子树进行处理。
//前序的第一个索引就是根节点，在中序数组中找到根节点的位置gen，gen的左边是左子树，右边是右子树。
//进而得到中序遍历的左右子树的两个数组left.vin, right.vin。前序数组的左子树长度为gen+1,可以得到前序遍历的左右子树的数组。
//对上述前序和中序得到的左右子树的数组分别进行二叉树重建，递归求解，递归一次，返回一次根节点。
// 直到数组长度为1，说明左右子树只有一个节点，叶节点，二叉树整理完毕，不用递归建树，直接返回该叶节点，递归结束。
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
	{
		int inlen = vin.size();
		if (inlen == 0)
		{
			return NULL;
		}
		vector<int> left_pre;
		vector<int> right_pre;
		vector<int> left_vin;
		vector<int> right_vin;
		//创建根节点，根节点肯定是前序遍历的第一个数
		TreeNode* head = new TreeNode(pre[0]);
		//找到中序遍历根节点所在位置,存放于变量gen中
		int gen = 0;
		for (int i= 0; i< inlen; i++)
		{
			if (vin[i] == pre[0])
			{
				gen = i;
				break;
			}
		}
		//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
		//利用上述这点，对二叉树节点进行归并
		for (int i = 0; i < gen; i++)
		{
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);
		}
		for (int i = gen + 1; i < inlen; i++)
		{
			right_vin.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}
		//和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
		//递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);
		return head;
	}
	
};

int main()
{
	return 0;
}

