#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
//2026.02.04力扣网刷题
//最长回文子串——双指针、字符串、动态规划——中等
//给你一个字符串 s，找到 s 中最长的回文子串。
//示例 1：
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
//示例 2：
//输入：s = "cbbd"
//输出："bb"
//提示：
//1 <= s.length <= 1000
//s 仅由数字和英文字母组成

// 方法一：动态规划——dp[i]——对应的最长子串
//                    l   
//         "[a , a , c , a ,  b , d , k , a , c , a , a]"
//    枚举： 1 3 5 3 7 1 3 1  3 1 3 1 3 1 3 1 7 1 3 3 1 
//  双指针:       l      r
//   dp_r : 1  0  
//   dp_l :-1  0 -1  1  -1
// 两个数组记录两侧的最长子串

// 分治：维护4个值
// 左侧最大子串
// 右侧最大子串
// 过中点最大子串
// 全局最大子串
// l = 0, r = len - 1, m = (r - l) / 2 + l;
// 长度为2：两元素相邻且相同
// 长度为3：三元素相同，或左右相同
// 长度为4：四元素相同，或左右相同
// 长度为5：五元素相同，或左右相同
// reverse?
// split(1)
// abb
// [ a , b , b ]
//   3 

// 回文串性质：
// 元素对称
// 通过双指针找相同元素

// 1.拆分
// 2. 遍历
// 3. 重组

void Print_int(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Print_str(char* str, int len) {
	for (int i = 0; i < len; i++) {
		printf("%c ", str[i]);
	}
	printf("\n");
}

void split(char* s, char* tmp, int len) {
	for (int i = 0, j = 0; i < len; i++, j++) {
		tmp[j] = s[i];
		if (i < len - 1) {
			tmp[++j] = ',';
		}
	}
}

char* longestPalindrome(char* s) {
	int len = strlen(s);
	int size = 2 * len - 1;
	char* tmp = (char*)calloc(size, sizeof(char));
	assert(tmp);
	// 拆分
	split(s, tmp, len);
	Print_str(tmp, size);
	int* max_len = (int*)calloc(size, sizeof(int));
	assert(max_len);
	// 记录中间最长子串
	for (int i = 1; i < size - 1; i++) {
		int l = i, r = i;
		while (l >= 0 && r < size && tmp[l] == tmp[r]) {
			l--, r++;
		}
		max_len[i] = (r - l - 1) / 2;
	}
	Print_int(max_len, size);
	// 找中间最长
	int max = max_len[0], max_i = 0;
	for (int i = 1; i < size; i++) {
		if (max_len[i] > max) {
			max = max_len[i];
			max_i = i;
		}
	}
	// 找两边最长
	int l = 1, r = len - 2;
	for (; l < len && r >= 0;) {
		if (s[l] == s[0]) {
			l += 1;
		}
		if (s[r] == s[len - 1]) {
			r -= 1;
		}
		if ((l < len && s[l] != s[0]) && (r >= 0 && s[r] != s[len - 1])) {
			break;
		}
	}
	r += 1;
	// 获取答案
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	int i = 0;
	int left = max_i -  max, right = max_i + max;
	while (left <= right) {
		printf("tmp[%d] = %c\n", left, tmp[left]);
		if (tmp[left] != ',') {
			ans[i++] = tmp[left];
		}
		left++;
	}
	if (i < len - r) {
		for (i = 0; i < len; i++, r++) {
			ans[i] = s[r];
		}
	}
	if (i < l) {
		for (i = 0; i < l; i++) {
			ans[i] = s[i];
		}
	}
	free(tmp);
	free(max_len);
	return ans;
}

