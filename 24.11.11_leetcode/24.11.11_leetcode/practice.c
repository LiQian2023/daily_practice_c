#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.11.11力扣网刷题
//将有序数组转换为二叉搜索树——树、二叉搜索树、数组、分治、二叉树——简单
//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵平衡二叉搜索树。
//示例 1：
//输入：nums = [-10, -3, 0, 5, 9]
//输出：[0, -3, 9, -10, null, 5]
//解释：[0, -10, 5, null, -3, null, 9] 也将被视为正确答案：
//示例 2：
//输入：nums = [1, 3]
//输出：[3, 1]
//解释：[1, null, 3] 和[3, 1] 都是高度平衡二叉搜索树。
//提示：
//1 <= nums.length <= 10^4
//- 10^4 <= nums[i] <= 10^4
//nums 按 严格递增 顺序排列

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode TN;
void Print(TN* root) {
	if (!root) {
		printf("NULL\n");
		return;
	}
	printf("root->val = %d\n", root->val);
	Print(root->left);
	Print(root->right);
}
void CreatBST(int* nums, int left, int right, TN** root) {
	if (left > right) {
		printf("NULL\n");
		return;
	}
	if (!(*root)) {
		*root = (TN*)calloc(1, sizeof(TN));
		assert(*root);
	}
	int m = (right - left) / 2 + left;
	(*root)->val = nums[m];
	printf("root->val = %d\n", (*root)->val);
	CreatBST(nums, left, m - 1, &(*root)->left);
	CreatBST(nums, m + 1, right, &(*root)->left);
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	TN* root = (TN*)calloc(1, sizeof(TN));
	assert(root);
	CreatBST(nums, 0, numsSize - 1, &root);
	return root;
}

