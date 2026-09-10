#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.09.10力扣网刷题
//2265. 统计值等于子树平均值的节点数——高级工程师、树、深度优先搜索、二叉树、第292场周赛——中等
//给你一棵二叉树的根节点 root ，找出并返回满足要求的节点数，要求节点的值等于其 子树 中值的 平均值 。
//注意：
//n 个元素的平均值可以由 n 个元素 求和 然后再除以 n ，并 向下舍入 到最近的整数。
//root 的 子树 由 root 和它的所有后代组成。
//示例 1：
//输入：root = [4, 8, 5, 0, 1, null, 6]
//输出：5
//解释：
//对值为 4 的节点：子树的平均值(4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4 。
//对值为 5 的节点：子树的平均值(5 + 6) / 2 = 11 / 2 = 5 。
//对值为 0 的节点：子树的平均值 0 / 1 = 0 。
//对值为 1 的节点：子树的平均值 1 / 1 = 1 。
//对值为 6 的节点：子树的平均值 6 / 1 = 6 。
//示例 2：
//输入：root = [1]
//输出：1
//解释：对值为 1 的节点：子树的平均值 1 / 1 = 1。
//提示：
//树中节点数目在范围[1, 1000] 内
//0 <= Node.val <= 1000

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
int getSize(TN* root) {
	if (!root) {
		return 0;
	}
	int left = getSize(root->left);
	int right = getSize(root->right);
	return left + right + 1;
}
int getSub(TN* root, int* sub, int* pi) {
	if (!root) {
		return 0;
	}
	int left = getSub(root->left, sub, pi);
	int right = getSub(root->right, sub, pi);
	sub[*pi] = left + right + 1;
	*pi += 1;
	return left + right + 1;
}
int getSum(TN* root, int* sums, int* pi) {
	if (!root) {
		return 0;
	}
	int left = getSum(root->left, sums, pi);
	int right = getSum(root->right, sums, pi);
	sums[*pi] = left + right + root->val;
	*pi += 1;
	return left + right + root->val;
}
void getAns(TN* root, int* sums, int* subs, int* pi, int* ans) {
	if (!root) {
		return;
	}
	getAns(root->left, sums, subs, pi, ans);
	getAns(root->right, sums, subs, pi, ans);
	if (sums[*pi] / subs[*pi] == root->val) {
		*ans += 1;
	}
	*pi += 1;
}
int averageOfSubtree(struct TreeNode* root) {
	int size = getSize(root);
	int* subs = (int*)calloc(size, sizeof(int));
	assert(subs);
	int sub_i = 0;
	int sub = getSub(root, subs, &sub_i);
	int* sums = (int*)calloc(size, sizeof(int));
	assert(sums);
	int sum_i = 0;
	int sum = getSum(root, sums, &sum_i);
	int ans = 0;
	int i = 0;
	getAns(root, sums, subs, &i, &ans);
	free(subs);
	free(sums);
	return ans;
}
int DFS(TN* root, int* sum, int* ans) {
	if (!root) {
		return 0;
	}
	int l_sum = 0, r_sum = 0;
	int l = DFS(root->left, &l_sum, ans);
	int r = DFS(root->right, &r_sum, ans);
	*sum = l_sum + r_sum + root->val;
	int sub = l + r + 1;
	if (*sum / sub == root->val) {
		*ans += 1;
	}
	return sub;
}
int averageOfSubtree(struct TreeNode* root) {
	int sum = 0, ans = 0;
	int size = DFS(root, &sum, &ans);
	return ans;
}