#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2024.11.12力扣网刷题
//统计满足 K 约束的子字符串数量 I——字符串、滑动窗口——简单
//给你一个 二进制 字符串 s 和一个整数 k。
//如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：
//字符串中 0 的数量最多为 k。
//字符串中 1 的数量最多为 k。
//返回一个整数，表示 s 的所有满足 k 约束 的子字符串的数量。
//示例 1：
//输入：s = "10101", k = 1
//输出：12
//解释：
//s 的所有子字符串中，除了 "1010"、"10101" 和 "0101" 外，其余子字符串都满足 k 约束。
//示例 2：
//输入：s = "1010101", k = 2
//输出：25
//解释：
//s 的所有子字符串中，除了长度大于 5 的子字符串外，其余子字符串都满足 k 约束。
//示例 3：
//输入：s = "11111", k = 1
//输出：15
//解释：
//s 的所有子字符串都满足 k 约束。
//提示：
//1 <= s.length <= 50
//1 <= k <= s.length
//s[i] 是 '0' 或 '1'。

int countKConstraintSubstrings(char* s, int k) {
	int len = strlen(s);
	int* tmp = (int*)calloc(len, sizeof(int));
	assert(tmp);
	int ch = 0;
	int one = 0;
	int zero = 0;
	bool flag = true;
	for (int i = 0; ch < len; ) {
		if (flag) {
			if (s[i] == '1')
				one += 1;
			else if (s[i] == '0')
				zero += 1;
		}
		if (one > k && zero > k || i == len) {
			tmp[ch] = i - ch;
			if (s[ch] == '0')
				zero -= 1;
			else if (s[ch] == '1')
				one -= 1;
			ch += 1;
			flag = false;
		}
		if ((zero <= k || one <= k) && i < len) {
			i += 1;
			flag = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < ch; i++) {
		ans += tmp[i];
	}
	free(tmp);
	return ans;
}