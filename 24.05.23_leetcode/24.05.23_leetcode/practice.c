#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.05.23力扣网刷题
//二叉树的后序遍历——栈、树、深度优先搜索、二叉树——简单
//给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
//示例 1：
//输入：root = [1, null, 2, 3]
//输出：[3, 2, 1]
//示例 2：
//输入：root = []
//输出：[]
//示例 3：
//输入：root = [1]
//输出：[1]
//提示：
//树中节点的数目在范围[0, 100] 内
//- 100 <= Node.val <= 100
//进阶：递归算法很简单，你可以通过迭代算法完成吗？

void PostOrder(struct TreeNode* root, int* arr, int* i) {
	if (!root)
		return;
	PostOrder(root->left, arr, i);
	PostOrder(root->right, arr, i);
	arr[(*i)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	if (!root)
		return NULL;
	int* ans = (int*)calloc(100, sizeof(int));
	assert(ans);
	PostOrder(root, ans, returnSize);
	return ans;
}