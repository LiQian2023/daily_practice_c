#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

//2026.01.12力扣网刷题
//3740. 三个相等元素之间的最小距离 I——数组、哈希表、第475场周赛——简单
//给你一个整数数组 nums。
//如果满足 nums[i] == nums[j] == nums[k]，且(i, j, k) 是 3 个 不同 下标，那么三元组(i, j, k) 被称为 有效三元组 。
//有效三元组 的 距离 被定义为 abs(i - j) + abs(j - k) + abs(k - i)，其中 abs(x) 表示 x 的 绝对值 。
//返回一个整数，表示 有效三元组 的 最小 可能距离。如果不存在 有效三元组 ，返回 - 1。
//示例 1：
//输入： nums = [1, 2, 1, 1, 3]
//输出： 6
//解释：
//最小距离对应的有效三元组是(0, 2, 3) 。
//(0, 2, 3) 是一个有效三元组，因为 nums[0] == nums[2] == nums[3] == 1。它的距离为 abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6。
//示例 2：
//输入： nums = [1, 1, 2, 3, 2, 1, 2]
//输出： 8
//解释：
//最小距离对应的有效三元组是(2, 4, 6) 。
//(2, 4, 6) 是一个有效三元组，因为 nums[2] == nums[4] == nums[6] == 2。它的距离为 abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8。
//示例 3：
//输入： nums = [1]
//输出： - 1
//解释：
//不存在有效三元组，因此答案为 - 1。
//提示：
//1 <= n == nums.length <= 100
//1 <= nums[i] <= n

typedef struct Hash {
	int* pi;
	int len;
	int maxlen;
}Hash;
void Free(Hash** hash, int min, int max) {
	for (int i = min; i < max; i++) {
		free((*hash)[i].pi);
		(*hash)[i].pi = NULL;
	}
	free(*hash);
	*hash = NULL;
}
int minimumDistance(int* nums, int numsSize) {
	int max = nums[0], min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		else if (nums[i] < min) {
			min = nums[i];
		}
	}
	Hash* hash = (Hash*)calloc(max + 1, sizeof(Hash));
	if (hash == NULL) {
		perror("calloc:hash");
		return -1;
	}
	for (int i = min; i < max + 1; i++) {
		hash[i].pi = (int*)calloc(numsSize, sizeof(int))l;
		if (hash[i].pi == NULL) {
			perror("calloc: hash[i].pi");
			Free(&hash, min, i);
			return -1;
		}
		hash[i].len = 0;
		hash[i].maxlen = numsSize;
	}

	for (int i = 0; i < numsSize; i++) {
		int key1 = nums[i];
		int key2 = hash[key1].len;
		hash[key1].pi[key2] = i;
		hash[key1].len += 1;
	}
	int ans = -1;
	for (int i = min; i <= max; i++) {
		if (hash[i].len >= 3) {
			int tmp = -1;
			for (int j = 1; j < hash[i].len - 1; j++) {
				int dis = hash[i].pi[j] - hash[i].pi[j - 1] + hash[i].pi[j + 1] - hash[i].pi[j] + hash[i].pi[j + 1] - hash[i].pi[j - 1];
				if (tmp == -1 || dis < tmp) {
					tmp = dis;
				}
			}
			if (ans == -1 || tmp < ans) {
				ans = tmp;
			}
		}
	}
	Free(&hash, min, max);
	return ans;
}