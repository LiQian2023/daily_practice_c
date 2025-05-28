#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//2025.05.28力扣网刷题
//二叉搜索树的最小绝对差——树、二叉搜索树、广度优先搜索、深度优先搜索、二叉树——简单
//给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
//差值是一个正数，其数值等于两值之差的绝对值。
//示例 1：
//输入：root = [4, 2, 6, 1, 3]
//输出：1
//示例 2：
//输入：root = [1, 0, 48, null, null, 12, 49]
//输出：1
//提示：
//树中节点的数目范围是[2, 10^4]
//0 <= Node.val <= 10^5
//注意：本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
void visit(TN* root, int* tmp, int* pi, int* max, int* min) {
	tmp[*pi] = root->val;
	*pi += 1;
	if (root->val > *max) {
		*max = root->val;
	}
	else if (root->val < *min) {
		*min = root->val;
	}
}
void dfs(TN* root, int* tmp, int* pi, int* max, int* min) {
	if (root) {
		visit(root, tmp, pi, max, min);
		dfs(root->left, tmp, pi, max, min);
		dfs(root->right, tmp, pi, max, min);
	}
}
int Get_Node(TN* root) {
	if (!root) {
		return 0;
	}
	int left = Get_Node(root->left);
	int right = Get_Node(root->right);
	return left + right + 1;
}
void Count_Sort(int* tmp, int size, int max, int min) {
	int* hash = (int*)calloc(max - min + 1, sizeof(int));
	assert(hash);
	for (int i = 0; i < size; i++) {
		int key = tmp[i] - min;
		hash[key] += 1;
	}
	for (int i = min, j = 0; i <= max; i++) {
		int key = i - min;
		while (hash[key]) {
			tmp[j] = i;
			j += 1;
			hash[key] -= 1;
		}
	}
	free(hash);
	hash = NULL;
}
int getMinimumDifference(struct TreeNode* root) {
	int size = Get_Node(root);
	int min = root->val, max = root->val;
	int* tmp = (int*)calloc(size, sizeof(int));
	assert(tmp);
	int i = 0;
	dfs(root, tmp, &i, &max, &min);
	Count_Sort(tmp, size, max, min);
	int ans = tmp[1] - tmp[0];
	for (int i = 1; i < size; i++) {
		if (tmp[i] - tmp[i - 1] < ans) {
			ans = tmp[i] - tmp[i - 1];
		}
	}
	free(tmp);
	tmp = NULL;
	return ans;
}