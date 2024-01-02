#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.01.02力扣网刷题
//移动零——数组、双指针——简单
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//示例 1:
//输入: nums = [0, 1, 0, 3, 12]
//输出 : [1, 3, 12, 0, 0]
//示例 2 :
//	输入 : nums = [0]
//	输出 : [0]
//	提示 :
//	1 <= nums.length <= 10^4
//	- 2^31 <= nums[i] <= 2^31 - 1
//	进阶：你能尽量减少完成的操作次数吗？
//方法一：顺序查找
void moveZeroes(int* nums, int numsSize) {
	for (int i = 0; i < numsSize-1; i++)
	{
		if (nums[i] == 0)
		{
			for (int j = i + 1; j < numsSize; j++)
			{
				if (nums[j] != 0)
				{
					nums[i] = nums[j];
					nums[j] = 0;
					break;
				}
			}
		}
	}
}

int main()
{
	int nums[10000] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		moveZeroes(nums, n);
		for (int i = 0; i < n; i++)
			printf("%d ", nums[i]);
	}
	return 0;
}