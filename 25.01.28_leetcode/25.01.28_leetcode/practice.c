#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.01.28力扣网刷题
//杨辉三角 II——数组、动态规划——简单
//给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//示例 1:
//输入: rowIndex = 3
//输出 : [1, 3, 3, 1]
//示例 2 :
//输入 : rowIndex = 0
//输出 : [1]
//示例 3 :
//输入 : rowIndex = 1
//输出 : [1, 1]
//提示 :
//0 <= rowIndex <= 33
//进阶：
//你可以优化你的算法到 O(rowIndex) 空间复杂度吗？


int* getRow(int rowIndex, int* returnSize) {
	*returnSize = rowIndex + 1;
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	for (int i = 0; i < *returnSize; i++) {
		ans[i] = 1;
	}
	for (int k = 2; k <= rowIndex; k++) {
		int l = 0, r = k;
		int* tmp = (int*)calloc(k, sizeof(int));
		assert(tmp);
		for (int i = 0; i < k; i++) {
			tmp[i] = ans[i];
		}
		for (int i = 1; i < r; i++) {
			ans[i] = tmp[i] + tmp[i - 1];
		}
		free(tmp);
	}
	return ans;
}