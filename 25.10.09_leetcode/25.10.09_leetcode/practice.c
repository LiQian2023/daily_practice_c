#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//2025.10.09力扣网刷题
//1380. 矩阵中的幸运数——数组、矩阵、第180场周赛——简单
//给你一个 m x n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。
//幸运数 是指矩阵中满足同时下列两个条件的元素：
//在同一行的所有元素中最小
//在同一列的所有元素中最大
//示例 1：
//输入：matrix = [[3, 7, 8], [9, 11, 13], [15, 16, 17]]
//输出：[15]
//解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
//示例 2：
//输入：matrix = [[1, 10, 4, 2], [9, 3, 8, 7], [15, 16, 17, 12]]
//输出：[12]
//解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
//示例 3：
//输入：matrix = [[7, 8], [1, 2]]
//输出：[7]
//解释：7 是唯一的幸运数字，因为它是行中的最小值，列中的最大值。
//提示：
//m == mat.length
//n == mat[i].length
//1 <= n, m <= 50
//1 <= matrix[i][j] <= 10^5
//矩阵中的所有元素都是不同的
int Get_Row_Min(int* arr, int len) {
	int min = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}
int Get_Col_Max(int** matrix, int col, int len) {
	int max = matrix[0][col];
	for (int i = 0; i < len; i++) {
		if (matrix[i][col] > max) {
			max = matrix[i][col];
		}
	}
	return max;
}
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	*returnSize = 0;
	int* row = (int*)calloc(matrixSize, sizeof(int));
	assert(row);
	for (int i = 0; i < matrixSize; i++) {
		row[i] = Get_Row_Min(matrix[i], matrixColSize[i]);
	}
	int* col = (int*)calloc(matrixColSize[0], sizeof(int));
	assert(col);
	for (int i = 0; i < matrixColSize[0]; i++) {
		col[i] = Get_Col_Max(matrix, i, matrixSize);
	}
	int base = matrixSize > matrixColSize[0] ? matrixSize : matrixColSize[0];
	int* ans = (int*)calloc(base, sizeof(int));
	assert(ans);
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixColSize[i]; j++) {
			if (row[i] == col[j]) {
				ans[*returnSize] = row[i];
				*returnSize += 1;
			}
		}
	}
	free(row);
	row = NULL;
	free(col);
	col = NULL;
	return ans;
}