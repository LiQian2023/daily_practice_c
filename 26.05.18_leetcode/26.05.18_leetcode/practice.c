#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.05.18力扣网刷题
//3931. 检查相邻数字差——第502场周赛——简单
//给你一个由数字组成的字符串 s。
//如果每一对 相邻 数字之间的 绝对差 都至多为 2，则返回 true；否则返回 false。
//a 和 b 之间的绝对差定义为 abs(a - b)。
//示例 1：
//输入： s = "132"
//输出： true
//解释：
//s[0] 和 s[1] 处数字的绝对差为 abs(1 - 3) = 2。
//s[1] 和 s[2] 处数字的绝对差为 abs(3 - 2) = 1。
//由于两个差值都至多为 2，因此答案为 true。
//示例 2：
//输入： s = "129"
//输出： false
//解释：
//s[0] 和 s[1] 处数字的绝对差为 abs(1 - 2) = 1。
//s[1] 和 s[2] 处数字的绝对差为 abs(2 - 9) = 7，大于 2。
//因此，答案为 false。
//提示：
//2 <= s.length <= 100
//s 仅由数字组成。

bool isAdjacentDiffAtMostTwo(char* s) {
	for (int i = 1; s[i]; i++) {
		if (abs(s[i] - s[i - 1]) > 2) {
			return false;
		}
	}
	return true;
}