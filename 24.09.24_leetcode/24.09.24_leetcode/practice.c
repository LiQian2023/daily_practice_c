#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.09.24力扣网刷题
//四数之和——数组、双指针、排序——中等
//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
//请你找出并返回满足下述全部条件且不重复的四元组[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
//0 <= a, b, c, d < n
//a、b、c 和 d 互不相同
//nums[a] + nums[b] + nums[c] + nums[d] == target
//你可以按 任意顺序 返回答案 。
//示例 1：
//输入：nums = [1, 0, -1, 0, -2, 2], target = 0
//输出： [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
//示例 2：
//输入：nums = [2, 2, 2, 2, 2], target = 8
//输出： [[2, 2, 2, 2]]
//提示：
//1 <= nums.length <= 200
//- 10^9 <= nums[i] <= 10^9
//- 10^9 <= target <= 10^9

//方法一：排序+双指针
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int base = numsSize;
	int** ans = (int**)calloc(base, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(base, sizeof(int));
	assert(returnColumnSizes);
	*returnSize = 0;
	if (nums[0] > 0 && nums[0] > target) {
		*returnColumnSizes = 0;
		return ans;
	}
	for (int i = 0; i < numsSize; i++) {
		if (i && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < numsSize; j++) {
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;
			int l = j + 1, r = numsSize - 1;
			while (l < r) {
				if (nums[i] + nums[j] < target - nums[l] - nums[r]) {
					l += 1;
				}
				else if (nums[i] + nums[j] > target - nums[l] - nums[r]) {
					r -= 1;
				}
				else {
					(*returnColumnSizes)[*returnSize] = 4;
					ans[*returnSize] = (int*)calloc(4, sizeof(int));
					assert(ans[*returnSize]);
					ans[*returnSize][0] = nums[i];
					ans[*returnSize][1] = nums[j];
					ans[*returnSize][2] = nums[l];
					ans[*returnSize][3] = nums[r];
					*returnSize += 1;
					if (*returnSize == base) {
						base += 10;
						int** tmp1 = (int**)realloc(ans, base * sizeof(int*));
						assert(tmp1);
						ans = tmp1;
						int* tmp2 = (int*)realloc(*returnColumnSizes, base * sizeof(int));
						assert(tmp2);
						*returnColumnSizes = tmp2;
					}
					l += 1;
					r -= 1;
					while (l < r && nums[l] == nums[l - 1])l += 1;
				}
			}
		}
	}
	return ans;
}