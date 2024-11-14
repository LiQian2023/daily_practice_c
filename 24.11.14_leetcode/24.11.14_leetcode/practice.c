#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.11.14力扣网刷题
//翻转二叉树——树、深度优先搜索、广度优先搜索、二叉树——简单
//给定一棵二叉树的根节点 root，请左右翻转这棵二叉树，并返回其根节点。
//示例 1：
//输入：root = [5, 7, 9, 8, 3, 2, 4]
//输出：[5, 9, 7, 4, 2, 3, 8]
//提示：
//树中节点数目范围在[0, 100] 内
//- 100 <= Node.val <= 100
//注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode TN;

void visit(TN* root) {
	TN* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}
void dfs(TN* root) {
	if (!root)
		return;
	visit(root);
	dfs(root->left);
	dfs(root->right);
}
struct TreeNode* flipTree(struct TreeNode* root) {
	dfs(root);
	return root;
}