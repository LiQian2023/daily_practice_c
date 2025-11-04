#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
//2025.11.04力扣网刷题
//判断矩阵经轮转后是否一致——数组、矩阵、第244场周赛——简单
//给你两个大小为 n x n 的二进制矩阵 mat 和 target 。现 以 90 度顺时针轮转 矩阵 mat 中的元素 若干次 ，如果能够使 mat 与 target 一致，返回 true ；否则，返回 false 。
//示例 1：
//输入：mat = [[0, 1], [1, 0]], target = [[1, 0], [0, 1]]
//输出：true
//解释：顺时针轮转 90 度一次可以使 mat 和 target 一致。
//示例 2：
//输入：mat = [[0, 1], [1, 1]], target = [[1, 0], [0, 1]]
//输出：false
//解释：无法通过轮转矩阵中的元素使 equal 与 target 一致。
//示例 3：
//输入：mat = [[0, 0, 0], [0, 1, 0], [1, 1, 1]], target = [[1, 1, 1], [0, 1, 0], [0, 0, 0]]
//输出：true
//解释：顺时针轮转 90 度两次可以使 mat 和 target 一致。
//提示：
//n == mat.length == target.length
//n == mat[i].length == target[i].length
//1 <= n <= 10
//mat[i][j] 和 target[i][j] 不是 0 就是 1

void Rotation(int** mat, int n, int k) {
	int* up = (int*)calloc(n, sizeof(int));
	assert(up);
	int* down = (int*)calloc(n, sizeof(int));
	assert(down);
	int* left = (int*)calloc(n, sizeof(int));
	assert(left);
	int* right = (int*)calloc(n, sizeof(int));
	assert(right);
	int len = 0;
	for (int i = k, j = n - k - 1; i < n - k && j >= k; i++, j--) {
		up[len] = mat[k][i];
		down[len] = mat[n - k - 1][i];
		left[len] = mat[j][k];
		right[len] = mat[j][n - k - 1];
		len += 1;
	}
	
	int pi = 0;
	for (int i = k; i < n - k; i++) {
		mat[k][i] = left[pi];
		mat[n - k - 1][i] = right[pi];
		mat[i][k] = down[pi];
		mat[i][n - k - 1] = up[pi];
		pi += 1;
	}
	free(up);
	up = NULL;
	free(down);
	down = NULL;
	free(left);
	left = NULL;
	free(right);
	right = NULL;
}
bool IsSame(int** mat, int** target, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != target[i][j]) {
				return false;
			}
		}
	}
	return true;
}
bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
	for (int i = 0; i < 4; i++) {
		if (IsSame(mat, target, matSize)) {
			return true;
		}
		for (int k = 0; k < matSize - k - 1; k++) {
			Rotation(mat, matSize, k);
		}
	}
	return false;
}