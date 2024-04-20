#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//2024.04.20力扣网刷题
//数组形式的整数加法——数组、数学——简单
//整数的 数组形式  num 是按照从左到右的顺序表示其数字的数组。
//例如，对于 num = 1321 ，数组形式是[1, 3, 2, 1] 。
//给定 num ，整数的 数组形式 ，和整数 k ，返回 整数 num + k 的 数组形式 。
//示例 1：
//输入：num = [1, 2, 0, 0], k = 34
//输出：[1, 2, 3, 4]
//解释：1200 + 34 = 1234
//示例 2：
//输入：num = [2, 7, 4], k = 181
//输出：[4, 5, 5]
//解释：274 + 181 = 455
//示例 3：
//输入：num = [2, 1, 5], k = 806
//输出：[1, 0, 2, 1]
//解释：215 + 806 = 1021
//提示：
//1 <= num.length <= 10^4
//0 <= num[i] <= 9
//num 不包含任何前导零，除了零本身
//1 <= k <= 10^4

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
	int a = k;
	int n = 0;
	while (a) {
		n++;
		a /= 10;
	}
	n = n > numSize ? n : numSize;
	int* ans = (int*)calloc(n + 1 , sizeof(int));
	if (!ans)
		return ans;
	int i = 0;
	for (int j = numSize - 1; j >= 0; j--) {
		ans[i] += num[j] + k % 10;
		if (ans[i] > 9) {
			ans[i] %= 10;
			ans[i + 1] = 1;
		}
		k /= 10;
		i++;
	}
	while (k) {
		ans[i] += k % 10;
		if (ans[i] > 9) {
			ans[i] %= 10;
			ans[i + 1] = 1;
		}
		k /= 10;
		i++;
	}
	if (ans[i] == 1)
		i++;
	int l = 0, r = i - 1;
	while (l < r) {
		int tmp = ans[l];
		ans[l] = ans[r];
		ans[r] = tmp;
		l++, r--;
	}
	*returnSize = i;
	return ans;
}

void test() {
	int num[10] = { 0 };
	int i = 0;
	while (scanf("%d", &num[i]) == 1) {
		i++;
	}
	getchar();
	int k = 0;
	scanf("%d", &k);
	int size = 0;
	int* ret = addToArrayForm(num, i, k, &size);
	for (int j = 0; j < size; j++) {
		printf("%d", ret[j]);
	}
	printf("\n");
	free(ret);
}

int main() {
	test();
	return 0;
}