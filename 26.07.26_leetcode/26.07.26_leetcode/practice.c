#include <stdio.h>
#include <limits.h>
//2026.07.26力扣网刷题
//628. 三个数的最大乘积——数组、数学、排序——简单
//给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//示例 1：
//输入：nums = [1, 2, 3]
//输出：6
//示例 2：
//输入：nums = [1, 2, 3, 4]
//输出：24
//示例 3：
//输入：nums = [-1, -2, -3]
//输出： - 6
//提示：
//3 <= nums.length <= 10^4
//- 1000 <= nums[i] <= 1000
void Print(int* nums, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d, ", nums[i]);
	}
	printf("\n");
}

int maximumProduct(int* nums, int numsSize) {
	int maxs[3] = { INT_MIN, INT_MIN, INT_MIN };
	int mins[3] = { INT_MAX, INT_MAX, INT_MAX };
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > maxs[0]) {
			maxs[2] = maxs[1];
			maxs[1] = maxs[0];
			maxs[0] = nums[i];
		}
		else if (nums[i] > maxs[1]) {
			maxs[2] = maxs[1];
			maxs[1] = nums[i];
		}
		else if (nums[i] > maxs[2]) {
			maxs[2] = nums[i];
		}
		if (nums[i] < mins[0]) {
			mins[2] = mins[1];
			mins[1] = mins[0];
			mins[0] = nums[i];
		}
		else if (nums[i] < mins[1]) {
			mins[2] = mins[1];
			mins[1] = nums[i];
		}
		else if (nums[i] < mins[2]) {
			mins[2] = nums[i];
		}
	}
	Print(maxs, 3);
	Print(mins, 3);
	int ans1 = maxs[0] * maxs[1] * maxs[2];
	int ans2 = mins[0] * mins[1] * maxs[0];
	return ans1 > ans2 ? ans1 : ans2;
}