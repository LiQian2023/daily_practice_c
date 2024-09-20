#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2024.09.20力扣网刷题
//三数之和——数组、双指针、排序——中等
//给你一个整数数组 nums ，判断是否存在三元组[nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
//同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
//示例 1：
//输入：nums = [-1, 0, 1, 2, -1, -4]
//输出： [[-1, -1, 2], [-1, 0, 1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是[-1, 0, 1] 和[-1, -1, 2] 。
//注意，输出的顺序和三元组的顺序并不重要。
//示例 2：
//输入：nums = [0, 1, 1]
//输出：[]
//解释：唯一可能的三元组和不为 0 。
//示例 3：
//输入：nums = [0, 0, 0]
//输出： [[0, 0, 0]]
//解释：唯一可能的三元组和为 0 。
//提示：
//3 <= nums.length <= 3000
//- 10^5 <= nums[i] <= 10^5


int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int** ans = NULL;
	int n = 0;
	int count = 0;
	for (int i = 1; i < numsSize - 2; i += 2) {
		int a = nums[i - 1], b = nums[i], c = nums[i + 1];
		if (a != b && b != c && c != a) {
			if (a + b + c == 0) {
				count += 1;
				if (count - n > 1) {
					int** tmp = (int**)realloc(ans, count * sizeof(int*));
					if (!tmp) {
						perror("realloc");
						return NULL;
					}
					ans = tmp;
					ans[n] = (int*)calloc(3, sizeof(int));
					assert(ans[n]);
				}
				ans[n][0] = a;
				ans[n][1] = b;
				ans[n][2] = c;
				n++;
			}
		}
	}
	

}