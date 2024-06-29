#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//2024.06.30力扣网刷题
//最长回文串——贪心、哈希表、字符串——简单
//给定一个包含大写字母和小写字母的字符串 s ，返回通过这些字母构造成的 最长的 回文串的长度。
//在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
//示例 1:
//输入:s = "abccccdd"
//输出 : 7
//解释 :
//	我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
//	示例 2 :
//	输入 : s = "a"
//	输出 : 1
//	解释：可以构造的最长回文串是"a"，它的长度是 1。
//	提示 :
//1 <= s.length <= 2000
//s 只由小写 和 / 或 大写英文字母组成

int longestPalindrome1(char* s) {
	int len = strlen(s);
	if (len == 1)
		return 1;
	int one = 0;
	int ch[52] = { 0 };
	for (int i = 0; i < len; i++) {
		int k = s[i] - 'A';
		if (k >= 32)
			k = k + 'A' - 'a' + 26;
		ch[k]++;
	}
	for (int i = 0; i < 52; i++) {
		if (ch[i] % 2 == 1)
			one++;
	}
	if (one == 0 || one == 1)
		return len;
	return len - one + 1;
}

int longestPalindrome(char* s) {
	int len = strlen(s);
	if (len == 1)
		return 1;
	int one = 0;
//	char ch[52] = { 0 };// 数组类型错误，数据存储超上限了
	int ch[52] = { 0 };// 改为int就没问题了
	for (int i = 0; i < len; i++) {
		int k = s[i] - 'A';
		if (k >= 32)
			k = k + 'A' - 'a' + 26;;
		ch[k]++;
		if (ch[k] % 2 == 1)
			one++;
		else
			one--;
	}
	if (one == 0 || one == 1)
		return len;
	return len - one + 1;
}
void test() {
	char str[2000] = { 0 };
	while (scanf("%s", str) == 1)
		printf("%d\n", longestPalindrome(str));
}

int main() {
	test();
	return 0;
}