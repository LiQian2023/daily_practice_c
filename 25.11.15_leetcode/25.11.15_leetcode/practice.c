#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.11.15力扣网刷题
//2373. 矩阵中的局部最大值——数组、矩阵、第306场周赛——简单
//给你一个大小为 n x n 的整数矩阵 grid 。
//生成一个大小为(n - 2) x(n - 2) 的整数矩阵  maxLocal ，并满足：
//maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。
//换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。
//返回生成的矩阵。
//示例 1：
//输入：grid = [[9, 9, 8, 1], [5, 6, 2, 6], [8, 2, 6, 4], [6, 2, 2, 2]]
//输出： [[9, 9], [8, 6]]
//解释：原矩阵和生成的矩阵如上图所示。
//注意，生成的矩阵中，每个值都对应 grid 中一个相接的 3 x 3 矩阵的最大值。
//示例 2：
//输入：grid = [[1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 2, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1]]
//输出： [[2, 2, 2], [2, 2, 2], [2, 2, 2]]
//解释：注意，2 包含在 grid 中每个 3 x 3 的矩阵中。
//提示：
//n == grid.length == grid[i].length
//3 <= n <= 100
//1 <= grid[i][j] <= 100

int Get_Max(int** grid, int n, int row, int col) {
	int num = grid[row][col];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp = grid[row + i][col + j];
			if (tmp > num) {
				num = tmp;
			}
		}
	}
	return num;
}
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
	int size = gridSize - 2;
	int** ans = (int**)calloc(size, sizeof(int*));
	assert(ans);
	*returnSize = size;
	*returnColumnSizes = (int*)calloc(size, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < size; i++) {
		ans[i] = (int*)calloc(size, sizeof(int));
		assert(ans[i]);
		(*returnColumnSizes)[i] = size;
	}
	int row = 0, col = 0;
	for (int i = 0; i < gridSize - 2; i++) {
		for (int j = 0; j < gridSize - 2; j++) {
			ans[row][col] = Get_Max(grid, gridSize, i, j);
			col += 1;
			if (col == size) {
				row += 1;
				col = 0;
			}
		}
	}
	return ans;
}