#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.08.20力扣网刷题
//和有限的最长子序列——贪心、数组、二分查找、前缀和、排序——简单
//给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。
//返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于 queries[i] 的 子序列 的 最大 长度  。
//子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。
//示例 1：
//输入：nums = [4, 5, 2, 1], queries = [3, 10, 21]
//输出：[2, 3, 4]
//解释：queries 对应的 answer 如下：
//- 子序列[2, 1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
//- 子序列[4, 5, 1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
//- 子序列[4, 5, 2, 1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
//示例 2：
//输入：nums = [2, 3, 4, 5], queries = [1]
//输出：[0]
//解释：空子序列是唯一一个满足元素和小于或等于 1 的子序列，所以 answer[0] = 0 。
//提示：
//n == nums.length
//m == queries.length
//1 <= n, m <= 1000
//1 <= nums[i], queries[i] <= 10^6

//方法一：希尔排序
void ShellSort(int* a, int len) {
	for (int gap = len / 2; gap; gap /= 2) {
		for (int i = 0; i < len - gap; i++) {
			int key = a[i + gap];
			int j = i;
			while (j >= 0 && a[j] > key) {
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = key;
		}
	}
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
	*returnSize = queriesSize;
	int* ans = (int*)calloc(queriesSize, sizeof(int));
	assert(ans);
	ShellSort(nums, numsSize);
	int len = 0;
	for (int i = 0; i < queriesSize; i++) {
		int sum = nums[0];
		int j = 0;
		while ( j < numsSize && sum <= queries[i]) {
			j++;
			if (j == numsSize)
				break;
			sum += nums[j];
		}
		ans[len++] = j;
	}
	return ans;
}

void test() {
	int a[10] = { 4, 5, 2, 1 };
	int len_a = 4;
	int b[10] = { 3, 10, 21 };
	int len_b = 3;
	int size = 0;
	int* ret = answerQueries(a, len_a, b, len_b, &size);
}

int main() {
	test();
	return 0;
}