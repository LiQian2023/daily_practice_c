#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.01.18力扣网刷题
//LCR 006. 两数之和 II - 输入有序数组——数组、双指针、二分查找——简单
//给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
//函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 0 开始计数 ，所以答案数组应当满足 0 <= answer[0] < answer[1] < numbers.length 。
//假设数组中存在且只存在一对符合条件的数字，同时一个数字不能使用两次。
//示例 1：
//输入：numbers = [1, 2, 4, 6, 10], target = 8
//输出：[1, 3]
//解释：2 与 6 之和等于目标数 8 。因此 index1 = 1, index2 = 3 。
//示例 2：
//输入：numbers = [2, 3, 4], target = 6
//输出：[0, 2]
//示例 3：
//输入：numbers = [-1, 0], target = -1
//输出：[0, 1]
//提示：
//2 <= numbers.length <= 3 * 10^4
//- 1000 <= numbers[i] <= 1000
//numbers 按 非递减顺序 排列
//- 1000 <= target <= 1000
//仅存在一个有效答案
//注意：本题与主站 167 题相似（下标起点不同）：https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
int Bi_Search(int* numbers, int len, int key) {
	int l = 0, r = len - 1;
	while (l <= r) {
		int m = (r - l) / 2 + l;
		if (numbers[m] > key) {
			r = m - 1;
		}
		else if (numbers[m] < key) {
			l = m - 1;
		}
		else {
			return m;
		}
	}
	return -1;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*returnSize = 2;
	for (int i = numbers[0]; i <= target / 2; i++) {
		int a = Bi_Search(numbers, numbersSize, i);
		if (a != -1) {
			int b = Bi_Search(numbers + a + 1, numbersSize - a - 1, target - i);
			if (b != -1) {
				ans[0] = a;
				ans[1] = b + a + 1;
				break;
			}
			else {
				b = Bi_Search(numbers, a, target - i);
				if (b != -1) {
					ans[0] = b;
					ans[1] = a;
					break;
				}
			}
		}
	}
	return ans;
}