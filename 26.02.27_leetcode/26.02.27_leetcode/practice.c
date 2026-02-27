#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//2026.02.27力扣网刷题
//501. 二叉搜索树中的众数——树、深度优先搜索、二叉搜索树、二叉树——简单
//给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
//如果树中有不止一个众数，可以按 任意顺序 返回。
//假定 BST 满足如下定义：
//结点左子树中所含节点的值 小于等于 当前节点的值
//结点右子树中所含节点的值 大于等于 当前节点的值
//左子树和右子树都是二叉搜索树
//示例 1：
//输入：root = [1, null, 2, 2]
//输出：[2]
//示例 2：
//输入：root = [0]
//输出：[0]
//提示：
//树中节点的数目在范围[1, 10^4] 内
//- 10^5 <= Node.val <= 10^5
//进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
int getSize(TN* root) {
	if(root == NULL) {
		return 0;
	}
	int left = getSize(root->left);
	int right = getSize(root->right);
	return left + right + 1;
}
void dfs(TN* root, int* ans, int* parent, int* count, int* mode, int* pi) {
	if (!root) {
		return;
	}
	dfs(root->left, ans, parent, count, mode, pi);
	if (*parent != root->val) {
		*count = 1;
	}
	else {
		*count += 1;
	}
	if (*count > *mode) {
		ans[0] = root->val;
		*pi = 1;
		*mode = *count;
	}
	else if (*count == *mode) {
		ans[*pi] = root->val;
		*pi += 1;
	}
	*parent = root->val;
	dfs(root->right, ans, parent, count, mode, pi);
}
int* findMode(struct TreeNode* root, int* returnSize) {
	int size = getSize(root);
	*returnSize = 0;
	int* ans = (int*)calloc(size, sizeof(int));
	assert(ans);
	int parent = root->val, count = 0, mode = 0;
	dfs(root, ans, &parent, &count, &mode, returnSize);
	return ans;
}