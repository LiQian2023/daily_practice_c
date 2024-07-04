#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//2024.07.04力扣网刷题
//验证回文串 II——贪心、双指针、字符串——简单
//给你一个字符串 s，最多 可以从中删除一个字符。
//请你判断 s 是否能成为回文字符串：如果能，返回 true ；否则，返回 false 。
//示例 1：
//输入：s = "aba"
//输出：true
//示例 2：
//输入：s = "abca"
//输出：true
//解释：你可以删除字符 'c' 。
//示例 3：
//输入：s = "abc"
//输出：false
//提示：
//1 <= s.length <= 10^5
//s 由小写英文字母组成

bool validPalindrome(char* s) {
	int len = strlen(s);
	int one = 1;
	int l = 0, r = len - 1;
	//判断原字符串是否回文字符串
	while (l < r) {
		if (s[l] != s[r]) {
			one--;
			break;
		}
		l++, r--;
	}
	if (one)
		return true;
	int flag_l = 1, flag_r = 1;
	//删除左侧字符后继续判断
	for (int i = l + 1, j = r; i < j; i++, j--) {
		if (s[i] != s[j]) {
			flag_l--;
			break;
		}
	}
	//删除右侧字符后继续判断
	for (int i = l, j = r - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			flag_r--;
			break;
		}
	}
	return flag_l | flag_r;
}

void test() {
	char s[100] = { 0 };
	while (scanf("%s", s) == 1) {
		printf("%d\n", validPalindrome(s));
	}
}

int main() {
	test();
	return 0;
}