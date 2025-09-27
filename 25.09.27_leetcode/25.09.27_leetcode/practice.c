#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//2025.09.27力扣网刷题
//翻转图像——位运算、数组、双指针、矩阵、模拟、第 84 场周赛——简单
//给定一个 n x n 的二进制矩阵 image ，先 水平 翻转图像，然后 反转 图像并返回 结果 。
//水平翻转图片就是将图片的每一行都进行翻转，即逆序。
//例如，水平翻转[1, 1, 0] 的结果是[0, 1, 1]。
//反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。
//例如，反转[0, 1, 1] 的结果是[1, 0, 0]。
//示例 1：
//输入：image = [[1, 1, 0], [1, 0, 1], [0, 0, 0]]
//输出： [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
//解释：首先翻转每一行: [[0, 1, 1], [1, 0, 1], [0, 0, 0]] ；
//然后反转图片 : [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
//示例 2：
//输入：image = [[1, 1, 0, 0], [1, 0, 0, 1], [0, 1, 1, 1], [1, 0, 1, 0]]
//输出： [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
//解释：首先翻转每一行 : [[0, 0, 1, 1], [1, 0, 0, 1], [1, 1, 1, 0], [0, 1, 0, 1]] ；
//然后反转图片 : [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
//提示：
//n == image.length
//n == image[i].length
//1 <= n <= 20
//images[i][j] == 0 或 1.


int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
	int** ans = (int**)calloc(imageSize, sizeof(int*));
	assert(ans);
	*returnSize = imageSize;
	*returnColumnSizes = (int*)calloc(imageSize, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < imageSize; i++) {
		ans[i] = (int*)calloc(imageColSize[i], sizeof(int));
		assert(ans[i]);
		*returnColumnSizes[i] = imageColSize[i];
	}
	for (int i = 0; i < imageSize; i++) {
		for (int j = 0, z = imageColSize[i] - 1; j < imageColSize[i]; j++, z--) {
			if (image[i][z] == 1) {
				ans[i][j] = 0;
			}
			else {
				ans[i][j] = 1;
			}
		}
	}
	return ans;
}