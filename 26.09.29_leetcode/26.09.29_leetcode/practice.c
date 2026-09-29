#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2026.09.29力扣网刷题
//93. 复原 IP 地址——字符串、回溯——中等
//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
//给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
//示例 1：
//输入：s = "25525511135"
//输出：["255.255.11.135", "255.255.111.35"]
//示例 2：
//输入：s = "0000"
//输出：["0.0.0.0"]
//示例 3：
//输入：s = "101023"
//输出：["1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"]
//提示：
//1 <= s.length <= 20
//s 仅由数字组成

 void DFS(char* s, int len, char* stack, int top, int start, int  n, char** ans, int* row) {
	if (len - start > n * 3 || len - start < n) {
		return;
	}
	if (n == 0) {
		if (top == len + 3) {
			ans[*row] = (char*)calloc(top + 1, sizeof(char));
			if (!ans[*row]) {
				perror("calloc");
				return;
			}
			memcpy(ans[*row], stack, top * sizeof(char));
			*row += 1;
		}
		return;
	}
	if (n != 4) {
		stack[top++] = '.';
	}
	int sum = 0;
	for (int i = start; i < start + 3 && i < len; i++) {
		if (i == start && s[i] == '0') {
			stack[top++] = '0';
			DFS(s, len, stack, top, i + 1, n - 1, ans, row);
			break;
		}
		else {
			sum *= 10;
			sum += s[i] - '0';
			if (sum > 255) {
				break;
			}
			stack[top++] = s[i];
			DFS(s, len, stack, top, i + 1, n - 1, ans, row);
		}
	}
}

char** restoreIpAddresses(char* s, int* returnSize) {
	*returnSize = 0;
	int len = strlen(s);
	if (len > 12 || len < 4) {
		return NULL;
	}
	char* stack = (char*)calloc(len + 4, sizeof(char));
	assert(stack);
	char** ans = (char**)calloc(19, sizeof(char*));
	assert(ans);
	DFS(s, len, stack, 0, 0, 4, ans, returnSize);
	free(stack);
	return ans;
}