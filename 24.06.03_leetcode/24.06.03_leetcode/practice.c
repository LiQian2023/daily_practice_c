#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.06.03力扣网刷题
//判断是否为平衡二叉树——树、二叉树、深度优先搜索——简单
//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
//示例 1:
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：true
//解释：如下图
//示例 2:
//输入：root = [1, 2, 2, 3, 3, null, null, 4, 4]
//输出：false
//解释：如下图
//提示：
//0 <= 树的结点个数 <= 10000

int Depth(struct TreeNode* root, int* ans) {
	if (!root)
		return 0;
	int l = Depth(root->left, ans);
	int r = Depth(root->right, ans);
	ans[0] = l > r ? l + 1 : r + 1;
	ans[1] &= l - r >= -1 && l - r <= 1;
	return ans[0];
}

bool isBalanced(struct TreeNode* root) {
	if (!root)
		return true;
	int ans[2] = { 0 };
	ans[1] = 1;
	ans[0] = Depth(root, ans);
	return ans[1];
}