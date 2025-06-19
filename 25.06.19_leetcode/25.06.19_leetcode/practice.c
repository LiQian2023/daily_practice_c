#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//2025.06.19力扣网刷题
//给小朋友们分糖果 I——数学、组合数学、枚举——简单
//给你两个正整数 n 和 limit 。
//请你将 n 颗糖果分给 3 位小朋友，确保没有任何小朋友得到超过 limit 颗糖果，请你返回满足此条件下的 总方案数 。
//示例 1：
//输入：n = 5, limit = 2
//输出：3
//解释：总共有 3 种方法分配 5 颗糖果，且每位小朋友的糖果数不超过 2 ：(1, 2, 2) ，(2, 1, 2) 和(2, 2, 1) 。
//示例 2：
//输入：n = 3, limit = 3
//输出：10
//解释：总共有 10 种方法分配 3 颗糖果，且每位小朋友的糖果数不超过 3 ：
//(0, 0, 3) ，(0, 1, 2) ，(0, 2, 1) ，(0, 3, 0) ，(1, 0, 2) ，(1, 1, 1) ，(1, 2, 0) ，(2, 0, 1) ，(2, 1, 0) 和(3, 0, 0) 。
//提示：
//1 <= n <= 50
//1 <= limit <= 50

int distributeCandies1(int n, int limit) {
	int ans = 0;
	for (int i = 0; i <= limit; i++) {
		for (int j = 0; j <= limit; j++) {
			for (int z = 0; z <= limit; z++) {
				if (i + j + z == n) {
					ans += 1;
					break;
				}
			}
		}
	}
	return ans;
}

int distributeCandies2(int n, int limit) {
	int ans = 0;
	for (int i = 0; i <= limit; i++) {
		if (i <= n) {
			for (int j = 0; j <= limit; j++) {
				if (i + j <= n) {
					for (int z = 0; z <= limit; z++) {
						if (i + j + z == n) {
							ans += 1;
							break;
						}
					}
				}
			}
		}
	}
	return ans;
}
