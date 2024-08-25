#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.08.25力扣网刷题
//删除每行中的最大值——数组、矩阵、排序、模拟、堆（优先队列）——简单
//给你一个 m x n 大小的矩阵 grid ，由若干正整数组成。
//执行下述操作，直到 grid 变为空矩阵：
//从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。
//将删除元素中的最大值与答案相加。
//注意 每执行一次操作，矩阵中列的数据就会减 1 。
//返回执行上述操作后的答案。
//示例 1：
//输入：grid = [[1, 2, 4], [3, 3, 1]]
//输出：8
//解释：上图展示在每一步中需要移除的值。
//- 在第一步操作中，从第一行删除 4 ，从第二行删除 3（注意，有两个单元格中的值为 3 ，我们可以删除任一）。在答案上加 4 。
//- 在第二步操作中，从第一行删除 2 ，从第二行删除 3 。在答案上加 3 。
//- 在第三步操作中，从第一行删除 1 ，从第二行删除 1 。在答案上加 1 。
//最终，答案 = 4 + 3 + 1 = 8 。
//示例 2：
//输入：grid = [[10]]
//输出：10
//解释：上图展示在每一步中需要移除的值。
//- 在第一步操作中，从第一行删除 10 。在答案上加 10 。
//最终，答案 = 10 。
//提示：
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 50
//1 <= grid[i][j] <= 100

//方法一：模拟
void CountSort(int* a, int n) {
	int count[101] = { 0 };
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		count[a[i]] += 1;
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	n = 0;
	for (int i = max; i >= min; i--) {
		while (count[i]) {
			a[n] = i;
			n += 1;
			count[i] -= 1;
		}
	}
}

int deleteGreatestValue(int** grid, int gridSize, int* gridColSize) {
	int* max = (int*)calloc(gridColSize[0], sizeof(int));
	assert(max);
	//排序
	for (int i = 0; i < gridSize; i++) {
		CountSort(grid[i], gridColSize[i]);
	}
	//找最大值
	for (int i = 0; i < gridSize; i++) {
		int len = 0;
		for (int j = 0; j < gridColSize[i]; j++) {
			if (i == 0) {
				max[len] = grid[i][j];
			}
			else {
				if (max[len] < grid[i][j]) {
					max[len] = grid[i][j];
				}
			}
			len += 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < gridColSize[0]; i++) {
		ans += max[i];
	}
	free(max);
	return ans;
}

void test() {
	int a[10] = { 1, 2, 4 };
	int len_a = 3;
	int b[10] = { 3, 3, 1 };
	int len_b = 3;
	int* arr[2] = { a,b };
	int row = 2;
	int col[] = { len_a,len_b };
	int ret = deleteGreatestValue(arr, row, col);
	printf("%d\n", ret);
}

void test1() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int a = 1111000010;
		while (a) {
			int x = a / n;
			int y = a % n;
			printf("x = %10d\t", x);
			printf("y = %d\n", y);
			a /= n;
		}
	}
}

int main() {
	test();
	return 0;
}