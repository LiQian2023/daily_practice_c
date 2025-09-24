#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2025.09.24力扣网刷题
//1比特与 2 比特字符——数组——简单
//有两种特殊字符：
//第一种字符可以用一比特 0 表示
//第二种字符可以用两比特（10 或 11）表示
//给你一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一个一比特字符，则返回 true 。
//示例 1:
//输入: bits = [1, 0, 0]
//输出 : true
//解释 : 唯一的解码方式是将其解析为一个两比特字符和一个一比特字符。
//所以最后一个字符是一比特字符。
//示例 2 :
//输入：bits = [1, 1, 1, 0]
//输出：false
//解释：唯一的解码方式是将其解析为两比特字符和两比特字符。
//所以最后一个字符不是一比特字符。
//提示 :
//1 <= bits.length <= 1000
//bits[i] 为 0 或 1

bool isOneBitCharacter(int* bits, int bitsSize) {
	if (bitsSize == 1) {
		return true;
	}
	int end = 0;
	for (int i = 0; i < bitsSize - 1; i++) {
		if (bits[i] == 1) {
			i += 1;
		}
		end = i;
	}
	return end == bitsSize - 2;
}