#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2024.10.21力扣网刷题
//最小差值 II——贪心、数组、数学、排序——中等
//给你一个整数数组 nums，和一个整数 k 。
//对于每个下标 i（0 <= i < nums.length），将 nums[i] 变成 nums[i] + k 或 nums[i] - k 。
//nums 的 分数 是 nums 中最大元素和最小元素的差值。
//在更改每个下标对应的值之后，返回 nums 的最小 分数 。
//示例 1：
//输入：nums = [1], k = 0
//输出：0
//解释：分数 = max(nums) - min(nums) = 1 - 1 = 0 。
//示例 2：
//输入：nums = [0, 10], k = 2
//输出：6
//解释：将数组变为[2, 8] 。分数 = max(nums) - min(nums) = 8 - 2 = 6 。
//示例 3：
//输入：nums = [1, 3, 6], k = 3
//输出：3
//解释：将数组变为[4, 6, 3] 。分数 = max(nums) - min(nums) = 6 - 3 = 3 。
//提示：
//1 <= nums.length <= 10^4
//0 <= nums[i] <= 10^4
//0 <= k <= 10^4

void Swap(int* pa, int* pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void CountSort(int* a, int len) {
	int count[10001] = { 0 };
	int min = a[0], max = a[0];
	for (int i = 0; i < len; i++) {
		count[a[i]] += 1;
		if (a[i] < min)
			min = a[i];
		else if (a[i] > max)
			max = a[i];
	}
	len = 0;
	for (int i = min; i <= max; i++) {
		while (count[i]) {
			a[len] = i;
			len += 1;
			count[i] -= 1;
		}
	}
}
void deal_arr(int* a, int len, int k, int min, int max) {
	for (int i = 0; i < len; i++) {
			a[i] += k;
	}
}
int get_Min(int* a, int len) {
	int min = a[0];
	for (int i = 0; i < len; i++) {
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int get_Max(int* a, int len) {
	int max = a[len - 1];
	for (int i = 0; i < len; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
int smallestRangeII(int* nums, int numsSize, int k) {
	CountSort(nums, numsSize);
	int min = nums[0], max = nums[numsSize - 1];
	int ans = max - min;
	if (ans > k) {
		min += k;
		max -= k;
		if (min > max)
			Swap(&min, &max);
		//处理大于等于最大值以及小于等于最小值的元素
		int left = 0, right = 0;
		for (int i = 0; i < numsSize; i++) {
			if (nums[i] + k == min || nums[i] + k == max) {
				nums[i] += k;
				left += 1;
			}
			else if (nums[i] - k == max || nums[i] - k == min) {
				nums[i] -= k;
				right += 1;
			}
		}
		//处理大于最小值，小于最大值的元素
		for (int i = left; i < numsSize - right; i++) {
			bool flag = false;
			if (nums[i] - k <= min && max - nums[i] + k <= max - min) {
				nums[i] -= k;
				min = nums[i];
				flag = true;
			}
			else if (nums[i] - k > min && max - min <= ans) {
				nums[i] -= k;
				flag = true;
			}
			if (flag) {
				if (nums[i] + 2 * k >= max && nums[i] + 2 * k - min <= max - min) {
					nums[i] += 2 * k;
					max = nums[i];
				}
				else if (nums[i] + 2 * k < max && max - min <= ans)
					nums[i] *= 2 * k;
			}
			else {
				if (nums[i] + k >= max && nums[i] + k - min <= max - min) {
					nums[i] += k;
					max = nums[i];
				}
				else if (nums[i] * k < max && max - min <= ans)
					nums[i] += k;
			}
		}
		max = get_Max(nums, numsSize);
		min = get_Min(nums, numsSize);
		int tmp = max - min;
		ans = ans < tmp ? ans : tmp;
	}
	return ans;
}