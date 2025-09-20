#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.09.20力扣网刷题
//重塑矩阵——数组、矩阵、模拟——简单
//在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
//给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
//重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
//如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
//示例 1：
//输入：mat = [[1, 2], [3, 4]], r = 1, c = 4
//输出： [[1, 2, 3, 4]]
//示例 2：
//输入：mat = [[1, 2], [3, 4]], r = 2, c = 4
//输出： [[1, 2], [3, 4]]
//提示：
//m == mat.length
//n == mat[i].length
//1 <= m, n <= 100
//- 1000 <= mat[i][j] <= 1000
//1 <= r, c <= 300

int** Creat_ans(int r, int c, int* returnSize, int** returnColumnSizes) {
	int** ans = (int**)calloc(r, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(r, sizeof(int));
	assert(*returnColumnSizes);
	*returnSize = r;
	for (int i = 0; i < r; i++) {
		ans[i] = (int*)calloc(c, sizeof(int));
		assert(ans[i]);
		(*returnColumnSizes)[i] = c;
	}
	return ans;
}
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
	int n = matSize * matColSize[0];
	if (r * c != n) {
		r = matSize, c = matColSize[0];
	}
	int** ans = Creat_ans(r, c, returnSize, returnColumnSizes);
	int row = 0, col = 0;
	for (int i = 0; i < matSize; i++) {
		for (int j = 0; j < matColSize[i]; j++) {
			ans[row][col] = mat[i][j];
			col += 1;
			if (col == c) {
				row += 1;
				col = 0;
			}
		}
	}
	return ans;
}