#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2026.07.19力扣网刷题
//1081. 不同字符的最小子序列——高级专家、栈、贪心、字符串、单调栈、第140场周赛——中等
//返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。
//示例 1：
//输入：s = "bcabc"
//输出："abc"
//示例 2：
//输入：s = "cbacdcbc"
//输出："acdb"
//提示：
//1 <= s.length <= 1000
//s 由小写英文字母组成
//注意：该题与 316 https://leetcode.cn/problems/remove-duplicate-letters/ 相同

char* smallestSubsequence(char* s) {
	int len = strlen(s);
	int last[26] = { 0 };
	for (int i = 0; i < len; i++) {
		last[s[i] - 'a'] = i;
	}
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	int top = -1;
	int hash[26] = { 0 };
	for (int i = 0; i < 26; i++) {
		hash[i] = -1;
	}
	for (int i = 0; s[i]; i++) {
		int key = s[i] - 'a';
		if (hash[key] != -1) {
			continue;
		}
		while (top >= 0 && s[i] < ans[top] && last[ans[top] - 'a'] >= i) {
			hash[ans[top] - 'a'] = -1;
			top -= 1;
		}
		ans[++top] = s[i];
		hash[s[i] - 'a'] = top;
	}
	return ans;
}