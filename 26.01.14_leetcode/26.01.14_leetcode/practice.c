#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.01.14力扣网刷题
//3774. 最大和最小 K 个元素的绝对差——数组、排序、第480场周赛——简单
//给你一个整数数组 nums 和一个整数 k。
//请计算以下两者的绝对差值：
//数组中 k 个 最大 元素的总和；
//数组中 k 个 最小 元素的总和。
//返回表示此差值的整数。
//示例 1：
//输入： nums = [5, 2, 2, 4], k = 2
//输出： 5
//解释：
//k = 2 个最大的元素是 4 和 5。它们的总和是 4 + 5 = 9。
//k = 2 个最小的元素是 2 和 2。它们的总和是 2 + 2 = 4。
//绝对差值是 abs(9 - 4) = 5。
//示例 2：
//输入： nums = [100], k = 1
//输出： 0
//解释：
//最大的元素是 100。
//最小的元素是 100。
//绝对差值是 abs(100 - 100) = 0。
//提示：
//1 <= n == nums.length <= 100
//1 <= nums[i] <= 100
//1 <= k <= n

// 方法一：计数排序
void Count_Sort(int* nums, int len, int max, int min) {
	int* hash = (int*)calloc((max - min + 1), sizeof(int));
	assert(hash != NULL);
	for (int i = 0;i < len;i++) {
		hash[nums[i] - min]++;
	}
	int index = 0;
	for (int i = 0;i <= max - min;i++) {
		while (hash[i]--) {
			nums[index++] = i + min;
		}
	}
	free(hash);
	hash = NULL;
}
int absDifference(int* nums, int numsSize, int k) {
	int max = nums[0], min = nums[0];
	for (int i = 0;i < numsSize;i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		else if(nums[i] < min) {
			min = nums[i];
		}
	}
	Count_Sort(nums, numsSize, max, min);
	int sum_max = 0, sum_min = 0;
	for (int i = 0;i < k;i++) {
		sum_min += nums[i];
		sum_max += nums[numsSize - 1 - i];
	}
	return sum_max - sum_min;
}