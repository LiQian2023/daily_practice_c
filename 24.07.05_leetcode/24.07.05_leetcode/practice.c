#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//2024.07.05力扣网刷题
//修改矩阵——数组、矩阵——简单
//给你一个下标从 0 开始、大小为 m x n 的整数矩阵 matrix ，新建一个下标从 0 开始、名为 answer 的矩阵。
//使 answer 与 matrix 相等，接着将其中每个值为 - 1 的元素替换为所在列的 最大 元素。
//返回矩阵 answer 。
//示例 1：
//输入：matrix = [[1, 2, -1], [4, -1, 6], [7, 8, 9]]
//输出： [[1, 2, 9], [4, 8, 6], [7, 8, 9]]
//解释：上图显示了发生替换的元素（蓝色区域）。
//- 将单元格[1][1] 中的值替换为列 1 中的最大值 8 。
//- 将单元格[0][2] 中的值替换为列 2 中的最大值 9 。
//示例 2：
//输入：matrix = [[3, -1], [5, 2]]
//输出： [[3, 2], [5, 2]]
//解释：上图显示了发生替换的元素（蓝色区域）。
//提示：
//m == matrix.length
//n == matrix[i].length
//2 <= m, n <= 50
//- 1 <= matrix[i][j] <= 100
//测试用例中生成的输入满足每列至少包含一个非负整数。

int** modifiedMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
	int** ans = (int**)calloc(matrixSize, sizeof(int*));
	assert(ans);
	// 复制元素
	for (int i = 0; i < matrixSize; i++) {
		ans[i] = (int*)calloc(*matrixColSize, sizeof(int));
		assert(ans[i]);
		for (int j = 0; j < *matrixColSize; j++) {
			ans[i][j] = matrix[i][j];
		}
	}
	//修改矩阵
	for (int col = 0; col < *matrixColSize; col++) {
		int max = ans[0][col];
		int taget[50] = { 0 };
		int i = 0;
		for (int row = 0; row < matrixSize; row++) {
			if (ans[row][col] > max)
				max = ans[row][col];
			if (ans[row][col] == -1) {
				taget[i++] = row;
			}
		}
		for (int j = 0; j < i; j++) {
			ans[taget[j]][col] = max;
		}
	}
	*returnSize = matrixSize;
	*returnColumnSizes = matrixColSize;
	return ans;
}