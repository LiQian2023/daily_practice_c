#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2024.11.13力扣网刷题
//平衡二叉树——树、深度优先搜索、二叉树——简单
//给定一个二叉树，判断它是否是平衡二叉树
//示例 1：
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：true
//示例 2：
//输入：root = [1, 2, 2, 3, 3, null, null, 4, 4]
//输出：false
//示例 3：
//输入：root = []
//输出：true
//提示：
//树中的节点数在范围[0, 5000] 内
//- 10^4 <= Node.val <= 10^4

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode TN;

int dfs(TN* root) {
	if (!root) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		root->val = 0;
		return 1;
	}
	int left = 1 + dfs(root->left);
	int right = 1 + dfs(root->right);
	root->val = left - right;
	return left > right ? left : right;
}
bool Check(TN* root) {
	if (!root)
		return true;
	if (root->val > 1 || root->val < -1)
		return false;
	bool left = Check(root->left);
	bool right = Check(root->right);
	return left & right;
}
bool isBalanced(struct TreeNode* root) {
	int depth = dfs(root);
	return Check(root);
}