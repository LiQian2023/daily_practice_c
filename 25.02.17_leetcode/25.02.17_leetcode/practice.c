#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//2025.02.17力扣网刷题
//有序数组中出现次数超过25 % 的元素——数组——简单
//给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25 % 。
//请你找到并返回这个整数
//示例：
//输入：arr = [1, 2, 2, 6, 6, 6, 6, 7, 10]
//输出：6
//提示：
//1 <= arr.length <= 10 ^ 4
//0 <= arr[i] <= 10 ^ 5

int findSpecialInteger(int* arr, int arrSize) {
	int key = arrSize * 0.25;
	int tmp = 1;
	for (int i = 1; i < arrSize; i++) {
		if (arr[i] == arr[i - 1]) {
			tmp += 1;
			if (tmp > key) {
				return arr[i];
			}
		}
		else {
			tmp = 1;
		}
	}
	return arr[0];
}