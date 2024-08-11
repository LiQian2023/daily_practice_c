#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.08.11力扣网刷题
//找到和最大的长度为 K 的子序列——数组、哈希表、排序、堆（优先队列）——简单
//给你一个整数数组 nums 和一个整数 k 。你需要找到 nums 中长度为 k 的 子序列 ，且这个子序列的 和最大 。
//请你返回 任意 一个长度为 k 的整数子序列。
//子序列 定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。
//示例 1：
//输入：nums = [2, 1, 3, 3], k = 2
//输出：[3, 3]
//解释：
//子序列有最大和：3 + 3 = 6 。
//示例 2：
//输入：nums = [-1, -2, 3, 4], k = 3
//输出：[-1, 3, 4]
//解释：
//子序列有最大和： - 1 + 3 + 4 = 6 。
//示例 3：
//输入：nums = [3, 4, 3, 3], k = 2
//输出：[3, 4]
//解释：
//子序列有最大和：3 + 4 = 7 。
//另一个可行的子序列为[4, 3] 。
//提示：
//1 <= nums.length <= 1000
//- 10^5 <= nums[i] <= 10^5
//1 <= k <= nums.length


//方法一：qsort排序
typedef struct Node {
	int value;
	int i;
}Node;

int cmp_value(const void* p1, const void* p2) {
	return ((Node*)p2)->value - ((Node*)p1)->value;
}
int cmp_i(const void* p1, const void* p2) {
	return ((Node*)p1)->i - ((Node*)p2)->i;
}
int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
	*returnSize = k;
	int* ans = (int*)calloc(k, sizeof(int));
	assert(ans);
	Node* tmp = (Node*)calloc(numsSize, sizeof(Node));
	assert(tmp);
	for (int i = 0; i < numsSize; i++) {
		tmp[i].value = nums[i];
		tmp[i].i = i;
	}
	qsort(tmp, numsSize, sizeof(Node), cmp_value);
	qsort(tmp, k, sizeof(Node), cmp_i);
	for (int i = 0; i < k; i++) {
		ans[i] = tmp[i].value;
	}
	free(tmp);
	return ans;
}