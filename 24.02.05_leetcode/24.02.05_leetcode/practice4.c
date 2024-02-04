#define _CRT_SECURE_NO_WARNINGS 1

#include "pratice.h"

//2024.02.05力扣网刷题
//重新排列数组——数组——简单
//给你一个数组 nums ，数组中有 2n 个元素，按[x1, x2, ..., xn, y1, y2, ..., yn] 的格式排列。
//请你将数组按[x1, y1, x2, y2, ..., xn, yn] 格式重新排列，返回重排后的数组。
//示例 1：
//输入：nums = [2, 5, 1, 3, 4, 7], n = 3
//输出：[2, 3, 5, 4, 1, 7]
//解释：由于 x1 = 2, x2 = 5, x3 = 1, y1 = 3, y2 = 4, y3 = 7 ，所以答案为[2, 3, 5, 4, 1, 7]
//示例 2：
//输入：nums = [1, 2, 3, 4, 4, 3, 2, 1], n = 4
//输出：[1, 4, 2, 3, 3, 2, 4, 1]
//示例 3：
//输入：nums = [1, 1, 2, 2], n = 2
//输出：[1, 2, 1, 2]
//提示：
//1 <= n <= 500
//nums.length == 2n
//1 <= nums[i] <= 10 ^ 3

//方法一：双指针
int* shuffle1(int* nums, int numsSize, int n, int* returnSize) {
	if (!nums || !returnSize)
		return NULL;
	*returnSize = numsSize;
	int* ans = (int*)calloc(numsSize, sizeof(int));
	if (!ans)
		return NULL;
	int i = 0, j = numsSize / 2;
	for (int m = 0; m < numsSize; m++) {
		if (0 == m % 2) {
			ans[m] = nums[i];
			i++;
		}
		else {
			ans[m] = nums[j];
			j++;
		}
	}
	return ans;
}

//方法二：双指针改良
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
	if (!nums || !returnSize)
		return NULL;
	*returnSize = numsSize;
	int* ans = (int*)calloc(numsSize, sizeof(int));
	if (!ans)
		return NULL;
	int i = 0, j = numsSize / 2;
	int x = 0, y = x + 1;
	for (x; x < numsSize - 1; x += 2) {
		y = x + 1;
		ans[x] = nums[i];
		ans[y] = nums[j];
		i++;
		j++;
	}
	return ans;
}
void test4() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int* p = (int*)calloc(n, sizeof(int));
		assert(p);
		for (int i = 0; i < n; i++) {
			scanf("%d", &p[i]);
		}
		int m = 0;
		scanf("%d", &m);
		int size = 0;
		int* ret = shuffle(p, n, m, &size);
		for (int i = 0; i < size; i++) {
			printf("%d,", ret[i]);
		}
		free(p);
		free(ret);
	}
}