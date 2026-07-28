#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2026.07.29力扣网刷题
//67. 二进制求和——位运算、数学、字符串、模拟——简单
//给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
//示例 1：
//输入 : a = "11", b = "1"
//输出："100"
//示例 2：
//输入：a = "1010", b = "1011"
//输出："10101"
//提示：
//1 <= a.length, b.length <= 10^4
//a 和 b 仅由字符 '0' 或 '1' 组成
//字符串如果不是 "0" ，就不含前导零

char* addBinary(char* a, char* b) {
	int len_a = strlen(a), len_b = strlen(b);
	int size = len_a > len_b ? len_a + 2 : len_b + 2;
	char* ans = (char*)calloc(size, sizeof(char));
	assert(ans);
	int len = 0;
	for (int i = len_a - 1, j = len_b - 1; i >= 0 || j >= 0; i--, j--, len++) {
		if (i >= 0 && j >= 0) {
			if (len == 0) {
				ans[len] = a[i] - '0' + b[j];
			}
			else {
				int tmp1 = (ans[len - 1] - '0') / 2, tmp2 = (ans[len - 1] - '0') % 2;
				ans[len] = a[i] - '0' + b[j] + tmp1;
				ans[len - 1] = tmp2 + '0';
			}
		}
		else if(i < 0 && j >= 0) {
			if (len == 0) {
				ans[len] = b[j];
			}
			else {
				int tmp1 = (ans[len - 1] - '0') / 2, tmp2 = (ans[len - 1] - '0') % 2;
				ans[len] = b[j] + tmp1;
				ans[len - 1] = tmp2 + '0';
			}
		}
		else if (i >= 0 && j < 0) {
			if (len == 0) {
				ans[len] = a[i];
			}
			else {
				int tmp1 = (ans[len - 1] - '0') / 2, tmp2 = (ans[len - 1] - '0') % 2;
				ans[len] = a[i] + tmp1;
				ans[len - 1] = tmp2 + '0';
			}
		}
	}
	if (ans[len - 1] >= '2') {
		ans[len] = (ans[len - 1] - '0') / 2 + '0';
		ans[len - 1] = (ans[len - 1] - '0') % 2 + '0';
		len += 1;
	}
	for (int l = 0, r = len - 1; l < r; l++, r--) {
		char tmp = ans[l];
		ans[l] = ans[r];
		ans[r] = tmp;
	}
	return ans;
}