#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2026.10.21力扣网刷题
//3863. 将一个字符串排序的最小操作次数——资深工程师、字符串、第492场周赛——重点
//给你一个由小写英文字母组成的字符串 s。
//在一次操作中，你可以选择 s 的任意 子字符串（但 不能 是整个字符串），并将其按 非降序字母顺序 进行 排序。
//返回使 s 按 非降序 排列所需的 最小 操作次数。如果无法做到，则返回 - 1。
//示例 1：
//输入： s = "dog"
//输出： 1
//解释：
//将子字符串 "og" 排序为 "go"。
//现在，s = "dgo"，已按升序排列。因此，答案是 1。
//示例 2：
//输入： s = "card"
//输出： 2
//解释：
//将子字符串 "car" 排序为 "acr"，得到 s = "acrd"。
//将子字符串 "rd" 排序为 "dr"，得到 s = "acdr"，已按升序排列。因此，答案是 2。
//示例 3：
//输入： s = "gf"
//输出： - 1
//解释：
//在给定提示下，无法对 s 进行排序。因此，答案是 - 1。
//提示：
//1 <= s.length <= 10^5
//s 仅由小写英文字母组成。


int minOperations(char* s) {
	int len = strlen(s);
	if (len == 2) {
		if (s[0] > s[1]) {
			return -1;
		}
		return 0;
	}
	int hash[26] = { 0 };
	for (int i = 0; i < len; i++) {
		int key = s[i] - 'a';
		hash[key] += 1;
	}
	char* tmp = (char*)calloc(len + 1, sizeof(char));
	assert(tmp);
	for (int i = 0, j = 0; i < 26; i++) {
		while (hash[i]) {
			tmp[j] = i + 'a';
			hash[i] -= 1;
			j += 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] != tmp[i]) {
			ans = 1;
			break;
		}
	}
	if (ans) {
		if (s[0] != tmp[0] && s[len - 1] != tmp[len - 1]) {
			int front = 1, rear = 1;
			for (int i = 0; i < len; i++) {
				if (i >= 0 && i < len - 1 && s[i] == tmp[0]) {
					front = 0;
					break;
				}
				else if (i >= 1 && i < len && s[i] == tmp[len - 1]) {
					rear = 0;
					break;
				}
			}
			ans += front + rear;
		}
	}
	free(tmp);
	return ans;
}