#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//2025.10.02力扣网刷题
//有效的山脉数组——数组、第111场周赛——简单
//给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。
//让我们回顾一下，如果 arr 满足下述条件，那么它是一个山脉数组：
//arr.length >= 3
//在 0 < i < arr.length - 1 条件下，存在 i 使得：
//arr[0] < arr[1] < ... arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//示例 1：
//输入：arr = [2, 1]
//输出：false
//示例 2：
//输入：arr = [3, 5, 5]
//输出：false
//示例 3：
//输入：arr = [0, 3, 2, 1]
//输出：true
//提示：
//1 <= arr.length <= 10^4
//0 <= arr[i] <= 10^4

bool validMountainArray(int* arr, int arrSize) {
	int top = 0, max = arr[0];
	for (int i = 1; i < arrSize; i++) {
		if (arr[i] > max) {
			max = arr[i];
			top = i;
		}
	}
	for (int i = 1; i < top; i++) {
		if (arr[i] <= arr[i - 1] || arr[i] == max) {
			return false;
		}
	}
	for (int i = top + 1; i < arrSize; i++) {
		if ((i < arrSize - 1 && arr[i] <= arr[i + 1]) || (arr[i] == max)) {
			return false;
		}
	}
	return top != 0 && top != arrSize - 1;
}