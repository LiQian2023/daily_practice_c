#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.06.23力扣网刷题
//翻转二叉树——树、深度优先搜索、广度优先搜索、二叉树——简单
//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
//示例 1：
//输入：root = [4, 2, 7, 1, 3, 6, 9]
//输出：[4, 7, 2, 9, 6, 3, 1]
//示例 2：
//输入：root = [2, 1, 3]
//输出：[2, 3, 1]
//示例 3：
//输入：root = []
//输出：[]
//提示：
//树中节点数目范围在[0, 100] 内
//- 100 <= Node.val <= 100

struct TreeNode* invertTree(struct TreeNode* root) {
	if (!root)
		return NULL;
	struct TreeNode* l = invertTree(root->left);
	struct TreeNode* r = invertTree(root->right);
	root->left = r;
	root->right = l;
	return root;
}