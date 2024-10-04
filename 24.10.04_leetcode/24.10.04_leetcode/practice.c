#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.10.04力扣网刷题
//摆动排序 II——贪心、数组、分治、快速选择、排序——中等
//给你一个整数数组nums，将它重新排列成
//nums[0] < nums[1] > nums[2] < nums[3]...的顺序。
//你可以假设所有输入数组都可以得到满足题目要求的结果。
//示例1：
//输入：nums = [1, 5, 1, 1, 6, 4]
//输出：[1, 6, 1, 5, 1, 4]
//解释：[1, 4, 1, 5, 1, 6]
//同样是符合题目要求的结果，可以被判题程序接受。
//示例2：
//输入：nums = [1, 3, 2, 2, 3, 1]
//输出：[2, 3, 1, 3, 1, 2]
//提示：
//1 <= nums.length <= 5 * 10 ^ 4
//0 <= nums[i] <= 5000
//题目数据保证，对于给定的输入nums ，总能产生满足题目要求的结果
//进阶：你能用O(n)时间复杂度和 / 或原地O(1)额外空间来实现吗？
void Swap(int* pa, int* pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void wiggleSort(int* nums, int numsSize) {
	//哈希计数
	int hash[5001] = { 0 };
	int min = nums[0], max = nums[0];
	for (int i = 0; i < numsSize; i++) {
		hash[nums[i]] += 1;
		if (nums[i] < min)
			min = nums[i];
		else if (nums[i] > max)
			max = nums[i];
	}
	//排序
	int len = 1;
	for (int i = max; i >= min; i--) {
		while (hash[i] && len < numsSize) {
			nums[len] = i;
			len += 2;
			hash[i] -= 1;
		}
	}
	len -= 1;
	if (len >= numsSize)
		len -= 2;
	for (int i = min; i <= max; i++) {
		while (hash[i] && len >= 0) {
			nums[len] = i;
			len -= 2;
			hash[i] -= 1;
		}
	}
}

void test() {
	int nums[13] = { 1, 4, 3, 4, 1, 2, 1, 3, 1, 3, 2, 3, 3 };
	int len = 13;
	//int nums[4] = { 4,5,5,6 };
	//int len = 4;
	//int nums[6] = { 1,3,2,2,3,1 };
	//int nums[6] = { 1,5,1,1,6,4 };
	//int len = 6;
	//int nums[11] = { 1,3,2,2,2,1,1,3,1,1,2 };
	//int len = 11;
	//int nums[6] = { 1,1,2,2,2,1 };
	//int len = 6;
	wiggleSort(nums, len);
	for (int i = 0; i < len; i++) {
		printf("%d ", nums[i]);
	}
}

int main() {
	test();
	return 0;
}