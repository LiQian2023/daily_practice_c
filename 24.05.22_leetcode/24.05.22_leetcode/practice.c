#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.05.22力扣网刷题
//二叉树的前序遍历——栈、树、深度优先搜索、二叉树——简单
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//示例 1：
//输入：root = [1, null, 2, 3]
//输出：[1, 2, 3]
//示例 2：
//输入：root = []
//输出：[]
//示例 3：
//输入：root = [1]
//输出：[1]
//示例 4：
//输入：root = [1, 2]
//输出：[1, 2]
//示例 5：
//输入：root = [1, null, 2]
//输出：[1, 2]
//提示：
//树中节点数目在范围[0, 100] 内
//- 100 <= Node.val <= 100
//进阶：递归算法很简单，你可以通过迭代算法完成吗？

void PreOrder(struct TreeNode* root, int* ans, int* i) {
	if (!root)
		return;
	ans[(*i)++] = root->val;
	PreOrder(root->left, ans, i);
	PreOrder(root->right, ans, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	if (!root)
		return NULL;
	int* ans = (int*)calloc(100, sizeof(int));
	assert(ans);
	PreOrder(root, ans, returnSize);
	return ans;
}