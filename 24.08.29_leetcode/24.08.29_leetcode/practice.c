#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
//2024.08.29力扣网刷题
//判断矩阵是否满足条件——数组、矩阵——简单
//给你一个大小为 m x n 的二维矩阵 grid 。你需要判断每一个格子 grid[i][j] 是否满足：
//如果它下面的格子存在，那么它需要等于它下面的格子，也就是 grid[i][j] == grid[i + 1][j] 。
//如果它右边的格子存在，那么它需要不等于它右边的格子，也就是 grid[i][j] != grid[i][j + 1] 。
//如果 所有 格子都满足以上条件，那么返回 true ，否则返回 false 。
//示例 1：
//输入：grid = [[1, 0, 2], [1, 0, 2]]
//输出：true
//解释：
//网格图中所有格子都符合条件。
//示例 2：
//输入：grid = [[1, 1, 1], [0, 0, 0]]
//输出：false
//解释：
//同一行中的格子值都相等。
//示例 3：
//输入：grid = [[1], [2], [3]]
//输出：false
//解释：
//同一列中的格子值不相等。
//提示：
//1 <= n, m <= 10
//0 <= grid[i][j] <= 9

bool CountSort(int* a, int n) {
	int nums[10] = { 0 };
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		nums[a[i]] += 1;
		if (nums[a[i]] > 1)
			return false;
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	n = 0;
	for (int i = min; i <= max; i++) {
		if (nums[i]) {
			a[n++] = i;
		}
	}
	return true;
}

//方法一：模拟
bool satisfiesConditions(int** grid, int gridSize, int* gridColSize) {
	//判断每一行是否存在相等
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i] - 1; j++) {
			if (grid[i][j] == grid[i][j + 1]) {
				return false;
			}
		}
	}
	//判断每一列是否存在不相等
	int row = 0;
	for (int i = 0; i < gridColSize[row]; i++) {
		for (int j = 0; j < gridSize - 1; j++) {
			if (grid[j][i] != grid[j + 1][i]) {
				return false;
			}
		}
	}
	return true;
}