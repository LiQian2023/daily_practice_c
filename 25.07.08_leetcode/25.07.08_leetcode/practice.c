#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2025.07.08力扣网刷题
//增减字符串匹配——贪心、数组、双指针、字符串——简单
//由范围[0, n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中 :
//如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I'
//如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D'
//给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。
//示例 1：
//输入：s = "IDID"
//输出：[0, 4, 1, 3, 2]
//示例 2：
//输入：s = "III"
//输出：[0, 1, 2, 3]
//示例 3：
//输入：s = "DDI"
//输出：[3, 2, 0, 1]
//提示：
//1 <= s.length <= 10^5
//s 只包含字符 "I" 或 "D"

int* diStringMatch(char* s, int* returnSize) {
	int len = strlen(s);
	*returnSize = len + 1;
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	int left = 0, right = len;
	for (int i = 0, j = 0; s[i]; i += 1, j += 1) {
		if (s[i] == 'D') {
			ans[j] = right;
			right -= 1;
		}
		else {
			ans[j] = left;
			left += 1;
		}
	}
	if (s[len - 1] == 'D') {
		ans[len] = right;
	}
	else {
		ans[len] = left;
	}
	return ans;
}