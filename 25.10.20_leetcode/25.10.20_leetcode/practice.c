#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.10.20力扣网刷题
//获取生成数组中的最大值——数组、模拟第214场周赛——简单
//给你一个整数 n 。按下述规则生成一个长度为 n + 1 的数组 nums ：
//nums[0] = 0
//nums[1] = 1
//当 2 <= 2 * i <= n 时，nums[2 * i] = nums[i]
//当 2 <= 2 * i + 1 <= n 时，nums[2 * i + 1] = nums[i] + nums[i + 1]
//返回生成数组 nums 中的 最大 值。
//示例 1：
//输入：n = 7
//输出：3
//解释：根据规则：
//nums[0] = 0
//nums[1] = 1
//nums[(1 * 2) = 2] = nums[1] = 1
//nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
//nums[(2 * 2) = 4] = nums[2] = 1
//nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
//nums[(3 * 2) = 6] = nums[3] = 2
//nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
//因此，nums = [0, 1, 1, 2, 1, 3, 2, 3]，最大值 3
//示例 2：
//输入：n = 2
//输出：1
//解释：根据规则，nums[0]、nums[1] 和 nums[2] 之中的最大值是 1
//示例 3：
//输入：n = 3
//输出：2
//解释：根据规则，nums[0]、nums[1]、nums[2] 和 nums[3] 之中的最大值是 2
//提示：
//0 <= n <= 100

int getMaximumGenerated(int n) {
	if (n == 0) {
		return 0;
	}
	int* f = (int*)calloc(n + 1, sizeof(int));
	assert(f);
	f[1] = 1;
	int ans = 1;
	for (int k = 2; k < n + 1; k++) {
		int i = k / 2;
		if (k % 2 == 0) {
			f[k] = f[i];
		}
		else {
			f[k] = f[i] + f[i + 1];
		}
		if (f[k] > ans) {
			ans = f[k];
		}
	}
	free(f);
	return ans;
}