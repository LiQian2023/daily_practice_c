#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//2025.01.01力扣网刷题
//将日期转换为二进制表示——数学、字符串——简单
//给你一个字符串 date，它的格式为 yyyy - mm - dd，表示一个公历日期。
//date 可以重写为二进制表示，只需要将年、月、日分别转换为对应的二进制表示（不带前导零）并遵循 year - month - day 的格式。
//返回 date 的 二进制 表示。
//示例 1：
//输入： date = "2080-02-29"
//输出： "100000100000-10-11101"
//解释：
//100000100000, 10 和 11101 分别是 2080, 02 和 29 的二进制表示。
//示例 2：
//输入： date = "1900-01-01"
//输出： "11101101100-1-1"
//解释：
//11101101100, 1 和 1 分别是 1900, 1 和 1 的二进制表示。
//提示：
//date.length == 10
//date[4] == date[7] == '-'，其余的 date[i] 都是数字。
//输入保证 date 代表一个有效的公历日期，日期范围从 1900 年 1 月 1 日到 2100 年 12 月 31 日（包括这两天）。

void Reverse(char* ans, int l, int r) {
	while (l < r) {
		char tmp = ans[l];
		ans[l] = ans[r];
		ans[r] = tmp;
		l += 1, r -= 1;
	}
}

char* convertDateToBinary(char* date) {
	int year = 0, month = 0, day = 0;
	for (int i = 0; i < 10; i++) {
		if (i < 4) {
			year += (date[i] - '0') * (int)pow(10, (3 - i));
		}
		else if (i > 4 && i < 7) {
			month += (date[i] - '0') * (int)pow(10, (6 - i));
		}
		else if (i > 7) {
			day += (date[i] - '0') * (int)pow(10, (9 - i));
		}
	}
	char* ans = (char*)calloc(24, sizeof(char));
	assert(ans);
	int len = 0;
	while (year) {
		ans[len++] = year % 2 + '0';
		year /= 2;
	}
	Reverse(ans, 0, len - 1);
	ans[len++] = '-';
	int l = len;
	while (month) {
		ans[len++] = month % 2 + '0';
		month /= 2;
	}
	Reverse(ans, l, len - 1);
	ans[len++] = '-';
	l = len;
	while (day) {
		ans[len++] = day % 2 + '0';
		day /= 2;
	}
	Reverse(ans, l, len - 1);
	return ans;
}

void test() {
	char date[10] = "2080-02-29";
	char* ret = convertDateToBinary(date);
	printf("ret = %s\n", ret);
	free(ret);
}

int main() {
	test();
	return 0;
}