#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//2025.08.16力扣网刷题
//6 和 9 组成的最大数字——贪心、数学、第172场周赛——简单
//给你一个仅由数字 6 和 9 组成的正整数 num。
//你最多只能翻转一位数字，将 6 变成 9，或者把 9 变成 6 。
//请返回你可以得到的最大数字。
//示例 1：
//输入：num = 9669
//输出：9969
//解释：
//改变第一位数字可以得到 6669 。
//改变第二位数字可以得到 9969 。
//改变第三位数字可以得到 9699 。
//改变第四位数字可以得到 9666 。
//其中最大的数字是 9969 。
//示例 2：
//输入：num = 9996
//输出：9999
//解释：将最后一位从 6 变到 9，其结果 9999 是最大的数。
//示例 3：
//输入：num = 9999
//输出：9999
//解释：无需改变就已经是最大的数字了。
//提示：
//1 <= num <= 10 ^ 4
//num 每一位上的数字都是 6 或者 9 。

int maximum69Number1(int num) {
	if (num > 1000) {
		if (num / 1000 == 6) {
			return 9000 + num % 1000;
		}
		else if (num / 100 == 96) {
			return 9900 + num % 100;
		}
		else if (num / 10 == 996) {
			return 9990 + num % 10;
		}
		return 9999;
	}
	else if (num < 1000 && num > 100) {
		if (num / 100 == 6) {
			return 900 + num % 100;
		}
		else if (num / 10 == 96) {
			return 990 + num % 10;
		}
		return 999;
	}
	else if (num < 100 && num > 10) {
		if (num / 10 == 6) {
			return 90 + num % 10;
		}
		return 99;
	}
	return 9;
}

int maximum69Number(int num) {
	int* arr = (int*)calloc(5, sizeof(int));
	assert(arr);
	int n = 0;
	for (n = 0; num; num /= 10) {
		arr[n++] = num % 10;
	}
	int ans = 0;
	int change = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans *= 10;
		if (change == 0 && arr[i] == 6) {
			ans += 9;
			change = 1;
			continue;
		}
		ans += arr[i];
	}
	free(arr);
	return ans;
}