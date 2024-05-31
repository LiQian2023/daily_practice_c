#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.06.01力扣网刷题
//二叉树的直径——树、深度搜索、二叉树——简单
//给你一棵二叉树的根节点，返回该树的 直径 。
//二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
//两节点之间路径的 长度 由它们之间边数表示。
//示例 1：
//输入：root = [1, 2, 3, 4, 5]
//输出：3
//解释：3 ，取路径[4, 2, 1, 3] 或[5, 2, 1, 3] 的长度。
//示例 2：
//输入：root = [1, 2]
//输出：1
//提示：
//树中节点数目在范围[1, 10^4] 内
//- 100 <= Node.val <= 100

int Depth(struct TreeNode* root,int* arr) {
	if (!root)
		return 0;
	int l = Depth(root->left, arr);
	int r = Depth(root->right, arr);
	arr[0] = l > r ? l + 1 : r + 1;
	arr[1] = l + r > arr[1] ? l + r : arr[1];
	return arr[0];
}
int diameterOfBinaryTree(struct TreeNode* root) {
	if (!root)
		return 0;
	int arr[2] = { 0 };
	int d = Depth(root, arr);
	return arr[1];
}