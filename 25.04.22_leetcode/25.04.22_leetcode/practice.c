#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2025.04.22力扣网刷题
//数组中紧跟 key 之后出现最频繁的数字——数组、哈希表、计数——简单
//给你一个下标从 0 开始的整数数组 nums ，同时给你一个整数 key ，它在 nums 出现过。
//统计 在 nums 数组中紧跟着 key 后面出现的不同整数 target 的出现次数。换言之，target 的出现次数为满足以下条件的 i 的数目：
//0 <= i <= n - 2
//nums[i] == key 且
//nums[i + 1] == target 。
//请你返回出现 最多 次数的 target 。测试数据保证出现次数最多的 target 是唯一的。
//示例 1：
//输入：nums = [1, 100, 200, 1, 100], key = 1
//输出：100
//解释：对于 target = 100 ，在下标 1 和 4 处出现过 2 次，且都紧跟着 key 。
//没有其他整数在 key 后面紧跟着出现，所以我们返回 100 。
//示例 2：
//输入：nums = [2, 2, 2, 2, 3], key = 2
//输出：2
//解释：对于 target = 2 ，在下标 1 ，2 和 3 处出现过 3 次，且都紧跟着 key 。
//对于 target = 3 ，在下标 4 出出现过 1 次，且紧跟着 key 。
//target = 2 是紧跟着 key 之后出现次数最多的数字，所以我们返回 2 。
//提示：
//2 <= nums.length <= 1000
//1 <= nums[i] <= 1000
//测试数据保证答案是唯一的。

int mostFrequent(int* nums, int numsSize, int key) {
	int* target = (int*)calloc(numsSize, sizeof(int));
	assert(target);
	int size = 0;
	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i] == key) {
			target[size] = nums[i + 1];
			size += 1;
		}
	}
	int hash[1001] = { 0 };
	int ans = hash[target[0]];
	int count = 0;
	for (int i = 0; i < size; i++) {
		hash[target[i]] += 1;
		if (hash[target[i]] > count) {
			ans = target[i];
			count = hash[target[i]];
		}
	}
	free(target);
	return ans;
}