#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2025.01.12力扣网刷题
//千位分隔数——字符串——简单
//给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。
//示例 1：
//输入：n = 987
//输出："987"
//示例 2：
//输入：n = 1234
//输出："1.234"
//示例 3：
//输入：n = 123456789
//输出："123.456.789"
//示例 4：
//输入：n = 0
//输出："0"
//提示：
//0 <= n < 2 ^ 31

char* thousandSeparator(int n) {
	if (n == 0)
		return "0";
	char* ans = (char*)calloc(14, sizeof(char));
	assert(ans);
	int i = 0;
	for (i; n; i++, n /= 10) {
		if (i == 3 || i == 7 || i == 11) {
			ans[i] = '.';
			i++;
		}
		ans[i] = n % 10 + '0';
	}
	int l = 0, r = i - 1;
	while (l < r) {
		char tmp = ans[l];
		ans[l] = ans[r];
		ans[r] = tmp;
		l++, r--;
	}
	return ans;
}