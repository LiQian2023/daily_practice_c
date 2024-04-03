#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//2024.04.04力扣网刷题
//转置矩阵——数组、矩阵、模拟——简单
//给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。
//矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
//示例 1：
//输入：matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//输出： [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
//示例 2：
//输入：matrix = [[1, 2, 3], [4, 5, 6]]
//输出： [[1, 4], [2, 5], [3, 6]]
//提示：
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 1000
//1 <= m * n <= 10^5
//- 10^9 <= matrix[i][j] <= 10^9
#define ROW 3
#define COL 3
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize, n = matrixColSize[0];
    int** transposed = malloc(sizeof(int*) * n);
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        transposed[i] = malloc(sizeof(int) * m);
        (*returnColumnSizes)[i] = m;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

//分别申请行和列的空间
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matrixColSize[0];//返回行空间大小
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));//行个数
    for (int i = 0; i < (*returnSize); i++) 
        (*returnColumnSizes)[i] = matrixSize;//每一行空间大小
    int** ans = (int**)malloc(sizeof(int*) * (*returnSize));//返回数组行个数
    for (int i = 0; i < (*returnSize); i++) 
        ans[i] = (int*)malloc(sizeof(int) * (matrixSize));//为每一行申请空间
    for (int i = 0; i < (*returnSize); i++) 
        for (int j = 0; j < (matrixSize); j++) 
            ans[i][j] = matrix[j][i];//转置
    return ans;
}