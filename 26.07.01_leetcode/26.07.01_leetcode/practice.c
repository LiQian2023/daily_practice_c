#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
//2026.07.01力扣网刷题
//14. 最长公共前缀——字典树、数组、字符串——简单
//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。
//示例 1：
//输入：strs = ["flower", "flow", "flight"]
//输出："fl"
//示例 2：
//输入：strs = ["dog", "racecar", "car"]
//输出：""
//解释：输入不存在公共前缀。
//提示：
//1 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] 如果非空，则仅由小写英文字母组成

char* longestCommonPrefix(char** strs, int strsSize) {
	int len1 = strlen(strs[0]);
	int len = len1;
	for (int i = 1; i < strsSize; i++) {
		int len2 = strlen(strs[i]);
		int tmp = 0;
		for (int j = 0; j < len1 && j < len2; j++) {
			if (strs[i][j] == strs[0][j]) {
				tmp += 1;
			}
			else {
				break;
			}
		}
		len = tmp < len ? tmp : len;
	}
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	for (int i = 0; i < len; i++) {
		ans[i] = strs[0][i];
	}
	return ans;
}