#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.08力扣网刷题
//两数之和——数组——哈希表
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
//示例 1：
//输入：nums = [2, 7, 11, 15], target = 9
//输出：[0, 1]
//解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
//示例 2：
//输入：nums = [3, 2, 4], target = 6
//输出：[1, 2]
//示例 3：
//输入：nums = [3, 3], target = 6
//输出：[0, 1]
//提示：
//2 <= nums.length <= 10^4
//- 10^9 <= nums[i] <= 10^9
//- 10^9 <= target <= 10^9
//只会存在一个有效答案
//进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
int Size;
//法一：双循环求解
int* twoSum1(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	int* num = (int*)malloc(8);
	int i = 0;
	int j = 0;
	for (i = 0; i < numsSize - 1; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				num[0] = i;
				num[1] = j;
				return num;
			}
		}
	}
	return NULL;
}
//法二：
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	int* num = (int*)malloc(8);

	return NULL;
}
int main()
{
	int nums[10000] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		int k = 0;
		scanf("%d", &k);
		int* sub[2] = twoSum(nums, n, k, &Size);
		printf("[%d, %d]\n", sub[0], sub[1]);
	}
	return 0;
}
