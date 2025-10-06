#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.10.07力扣网刷题
//1260. 二维网格迁移——数组、矩阵、模拟、第163场周赛——简单
//给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。
//每次「迁移」操作将会引发下述活动：
//位于 grid[i][j]（j < n - 1）的元素将会移动到 grid[i][j + 1]。
//位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
//位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
//请你返回 k 次迁移操作后最终得到的 二维网格。
//示例 1：
//输入：grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 1
//输出： [[9, 1, 2], [3, 4, 5], [6, 7, 8]]
//示例 2：
//输入：grid = [[3, 8, 1, 9], [19, 7, 2, 5], [4, 6, 11, 10], [12, 0, 21, 13]], k = 4
//输出： [[12, 0, 21, 13], [3, 8, 1, 9], [19, 7, 2, 5], [4, 6, 11, 10]]
//示例 3：
//输入：grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 9
//输出： [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//提示：
//m == grid.length
//n == grid[i].length
//1 <= m <= 50
//1 <= n <= 50
//- 1000 <= grid[i][j] <= 1000
//0 <= k <= 100

int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = gridSize;
    *returnColumnSizes = (int*)calloc(gridSize, sizeof(int));
    assert(*returnColumnSizes);
    int** ans = (int**)calloc(gridSize, sizeof(int*));
    assert(ans);
    for (int i = 0; i < gridSize; i++) {
        (*returnColumnSizes)[i] = gridColSize[i];
        ans[i] = (int*)calloc(gridColSize[i], sizeof(int));
        assert(ans[i]);
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            int move_r = (j + k) / gridColSize[i];
            int move_c = (j + k) % gridColSize[i];
            printf("move_r = %d\tmove_c = %d\n", move_r, move_c);
            int row = (i + move_r) % gridSize, col = move_c;
            printf("row = %d\tcol = %d\n", row, col);
            ans[row][col] = grid[i][j];
            row += 1, col += 1;
        }
    }
    return ans;
}