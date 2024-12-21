#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <strlib.h>
#include <assert.h>
//2024.12.21力扣网刷题
//找到一个数字的 K 美丽值——数学、字符串、滑动窗口——简单
//一个整数 num 的 k 美丽值定义为 num 中符合以下条件的 子字符串 数目：
//子字符串长度为 k 。
//子字符串能整除 num 。
//给你整数 num 和 k ，请你返回 num 的 k 美丽值。
//注意：
//允许有 前缀 0 。
//0 不能整除任何值。
//一个 子字符串 是一个字符串里的连续一段字符序列。
//示例 1：
//输入：num = 240, k = 2
//输出：2
//解释：以下是 num 里长度为 k 的子字符串：
//- "240" 中的 "24" ：24 能整除 240 。
//- "240" 中的 "40" ：40 能整除 240 。
//所以，k 美丽值为 2 。
//示例 2：
//输入：num = 430043, k = 2
//输出：2
//解释：以下是 num 里长度为 k 的子字符串：
//- "430043" 中的 "43" ：43 能整除 430043 。
//- "430043" 中的 "30" ：30 不能整除 430043 。
//- "430043" 中的 "00" ：0 不能整除 430043 。
//- "430043" 中的 "04" ：4 不能整除 430043 。
//- "430043" 中的 "43" ：43 能整除 430043 。
//所以，k 美丽值为 2 。
//提示：
//1 <= num <= 10^9
//1 <= k <= num.length （将 num 视为字符串）

void int_to_str(char* str, int a, int* pi) {
	int i = 9;
	for (; a; i -= 1, a /= 10) {
		str[i] = a % 10 + '0';
	}
	*pi = 9 - i;
	i += 1;
	if (str[0] == 0) {
		for (int j = 0; j < *pi; j++, i++) {
			str[j] = str[i];
			str[i] = 0;
		}
	}
}
int divisorSubstrings(int num, int k) {
	char* str = (char*)calloc(10, sizeof(char));
	assert(str);
	int len = 0;
	int_to_str(str, num, &len);
	int ans = 0;
	for (int i = 0; i < len; i++) {
		int tmp = 0;
		for (int j = i; j < i + k && i + k <= len; j++) {
			tmp *= 10;
			tmp += str[j] - '0';
		}
		if (tmp && num % tmp == 0) {
			ans += 1;
		}
	}
	free(str);
	return ans;
}