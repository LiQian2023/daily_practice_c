#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.08.01力扣网刷题
//元素计数——数组、排序——简单
//给你一个整数数组 nums ，统计并返回在 nums 中同时至少具有一个严格较小元素和一个严格较大元素的元素数目。
//示例 1：
//输入：nums = [11, 7, 2, 15]
//输出：2
//解释：元素 7 ：严格较小元素是元素 2 ，严格较大元素是元素 11 。
//元素 11 ：严格较小元素是元素 7 ，严格较大元素是元素 15 。
//总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
//示例 2：
//输入：nums = [-3, 3, 3, 90]
//输出：2
//解释：元素 3 ：严格较小元素是元素 - 3 ，严格较大元素是元素 90 。
//由于有两个元素的值为 3 ，总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
//提示：
//1 <= nums.length <= 100
//- 10^5 <= nums[i] <= 10^5

//方法一：希尔排序
int countElements1(int* nums, int numsSize) {
	ShellSort(nums, numsSize);
	int min = nums[0], max = nums[numsSize - 1];
	int ans = 0;
	for (int i = 1; i < numsSize - 1; i++) {
		if (nums[i] > min && nums[i] < max)
			ans += 1;
	}
	return ans;
}
//方法二：堆排序
int countElements2(int* nums, int numsSize) {
	CreatHeap(nums, numsSize);
	HeapSort(nums, numsSize);
	int min = nums[0], max = nums[numsSize - 1];
	int ans = 0;
	for (int i = 1; i < numsSize - 1; i++) {
		if (nums[i] > min && nums[i] < max)
			ans += 1;
	}
	return ans;
}

//方法三：快速排序——三数取中
int countElements3(int* nums, int numsSize) {
	QuickSort3(nums, 0, numsSize - 1);
	int min = nums[0], max = nums[numsSize - 1];
	int ans = 0;
	for (int i = 1; i < numsSize - 1; i++) {
		if (nums[i] > min && nums[i] < max)
			ans += 1;
	}
	return ans;
}

//方法四：插入排序
int countElements4(int* nums, int numsSize) {
	InsertSort(nums, numsSize);
	int min = nums[0], max = nums[numsSize - 1];
	int ans = 0;
	for (int i = 1; i < numsSize - 1; i++) {
		if (nums[i] > min && nums[i] < max)
			ans += 1;
	}
	return ans;
}

//方法五：快速排序——小区间优化
int countElements5(int* nums, int numsSize) {
	QuickSort4(nums, 0, numsSize - 1);
	int min = nums[0], max = nums[numsSize - 1];
	int ans = 0;
	for (int i = 1; i < numsSize - 1; i++) {
		if (nums[i] > min && nums[i] < max)
			ans += 1;
	}
	return ans;
}

//方法六：折半插入排序
int countElements5(int* nums, int numsSize) {
	Binary_InsertSort(nums, numsSize);
	int min = nums[0], max = nums[numsSize - 1];
	int ans = 0;
	for (int i = 1; i < numsSize - 1; i++) {
		if (nums[i] > min && nums[i] < max)
			ans += 1;
	}
	return ans;
}
void test7() {
	int nums[10] = { -162, -162, -551, -162, -162, -162, 913, 913, -162, -463 };
	int len = 10;
	printf("%d\n", countElements5(nums, len));
}