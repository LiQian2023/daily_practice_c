#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.03力扣网刷题
//796. 旋转字符串——字符串、字符串匹配——简单
//给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。
//s 的 旋转操作 就是将 s 最左边的字符移动到最右边。
//例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
//示例 1:
//输入: s = "abcde", goal = "cdeab"
//输出 : true
//示例 2 :
//输入 : s = "abcde", goal = "abced"
//输出 : false
//提示 :
//1 <= s.length, goal.length <= 100
//s 和 goal 由小写英文字母组成

bool rotateString(char* s, char* goal) {
	int size = strlen(s);
	int size2 = strlen(goal);
	if (size != size2) {
		return false;
	}
	char* tmp = (char*)calloc(2 * size + 1, sizeof(char));
	assert(tmp);
	for (int i = 0; i < size; i++) {
		tmp[i] = s[i];
		tmp[i + size] = s[i];
	}
	bool ans = strstr(tmp, goal);
	free(tmp);
	return ans;
}