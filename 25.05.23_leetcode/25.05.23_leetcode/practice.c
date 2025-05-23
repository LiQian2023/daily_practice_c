#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2025.05.23力扣网刷题
//统计特殊四元组——数组、哈希表、枚举——简单
//给你一个 下标从 0 开始 的整数数组 nums ，返回满足下述条件的 不同 四元组(a, b, c, d) 的 数目 ：
//nums[a] + nums[b] + nums[c] == nums[d] ，且
//a < b < c < d
//示例 1：
//输入：nums = [1, 2, 3, 6]
//输出：1
//解释：满足要求的唯一一个四元组是(0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
//示例 2：
//输入：nums = [3, 3, 6, 4, 5]
//输出：0
//解释：[3, 3, 6, 4, 5] 中不存在满足要求的四元组。
//示例 3：
//输入：nums = [1, 1, 1, 3, 5]
//输出：4
//解释：满足要求的 4 个四元组如下：
//- (0, 1, 2, 3) : 1 + 1 + 1 == 3
//- (0, 1, 3, 4) : 1 + 1 + 3 == 5
//- (0, 2, 3, 4) : 1 + 1 + 3 == 5
//- (1, 2, 3, 4) : 1 + 1 + 3 == 5
//提示：
//4 <= nums.length <= 50
//1 <= nums[i] <= 100
typedef struct Hash {
	int sum;
	int pi;
}Hash;
int countQuadruplets(int* nums, int numsSize) {
	int size = (numsSize * (numsSize - 5) + 6) / 2;
	Hash* hash = (Hash*)calloc(size, sizeof(Hash));
	assert(hash);
	int len1 = 0;
	for (int i = 0; i < numsSize - 3; i++) {
		for (int j = i + 1; j < numsSize - 2; j++) {
			hash[len1].sum = nums[i] + nums[j];
			hash[len1].pi = j;
			len1 += 1;
		}
	}
	Hash* sub = (Hash*)calloc(size, sizeof(Hash));
	assert(sub);
	int len2 = 0;
	for (int i = 2; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			sub[len2].sum = nums[j] - nums[i];
			sub[len2].pi = i;
			len2 += 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (hash[i].pi < sub[j].pi && hash[i].sum == sub[j].sum) {
				ans += 1;
			}
		}
	}
	free(hash);
	hash = NULL;
	free(sub);
	sub = NULL;
	return ans;
}