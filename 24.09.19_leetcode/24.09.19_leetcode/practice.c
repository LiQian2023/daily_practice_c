#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2024.09.19力扣网刷题
//数组的相对排序——数组、哈希表、计数排序、排序——简单
//给定两个数组，arr1 和 arr2，
//arr2 中的元素各不相同
//arr2 中的每个元素都出现在 arr1 中
//对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
//示例：
//输入：arr1 = [2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19], arr2 = [2, 1, 4, 3, 9, 6]
//输出：[2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19]
//提示：
//1 <= arr1.length, arr2.length <= 1000
//0 <= arr1[i], arr2[i] <= 1000
//arr2 中的元素 arr2[i] 各不相同
//arr2 中的每个元素 arr2[i] 都出现在 arr1 中
//注意：本题与主站 1122 题相同：https://leetcode-cn.com/problems/relative-sort-array/ 


//方法一：计数排序
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
	int* ans = (int*)calloc(arr1Size, sizeof(int));
	assert(ans);
	*returnSize = arr1Size;
	int tmp[1001] = { 0 };
	int min = arr1[0], max = arr1[0];
	for (int i = 0; i < arr1Size; i++) {
		tmp[arr1[i]] += 1;
		if (min > arr1[i])
			min = arr1[i];
		if (max < arr1[i])
			max = arr1[i];
	}
	int n = 0;
	for (int i = 0; i < arr2Size; i++) {
		while (tmp[arr2[i]]) {
			ans[n++] = arr2[i];
			tmp[arr2[i]] -= 1;
		}
	}
	for (int i = min; i <= max; i++) {
		while (tmp[i]) {
			ans[n++] = i;
			tmp[i] -= 1;
		}
	}
	return ans;
}