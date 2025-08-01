 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.08.01力扣网刷题
//杨辉三角——数组、动态规划——简单
//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//示例 1:
//输入: numRows = 5
//输出 : [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
//示例 2 :
//输入 : numRows = 1
//输出 : [[1]]
//提示 :
//1 <= numRows <= 30

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	*returnSize = numRows;
	*returnColumnSizes = (int*)calloc(numRows, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < numRows; i++) {
		(*returnColumnSizes)[i] = i + 1;
	}
	int** ans = (int**)calloc(numRows, sizeof(int*));
	assert(ans);
	for (int i = 0; i < numRows; i++) {
		ans[i] = (int*)calloc(i + 1, sizeof(int));
		assert(ans[i]);
		for (int j = 0; j < i + 1; j++) {
			ans[i][j] = 1;
		}
	}
	for (int i = 2; i < numRows; i++) {
		for (int j = 1; j < i; j++) {
			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}
	return ans;
}