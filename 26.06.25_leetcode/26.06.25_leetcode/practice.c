#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.06.25力扣网刷题
//LCR 193. 二叉搜索树的最近公共祖先——树、深度优先搜索、二叉搜索树、二叉树——简单
//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//例如，给定如下二叉搜索树 : root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5]
//示例 1：
//输入：root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5], p = 2, q = 8
//输出：6
//解释：节点 2 和节点 8 的最近公共祖先是 6。
//示例 2：
//输入：root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5], p = 2, q = 4
//输出：2
//解释：节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
//说明：
//所有节点的值都是唯一的。
//p、q 为不同节点且均存在于给定的二叉搜索树中。
//注意：本题与主站 235 题相同：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
int getSize(TN* root) {
	if (!root) {
		return 0;
	}
	int left = getSize(root->left);
	int right = getSize(root->right);
	return left + right + 1;
}
void DFS(TN* node, TN** stack, int* top, int key) {
	if (!node) {
		return;
	}
	stack[*top] = node;
	*top += 1;
	if (node->val == key) {
		return;
	}
	if (node->val < key) {
		DFS(node->right, stack, top, key);
	}
	else {
		DFS(node->left, stack, top, key);
	}
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	int size = getSize(root);
	TN** stack1 = (TN**)calloc(size, sizeof(TN*));
	assert(stack1);
	TN** stack2 = (TN**)calloc(size, sizeof(TN*));
	assert(stack2);
	int top1 = 0, top2 = 0;
	DFS(root, stack1, &top1, p->val);
	DFS(root, stack2, &top2, q->val);
	int index = 0;
	for (int i = 0, j = 0; i < top1 && j < top2; i++, j++) {
		if (stack1[i]->val == stack2[j]->val) {
			index = i;
		}
	}
	TN* ans = stack1[index];
	free(stack1);
	free(stack2);
	return ans;
}