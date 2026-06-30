#include <stdio.h>
#include <string.h>
#include <ctype.h>

//2026.06.30力扣网刷题
//1358. 包含所有三种字符的子字符串数目——资深工程师、哈希表、字符串、滑动串口、第20场双周赛——中等
//给你一个字符串 s ，它只包含三种字符 a, b 和 c 。
//请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。
//示例 1：
//输入：s = "abcabc"
//输出：10
//解释：包含 a，b 和 c 各至少一次的子字符串为 "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" 和 "abc" (相同字符串算多次)。
//示例 2：
//输入：s = "aaacb"
//输出：3
//解释：包含 a，b 和 c 各至少一次的子字符串为 "aaacb", "aacb" 和 "acb" 。
//示例 3：
//输入：s = "abc"
//输出：1
//提示：
//3 <= s.length <= 5 x 10 ^ 4
//s 只包含字符 a，b 和 c 。

int numberOfSubstrings(char* s) {
	int a = 0, b = 0, c = 0, n = strlen(s), ans = 0;
	for (int l = 0, r = 0; r < n; r++) {
		switch (s[r]) {
			case 'a':
				a += 1;
				break;
			case 'b':
				b += 1;
				break;
			default:
				c += 1;
				break;
		}
		for (; l <= r - 2 && a > 0 && b > 0 && c > 0; l++) {
			ans += n - r;
			switch (s[l]) {
				case 'a':
					a -= 1;
					break;
				case 'b':
					b -= 1;
					break;
				default:
					c -= 1;
					break;
			}
		}
	}
	return ans;
}