#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
//2026.07.05力扣网刷题
//3. 无重复字符的最长子串——中级工程师、哈希表、字符串、滑动窗口——中等
//给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
//示例 1:
//输入: s = "abcabcbb"
//输出 : 3
//解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
//示例 2 :
//输入 : s = "bbbbb"
//输出 : 1
//解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//示例 3 :
//输入 : s = "pwwkew"
//输出 : 3
//解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//提示：
//0 <= s.length <= 5 * 10^4
//s 由英文字母、数字、符号和空格组成

int lengthOfLongestSubstring(char* s) {
	int hash[128] = { 0 };
	int ans = 0;
	for (int l = 0, r = 0; s[r]; r++) {
		hash[s[r]] += 1;
		while (hash[s[r]] > 1) {
			hash[s[l]] -= 1;
			l += 1;
		}
		ans = (int)fmax((double)ans, (double)(r - l + 1));
	}
	return ans;
}