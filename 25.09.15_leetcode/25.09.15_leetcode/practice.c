#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2025.09.15力扣网刷题
//面试题 01.06.字符串压缩——字符串、双指针——简单
//字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
//比如，字符串aabcccccaaa会变为a2b1c5a3。
//若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。
//示例 1：
//输入："aabcccccaaa"
//输出："a2b1c5a3"
//示例 2：
//输入："abbccd"
//输出："abbccd"
//解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
//提示：
//字符串长度在[0, 50000] 范围内。

char* compressString(char* S) {
	int len = strlen(S);
	char* ans = (char*)calloc(len + 2, sizeof(char));
	assert(ans);
	int size = 0;
	for (int l = 0, r = 0; r <= len; r++) {
		ans[size] = S[l];
		size += 1;
		while (r < len && S[r] == S[l]) {
			r += 1;
		}
		int num = r - l;
		int n = 0;
		for (int a = num; a; a /= 10) {
			n += 1;
		}
		for (n; n; n -= 1) {
			ans[size] = num / (int)pow(10, n - 1) + '0';
			num %= (int)pow(10, n - 1);
			size += 1;
			if (size >= len) {
				return S;
			}
		}
		l = r;
	}
	return ans;
}