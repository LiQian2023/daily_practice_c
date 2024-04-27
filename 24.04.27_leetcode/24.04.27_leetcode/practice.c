#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//2024.04.27力扣网刷题
//查询网格图中每一列的宽度——数组、矩阵——简单
//给你一个下标从 0 开始的 m x n 整数矩阵 grid 。矩阵中某一列的宽度是这一列数字的最大 字符串长度 。
//比方说，如果 grid = [[-10], [3], [12]] ，那么唯一一列的宽度是 3 ，因为 - 10 的字符串长度为 3 。
//请你返回一个大小为 n 的整数数组 ans ，其中 ans[i] 是第 i 列的宽度。
//一个有 len 个数位的整数 x ，如果是非负数，那么 字符串长度 为 len ，否则为 len + 1 。
//示例 1：
//输入：grid = [[1], [22], [333]]
//输出：[3]
//解释：第 0 列中，333 字符串长度为 3 。
//示例 2：
//输入：grid = [[-15, 1, 3], [15, 7, 12], [5, 6, -2]]
//输出：[3, 1, 2]
//解释：
//第 0 列中，只有 - 15 字符串长度为 3 。
//第 1 列中，所有整数的字符串长度都是 1 。
//第 2 列中，12 和 - 2 的字符串长度都为 2 。
//提示：
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 100
//- 10^9 <= grid[r][c] <= 10^9

int* findColumnWidth(int** grid, int gridSize, int* gridColSize, int* returnSize) {
	int* ans = (int*)calloc(*gridColSize, sizeof(int));
	if (!ans)
		return NULL;
	*returnSize = *gridColSize;
	//获取行元素
	for (int i = 0; i < gridSize; i++) {
		int j = 0;
		//获取列元素
		for (int z = 0; z < (*gridColSize); z++) {
			int a = grid[i][z];
			int max = 0;
			if (a == 0)
				max++;
			//获取每列元素的字符个数
			if (a < 0) 
				max++;
			while (a) {
				max++;
				a /= 10;
			}
			if (ans[j] < max)
				ans[j] = max;
			j++;
		}
	}
	return ans;
}

void test() {
	int m = 0, n = 0;
	while (scanf("%d%d", &m, &n) == 2) {
		int** num = (int**)calloc(m, sizeof(int*));
		assert(num);
		for (int i = 0; i < m; i++) {
			num[i] = (int*)calloc(n, sizeof(int));
			assert(num[i]);
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &num[i][j]);
		int size = 0;
		int* ret = findColumnWidth(num, m, &n, &size);
		for (int i = 0; i < size; i++)
			printf("%d ", ret[i]);
		free(num);
		free(ret);
	}
}

int main() {
	test();
	return 0;
}