#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


//2026.02.19力扣网刷题
//LCR 056. 两数之和 IV - 输入二叉搜索树——数组、滑动窗口——简单
//给定一个二叉搜索树的 根节点 root 和一个整数 k, 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 k 。假设二叉搜索树中节点的值均唯一。
//示例 1：
//输入 : root = [8, 6, 10, 5, 7, 9, 11], k = 12
//输出 : true
//解释 : 节点 5 和节点 7 之和等于 12
//示例 2：
//输入 : root = [8, 6, 10, 5, 7, 9, 11], k = 22
//输出 : false
//解释 : 不存在两个节点值之和为 22 的节点
//提示：
//二叉树的节点个数的范围是[1, 10^4].
//- 10^4 <= Node.val <= 10^4
//root 为二叉搜索树
//- 10^5 <= k <= 10^5
//注意：本题与主站 653 题相同： https ://leetcode.cn/problems/two-sum-iv-input-is-a-bst/

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
bool dfs(TN* root, int target,int k) {
	if (!root) {
		return false;
	}
	if (root->val == target) {
		return true;
	}
	if (target < root->val) {
		return dfs(root->left, target, k);
	} else {
		return dfs(root->right, target, k);
	}
}
void InOrder(TN* root, int* tmp, int* pi) {
	if (!root) {
		return;
	}
	InOrder(root->left, tmp, pi);
	tmp[*pi] = root->val;
	*pi += 1;
	InOrder(root->right, tmp, pi);
}
int getSize(TN* root) {
	if (!root) {
		return 0;
	}
	int left = getSize(root->left);
	int right = getSize(root->right);
	return left + right + 1;
}
bool findTarget(struct TreeNode* root, int k) {
	int size = getSize(root);
	int* tmp = (int*)calloc(size, sizeof(int));
	assert(tmp);
	int i = 0;
	InOrder(root, tmp, &i);
	bool ans = false;
	for (i = 0; i < size && !ans; i++) {
		int target = k - tmp[i];
		if (target == tmp[i]) {
			continue;
		}
		ans = dfs(root, target, k);
	}
	free(tmp);
	return ans;
}