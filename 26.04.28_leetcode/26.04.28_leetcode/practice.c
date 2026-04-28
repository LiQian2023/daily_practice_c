#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2026.04.28力扣网刷题
//面试题 04.04.检查平衡性——树、深度优先搜索、二叉树——简单
//实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。
//示例 1：
//给定二叉树[3, 9, 20, null, null, 15, 7]
//3
/// \
//9  20
/// \
//15   7
//返回 true 。
//示例 2：
//给定二叉树[1, 2, 2, 3, 3, null, null, 4, 4]
//1
/// \
//2   2
/// \
//3   3
/// \
//4   4
//返回 false 。

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
int getHeight(TN* root) {
	if (!root)return 0;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return left > right ? left + 1 : right + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (!root)return true;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	bool ans = abs(left - right) <= 1;
	return ans && isBalanced(root->left) && isBalanced(root->right);
}