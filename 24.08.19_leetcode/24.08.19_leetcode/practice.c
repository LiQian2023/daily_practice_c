#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.08.19力扣网刷题
//合并相似的物品——数组、哈希表、有序集合、排序——简单
//给你两个二维整数数组 items1 和 items2 ，表示两个物品集合。每个数组 items 有以下特质：
//items[i] = [valuei, weighti] 其中 valuei 表示第 i 件物品的 价值 ，weighti 表示第 i 件物品的 重量 。
//items 中每件物品的价值都是 唯一的 。
//请你返回一个二维数组 ret，其中 ret[i] = [valuei, weighti]， weighti 是所有价值为 valuei 物品的 重量之和 。
//注意：ret 应该按价值 升序 排序后返回。
//示例 1：
//输入：items1 = [[1, 1], [4, 5], [3, 8]], items2 = [[3, 1], [1, 5]]
//输出： [[1, 6], [3, 9], [4, 5]]
//解释：
//value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 5 ，总重量为 1 + 5 = 6 。
//value = 3 的物品再 items1 中 weight = 8 ，在 items2 中 weight = 1 ，总重量为 8 + 1 = 9 。
//value = 4 的物品在 items1 中 weight = 5 ，总重量为 5 。
//所以，我们返回 [[1, 6], [3, 9], [4, 5]] 。
//示例 2：
//输入：items1 = [[1, 1], [3, 2], [2, 3]], items2 = [[2, 1], [3, 2], [1, 3]]
//输出： [[1, 4], [2, 4], [3, 4]]
//解释：
//value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 3 ，总重量为 1 + 3 = 4 。
//value = 2 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 1 ，总重量为 3 + 1 = 4 。
//value = 3 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
//所以，我们返回 [[1, 4], [2, 4], [3, 4]] 。
//示例 3：
//输入：items1 = [[1, 3], [2, 2]], items2 = [[7, 1], [2, 2], [1, 4]]
//输出： [[1, 7], [2, 4], [7, 1]]
//解释：
//value = 1 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 4 ，总重量为 3 + 4 = 7 。
//value = 2 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
//value = 7 的物品在 items2 中 weight = 1 ，总重量为 1 。
//所以，我们返回 [[1, 7], [2, 4], [7, 1]] 。
//提示：
//1 <= items1.length, items2.length <= 1000
//items1[i].length == items2[i].length == 2
//1 <= valuei, weighti <= 1000
//items1 中每个 valuei 都是 唯一的 。
//items2 中每个 valuei 都是 唯一的 。

//方法一：计数排序
void CountSort(int** a, int len) {
	int nums[1001][2] = { 0 };
	int min = a[0][0], max = a[0][0];
	for (int i = 0; i < len; i++) {
		nums[a[i][0]][0] += 1;
		nums[a[i][0]][1] += a[i][1];
		if (min > a[i][0])
			min = a[i][0];
		if (max < a[i][0])
			max = a[i][0];
	}
	len = 0;
	for (int i = min; i <= max; i++) {
		while (nums[i][0]) {
			a[len][0] = i;
			a[len][1] = nums[i][1];
			nums[i][0] -= 1;
			len += 1;
		}
	}
}

int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size, int* items2ColSize, int* returnSize, int** returnColumnSizes) {
	CountSort(items1, items1Size);
	CountSort(items2, items2Size);
	int len =  items1Size + items2Size;
	int** ans = (int**)calloc(len, sizeof(int*));
	assert(ans);
	int i = 0, j = 0, z = 0;
	for (i, j, z; i < len && j < items1Size && z < items2Size; i++) {
		ans[i] = (int*)calloc(2, sizeof(int));
		assert(ans[i]);
		if (items1[j][0] < items2[z][0]) {
			ans[i][0] = items1[j][0];
			ans[i][1] = items1[j][1];
			j += 1;
		}
		else if (items1[j][0] > items2[z][0]) {
			ans[i][0] = items2[z][0];
			ans[i][1] = items2[z][1];
			z += 1;
		}
		else {
			ans[i][0] = items1[j][0];
			ans[i][1] = items1[j][1] + items2[z][1];
			j += 1;
			z += 1;
		}
	}
	while (j < items1Size) {
		ans[i] = (int*)calloc(2, sizeof(int));
		assert(ans[i]);
		ans[i][0] = items1[j][0];
		ans[i][1] = items1[j][1];
		i += 1;
		j += 1;
	}
	while (z < items2Size) {
		ans[i] = (int*)calloc(2, sizeof(int));
		assert(ans[i]);
		ans[i][0] = items2[z][0];
		ans[i][1] = items2[z][1];
		i += 1;
		z += 1;
	}
	*returnSize = i;
	int* colsize = (int*)calloc(i, sizeof(int));
	assert(colsize);
	for (int n = 0; n < i; n++) {
		colsize[n] = 2;
	}
	*returnColumnSizes = colsize;
	return ans;
}

void test() {
	int a1[2] = { 1,1 };
	int a2[2] = { 4,5 };
	int a3[2] = { 3,8 };
	int* a[] = { a1,a2,a3 };
	int row_a = 3;
	int col_a[] = { 2,2,2 };
	int b1[2] = { 3,1 };
	int b2[2] = { 1,5 };
	int b3[2] = { 1,3 };
	int* b[] = { b1,b2 };
	int row_b = 2;
	int col_b[] = { 2,2 };
	int size = 0;
	int* colsize = NULL;
	int** ret = mergeSimilarItems(a, row_a, col_a, b, row_b, col_b, &size, &colsize);
	for (int i = 0; i < size; i++) {
		printf("[ %d,%d ], ", ret[i][0], ret[i][1]);
	}
	free(colsize);
	free(ret);
}

int main() {
	test();
	return 0;
}