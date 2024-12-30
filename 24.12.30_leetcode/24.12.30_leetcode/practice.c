#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2024.12.30力扣网刷题
//搜索插入位置——数组、二分查找——简单
//给定一个排序的整数数组 nums 和一个整数目标值 target ，请在数组中找到 target ，并返回其下标。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。
//示例 1：
//输入 : nums = [1, 3, 5, 6], target = 5
//输出 : 2
//示例 2：
//输入 : nums = [1, 3, 5, 6], target = 2
//输出 : 1
//示例 3：
//输入 : nums = [1, 3, 5, 6], target = 7
//输出 : 4
//示例 4：
//输入 : nums = [1, 3, 5, 6], target = 0
//输出 : 0
//示例 5：
//输入 : nums = [1], target = 0
//输出 : 0
//提示：
//1 <= nums.length <= 10^4
//- 10^4 <= nums[i] <= 10^4
//nums 为无重复元素的升序排列数组
//- 10^4 <= target <= 10^4
//注意：本题与主站 35 题相同： https ://leetcode-cn.com/problems/search-insert-position/

int searchInsert(int* nums, int numsSize, int target) {
	int l = 0, r = numsSize - 1;
	while (l <= r) {
		int m = (r - l) / 2 + l;
		if (nums[m] < target) {
			l = m + 1;
		}
		else if (nums[m] > target) {
			r = m - 1;
		}
		else
			return m;
	}
	return l;
}

#if 0
//二叉树中的链表——树、深度优先搜索、链表、二叉树——中等
//给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。
//如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False 。
//一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。
//示例 1：
//输入：head = [4, 2, 8], root = [1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3]
//输出：true
//解释：树中蓝色的节点构成了与链表对应的子路径。
//示例 2：
//输入：head = [1, 4, 2, 6], root = [1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3]
//输出：true
//示例 3：
//输入：head = [1, 4, 2, 6, 8], root = [1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3]
//输出：false
//解释：二叉树中不存在一一对应链表的路径。
//提示：
//二叉树和链表中的每个节点的值都满足 1 <= node.val <= 100 。
//链表包含的节点数目在 1 到 100 之间。
//二叉树包含的节点数目在 1 到 2500 之间。

//
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
 
struct ListNode {
	int val;
	struct ListNode* next;
};

 // Definition for a binary tree node.
 // struct TreeNode {
 //     int val;
 //     struct TreeNode *left;
 //     struct TreeNode *right;
 // };
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct ListNode LN;
typedef struct TreeNode TN;

bool isSame(LN* head, LN* list, TN* root, TN* tree) {
	if (list == NULL)
		return true;
	if (tree == NULL && list) {
		return false;
	}
	bool left = false, right = false;
	if (tree->val != list->val) {
		list = head;
		left = isSame(head, list, root->left, root->left);
		if (!left)
			right = isSame(head, list, root->right, root->right);
	}
	else {
		left = isSame(head, list->next, root, tree->left);
		if (!left)
			right = isSame(head, list->next, root, tree->right);
	}
	return left || right;
}
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
	return isSame(head, head, root, root);
}
#endif