#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2025.04.03力扣网刷题
//将数组按照奇偶性转化——数组、计数、排序——简单
//给你一个整数数组 nums。请你按照以下顺序 依次 执行操作，转换 nums：
//将每个偶数替换为 0。
//将每个奇数替换为 1。
//按 非递减 顺序排序修改后的数组。
//执行完这些操作后，返回结果数组。
//示例 1:
//输入：nums = [4, 3, 2, 1]
//输出：[0, 0, 1, 1]
//解释：
//将偶数（4 和 2）替换为 0，将奇数（3 和 1）替换为 1。现在，nums = [0, 1, 0, 1]。
//按非递减顺序排序 nums，得到 nums = [0, 0, 1, 1]。
//示例 2:
//输入：nums = [1, 5, 1, 4, 2]
//输出：[0, 0, 1, 1, 1]
//解释：
//将偶数（4 和 2）替换为 0，将奇数（1, 5 和 1）替换为 1。现在，nums = [1, 1, 1, 0, 0]。
//按非递减顺序排序 nums，得到 nums = [0, 0, 1, 1, 1]。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 1000

int* transformArray(int* nums, int numsSize, int* returnSize) {
	*returnSize = 0;
	int* ans = (int*)calloc(numsSize, sizeof(int));
	assert(ans);
	int hash[2] = { 0 };
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] % 2) {
			hash[1] += 1;
		}
		else {
			hash[0] += 1;
		}
	}

	for (int i = 0; i < 2; i++) {
		while (hash[i]) {
			ans[*returnSize] = i;
			*returnSize += 1;
			hash[i] -= 1;
		}
	}
	return ans;
}