#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.06.26力扣网刷题
//LCR 194. 二叉树的最近公共祖先——树、深度优先搜索、二叉树——简单
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//例如，给定如下二叉树 : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
//示例 1：
//输入：root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
//输出：3
//解释：节点 5 和节点 1 的最近公共祖先是节点 3。
//示例 2：
//输入：root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 4
//输出：5
//解释：节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
//说明：
//所有节点的值都是唯一的。
//p、q 为不同节点且均存在于给定的二叉树中。
//注意：本题与主站 236 题相同：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
void dfs(TN* root, TN** stack, int* top, TN* target, bool* flag) {
	if (!root) {
		return;
	}
	stack[*top] = root;
	*top += 1;
	if (root->val == target->val) {
		*flag = true;
		return;
	}
	if (!(*flag)) {
		dfs(root->left, stack, top, target, flag);
	}
	if (!(*flag)) {
		dfs(root->right, stack, top, target, flag);
	}
	if (!(*flag)) {
		*top -= 1;
	}
	return;
}
int getSize(TN* root) {
	if (!root) {
		return 0;
	}
	int left = getSize(root->left);
	int right = getSize(root->right);
	return left + right + 1;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	int size = getSize(root);
	TN** stack1 = (TN**)calloc(size, sizeof(TN*));
	assert(stack1);
	TN** stack2 = (TN**)calloc(size, sizeof(TN*));
	assert(stack2);
	bool flag1 = false, flag2 = false;
	int top1 = 0, top2 = 0;
	dfs(root, stack1, &top1, p, &flag1);
	dfs(root, stack2, &top2, q, &flag2);
	TN* ans = NULL;
	for (int i = 0, j = 0; i < top1 && j < top2; i++, j++) {
		if (stack1[i] == stack2[j]) {
			ans = stack1[i];
		}
	}
	free(stack1);
	free(stack2);
	return ans;
}
