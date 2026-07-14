#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

//2026.07.14力扣网刷题
//6. Z 字形变换——字符串——中等
//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//P   A   H   N
//A P L S I I G
//Y   I   R
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//请你实现这个将字符串进行指定行数变换的函数：
//string convert(string s, int numRows);
//示例 1：
//输入：s = "PAYPALISHIRING", numRows = 3
//输出："PAHNAPLSIIGYIR"
//示例 2：
//输入：s = "PAYPALISHIRING", numRows = 4
//输出："PINALSIGYAHRPI"
//解释：
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
//示例 3：
//输入：s = "A", numRows = 1
//输出："A"
//提示：
//1 <= s.length <= 1000
//s 由英文字母（小写和大写）、',' 和 '.' 组成
//1 <= numRows <= 1000

char* convert(char* s, int numRows) {
	if (numRows == 1) {
		return s;
	}
	int length = strlen(s);
	char* ans = (char*)calloc(length + 1, sizeof(char));
	assert(ans);
	int flag = 0;
	for (int row = 1, i = 0, len = 0; len < length;) {
		int down = numRows - row;
		if (row == 1 || row == numRows) {
			down = numRows - 1;
		}
		else {
			if (flag) {
				down = row - 1;
			}
		}
		flag = (flag + 1) % 2;
		int up = down;
		ans[len] = s[i];
		len += 1;
		i += up + down;
		if (i >= length) {
			i = row;
			row += 1;
		}
	}
	return ans;
}