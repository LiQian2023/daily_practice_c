#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.11.30力扣网刷题
//好数对的数目——数组、哈希表、数学、计数——简单
//给你一个整数数组 nums 。
//如果一组数字(i, j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。
//	返回好数对的数目。
//	示例 1：
//	输入：nums = [1, 2, 3, 1, 1, 3]
//	输出：4
//	解释：有 4 组好数对，分别是(0, 3), (0, 4), (3, 4), (2, 5) ，下标从 0 开始
//	示例 2：
//	输入：nums = [1, 1, 1, 1]
//	输出：6
//	解释：数组中的每组数字都是好数对
//	示例 3：
//	输入：nums = [1, 2, 3]
//	输出：0
//	提示：
//	1 <= nums.length <= 100
//	1 <= nums[i] <= 100
int numIdenticalPairs(int* nums, int numsSize) {
	//int* left = nums;
	int* right = nums + numsSize - 1;
	int count = 0;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = 0; j < numsSize - 1 - i; j++)
		{
			//if (*(right - j) == *left)
			if (*(right - j) == *nums)
				count++;
		}
		//left++;
		nums++;
	}
	return count;
}
int main()
{
	int arr[100] = { 0 };
	int n = 0;
	while (scanf("%d", &n)==1)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		int ret = numIdenticalPairs(arr, n);
		printf("%d\n", ret);
	}
	return 0;
}