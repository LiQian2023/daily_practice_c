#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.10.19力扣网刷题
//二进制矩阵中的特殊位置——数组、矩阵、第206场周赛——简单
//给定一个 m x n 的二进制矩阵 mat，返回矩阵 mat 中特殊位置的数量。
//如果位置(i, j) 满足 mat[i][j] == 1 并且行 i 与列 j 中的所有其他元素都是 0（行和列的下标从 0 开始计数），那么它被称为 特殊 位置。
//示例 1：
//输入：mat = [[1, 0, 0], [0, 0, 1], [1, 0, 0]]
//输出：1
//解释：位置(1, 2) 是一个特殊位置，因为 mat[1][2] == 1 且第 1 行和第 2 列的其他所有元素都是 0。
//示例 2：
//输入：mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
//输出：3
//解释：位置(0, 0)，(1, 1) 和(2, 2) 都是特殊位置。
//提示：
//m == mat.length
//n == mat[i].length
//1 <= m, n <= 100
//mat[i][j] 是 0 或 1。

int numSpecial(int** mat, int matSize, int* matColSize) {
	int m = matSize, n = matColSize[0];
	int* row = (int*)calloc(m, sizeof(int));
	assert(row);
	int* col = (int*)calloc(n, sizeof(int));
	assert(col);
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		int target = 0;
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 1) {
				tmp += 1;
				target = j;
			}
		}
		if (tmp == 1) {
			row[i] = target;
		}
		else {
			row[i] = -1;
		}
	}
	for (int j = 0; j < n; j++) {
		int tmp = 0;
		int target = 0;
		for (int i = 0; i < m; i++) {
			if (mat[i][j] == 1) {
				tmp += 1;
				target = i;
			}
		}
		if (tmp == 1) {
			col[j] = target;
		}
		else {
			col[j] = -1;
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (row[i] != -1&&col[row[i]]==i) {
			ans += 1;
		}
	}
	free(row);
	free(col);
	return ans;
}