#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.04.30力扣网刷题
//面试题 05.03.翻转数位——位运算、动态规划——简单
//给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。
//示例 1：
//输入 : num = 1775(110111011112)
//输出 : 8
//示例 2：
//输入 : num = 7(01112)
//输出 : 4

int reverseBits(int num) {
	unsigned int tmp = (unsigned)num;
	int maxLen = 0;
	int pre = 0;
	while (tmp) {
		int dp = 0;
		for (int i = tmp % 2; i != 0; i = tmp % 2) {
			dp += 1;
			tmp /= 2;
		}
		if (dp + pre > maxLen) {
			maxLen = dp + pre;
		}
		pre = dp;
		tmp /= 2;
	}
	return maxLen >= 32 ? 32 : maxLen + 1;
}