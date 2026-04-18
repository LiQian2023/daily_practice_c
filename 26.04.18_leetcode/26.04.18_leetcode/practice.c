#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.04.18力扣网刷题
//LCR 174. 寻找二叉搜索树中的目标节点——树、深度优先搜索、二叉搜索树、二叉树——简单
//某公司组织架构以二叉搜索树形式记录，节点值为处于该职位的员工编号。请返回第 cnt 大的员工编号。
//示例 1：
//输入：root = [7, 3, 9, 1, 5], cnt = 2
//7
/// \
//3   9
/// \
//1   5
//输出：7
//示例 2：
//输入: root = [10, 5, 15, 2, 7, null, 20, 1, null, 6, 8], cnt = 4
//10
/// \
//5   15
/// \    \
//2   7    20
///   / \
//1   6   8
//输出: 8
//提示：
//1 ≤ cnt ≤ 二叉搜索树元素个数

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
void dfs(TN* root, int* ans, int* pi) {
	if (!root) {
		return;
	}
	dfs(root->left, ans, pi);
	ans[*pi] = root->val;
	*pi += 1;
	dfs(root->right, ans, pi);
}
int getSize(TN* root) {
	if (!root) {
		return 0;
	}
	int left = getSize(root->left);
	int right = getSize(root->right);
	return left + right + 1;
}
int findTargetNode(struct TreeNode* root, int cnt) {
	int size = getSize(root);
	int* ans = (int*)calloc(size, sizeof(int));
	assert(ans);
	int pi = 0;
	dfs(root, ans, &pi);
	int res = ans[size - cnt];
	free(ans);
	return res;
}