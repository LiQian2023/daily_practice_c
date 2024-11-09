#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.11.09力扣网刷题
//设计相邻元素求和服务——设计、数组、哈希、矩阵、模拟——简单
//给你一个 n x n 的二维数组 grid，它包含范围[0, n2 - 1] 内的不重复元素。
//实现 neighborSum 类：
//neighborSum(int[][]grid) 初始化对象。
//int adjacentSum(int value) 返回在 grid 中与 value 相邻的元素之和，相邻指的是与 value 在上、左、右或下的元素。
//int diagonalSum(int value) 返回在 grid 中与 value 对角线相邻的元素之和，对角线相邻指的是与 value 在左上、右上、左下或右下的元素。
//示例 1：
//输入：
//["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"]
//[[[[0, 1, 2], [3, 4, 5], [6, 7, 8]] ], [1], [4], [4], [8]]
//输出：[null, 6, 16, 16, 4]
//解释：
//1 的相邻元素是 0、2 和 4。
//4 的相邻元素是 1、3、5 和 7。
//4 的对角线相邻元素是 0、2、6 和 8。
//8 的对角线相邻元素是 4。
//示例 2：
//输入：
//["neighborSum", "adjacentSum", "diagonalSum"]
//[[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]] ], [15], [9]]
//输出：[null, 23, 45]
//解释：
//15 的相邻元素是 0、10、7 和 6。
//9 的对角线相邻元素是 4、12、14 和 15。
//提示：
//3 <= n == grid.length == grid[0].length <= 10
//0 <= grid[i][j] <= n^2 - 1
//所有 grid[i][j] 值均不重复。
//adjacentSum 和 diagonalSum 中的 value 均在范围[0, n^2 - 1] 内。
//最多会调用 adjacentSum 和 diagonalSum 总共 2 * n^2 次。

int size = 0;
typedef struct {
	int key;
	int adjacent[4];
	int diagonal[4];
} NeighborSum;


NeighborSum* neighborSumCreate(int** grid, int gridSize, int* gridColSize) {
	size = gridSize * gridColSize[0];
	NeighborSum* obj = (NeighborSum*)calloc(size, sizeof(NeighborSum));
	assert(obj);
	int len = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i]; j++) {
			obj[len].key = grid[i][j];
			if (i - 1 >= 0)
				obj[len].adjacent[0] = grid[i - 1][j];
			else
				obj[len].adjacent[0] = 0;
			if (i + 1 < gridSize)
				obj[len].adjacent[1] = grid[i + 1][j];
			else
				obj[len].adjacent[1] = 0;
			if (j - 1 >= 0)
				obj[len].adjacent[2] = grid[i][j - 1];
			else
				obj[len].adjacent[2] = 0;
			if (j + 1 < gridColSize[i])
				obj[len].adjacent[3] = grid[i][j + 1];
			else
				obj[len].adjacent[3] = 0;
			if (i - 1 >= 0 && j - 1 >= 0)
				obj[len].diagonal[0] = grid[i - 1][j - 1];
			else
				obj[len].diagonal[0] = 0;
			if (i + 1 < gridSize && j + 1 < gridColSize[i])
				obj[len].diagonal[1] = grid[i + 1][j + 1];
			else
				obj[len].diagonal[1] = 0;
			if (i - 1 >= 0 && j + 1 < gridColSize[i])
				obj[len].diagonal[2] = grid[i - 1][j + 1];
			else
				obj[len].diagonal[2] = 0;
			if (i + 1 < gridSize && j - 1 >= 0)
				obj[len].diagonal[3] = grid[i + 1][j - 1];
			else
				obj[len].diagonal[3] = 0;
			len += 1;
		}
	}
	return obj;
}

int neighborSumAdjacentSum(NeighborSum* obj, int value) {
	int i = 0;
	for (i; i < size; i++) {
		if (obj[i].key == value)
			break;
	}
	int sum = 0;
	for (int j = 0; j < 4; j++) {
		sum += obj[i].adjacent[j];
	}
	return sum;
}

int neighborSumDiagonalSum(NeighborSum* obj, int value) {
	int i = 0;
	for (i; i < size; i++) {
		if (obj[i].key == value)
			break;
	}
	int sum = 0;
	for (int j = 0; j < 4; j++) {
		sum += obj[i].diagonal[j];
	}
	return sum;
}

void neighborSumFree(NeighborSum* obj) {
	free(obj);
}