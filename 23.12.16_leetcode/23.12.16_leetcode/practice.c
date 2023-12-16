#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.16力扣网刷题
//在排序数组中查找元素的第一个和最后一个位置——数组、二分查找——中等
//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//如果数组中不存在目标值 target，返回[-1, -1]。
//你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
//示例 1：
//输入：nums = [5, 7, 7, 8, 8, 10], target = 8
//输出：[3, 4]
//示例 2：
//输入：nums = [5, 7, 7, 8, 8, 10], target = 6
//输出：[-1, -1]
//示例 3：
//输入：nums = [], target = 0
//输出：[-1, -1]
//提示：
//0 <= nums.length <= 10^5
//- 10^9 <= nums[i] <= 10^9
//nums 是一个非递减数组
//- 10^9 <= target <= 10^9
#include <stdlib.h>
#include <malloc.h>

//法一：二分查找
int* searchRange1(int* nums, int numsSize, int target, int* returnSize) {
	int* arr = (int*)calloc(2, 4);
	*returnSize = 2;
	if (arr == NULL)
	{
		perror("calloc");
		return NULL;
	}
	arr[0] = -1;
	arr[1] = -1;
	if (numsSize == 0)
		return arr;
	int l = 0, r = numsSize - 1, flag = -1;
	if (nums[r] < target || nums[l]>target)
		return arr;
	else {
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (nums[m] < target)
				l = m + 1 ;
			else if(nums[m]>target)
				r = m - 1;
			else
			{
				flag = m;
				r = m - 1;
			}
		}
		if (-1 != flag)
			arr[0] = l ;
		r = numsSize - 1;
		flag = -1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (nums[m] > target)
				r = m -1;
			else if(nums[m]<target)
				l = m + 1;
			else
			{
				flag = m;
				l = m + 1;
			}
		}
		if (-1 != flag)
			arr[1] = r;
	}
	return arr;
}
//法二：头尾指针查找查找
int* searchRange2(int* nums, int numsSize, int target, int* returnSize) {
	int* arr = (int*)calloc(2, 4);
	*returnSize = 2;
	if (arr == NULL)
	{
		perror("calloc");
		return NULL;
	}
	arr[0] = -1;
	arr[1] = -1;
	if (numsSize == 0)
		return arr;
	int l = 0, r = numsSize - 1;
	if (nums[r] < target || nums[l]>target)
		return arr;
	else {
		for (l; l <= r; l++)
		{
			if (nums[l] == target)
			{
				arr[0] = l;
				break;
			}
		}
		for (r; l <= r; r--)
		{
			if (nums[r] == target)
			{
				arr[1] = r;
				break;
			}
		}
	}
	return arr;
}
//方法三：二分查找——查找目标值并往两侧查找


int main()
{
	int nums[100000] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		int k = 0;
		scanf("%d", &k);
		int size = 2;
		int* ret = searchRange(nums, n, k, &size);
		printf("[%d,%d]\n", ret[0], ret[1]);
		free(ret);
	}
	return 0;
}
