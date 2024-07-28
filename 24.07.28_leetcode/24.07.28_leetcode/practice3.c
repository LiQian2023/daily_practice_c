#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.07.28力扣网刷题
//检查整数及其两倍数是否存在——数组、双指针、二分查找、哈希表、排序——简单
//给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，满足 N 是 M 的两倍（即，N = 2 * M）。
//更正式地，检查是否存在两个下标 i 和 j 满足：
//i != j
//0 <= i, j < arr.length
//arr[i] == 2 * arr[j]
//示例 1：
//输入：arr = [10, 2, 5, 3]
//输出：true
//解释：N = 10 是 M = 5 的两倍，即 10 = 2 * 5 。
//示例 2：
//输入：arr = [7, 1, 14, 11]
//输出：true
//解释：N = 14 是 M = 7 的两倍，即 14 = 2 * 7 。
//示例 3：
//输入：arr = [3, 1, 7, 11]
//输出：false
//解释：在该情况下不存在 N 和 M 满足 N = 2 * M 。
//提示：
//2 <= arr.length <= 500
//- 10 ^ 3 <= arr[i] <= 10 ^ 3


//方法一：二分查找
bool Binary_Search1(int* arr, int left, int right, int key) {
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			return true;
	}
	return false;
}

bool checkIfExist(int* arr, int arrSize) {
	ShellSort(arr, arrSize);
	for (int i = 0; i < arrSize - 1; i++) {
		int key = arr[i] * 2;
		bool flag1 = Binary_Search1(arr, 0, i - 1, key);
		bool flag2 = Binary_Search1(arr, i + 1, arrSize - 1, key);
		if (flag1 || flag2)
			return true;
	}
	return false;
}



void test3() {
	int arr[10] = { -2,0,10,-19,1,6,-4 };
	int n = 7;
	printf("%d\n", checkIfExist(arr, n));
}