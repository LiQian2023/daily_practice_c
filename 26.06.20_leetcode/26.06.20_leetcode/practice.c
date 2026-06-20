#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.06.20力扣网刷题
//面试题 04.02.最小高度树——树、二叉搜索树、数组、分治、二叉树——简单
//给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。
//示例：
//给定有序数组 : [-10, -3, 0, 5, 9] ,
//一个可能的答案是：[0, -3, 9, -10, null, 5]，它可以表示下面这个高度平衡二叉搜索树：
//0
/// \
//- 3   9
///   /
//-10  5

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
TN* DFS(int* nums, int left, int right) {
	if (right - left == 0) {
		return NULL;
	}
	int mid = (right - left) / 2 + left;
	TN* node = (TN*)calloc(1, sizeof(TN));
	assert(node);
	node->val = nums[mid];
	node->left = DFS(nums, left, mid);
	node->right = DFS(nums, mid + 1, right);
	return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	return DFS(nums, 0, numsSize);
}