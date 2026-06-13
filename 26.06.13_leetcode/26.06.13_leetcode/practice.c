#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.06.13力扣网刷题
//LCR 052. 递增顺序搜索树——栈、树、深度优先搜索——二叉搜索树、二叉树——简单
//给你一棵二叉搜索树，请 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
//示例 1：
//输入：root = [5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9]
//输出：[1, null, 2, null, 3, null, 4, null, 5, null, 6, null, 7, null, 8, null, 9]
//示例 2：
//输入：root = [5, 1, 7]
//输出：[1, null, 5, null, 7]
//提示：
//树中节点数的取值范围是[1, 100]
//0 <= Node.val <= 1000
//注意：本题与主站 897 题相同： https ://leetcode.cn/problems/increasing-order-search-tree/

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
void visited(TN* node, TN** pre, TN** newRoot) {
	if (!(*newRoot)) {
		*newRoot = node;
	}
	if (*pre) {
		(*pre)->right = node;
	}
	node->left = NULL;
	(*pre) = node;
}
void dfs(TN* node, TN** pre, TN** newRoot) {
	if (!node) {
		return;
	}
	dfs(node->left, pre, newRoot);
	visited(node, pre, newRoot);
	dfs(node->right, pre, newRoot);

}
struct TreeNode* increasingBST(struct TreeNode* root) {
	TN* pre = NULL;
	TN* newRoot = NULL;
	dfs(root, &pre, &newRoot);
	return newRoot;
}