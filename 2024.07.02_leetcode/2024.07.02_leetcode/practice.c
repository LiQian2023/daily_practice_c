#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2024.07.02力扣网刷题
//反转字符串 II——双指针、字符串——简单
//给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//示例 1：
//输入：s = "abcdefg", k = 2
//输出："bacdfeg"
//示例 2：
//输入：s = "abcd", k = 2
//输出："bacd"
//提示：
//1 <= s.length <= 10^4
//s 仅由小写英文组成
//1 <= k <= 10^4

void reverse(char* s, int l, int r) {
	while (l < r) {
		char tmp = s[l];
		s[l] = s[r];
		s[r] = tmp;
		l++, r--;
	}
}

char* reverseStr(char* s, int k) {
	int len = strlen(s);
	int l = 0, r = k - 1;
	while (r < len) {
		//反转前k个字符
		reverse(s, l, r);
		l = r;
		r = l + k;
		//判断剩余字符串的长度
		if (r > len)
			break;
		//反转下一个2k
		l = r + 1;
		r = l + k - 1;
	}
	//处理字符串总长小于k和剩余字符小于k的情况
	if (len < k || l % (2 * k) == 0 && len - l < k)
		reverse(s, l, len - 1);
	return s;
}

void test1() {
	char s[1000] = { 0 };
	int k = 0;
	while (scanf("%s%d", s, &k) == 2) {
		printf("%s\n", reverseStr(s, k));
	}
}

int main() {
	test1();
	return 0;
}