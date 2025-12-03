#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.12.03力扣网刷题
//3668. 重排完成顺序——数组、哈希表、第465场周赛——简单
//给你一个长度为 n 的整数数组 order 和一个整数数组 friends。
//order 包含从 1 到 n 的每个整数，且 恰好出现一次 ，表示比赛中参赛者按照 完成顺序 的 ID。
//friends 包含你朋友们的 ID，按照 严格递增 的顺序排列。friends 中的每个 ID 都保证出现在 order 数组中。
//请返回一个数组，包含你朋友们的 ID，按照他们的 完成顺序 排列。
//示例 1：
//输入：order = [3, 1, 2, 5, 4], friends = [1, 3, 4]
//输出：[3, 1, 4]
//解释：
//完成顺序是[3, 1, 2, 5, 4]。因此，你朋友的完成顺序是[3, 1, 4]。
//示例 2：
//输入：order = [1, 4, 5, 3, 2], friends = [2, 5]
//输出：[5, 2]
//解释：
//完成顺序是[1, 4, 5, 3, 2]。因此，你朋友的完成顺序是[5, 2]。
//提示：
//1 <= n == order.length <= 100
//order 包含从 1 到 n 的每个整数，且恰好出现一次
//1 <= friends.length <= min(8, n)
//1 <= friends[i] <= n
//friends 是严格递增的

typedef struct Hash_Node {
	int data;
	int index;
}HNode;
int cmp(const void* p1, const void* p2) {
	return (*(HNode*)p1).index - (*(HNode*)p2).index;
}
int* recoverOrder(int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {
	int* hash_order = (int*)calloc(orderSize + 1, sizeof(int));
	assert(hash_order);
	for (int i = 0; i < orderSize; i++) {
		hash_order[order[i]] = i;
	}
	HNode* hash = (HNode*)calloc(friendsSize, sizeof(HNode));
	assert(hash);
	for (int i = 0; i < friendsSize; i++) {
		hash[i].data = friends[i];
		hash[i].index = hash_order[friends[i]];
	}
	qsort(hash, friendsSize, sizeof(HNode), cmp);
	int* ans = (int*)calloc(friendsSize, sizeof(int));
	assert(ans);
	*returnSize = friendsSize;
	for (int i = 0; i < friendsSize; i++) {
		ans[i] = hash[i].data;
	}
	free(hash_order);
	free(hash);
	hash_order = NULL;
	hash = NULL;
	return ans;
}