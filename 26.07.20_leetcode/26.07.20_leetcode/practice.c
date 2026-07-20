#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.07.20力扣网刷题
//1260. 二维网格迁移——中级工程师、数组、矩阵、模拟、第163场周赛——简单
//给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。
//每次「迁移」操作将会引发下述活动：
//位于 grid[i][j]（j < n - 1）的元素将会移动到 grid[i][j + 1]。
//位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
//位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
//请你返回 k 次迁移操作后最终得到的 二维网格。
//示例 1：
//输入：grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 1
//输出： [[9, 1, 2], [3, 4, 5], [6, 7, 8]]
//示例 2：
//输入：grid = [[3, 8, 1, 9], [19, 7, 2, 5], [4, 6, 11, 10], [12, 0, 21, 13]], k = 4
//输出： [[12, 0, 21, 13], [3, 8, 1, 9], [19, 7, 2, 5], [4, 6, 11, 10]]
//示例 3：
//输入：grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 9
//输出： [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//提示：
//m == grid.length
//n == grid[i].length
//1 <= m <= 50
//1 <= n <= 50
//- 1000 <= grid[i][j] <= 1000
//0 <= k <= 100

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
	int m = gridSize, n = gridColSize[0];
	int** ans = (int**)calloc(m, sizeof(int*));
	assert(ans);
	*returnSize = m;
	*returnColumnSizes = (int*)calloc(m, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < m; i++) {
		ans[i] = (int*)calloc(n, sizeof(int));
		assert(ans[i]);
		*returnColumnSizes[i] = n;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int new_I = i;
			int new_J = j + k;
			if (new_J > n) {
				new_I = (new_I + new_J / n) % m;
				new_J %= n;
			}
			ans[new_I][new_J] = grid[i][j];
		}
	}

	return ans;
}