#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.08.01力扣网刷题
//对奇偶下标分别排序——数组、排序——简单
//给你一个下标从 0 开始的整数数组 nums 。根据下述规则重排 nums 中的值：
//按 非递增 顺序排列 nums 奇数下标 上的所有值。
//举个例子，如果排序前 nums = [4, 1, 2, 3] ，对奇数下标的值排序后变为[4, 3, 2, 1] 。奇数下标 1 和 3 的值按照非递增顺序重排。
//按 非递减 顺序排列 nums 偶数下标 上的所有值。
//举个例子，如果排序前 nums = [4, 1, 2, 3] ，对偶数下标的值排序后变为[2, 1, 4, 3] 。偶数下标 0 和 2 的值按照非递减顺序重排。
//返回重排 nums 的值之后形成的数组。
//示例 1：
//输入：nums = [4, 1, 2, 3]
//输出：[2, 3, 4, 1]
//解释：
//首先，按非递增顺序重排奇数下标（1 和 3）的值。
//所以，nums 从[4, 1, 2, 3] 变为[4, 3, 2, 1] 。
//然后，按非递减顺序重排偶数下标（0 和 2）的值。
//所以，nums 从[4, 1, 2, 3] 变为[2, 3, 4, 1] 。
//因此，重排之后形成的数组是[2, 3, 4, 1] 。
//示例 2：
//输入：nums = [2, 1]
//输出：[2, 1]
//解释：
//由于只有一个奇数下标和一个偶数下标，所以不会发生重排。
//形成的结果数组是[2, 1] ，和初始数组一样。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

//方法一：计数排序
int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
	int* ans = (int*)calloc(numsSize, sizeof(int));
	assert(ans);
	*returnSize = numsSize;
	if (numsSize <= 2) {
		for (int i = 0; i < numsSize; i++)
			ans[i] = nums[i];
	}
	else {
		int tmp[101] = { 0 };
		int max = nums[0], min = nums[0];
		//偶数下标计数
		for (int i = 0; i < numsSize; i += 2) {
			tmp[nums[i]] += 1;
			if (nums[i] > max)
				max = nums[i];
			if (nums[i] < min)
				min = nums[i];
		}

		int len = 0;
		//偶数下标排序——非递减
		for (int i = min; i <= max;) {
			if (tmp[i]) {
				ans[len] = i;
				len += 2;
				tmp[i] -= 1;
			}
			else
				i += 1;
		}
		//奇数下标计数
		max = nums[1], min = nums[1];
		for (int i = 1; i < numsSize; i += 2) {
			tmp[nums[i]] += 1;
			if (nums[i] > max)
				max = nums[i];
			if (nums[i] < min)
				min = nums[i];
		}
		//奇数下标排序——非递增
		len = 1;
		for (int i = max; i >= min;) {
			if (tmp[i]) {
				ans[len] = i;
				len += 2;
				tmp[i] -= 1;
			}
			else
				i -= 1;
		}
	}
	return ans;
}