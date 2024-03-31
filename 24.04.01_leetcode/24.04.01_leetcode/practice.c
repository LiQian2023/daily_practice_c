#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//24.04.01力扣网刷题
//旋转字符串——字符串、字符串匹配——简单
//给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。
//s 的 旋转操作 就是将 s 最左边的字符移动到最右边。
//例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
//示例 1:
//输入: s = "abcde", goal = "cdeab"
//输出 : true
//示例 2 :
//	输入 : s = "abcde", goal = "abced"
//	输出 : false
//	提示 :
//	1 <= s.length, goal.length <= 100
//	s 和 goal 由小写英文字母组成

bool rotateString(char* s, char* goal) {
	if (strcmp(s, goal) == 0)
		return true;
	int len = strlen(s);
	for (int i = 1; i < len; i++) {
		char tmp = s[0];
		for (int j = 0; j < len - 1; j++) {
			s[j] = s[j + 1];
		}
		s[len - 1] = tmp;
		if (strcmp(s, goal) == 0)
			return true;
	}
	return false;
}

