#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.04.10力扣网刷题
//螺旋矩阵——数组、矩阵、模拟——中等
//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
//示例 1：
//输入：matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//输出：[1, 2, 3, 6, 9, 8, 7, 4, 5]
//示例 2：
//输入：matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
//输出：[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
//提示：
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 10
//- 100 <= matrix[i][j] <= 100

#define ROW 3
#define COL 4

//方法一：模拟——超时
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	int* ans = (int*)calloc(matrixSize * (*matrixColSize), sizeof(int));
	if (!ans)
		return NULL;
	*returnSize = matrixSize * (*matrixColSize);
	int row = matrixSize - 1, col = *matrixColSize - 1;//行、列元素个数
	int count = row < col ? (row / 2 + row % 2) : (col / 2 + col % 2);//总层数
	int k = 0;//一维数组下标
	int i = 0, j = 0;//二维数组下标
	//存放层数
	int m = 0;
	for (m; m < count;) {
		if (i == m && j < col - m) {
			while (j < col - m)//存放上边
				ans[k++] = matrix[i][j++];
		}
		else if (j == col - m && i == m) {
			while (i < row - m)//存放右边
				ans[k++] = matrix[i++][j];
		}
		else if (i == row - m && j == col - m) {
			while (j > m) //存放下边
				ans[k++] = matrix[i][j--];
		}
		else if (i == row - m && j == m) {
			while (i > m) //存放左边
				ans[k++] = matrix[i--][j];
			m++;
			i++;
			j++;
		}
	}
	while (k < *returnSize)
	{
		if (row < col)
			ans[k++] = matrix[i][j++];
		else
			ans[k++] = matrix[i++][j];
	}
	return ans;
}

void test() {
	int** arr = (int**)calloc(ROW, sizeof(int*));
	assert(arr);
	for (int i = 0; i < ROW; i++)
		arr[i] = (int*)calloc(COL, sizeof(int));
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			scanf("%d", &arr[i][j]);
	int m = ROW, n = COL;
	int size = 0;
	int* ans = spiralOrder(arr, m, &n, &size);
	for (int i = 0; i < size; i++)
		printf("%d ", ans[i]);
	free(ans);
}

int main() {
	test();
	return 0;
}