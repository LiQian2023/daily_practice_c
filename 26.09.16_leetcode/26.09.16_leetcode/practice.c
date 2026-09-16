#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.09.16力扣网刷题
//4048. 统计等间距出现整数数目 I——中级工程师、第191场双周赛——简单
//给你一个整数数组 nums。
//如果一个整数 x 满足以下条件，则被称为 特别 的：
//x 在 nums 中 恰好出现三次。
//x 的 所有 三次出现，在 nums 中都是 等间隔 的。换句话说，如果 x 的所有出现位置的下标为 i1 < i2 < i3，那么 i2 - i1 = i3 - i2。
//返回 nums 中 不同 特别整数的数量。
//示例 1:
//输入: nums = [1, 8, 1, 5, 1, 5, 8, 5]
//输出 : 2
//解释 :
//1 是特别的，因为它恰好出现三次，且出现的等间隔下标为 0、2 和 4。
//5 是特别的，因为它恰好出现三次，且出现的等间隔下标为 3、5 和 7。
//8 不是特别的，因为它只出现了两次。
//因此，答案是 2。
//示例 2:
//输入: nums = [8, 8, 8, 8]
//输出 : 0
//解释 :
//8 不是特别的，因为它出现的次数不是恰好三次。因此，答案是 0。
//示例 3 :
//输入 : nums = [8, 6, 6, 8, 8]
//输出 : 0
//解释 :
//8 出现的下标为 0、3 和 4，这些下标不是等间隔的。6 只出现了两次。因此，没有整数是特别的。
//提示:
//3 <= nums.length <= 100
//1 <= nums[i] <= 100

int countSpecialIntegers(int* nums, int numsSize) {
	int ans = 0;
	int hash[101] = { 0 };
	int count[101] = { 0 };
	int max = nums[0], min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		count[nums[i]] += 1;
	}
	for (int i = 0; i < numsSize; i++) {
		for (int j = 1; i + j + j < numsSize; j++) {
			int a = nums[i], b = nums[i + j], c = nums[i + j + j];
			if (a == b && b == c) {
				hash[a] += 1;
			}
			if (a > max) {
				max = a;
			}
			else if (a < min) {
				min = a;
			}
		}
	}
	for (int i = min; i <= max; i++) {
		if (hash[i] == 1 && count[i] == 3) {
			ans += 1;
		}
	}
	return ans;
}

int countSpecialIntegers(int* nums, int numsSize) {
	int** hash = (int**)calloc(101, sizeof(int*));
	assert(hash);
	for (int i = 0; i < 101; i++) {
		hash[i] = (int*)calloc(4, sizeof(int));
		assert(hash[i]);
	}
	int min = nums[0], max = nums[0];
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i];
		if (key > max) {
			max = key;
		}
		else if (key < min) {
			min = key;
		}
		int top = hash[key][0];
		if (top < 3) {
			hash[key][top + 1] = i;
		}
		hash[key][0] += 1;
	}
	int ans = 0;
	for (int i = min; i <= max; i++) {
		int top = hash[i][0];
		int a = hash[i][1], b = hash[i][2], c = hash[i][3];
		if (top == 3 && b - a == c - b) {
			ans += 1;
		}
	}
	for (int i = 0; i < 101; i++) {
		free(hash[i]);
	}
	free(hash);
	return ans;
}