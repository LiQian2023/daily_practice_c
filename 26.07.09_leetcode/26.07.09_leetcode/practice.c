#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2026.07.09力扣网刷题
//3978. 唯一中间元素——中级工程师、第186场双周赛——简单
//给你一个长度为奇数 n 的整数数组 nums 。
//如果 nums 的下标中间元素在数组中 恰好 出现一次，返回 true 。否则返回 false 。
//示例 1：
//输入： nums = [1, 2, 3]
//输出： true
//解释：
//nums 的中间元素是 2 ，它恰好出现一次。
//因此，答案为 true 。
//示例 2：
//输入： nums = [1, 2, 2]
//输出： false
//解释：
//nums 的中间元素是 2 ，它出现了两次。
//因此，答案为 false 。
//提示：
//1 <= n == nums.length <= 100
//n 是奇数。
//1 <= nums[i] <= 100

bool isMiddleElementUnique(int* nums, int numsSize) {
	int midIndex = numsSize / 2;
	for (int i = 0; i < numsSize; i++) {
		if (i != midIndex && nums[i] == nums[midIndex]) {
			return false;
		}
	}
	return true;
}