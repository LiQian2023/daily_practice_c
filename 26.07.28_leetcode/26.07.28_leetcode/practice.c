#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.07.28力扣网刷题
//66. 加一——数组、数学——简单
//给定一个表示 大整数 的整数数组 digits，其中 digits[i] 是整数的第 i 位数字。这些数字按从左到右，从最高位到最低位排列。这个大整数不包含任何前导 0。
//将大整数加 1，并返回结果的数字数组。
//示例 1：
//输入：digits = [1, 2, 3]
//输出：[1, 2, 4]
//解释：输入数组表示数字 123。
//加 1 后得到 123 + 1 = 124。
//因此，结果应该是[1, 2, 4]。
//示例 2：
//输入：digits = [4, 3, 2, 1]
//输出：[4, 3, 2, 2]
//解释：输入数组表示数字 4321。
//加 1 后得到 4321 + 1 = 4322。
//因此，结果应该是[4, 3, 2, 2]。
//示例 3：
//输入：digits = [9]
//输出：[1, 0]
//解释：输入数组表示数字 9。
//加 1 得到了 9 + 1 = 10。
//因此，结果应该是[1, 0]。
//提示：
//1 <= digits.length <= 100
//0 <= digits[i] <= 9
//digits 不包含任何前导 0。

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int* ans = (int*)calloc(digitsSize + 1, sizeof(int));
	assert(ans);
	int i = 0;
	for (int j = digitsSize - 1; j >= 0; j--, i++) {
		if (i == 0) {
			ans[i] = digits[j] + 1;
		}
		else {
			int a = ans[i - 1] / 10, b = ans[i - 1] % 10;
			ans[i] = digits[j] + a;
			ans[i - 1] = b;
		}
	}
	if (ans[i - 1] >= 10) {
		ans[i] = ans[i - 1] / 10;
		ans[i - 1] %= 10;
		i += 1;
	}
	*returnSize = i;
	for (int l = 0, r = i - 1; l < r; l++, r--) {
		int tmp = ans[l];
		ans[l] = ans[r];
		ans[r] = tmp;
	}
	return ans;
}