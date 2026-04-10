#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.04.10力扣网刷题
//3740. 三个相等元素之间的最小距离 I——中级工程师、数组、哈希表、第475场周赛——简单
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
#define MAXSIZE 101
typedef struct Hash {
	int len;
	int count;
	int* pi;
}Hash;

int minimumDistance(int* nums, int numsSize) {
	Hash* hash = (Hash*)calloc(MAXSIZE, sizeof(Hash));
	assert(hash);
	for (int i = 0; i < MAXSIZE; i++) {
		hash[i].len = numsSize;
		hash[i].count = 0;
		hash[i].pi = (int*)calloc(numsSize, sizeof(int));
		assert(hash[i].pi);
	}
	int max = nums[0], min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i];
		int index = hash[key].count;
		hash[key].pi[index] = i;
		hash[key].count += 1;
		if (key > max) {
			max = key;
		}
		else if (key < min) {
			min = key;
		}
	}
	int ans = -1;
	for (int i = min; i <= max; i++) {
		if (hash[i].count >= 3) {
			for (int j = 1; j < hash[i].count - 1; j++) {
				int tmp = abs(hash[i].pi[j - 1] - hash[i].pi[j]) 
					+ abs(hash[i].pi[j] - hash[i].pi[j +  1]) 
					+ abs(hash[i].pi[j + 1] - hash[i].pi[j - 1]);
				if (ans == -1 || tmp < ans) {
					ans = tmp;
				}
			}
		}
	}
	for (int i = 0; i < MAXSIZE; i++) {
		free(hash[i].pi);
	}
	free(hash);
	return ans;
}