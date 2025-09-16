#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//2025.09.16力扣网刷题
//面试题 01.09.字符串轮转——字符串、字符串匹配——简单
//字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
//示例 1：
//输入：s1 = "waterbottle", s2 = "erbottlewat"
//输出：True
//示例 2：
//输入：s1 = "aa", s2 = "aba"
//输出：False
//提示：
//字符串长度在[0, 100000]范围内。
//说明 :
//你能只调用一次检查子串的方法吗？

int Index(char* s, char* sub, int len) {
	for (int i = 0, j = 0, z = 0; i < len * 2; i++) {
		j = i;
		while (j < len * 2 && z < len && s[j] == sub[z]) {
			j += 1;
			z += 1;
		}
		if (z == len) {
			return i;
		}
		z = 0;
	}
	return -1;
}
bool isFlipedString(char* s1, char* s2) {
	int len = strlen(s1);
	if (len == 0) {
		return true;
	}
	char* s = (char*)calloc(len * 2 + 1, sizeof(char));
	assert(s);
	for (int i = 0, j = len; i < len; i++, j++) {
		s[i] = s[j] = s1[i];
	}
	int ans = Index(s, s2, len);
	free(s);
	s = NULL;
	return ans != -1;
}