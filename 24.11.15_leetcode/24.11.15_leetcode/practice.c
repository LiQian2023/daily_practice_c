#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2024.11.15力扣网刷题
//判断对称二叉树——树、深度优先搜索、广度优先搜索、二叉树——简单
//请设计一个函数判断一棵二叉树是否 轴对称 。
//示例 1：
//输入：root = [6, 7, 7, 8, 9, 9, 8]
//输出：true
//解释：从图中可看出树是轴对称的。
//示例 2：
//输入：root = [1, 2, 2, null, 3, null, 3]
//输出：false
//解释：从图中可看出最后一层的节点不对称。
//提示：
//0 <= 节点个数 <= 1000
//注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
bool dfs(TN* left, TN* right) {
	if (left && !right || right && !left)
		return false;
	if (!left && !right)
		return true;
	if (left->val != right->val)
		return false;
	TN* ll = left->left;
	TN* rl = right->left;
	TN* lr = left->right;
	TN* rr = right->right;
	bool ret1 = dfs(ll, rr);
	bool ret2 = dfs(lr, rl);
	return ret1 && ret2;
}

bool checkSymmetricTree(struct TreeNode* root) {
	if (!root)
		return true;
	return dfs(root->left, root->right);
}