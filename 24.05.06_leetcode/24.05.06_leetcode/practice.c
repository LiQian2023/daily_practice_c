#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"


//2024.05.06力扣网刷题
//二叉树的最小深度——树、深度优先搜索、广度优先搜索、二叉树——简单
//给定一个二叉树，找出其最小深度。
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//说明：叶子节点是指没有子节点的节点。
//示例 1：
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：2
//示例 2：
//输入：root = [2, null, 3, null, 4, null, 5, null, 6]
//输出：5
//提示：
//树中节点数的范围在[0, 10^5] 内
//- 1000 <= Node.val <= 1000

int minDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int left = minDepth(root->left);
	int right = minDepth(root->right);
	if (right == 0)
		return left + 1;
	if (left == 0)
		return right + 1;
	return left < right ? left + 1 : right + 1;
}