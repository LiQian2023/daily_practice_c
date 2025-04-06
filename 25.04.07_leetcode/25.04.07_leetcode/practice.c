#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.04.07力扣网刷题
//独一无二的出现次数——数组、哈希表——简单
//给你一个整数数组 arr，如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
//示例 1：
//输入：arr = [1, 2, 2, 1, 1, 3]
//输出：true
//解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
//示例 2：
//输入：arr = [1, 2]
//输出：false
//示例 3：
//输入：arr = [-3, 0, 1, -3, 1, 1, 1, -3, 10, 0]
//输出：true
//提示：
//1 <= arr.length <= 1000
//- 1000 <= arr[i] <= 1000

bool uniqueOccurrences(int* arr, int arrSize) {
	int max = arr[0], min = arr[0];
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		else if (arr[i] < min) {
			min = arr[i];
		}
	}
	int size1 = max - min + 1;
	int* hash1 = (int*)calloc(size1, sizeof(int));
	assert(hash1);
	max = 0;
	for (int i = 0; i < arrSize; i++) {
		int key = arr[i] - min;
		hash1[key] += 1;
		if (hash1[key] > max) {
			max = hash1[key];
		}
	}
	int* hash2 = (int*)calloc(max + 1, sizeof(int));
	assert(hash2);
	for (int i = 0; i < size1; i++) {
		if (hash1[i]) {
			int key = hash1[i];
			hash2[key] += 1;
			if (hash2[key] > 1) {
				return false;
			}
		}
	}
	free(hash1);
	hash1 = NULL;
	free(hash2);
	hash2 = NULL;
	return true;
}