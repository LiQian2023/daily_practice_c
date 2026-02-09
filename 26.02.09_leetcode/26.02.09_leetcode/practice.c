#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

//2026.02.09力扣网刷题
//3794. 反转字符串前缀——中级工程师、双指针、字符串、第173场双周赛——简单
//给你一个字符串 s 和一个整数 k。
//反转 s 的前 k 个字符，并返回结果字符串。
//示例 1:
//输入: s = "abcd", k = 2
//输出 : "bacd"
//解释 :
//前 k = 2 个字符 "ab" 反转为 "ba"。最终得到的结果字符串为 "bacd"。
//示例 2 :
//输入 : s = "xyz", k = 3
//输出 : "zyx"
//解释 :
//前 k = 3 个字符 "xyz" 反转为 "zyx"。最终得到的结果字符串为 "zyx"。
//示例 3 :
//输入 : s = "hey", k = 1
//输出 : "hey"
//解释 :
//前 k = 1 个字符 "h" 在反转后保持不变。最终得到的结果字符串为 "hey"。
//提示:
//1 <= s.length <= 100
//s 仅由小写英文字母组成。
//1 <= k <= s.length

void Reverse(char* s, int len) {
	int l = 0, r = len - 1;
	while (l < r) {
		char tmp = s[l];
		s[l] = s[r];
		s[r] = tmp;
		l += 1, r -= 1;
	}
}

char* reversePrefix(char* s, int k) {
	Reverse(s, k);
	return s;
}