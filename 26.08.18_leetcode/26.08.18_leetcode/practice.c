#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.08.18力扣网刷题
//3471. 找出最大的几近缺失整数——中级工程师、数组、哈希表、第439场周赛——简单
//给你一个整数数组 nums 和一个整数 k 。
//如果整数 x 恰好仅出现在 nums 中的一个大小为 k 的子数组中，则认为 x 是 nums 中的几近缺失（almost missing）整数。
//返回 nums 中 最大的几近缺失 整数，如果不存在这样的整数，返回 - 1 。
//子数组 是数组中的一个连续元素序列。
//示例 1：
//输入：nums = [3, 9, 2, 1, 7], k = 3
//输出：7
//解释：
//1 出现在两个大小为 3 的子数组中：[9, 2, 1]、[2, 1, 7]
//2 出现在三个大小为 3 的子数组中：[3, 9, 2]、[9, 2, 1]、[2, 1, 7]
//3 出现在一个大小为 3 的子数组中：[3, 9, 2]
//7 出现在一个大小为 3 的子数组中：[2, 1, 7]
//9 出现在两个大小为 3 的子数组中：[3, 9, 2]、[9, 2, 1]
//返回 7 ，因为它满足题意的所有整数中最大的那个。
//示例 2：
//输入：nums = [3, 9, 7, 2, 1, 7], k = 4
//输出：3
//解释：
//1 出现在两个大小为 4 的子数组中：[9, 7, 2, 1]、[7, 2, 1, 7]
//2 出现在三个大小为 4 的子数组中：[3, 9, 7, 2]、[9, 7, 2, 1]、[7, 2, 1, 7]
//3 出现在一个大小为 4 的子数组中：[3, 9, 7, 2]
//7 出现在三个大小为 4 的子数组中：[3, 9, 7, 2]、[9, 7, 2, 1]、[7, 2, 1, 7]
//9 出现在两个大小为 4 的子数组中：[3, 9, 7, 2]、[9, 7, 2, 1]
//返回 3 ，因为它满足题意的所有整数中最大的那个。
//示例 3：
//输入：nums = [0, 0], k = 1
//输出： - 1
//解释：
//不存在满足题意的整数。
//提示：
//1 <= nums.length <= 50
//0 <= nums[i] <= 50
//1 <= k <= nums.length

typedef struct Hash {
	int val;
	int num;
	int group;
}Hash;
Hash* Create(int n) {
	Hash* h = (Hash*)calloc(n, sizeof(Hash));
	assert(h);
	for (int i = 0; i < n; i++) {
		h[i].val = -1;
		h[i].num = 0;
		h[i].group = -1;
	}
	return h;
}
int getKey(Hash* h, int len, int x) {
	int key = x % len;
	while (h[key].val != x && h[key].val != -1) {
		key = (key + 1) % len;
	}
	return key;
}

void Push(Hash* h, int len, int x, int group) {
	int key = getKey(h, len, x);
	h[key].val = x;
	if (h[key].group != group) {
		h[key].num += 1;
		h[key].group = group;
	}
}
void Destroy(Hash** h) {
	free(*h);
	*h = NULL;
}
int largestInteger(int* nums, int numsSize, int k) {
	int ans = -1;
	Hash* h = Create(numsSize);
	for (int i = 0, g = 1; i < numsSize; i++, g++) {
		int r = i + k - 1;
		if (r < numsSize) {
			for (int j = i; j <= r; j++) {
				Push(h, numsSize, nums[j], g);
			}
		}
		else {
			break;
		}
	}
	for (int i = 0; i < numsSize; i++) {
		int key = getKey(h, numsSize, nums[i]);
		if (h[key].num == 1 && nums[i] > ans) {
			ans = nums[i];
		}
	}
	Destroy(&h);
	return ans;
}