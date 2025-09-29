#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.09.29力扣网刷题
//三维形体投影面积——几何、数组、数学、矩阵、第96场周赛——简单
//在 n x n 的网格 grid 中，我们放置了一些与 x，y，z 三轴对齐的 1 x 1 x 1 立方体。
//每个值 v = grid[i][j] 表示有一列 v 个正方体叠放在格子(i, j) 上。
//现在，我们查看这些立方体在 xy 、yz 和 zx 平面上的投影。
//投影 就像影子，将 三维 形体映射到一个 二维 平面上。从顶部、前面和侧面看立方体时，我们会看到“影子”。
//返回 所有三个投影的总面积 。
//示例 1：
//输入： [[1, 2], [3, 4]]
//输出：17
//解释：这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。
//示例 2:
//输入：grid = [[2]]
//输出：5
//示例 3：
//输入： [[1, 0], [0, 2]]
//输出：8
//提示：
//n == grid.length == grid[i].length
//1 <= n <= 50
//0 <= grid[i][j] <= 50

int projectionArea(int** grid, int gridSize, int* gridColSize) {
	int* front = (int*)calloc(gridColSize[0], sizeof(int));
	assert(front);
	int* side = (int*)calloc(gridColSize[0], sizeof(int));
	assert(side);
	int top = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i]; j++) {
			// 俯视
			top += grid[i][j] ? 1 : 0;
			// 侧视
			if (grid[i][j] > side[j]) {
				side[j] = grid[i][j];
			}
			// 正视
			if (grid[i][j] > front[i]) {
				front[i] = grid[i][j];
			}
		}
	}
	int ans = top;
	for (int i = 0; i < gridColSize[0]; i++) {
		ans += side[i] + front[i];
	}
	free(side);
	side = NULL;
	free(front);
	front = NULL;
	return ans;
}