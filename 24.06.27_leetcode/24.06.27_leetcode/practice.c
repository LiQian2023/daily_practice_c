#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//2024.06.27力扣网刷题
//同构字符串——哈希表、字符串——简单
//给定两个字符串 s 和 t ，判断它们是否是同构的。
//如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
//每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
//示例 1:
//输入：s = "egg", t = "add"
//输出：true
//示例 2：
//输入：s = "foo", t = "bar"
//输出：false
//示例 3：
//输入：s = "paper", t = "title"
//输出：true
//提示：
//1 <= s.length <= 5 * 10^4
//t.length == s.length
//s 和 t 由任意有效的 ASCII 字符组成

void strStruct(char* s,char* ret) {
	char max = ret[0];
	for (int i = 1; s[i]; i++) {
		ret[i] = max + 1;
		max = max + 1;
		for (int j = i - 1; j >= 0; j--) {
			if (s[j] == s[i]) {
				ret[i] = ret[j];
				max -= 1;
				break;
			}
		}
	}
}

bool isIsomorphic(char* s, char* t) {
	char tmp1[50001] = { 0 };
	tmp1[0] = 'a';
	strStruct(s, tmp1);
	char tmp2[50001] = { 0 };
	tmp2[0] = 'a';
	strStruct(t, tmp2);
	return strcmp(tmp1, tmp2) == 0;
}