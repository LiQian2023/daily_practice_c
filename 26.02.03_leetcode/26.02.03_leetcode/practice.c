#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.02.03力扣网刷题
//面试题 08.10.颜色填充——深度优先、广度优先、数组、矩阵——简单
//编写函数，实现许多图片编辑软件都支持的「颜色填充」功能。
//待填充的图像用二维数组 image 表示，元素为初始颜色值。初始坐标点的行坐标为 sr 列坐标为 sc。需要填充的新颜色为 newColor 。
//「周围区域」是指颜色相同且在上、下、左、右四个方向上存在相连情况的若干元素。
//请用新颜色填充初始坐标点的周围区域，并返回填充后的图像。
//示例：
//输入：
//image = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
//sr = 1, sc = 1, newColor = 2
//输出： [[2, 2, 2], [2, 2, 0], [2, 0, 1]]
//解释:
//初始坐标点位于图像的正中间，坐标(sr, sc) = (1, 1) 。
//初始坐标点周围区域上所有符合条件的像素点的颜色都被更改成 2 。
//注意，右下角的像素没有更改为 2 ，因为它不属于初始坐标点的周围区域。
//提示：
//image 和 image[0] 的长度均在范围[1, 50] 内。
//初始坐标点(sr, sc) 满足 0 <= sr < image.length 和 0 <= sc < image[0].length 。
//image[i][j] 和 newColor 表示的颜色值在范围[0, 65535] 内。

void dfs(int** ans, int row, int* col, int sr, int sc, int newColor, bool** flag, int oldColor) {
	if (sr < 0 || sr >= row || sc < 0 || sc >= col[sr] || flag[sr][sc]) {
		return;
	}
	if (ans[sr][sc] == oldColor) {
		ans[sr][sc] = newColor;
		flag[sr][sc] = true;
		dfs(ans, row, col, sr - 1, sc, newColor, flag, oldColor);
		dfs(ans, row, col, sr + 1, sc, newColor, flag, oldColor);
		dfs(ans, row, col, sr, sc - 1, newColor, flag, oldColor);
		dfs(ans, row, col, sr, sc + 1, newColor, flag, oldColor);
	}
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes) {
	bool** flag = (bool**)calloc(imageSize, sizeof(bool*));
	assert(flag);
	int** ans = (int**)calloc(imageSize, sizeof(int*));
	assert(ans);
	*returnSize = imageSize;
	*returnColumnSizes = (int*)calloc(imageSize, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < imageSize; i++) {
		flag[i] = (bool*)calloc(imageColSize[i], sizeof(bool));
		assert(flag[i]);
		ans[i] = (int*)calloc(imageColSize[i], sizeof(int));
		assert(ans[i]);
		(*returnColumnSizes)[i] = imageColSize[i];
	}
	for (int i = 0; i < imageSize; i++) {
		for (int j = 0; j < imageColSize[i]; j++) {
			ans[i][j] = image[i][j];
		}
	}
	dfs(ans, imageSize, imageColSize, sr, sc, newColor, flag, image[sr][sc]);
	for (int i = 0; i < imageSize; i++) {
		free(flag[i]);
	}
	free(flag);
	return ans;
}