#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//2024.10.23力扣网刷题
//构成整天的下标对数目 II——数组、哈希、计数——中等
//给你一个整数数组 hours，表示以 小时 为单位的时间，返回一个整数，表示满足 i < j 且 hours[i] + hours[j] 构成 整天 的下标对 i, j 的数目。
//整天 定义为时间持续时间是 24 小时的 整数倍 。
//例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。
//示例 1：
//输入： hours = [12, 12, 30, 24, 24]
//输出： 2
//解释：
//构成整天的下标对分别是(0, 1) 和(3, 4)。
//示例 2：
//输入： hours = [72, 48, 24, 3]
//输出： 3
//解释：
//构成整天的下标对分别是(0, 1)、(0, 2) 和(1, 2)。
//提示：
//1 <= hours.length <= 5 * 10^5
//1 <= hours[i] <= 10^9


long long countCompleteDayPairs(int* hours, int hoursSize) {
	int nums[24] = { 0 };
	for (int i = 0; i < hoursSize; i++) {
		int key = hours[i] % 24;
		nums[key] += 1;
	}
	long long ans = 0;
	for (int i = 0; i < 13; i++) {
		if (i == 0 || i == 12) {
			ans += nums[i] * (nums[i] - 1) / 2;
		}
		else {
			ans += nums[i] * nums[24 - i];
		}
	}
	return ans;
}