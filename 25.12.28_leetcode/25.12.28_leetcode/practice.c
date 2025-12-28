#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2025.12.28力扣网刷题
//1351. 统计有序矩阵中的负数——数组、二分查找、矩阵、第176场周赛——简单
//给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非严格递减顺序排列。 请你统计并返回 grid 中 负数 的数目。
//示例 1：
//输入：grid = [[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]
//输出：8
//解释：矩阵中共有 8 个负数。
//示例 2：
//输入：grid = [[3, 2], [1, 0]]
//输出：0
//提示：
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 100
//- 100 <= grid[i][j] <= 100
//进阶：你可以设计一个时间复杂度为 O(n + m) 的解决方案吗？

int countNegatives(int** grid, int gridSize, int* gridColSize) {
	int ans = 0;
	int i = 0, j = 0;
	for (; i < gridSize && j <= gridColSize[0] && j >= 0;) {
		if (j == gridColSize[0] && grid[i][j] >= 0) {
			i += 1;
		}
		else {
			if (grid[i][j] >= 0) {
				j += 1;
			}
			else {
				if (j - 1 >= 0 && grid[i][j - 1] >= 0) {
					ans += gridColSize[0] - j;
					i += 1;
				}
				j -= 1;
			}
		}
	}
	if (j < 0) {
		ans += (gridSize - i) * gridColSize[0];
	}
	return ans;
}