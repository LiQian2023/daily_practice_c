#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2025.07.13力扣网刷题
//分割平衡字符串——贪心、字符串、计数——简单
//平衡字符串 中，'L' 和 'R' 字符的数量是相同的。
//给你一个平衡字符串 s，请你将它分割成尽可能多的子字符串，并满足：
//每个子字符串都是平衡字符串。
//返回可以通过分割得到的平衡字符串的 最大数量 。
//示例 1：
//输入：s = "RLRRLLRLRL"
//输出：4
//解释：s 可以分割为 "RL"、"RRLL"、"RL"、"RL" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
//示例 2：
//输入：s = "RLRRRLLRLL"
//输出：2
//解释：s 可以分割为 "RL"、"RRRLLRLL"，每个子字符串中都包含相同数量的 'L' 和 'R' 。
//注意，s 无法分割为 "RL"、"RR"、"RL"、"LR"、"LL" 因为第 2 个和第 5 个子字符串不是平衡字符串。
//示例 3：
//输入：s = "LLLLRRRR"
//输出：1
//解释：s 只能保持原样 "LLLLRRRR" 。
//提示：
//2 <= s.length <= 1000
//s[i] = 'L' 或 'R'
//s 是一个 平衡 字符串

int balancedStringSplit(char* s) {
	int l = 0, r = 0, ans = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'L') {
			l += 1;
		}
		else {
			r += 1;
		}
		if (l == r) {
			ans += 1;
			l = 0, r = 0;
		}
	}
	return ans;
}