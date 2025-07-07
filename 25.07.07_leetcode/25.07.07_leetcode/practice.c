#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2025.07.07力扣网刷题
//删除字符串中的所有相邻重复项——栈、字符串——简单
//给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//在 s 上反复执行重复项删除操作，直到无法继续删除。
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
//示例：
//输入："abbaca"
//输出："ca"
//解释：
//例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。
//之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
//提示：
//1 <= s.length <= 10^5
//s 仅由小写英文字母组成。

char* removeDuplicates(char* s) {
	int len = strlen(s);
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	for (int i = 0, j = 0; j < len; j++) {
		ans[i] = s[j];
		if (i == 0 || ans[i] != ans[i - 1]) {
			i += 1;
		}
		else {
			ans[i] = 0;
			ans[i - 1] = 0;
			i -= 1;
		}
	}
	return ans;
}