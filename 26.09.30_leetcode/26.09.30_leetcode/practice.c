#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
//2026.09.30力扣网刷题
//113. 路径总和 II——树、深度优先搜索、回溯、二叉树——中等
//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//叶子节点 是指没有子节点的节点。
//示例 1：
//输入：root = [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1], targetSum = 22
//输出： [[5, 4, 11, 2], [5, 8, 4, 5]]
//示例 2：
//输入：root = [1, 2, 3], targetSum = 5
//输出：[]
//示例 3：
//输入：root = [1, 2], targetSum = 0
//输出：[]
//提示：
//树中节点总数在范围[0, 5000] 内
//- 1000 <= Node.val <= 1000
//- 1000 <= targetSum <= 1000

/**
 * Definition for a binary tree node.

 */
 /**
  * Return an array of arrays of size *returnSize.
  * The sizes of the arrays are returned as *returnColumnSizes array.
  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
  */

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;

void DFS(TN* root, int target, int sum, int* stack, int top, int** ans, int* row, int** col) {
	if (!root) {
		return;
	}
	stack[top] = root->val;
	if (root->left == NULL && root->right == NULL && sum == target) {
		(*col)[*row] = top + 1;
		ans[*row] = (int*)calloc(top + 1, sizeof(int));
		assert(ans[*row]);
		memcpy(ans[*row], stack, (top + 1) * sizeof(int));
		*row += 1;
		return;
	}
	if (root->left) {
		DFS(root->left, target, sum + root->left->val, stack, top + 1, ans, row, col);
	}
	if (root->right) {
		DFS(root->right, target, sum + root->right->val, stack, top + 1, ans, row, col);
	}
}
int getLeave(TN* root) {
	if (!root) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	int left = getLeave(root->left);
	int right = getLeave(root->right);
	return left + right;
}
int getLevel(TN* root) {
	if (!root) {
		return 0;
	}
	int left = getLevel(root->left);
	int right = getLevel(root->right);
	return left > right ? left + 1 : right + 1;
}
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
	if (!root) {
		*returnColumnSizes = NULL;
		return NULL;
	}
	int size = getLeave(root);
	int level = getLevel(root);
	int* stack = (int*)calloc(level, sizeof(int));
	assert(stack);
	int** ans = (int**)calloc(size, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(size, sizeof(int));
	assert(*returnColumnSizes);
	DFS(root, targetSum, root->val, stack, 0, ans, returnSize, returnColumnSizes);
	free(stack);
	return ans;
}