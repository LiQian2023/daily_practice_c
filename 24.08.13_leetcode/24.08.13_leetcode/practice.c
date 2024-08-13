#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
//2024.08.13力扣网刷题
//特殊数组 I——数组、简单
//如果数组的每一对相邻元素都是两个奇偶性不同的数字，则该数组被认为是一个 特殊数组 。
//Aging 有一个整数数组 nums。如果 nums 是一个 特殊数组 ，返回 true，否则返回 false。
//示例 1：
//输入：nums = [1]
//输出：true
//解释：
//只有一个元素，所以答案为 true。
//示例 2：
//输入：nums = [2, 1, 4]
//输出：true
//解释：
//只有两对相邻元素：(2, 1) 和(1, 4)，它们都包含了奇偶性不同的数字，因此答案为 true。
//示例 3：
//输入：nums = [4, 3, 1, 6]
//输出：false
//解释：
//nums[1] 和 nums[2] 都是奇数。因此答案为 false。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

bool isArraySpecial(int* nums, int numsSize) {
	bool flag = true;
	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i] % 2 == 0 && nums[i + 1] % 2 == 0 || nums[i] % 2 && nums[i + 1] % 2) {
			flag = false;
			break;
		}
	}
	return flag;
}



