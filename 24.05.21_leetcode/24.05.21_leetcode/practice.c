#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.05.21力扣网刷题
//二叉树的中序遍历——深度优先搜索、栈、树、二叉树——简单
//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
//示例 1：
//输入：root = [1, null, 2, 3]
//输出：[1, 3, 2]
//示例 2：
//输入：root = []
//输出：[]
//示例 3：
//输入：root = [1]
//输出：[1]
//提示：
//树中节点数目在范围[0, 100] 内
//- 100 <= Node.val <= 100

void visit(struct TreeNode* root,int* ans,int i) {
	ans[i] = root->val;
}
void InOrder(struct TreeNode* root, int* ans, int* i) {
	if (!root)
		return;
	InOrder(root->left, ans, i);
	visit(root, ans, *i);
	(*i)++;
	InOrder(root->right, ans, i);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	if (!root) {
		return NULL;
	}
	int* ans = (int*)calloc(100, sizeof(int));
	assert(ans);
	InOrder(root, ans, returnSize);
	return ans;
}