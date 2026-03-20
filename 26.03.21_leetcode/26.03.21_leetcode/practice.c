#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2026.03.21力扣网刷题
//3643. 垂直翻转子矩阵——中级工程师、数组、双指针、矩阵、第462场周赛——简单
//给你一个 m x n 的整数矩阵 grid，以及三个整数 x、y 和 k。
//整数 x 和 y 表示一个 正方形子矩阵 的左上角下标，整数 k 表示该正方形子矩阵的边长。
//你的任务是垂直翻转子矩阵的行顺序。
//返回更新后的矩阵。
//示例 1：
//输入： grid = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]], x = 1, y = 0, k = 3
//输出： [[1, 2, 3, 4], [13, 14, 15, 8], [9, 10, 11, 12], [5, 6, 7, 16]]
//解释：
//上图展示了矩阵在变换前后的样子。
//示例 2：
//输入： grid = [[3, 4, 2, 3], [2, 3, 4, 2]], x = 0, y = 2, k = 2
//输出： [[3, 4, 4, 2], [2, 3, 2, 3]]
//解释：
//上图展示了矩阵在变换前后的样子。
//提示：
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 50
//1 <= grid[i][j] <= 100
//0 <= x < m
//0 <= y < n
//1 <= k <= min(m - x, n - y)

int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {
	int** ans = (int**)calloc(gridSize, sizeof(int*));
	assert(ans);
	*returnSize = gridSize;
	*returnColumnSizes = (int*)calloc(gridSize, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < gridSize; i++) {
		ans[i] = (int*)calloc(gridColSize[0], sizeof(int));
		assert(ans[i]);
		(*returnColumnSizes)[i] = gridColSize[0];
	}
	int end_x = x + k - 1, end_y = y + k - 1;
	for (int i = 0; i < gridSize; i++) {
		bool flag = false;
		for (int j = 0; j < gridColSize[0]; j++) {
			if (i >= x && i <= x + k - 1 && j >= y && j <= y + k - 1) {
				ans[i][j] = grid[end_x][j];
				flag = true;
			}
			else { 
				ans[i][j] = grid[i][j];
			}
		}
		if (flag) {
			end_x -= 1;
		}
	}
	return ans;
}