#include <stdio.h>
#include <string.h>

//2026.10.20力扣网刷题
//4043. 恰好有 K 对相等相邻字符的循环移位数量——中级工程师、字符串、枚举、滑动窗口、第518场周赛——简单
//给你一个长度为 n 的字符串 s 和一个整数 k。
//s 的一次 循环移位 可以通过以下方式得到：选择 s 的一个长度在 0 到 n - 1（包含两端）之间的 前缀 ，并将其移动到字符串末尾，同时保持所有字符的相对顺序不变。
//对于 s 的 每一种 循环移位，定义其 得分 为满足以下条件的下标 i 的数量：0 <= i < n - 1，且位置 i 和 i + 1 处的字符相同。
//返回得分等于 k 的循环移位数量。
//字符串的 前缀 是指从字符串开头开始，并延伸到字符串中某个位置的子串。
//子串 是字符串中一段连续的字符序列，可以为空。
//示例 1：
//输入： s = "aab", k = 1
//输出： 2
//解释：
//s 的所有循环移位为：
//"aab"：位置 0 和 1 处的字符相同，因此 score = 1。
//"aba"：不存在两个相邻且相同的字符，因此 score = 0。
//"baa"：位置 1 和 2 处的字符相同，因此 score = 1。
//共有 2 种 s 的循环移位，其 score 等于 k，因此答案为 2。
//示例 2：
//输入： s = "abca", k = 0
//输出： 1
//解释：
//s 的所有循环移位为：
//"abca"：不存在两个相邻且相同的字符，因此 score = 0。
//"bcaa"：位置 2 和 3 处的字符相同，因此 score = 1。
//"caab"：位置 1 和 2 处的字符相同，因此 score = 1。
//"aabc"：位置 0 和 1 处的字符相同，因此 score = 1。
//只有 1 种 s 的循环移位，其 score 等于 k，因此答案为 1。
//提示：
//2 <= n == s.length <= 100
//s 仅由小写英文字母组成。
//0 <= k <= n - 1

int countRotations(char* s, int k) {
	int ans = 0, len = strlen(s);
	int count = 0;
	for (int i = 1; s[i];i++) {
		if (s[i] == s[i - 1]) {
			count += 1;
		}
	}
	if (count <= k + 1 && count >= k - 1) {
		int score = count;
		for (int i = 0; s[i]; i++) {
			if (score == k) {
				ans += 1;
			}
			int pre = (i + len - 1) % len, rear = (i + 1) % len;
			int next_l = 0, next_r = 0;
			if (s[i] == s[pre]) {
				next_r = 1;
			}
			if (s[i] == s[rear]) {
				next_l = -1;
			}
			score = score + next_l + next_r;
		}
	}
	return ans;
}