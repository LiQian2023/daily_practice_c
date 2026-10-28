#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

//2026.10.28力扣网刷题
//3882. 网格图中最小异或路径——资深工程师、位运算、数组、动态规划、矩阵、第179场双周赛——中等
//给你一个大小为 m * n 的二维整数数组 grid。
//你从 左上角 的单元格(0, 0) 出发，想要到达 右下角 的单元格(m - 1, n - 1)。
//在每一步中，你 可以 向右或向下 移动。
//路径的 代价 定义为该路径上所有单元格（包括 起点和终点）的值的 按位异或。
//返回从(0, 0) 到(m - 1, n - 1) 的所有有效路径中 最小 的可能异或值。
//示例 1：
//输入： grid = [[1, 2], [3, 4]]
//输出： 6
//解释：
//有两条有效路径：
//(0, 0) →(0, 1) →(1, 1)，异或值为：1 XOR 2 XOR 4 = 7
//(0, 0) →(1, 0) →(1, 1)，异或值为：1 XOR 3 XOR 4 = 6
//所有有效路径中的最小异或值为 6。
//示例 2：
//输入： grid = [[6, 7], [5, 8]]
//输出： 9
//解释：
//有两条有效路径：
//(0, 0) →(0, 1) →(1, 1)，异或值为：6 XOR 7 XOR 8 = 9
//(0, 0) →(1, 0) →(1, 1)，异或值为：6 XOR 5 XOR 8 = 11
//所有有效路径中的最小异或值为 9。
//示例 3：
//输入： grid = [[2, 7, 5]]
//输出： 0
//解释：
//只有一条有效路径：
//(0, 0) →(0, 1) →(0, 2)，异或值为：2 XOR 7 XOR 5 = 0
//这条路径的异或值为 0，这是可能达到的最小值。
//提示：
//1 <= m == grid.length <= 1000
//1 <= n == grid[i].length <= 1000
//m * n <= 1000
//0 <= grid[i][j] <= 1023​

bool*** Create(int m, int n) {
	bool*** dp = (bool***)calloc(m, sizeof(bool**));
	assert(dp);
	for (int i = 0; i < m; i++) {
		dp[i] = (bool**)calloc(n, sizeof(bool*));
		assert(dp[i]);
		for (int j = 0; j < n; j++) {
			dp[i][j] = (bool*)calloc(1024, sizeof(bool));
			assert(dp[i][j]);
		}
	}
	return dp;
}
void Destroy(bool**** dp, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			free((*dp)[i][j]);
			(*dp)[i][j] = NULL;
		}
		free((*dp)[i]);
		(*dp)[i] = NULL;
	}
	free(*dp);
	*dp = NULL;
}

// 方法一：DFS + 状态去重
void dfs(int** grid, int m, int n, int val, int x, int y,bool*** visited) {
	if (x >= m || y >= n) {
		return;
	}
	val ^= grid[x][y];
	if (visited[x][y][val]) {
		return;
	}
	visited[x][y][val] = true;
	if (x == m - 1 && y == n - 1) {
		return;
	}
	dfs(grid, m, n, val, x, y + 1, visited);
	dfs(grid, m, n, val, x + 1, y, visited);
}

int minCost1(int** grid, int gridSize, int* gridColSize) {
	int m = gridSize, n = gridColSize[0];
	bool*** visited = Create(m, n);
	dfs(grid, gridSize, gridColSize[0], 0, 0, 0, visited);
	int ans = 0;
	for (int i = m - 1, j = n - 1, k = 0; k < 1024; k++) {
		if (visited[i][j][k]) {
			ans = k;
			break;
		}
	}
	Destroy(&visited, m, n);
	return ans;
}

// 方法二：迭代DP + 三维数组

int minCost2(int** grid, int gridSize, int* gridColSize) {
	int m = gridSize, n = gridColSize[0];
	bool*** dp = Create(m, n);
	dp[0][0][grid[0][0]] = true;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 1024; k++) {
				if (!dp[i][j][k]) {
					continue;
				}
				if (i < m - 1) {
					dp[i + 1][j][k ^ grid[i + 1][j]] = true;
				}
				if (j < n - 1) {
					dp[i][j + 1][k ^ grid[i][j + 1]] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int k = 0; k < 1024; k++) {
		if (dp[m - 1][n - 1][k]) {
			ans = k;
			break;
		}
	}
	Destroy(&dp, m, n);
	return ans;
}

int minCost(int** grid, int gridSize, int* gridColSize) {
	int m = gridSize, n = gridColSize[0];
	bool** dp = (bool**)calloc(n, sizeof(bool*));
	assert(dp);
	for (int i = 0; i < n; i++) {
		dp[i] = (bool*)calloc(1024, sizeof(bool));
		assert(dp[i]);
	}
	dp[0][grid[0][0]] = true;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			bool cur[1024] = { 0 };
			for (int k = 0; k < 1024; k++) {
				if ((i > 0 && dp[j][k]) || (j > 0 && dp[j - 1][k])) {
					cur[k ^ grid[i][j]] = 1;
				}
			}
			memcpy(dp[j], cur, 1024 * sizeof(cur[0]));
		}
	}
	int ans = 0;
	for (int i = 0; i < 1024; i++) {
		if (dp[n - 1][i]) {
			ans = i;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		free(dp[i]);
		dp[i] = NULL;
	}
	free(dp);
	dp = NULL;
	return ans;
}