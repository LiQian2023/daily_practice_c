#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2025.12.07力扣网刷题
//1523. 在区间范围内统计奇数数目——数学、第31场双周赛——简单
//给你两个非负整数 low 和 high 。请你返回 low 和 high 之间（包括二者）奇数的数目。
//示例 1：
//输入：low = 3, high = 7
//输出：3
//解释：3 到 7 之间奇数数字为[3, 5, 7] 。
//示例 2：
//输入：low = 8, high = 10
//输出：1
//解释：8 到 10 之间奇数数字为[9] 。
//提示：
//0 <= low <= high <= 10 ^ 9

int countOdds(int low, int high) {
	if (high % 2 == 1 || low % 2 == 1) {
		return (high - low) / 2 + 1;
	}
	return (high - low) / 2;
}