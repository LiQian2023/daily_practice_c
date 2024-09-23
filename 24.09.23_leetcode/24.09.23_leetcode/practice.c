#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//2024.09.23力扣网刷题
//最佳观光组合——数组、动态规划——中等
//给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
//一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去 它们两者之间的距离。
//返回一对观光景点能取得的最高分。
//示例 1：
//输入：values = [8, 1, 5, 2, 6]
//输出：11
//解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
//示例 2：
//输入：values = [1, 2]
//输出：2
//提示：
//2 <= values.length <= 5 * 10^4
//1 <= values[i] <= 1000


//暴力求解
int maxScoreSightseeingPair(int* values, int valuesSize) {
	int max = values[0] + values[1] + 0 - 1;
	for (int i = 0; i < valuesSize; i++) {
		for (int j = i + 1; j < valuesSize; j++) {
			int a = i - j;
			int b = values[i] + values[j];
			if (a + b > max) {
				max = a + b;
			}
		}
	}
	return max;
}

int maxScoreSightseeingPair(int* values, int valuesSize) {
	int max = values[0] + 0;
	int ans = max;
	for (int i = 1; i < valuesSize; i++) {
		if (max + values[i] - i > ans) {
			ans = max + values[i] - i;
		}
		if (values[i] + i > max) {
			max = values[i] + i;
		}
	}
	return ans;
}