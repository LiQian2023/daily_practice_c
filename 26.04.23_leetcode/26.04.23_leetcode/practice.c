#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.04.23力扣网刷题
//2615. 等值距离和——高级工程师、数组、哈希表、前缀和、第340场周赛——简单
//给你一个下标从 0 开始的整数数组 nums 。现有一个长度等于 nums.length 的数组 arr 。对于满足 nums[j] == nums[i] 且 j != i 的所有 j ，arr[i] 等于所有 | i - j | 之和。如果不存在这样的 j ，则令 arr[i] 等于 0 。
//返回数组 arr 。
//示例 1：
//输入：nums = [1, 3, 1, 1, 2]
//输出：[5, 0, 3, 4, 0]
//解释：
//i = 0 ，nums[0] == nums[2] 且 nums[0] == nums[3] 。因此，arr[0] = | 0 - 2 | +| 0 - 3 | = 5 。
//i = 1 ，arr[1] = 0 因为不存在值等于 3 的其他下标。
//i = 2 ，nums[2] == nums[0] 且 nums[2] == nums[3] 。因此，arr[2] = | 2 - 0 | +| 2 - 3 | = 3 。
//i = 3 ，nums[3] == nums[0] 且 nums[3] == nums[2] 。因此，arr[3] = | 3 - 0 | +| 3 - 2 | = 4 。
//i = 4 ，arr[4] = 0 因为不存在值等于 2 的其他下标。
//示例 2：
//输入：nums = [0, 5, 3]
//输出：[0, 0, 0]
//解释：因为 nums 中的元素互不相同，对于所有 i ，都有 arr[i] = 0 。
//提示：
//1 <= nums.length <= 10^5
//0 <= nums[i] <= 10^9


typedef struct Hash {
	int num;
	int len;
	int count;
	int* pi;
	long long* prefix;
}Hash;
Hash* initHash(int len) {
	Hash* h = (Hash*)calloc(len, sizeof(Hash));
	assert(h);
	for (int i = 0; i < len; i++) {
		h[i].num = -1;
		h[i].len = 0;
		h[i].pi = NULL;
	}
	return h;
}
int getKey(Hash* h, int x, int len) {
	int key = x % len;
	while (h[key].num != x && h[key].num != -1) {
		key = (key + 1) % len;
	}
	return key;
}
void Record(Hash* h, int key, int x) {
	h[key].num = x;
	h[key].count += 1;
}
void Push(Hash* h, int key, int i) {
	if (h[key].pi == NULL) {
		h[key].pi = (int*)calloc(h[key].count, sizeof(int));
		assert(h[key].pi);
		h[key].prefix = (long long*)calloc(h[key].count, sizeof(long long));
		assert(h[key].prefix);
	}
	h[key].pi[h[key].len] = i;
	if (h[key].len > 0) {
		h[key].prefix[h[key].len] += i + h[key].prefix[h[key].len - 1];
	}
	else {
		h[key].prefix[h[key].len] = i;
	}
	h[key].len += 1;
}

void Destroy(Hash** h, int len) {
	for (int i = 0; i < len; i++) {
		if ((*h)[i].pi != NULL) {
			free((*h)[i].pi);
			(*h)[i].pi = NULL;
			free((*h)[i].prefix);
			(*h)[i].prefix = NULL;
		}
	}
	free(*h);
	*h = NULL;
}
// 方法一：哈希表——超时
long long* distance1(int* nums, int numsSize, int* returnSize) {
	Hash* h = initHash(numsSize);
	for (int i = 0; i < numsSize; i++) {
		int key = getKey(h, nums[i], numsSize);
		Record(h, key, nums[i]);
	}
	for (int i = 0; i < numsSize; i++) {
		int key = getKey(h, nums[i], numsSize);
		Push(h, key, i);
	}
	long long* ans = (long long*)calloc(numsSize, sizeof(long long));
	assert(ans);
	*returnSize = numsSize;
	for (int i = 0; i < numsSize; i++) {
		if (h[i].len != 0) {
			for (int j = 0; j < h[i].count; j++) {
				int index = h[i].pi[j];
				long long sum = 0;
				for (int z = 0; z < h[i].count; z++) {
					if (z != j) {
						sum += abs(h[i].pi[j] - h[i].pi[z]);
					}
				}
				ans[index] = sum;
			}
		}
	}
	Destroy(&h, numsSize);
	return ans;
}
// 方法一：哈希表优化——超时
long long* distance(int* nums, int numsSize, int* returnSize) {
	Hash* h = initHash(numsSize);
	for (int i = 0; i < numsSize; i++) {
		int key = getKey(h, nums[i], numsSize);
		Record(h, key, nums[i]);
	}
	for (int i = 0; i < numsSize; i++) {
		int key = getKey(h, nums[i], numsSize);
		Push(h, key, i);
	}
	long long* ans = (long long*)calloc(numsSize, sizeof(long long));
	assert(ans);
	*returnSize = numsSize;
	for (int i = 0; i < numsSize; i++) {
		if (h[i].len > 1) {
			for (int j = 0; j < h[i].len; j++) {
				int index = h[i].pi[j];
				long long left = (long long)index * j - (j == 0 ? 0 : h[i].prefix[j - 1]);
				long long right = h[i].prefix[h[i].len - 1] - h[i].prefix[j] - (long long)index * (h[i].len - 1 - j);
				ans[index] = left + right;
			}
		}
	}
	Destroy(&h, numsSize);
	return ans;
}