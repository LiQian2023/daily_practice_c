#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.02.28力扣网刷题
//消失的数字——位运算、数组、哈希表、数学、排序——简单
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//注意：本题相对书上原题稍作改动
//示例 1：
//输入：[3, 0, 1]
//输出：2
//示例 2：
//输入：[9, 6, 4, 2, 3, 5, 7, 0, 1]
//输出：8

int missingNumber(int* nums, int numsSize) {
	int ans = numsSize;
	for (int i = 0; i < numsSize; i++) {
		ans += i;
		ans -= nums[i];
	}
	return ans;
}