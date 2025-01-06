#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.01.06力扣网刷题
//螺旋遍历二维数组——数组、矩阵、模拟——简单
//给定一个二维数组 array，请返回「螺旋遍历」该数组的结果。
//螺旋遍历：从左上角开始，按照 向右、向下、向左、向上 的顺序 依次 提取元素，然后再进入内部一层重复相同的步骤，直到提取完所有元素。
//示例 1：
//输入：array = [[1, 2, 3], [8, 9, 4], [7, 6, 5]]
//输出：[1, 2, 3, 4, 5, 6, 7, 8, 9]
//示例 2：
//输入：array = [[1, 2, 3, 4], [12, 13, 14, 5], [11, 16, 15, 6], [10, 9, 8, 7]]
//输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
//限制：
//0 <= array.length <= 100
//0 <= array[i].length <= 100
//注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/

int* spiralArray(int** array, int arraySize, int* arrayColSize, int* returnSize) {
	*returnSize = 0;
	for (int i = 0; i < arraySize; i++) {
		*returnSize += arrayColSize[i];
	}
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	int len = 0;//下标
	int begin = 0;//圈数
	while (len < *returnSize) {
		int i = begin, j = begin;
		if (j == arrayColSize[i] - begin - 1) {
			ans[len++] = array[i][j];
			i += 1;
		}
		//向右
		for (j; len < *returnSize && j < arrayColSize[i] - begin - 1; j++) {
			ans[len++] = array[i][j];
		}
		if (i == arraySize - begin - 1) {
			ans[len++] = array[i][j];
		}
		//向下
		for (i; len < *returnSize && i < arraySize - begin - 1; i++) {
			ans[len++] = array[i][j];
		}
		//向左
		for (j; len < *returnSize && j > begin; j--) {
			ans[len++] = array[i][j];
		}
		//向上
		for (i; len < *returnSize && i > begin; i--) {
			ans[len++] = array[i][j];
		}
		begin += 1;
	}
	return ans;
}