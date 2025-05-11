#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.11力扣网刷题
//存在连续三个奇数的数组——数组——简单
//给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。
//示例 1：
//输入：arr = [2, 6, 4, 1]
//输出：false
//解释：不存在连续三个元素都是奇数的情况。
//示例 2：
//输入：arr = [1, 2, 34, 3, 4, 5, 7, 23, 12]
//输出：true
//解释：存在连续三个元素都是奇数的情况，即[5, 7, 23] 。
//提示：
//1 <= arr.length <= 1000
//1 <= arr[i] <= 1000

bool threeConsecutiveOdds(int* arr, int arrSize) {
	for (int i = 1; i < arrSize - 1; i++) {
		bool a = arr[i - 1] % 2;
		bool b = arr[i] % 2;
		bool c = arr[i + 1] % 2;
		if (a && b && c) {
			return true;
		}
		if (b == 0 && c) {
			i += 1;
		}
		else if (c == 0) {
			i += 2;
		}
	}
	return false;
}