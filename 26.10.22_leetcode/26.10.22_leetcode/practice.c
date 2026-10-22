#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.10.22力扣网刷题
//3942. 排序排列的最少操作数——资深工程师、数组、第503场周赛——中等
//给你一个长度为 n 的整数数组 nums，其中 nums 是区间[0..n - 1] 中所有数字的一个排列。
//你 只能 执行以下操作：
//反转 整个数组。
//左旋一位：将第一个元素移动到数组末尾，其余元素整体向左移动一位。
//返回将数组按 递增 顺序排序所需的 最少 操作次数。如果仅使用给定操作无法将数组排序，则返回 - 1。
//排列 是数组中所有元素的一种重新排列。
//示例 1：
//输入： nums = [0, 2, 1]
//输出： 2
//解释：
//左旋一位：[2, 1, 0]
//反转数组：[0, 1, 2]
//数组在 2 次操作后变为有序，这是最少操作次数。
//示例 2：
//输入： nums = [1, 0, 2]
//输出： 2
//解释：
//反转数组：[2, 0, 1]
//左旋一位：[0, 1, 2]
//数组在 2 次操作后变为有序，这是最少操作次数。
//示例 3：
//输入： nums = [2, 0, 1, 3]
//输出： - 1
//解释：
//无法将该数组变为[0, 1, 2, 3]。因此答案为 - 1。
//提示：
//1 <= n == nums.length <= 10^5
//0 <= nums[i] <= n - 1
//nums 是从 0 到 n - 1 的整数排列。

int minOperations1(int* nums, int numsSize) {
	int size = 2 * numsSize;
	int* tmp = (int*)calloc(size, sizeof(int));
	assert(tmp);
	int mi = 0, ma = 0;
	for (int i = 0; i < numsSize; i++) {
		tmp[i] = nums[i];
		tmp[i + numsSize] = nums[i];
		if (nums[i] > nums[ma]) {
			ma = i;
		}
		else if (nums[i] < nums[mi]) {
			mi = i;
		}
	}
	int increase = 1, decrease = 1;
	for (int i = ma; i < ma + numsSize - 1; i++) {
		if (tmp[i] < tmp[i + 1]) {
			decrease = 0;
			break;
		}
	}
	for (int i = mi; i < mi + numsSize - 1; i++) {
		if (tmp[i] > tmp[i + 1]) {
			increase = 0;
			break;
		}
	}
	int ans = -1;
	if (increase) {
		int op1 = mi, op2 = numsSize - mi + 2;
		ans = op1 < op2 ? op1 : op2;
	}
	if (decrease) {
		int op1 = ma + 1, op2 = numsSize - ma + 1;
		if (ans == -1) {
			ans = op1 < op2 ? op1 : op2;
		}
		else {
			ans = ans < op1 ? ans : op1;
			ans = ans < op2 ? ans : op2;
		}
	}
	free(tmp);
	return ans;
}

int check(int* nums, int len, int begin, int flag) {
	for (int i = begin; 1; i = (i + 1) % len) {
		if ((i + 1) % len == begin) {
			break;
		}
		if ((nums[i] - nums[(i + 1) % len]) * flag > 0) {
			return 0;
		}
	}
	return 1;
}
int minOperations(int* nums, int numsSize) {
	int mi = 0, ma = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > nums[ma]) {
			ma = i;
		}
		else if (nums[i] < nums[mi]) {
			mi = i;
		}
	}
	int increase = check(nums, numsSize, mi, 1),
		decrease = check(nums, numsSize, ma, -1);
	int ans = -1;
	if (increase) {
		int op1 = mi, op2 = numsSize - mi + 2;
		ans = op1 < op2 ? op1 : op2;
	}
	if (decrease) {
		int op1 = ma + 1, op2 = numsSize - ma + 1;
		if (ans == -1) {
			ans = op1 < op2 ? op1 : op2;
		}
		else {
			ans = ans < op1 ? ans : op1;
			ans = ans < op2 ? ans : op2;
		}
	}
	return ans;
}