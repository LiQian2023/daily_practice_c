#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.09.28力扣网刷题
//颜色分类——数组、双指针、排序——中等
//给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，
//原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//必须在不使用库内置的 sort 函数的情况下解决这个问题。
//示例 1：
//输入：nums = [2, 0, 2, 1, 1, 0]
//输出：[0, 0, 1, 1, 2, 2]
//示例 2：
//输入：nums = [2, 0, 1]
//输出：[0, 1, 2]
//提示：
//n == nums.length
//1 <= n <= 300
//nums[i] 为 0、1 或 2
//进阶：
//你能想出一个仅使用常数空间的一趟扫描算法吗？

//方法一：计数排序
void sortColors(int* nums, int numsSize) {
	int color[3] = { 0 };
	for (int i = 0; i < numsSize; i++) {
		color[nums[i]] += 1;
	}
	numsSize = 0;
	for (int i = 0; i < 3; i++) {
		while (color[i]) {
			nums[numsSize] = i;
			numsSize += 1;
			color[i] -= 1;
		}
	}
}