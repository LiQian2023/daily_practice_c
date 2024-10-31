#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
//2024.10.31力扣网刷题
//消除游戏——数学、递归——中等
//列表 arr 由在范围[1, n] 中的所有整数组成，并按严格递增排序。请你对 arr 应用下述算法：
//从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。
//重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。
//不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
//给你整数 n ，返回 arr 最后剩下的数字。
//示例 1：
//输入：n = 9
//输出：6
//解释：
//arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
//arr = [2, 4, 6, 8]
//arr = [2, 6]
//arr = [6]
//示例 2：
//输入：n = 1
//输出：1
//提示：
//1 <= n <= 10^9

//方法一：暴力求解
void dfs1(int* a, int len, int* pi, int level, int n, int flag) {
	if (n == 1)
		return;
	int gap = (int)pow(2, level) * flag;
	for (*pi; *pi < len && *pi >= 1; *pi += gap) {
		a[*pi] = 1;
		n -= 1;
	}
	if (*pi >= len) {
		*pi = len - 1;
		while (a[*pi]) {
			*pi -= 1;
		}
	}
	else {
		*pi = 2;
		while (a[*pi]) {
			*pi += 1;
		}
	}
	flag *= -1;
	level += 1;
	dfs1(a, len, pi, level, n, flag);
}
int lastRemaining1(int n) {
	if (n == 1)
		return 1;
	int* nums = (int*)calloc(n + 1, sizeof(int));
	assert(nums);
	int i = 1;
	int level = 1;
	int len = n + 1;
	int flag = 1;
	dfs1(nums, len, &i, level, n, flag);
	int ans = 1;
	for (int i = 2; i < len; i += 2) {
		if (nums[i] == 0) {
			ans = i;
			break;
		}
	}
	free(nums);
	return ans;
}

//方法二：空间优化
void dfs2(int* a, int len, int* pi, int level, int n, int flag) {
	if (n == 1)
		return;
	int gap = (int)pow(2, level) * flag;
	for (*pi; *pi < len && *pi >= 1; *pi += gap) {
		a[*pi] = 1;
		n -= 1;
	}
	if (*pi >= len) {
		*pi = len - 1;
		while (a[*pi]) {
			*pi -= 1;
		}
	}
	else {
		*pi = 1;
		while (a[*pi]) {
			*pi += 1;
		}
	}
	flag *= -1;
	level += 1;
	dfs2(a, len, pi, level, n, flag);
}
int lastRemaining2(int n) {
	if (n == 1)
		return 1;
	n /= 2;
	int* nums = (int*)calloc(n + 1, sizeof(int));
	assert(nums);
	int i = n;
	int level = 1;
	int len = n + 1;
	int flag = -1;
	dfs2(nums, len, &i, level, n, flag);
	int ans = 1;
	for (int i = 1; i < len; i += 1) {
		if (nums[i] == 0) {
			ans = i * 2;
			break;
		}
	}
	free(nums);
	return ans;
}

//方法三：空间优化2
void dfs3(bool* a, int len, int* pi, int level, int n, int flag) {
	if (n == 1)
		return;
	int gap = (int)pow(2, level) * flag;
	for (*pi; *pi < len && *pi >= 1; *pi += gap) {
		a[*pi] = true;
		n -= 1;
	}
	if (*pi >= len) {
		*pi = len - 1;
		while (a[*pi]) {
			*pi -= 1;
		}
	}
	else {
		*pi = 1;
		while (a[*pi]) {
			*pi += 1;
		}
	}
	flag *= -1;
	level += 1;
	dfs3(a, len, pi, level, n, flag);
}
int lastRemaining3(int n) {
	if (n == 1)
		return 1;
	n /= 2;
	bool* nums = (bool*)calloc(n + 1, sizeof(bool));
	assert(nums);
	int i = n;
	int level = 1;
	int len = n + 1;
	int flag = -1;
	dfs3(nums, len, &i, level, n, flag);
	int ans = 1;
	for (int i = 1; i < len; i += 1) {
		if (nums[i] == 0) {
			ans = i * 2;
			break;
		}
	}
	free(nums);
	return ans;
}

//方法四：算法优化——等差数列模型
int lastRemaining4(int n) {
	int a1 = 1;//每次消除的数列首项
	int d = 2;//每次消除的数列公差
	int nums = n % 2 ? n / 2 + 1 : n / 2;//每次消除的数列元素个数
	int an = a1 + (nums - 1) * d;//每次消除的数列尾项
	while (n > 1) {
		a1 = n % 2 ? an - d / 2 : an + d / 2;
		n -= nums;//剩余元素个数
		d *= -2;
		nums = n % 2 ? n / 2 + 1 : n / 2;
		an = a1 + (nums - 1) * d;
	}
	return a1;
}
//方法五：递归
int dfs(int* a1, int* an, int* d, int* nums, int* n) {
	if (*n == 1)
		return *a1;
	*a1 = (*n) % 2 ? (*an) - (*d) / 2 : (*an) + (*d) / 2;
	*n -= *nums;
	*d *= -2;
	*nums = (*n) % 2 ? (*n) / 2 + 1 : (*n) / 2;
	*an = (*a1) + (*nums - 1) * (*d);
	return dfs(a1, an, d, nums, n);
}
int lastRemaining(int n) {
	int a1 = 1;
	int d = 2;
	int nums = n % 2 ? n / 2 + 1 : n / 2;
	int an = a1 + (nums - 1) * d;
	return dfs(&a1, &an, &d, &nums, &n);
}
void test() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int ret = lastRemaining(n);
		printf("ret = %d\n", ret);
	}
}

int main() {
	test();
	return 0;
}

//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64——1
//64 62 60 58 56 54 52 50 48 46 44 42 40 38 36 34 32 30 28 26 24 22 20 18 16 14 12 10 8 6 4 2——2
//2 6 10 14 18 22 26 30 34 38 42 46 50 54 58 62——4
//62 54 46 38 30 22 14 6——8
//6 22 38 54——16
//54 22——32
//22