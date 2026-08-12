#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.08.12力扣网刷题
//2958. 最多 K 个重复元素的最长子数组——资深工程师、数组、哈希表、滑动窗口、第119场双周赛——中等
//给你一个整数数组 nums 和一个整数 k 。
//一个元素 x 在数组中的 频率 指的是它在数组中的出现次数。
//如果一个数组中所有元素的频率都 小于等于 k ，那么我们称这个数组是 好 数组。
//请你返回 nums 中 最长好 子数组的长度。
//子数组 指的是一个数组中一段连续非空的元素序列。
//示例 1：
//输入：nums = [1, 2, 3, 1, 2, 3, 1, 2], k = 2
//输出：6
//解释：最长好子数组是[1, 2, 3, 1, 2, 3] ，值 1 ，2 和 3 在子数组中的频率都没有超过 k = 2 。[2, 3, 1, 2, 3, 1] 和[3, 1, 2, 3, 1, 2] 也是好子数组。
//最长好子数组的长度为 6 。
//示例 2：
//输入：nums = [1, 2, 1, 2, 1, 2, 1, 2], k = 1
//输出：2
//解释：最长好子数组是[1, 2] ，值 1 和 2 在子数组中的频率都没有超过 k = 1 。[2, 1] 也是好子数组。
//最长好子数组的长度为 2 。
//示例 3：
//输入：nums = [5, 5, 5, 5, 5, 5, 5], k = 4
//输出：4
//解释：最长好子数组是[5, 5, 5, 5] ，值 5 在子数组中的频率没有超过 k = 4 。
//最长好子数组的长度为 4 。
//提示：
//1 <= nums.length <= 10^5
//1 <= nums[i] <= 10^9
//1 <= k <= nums.length
typedef struct Hash {
	int val;
	int num;
}Hash;
int getKey(int len, int x) {
	return x % len;
}
int Push(Hash* hash, int len, int x) {
	int key = getKey(len, x);
	while (hash[key].val != x && hash[key].num) {
		key = (key + 1) % len;
	}
	hash[key].val = x;
	hash[key].num += 1;
	return key;
}
int find(Hash* hash, int len, int x) {
	int key = getKey(len, x);
	while (hash[key].val != x) {
		key = (key + 1) % len;
	}
	return key;
}
int maxSubarrayLength(int* nums, int numsSize, int k) {
	Hash* hash = (Hash*)calloc(numsSize, sizeof(Hash));
	assert(hash);
	int ans = 0;
    for (int l = 0, r = 0; l <= r && r < numsSize; r++) {
        int key = Push(hash, numsSize, nums[r]);
        if (hash[key].num > k) {
            while (l <= r) {
				int index = find(hash, numsSize, nums[l]);
                l += 1;
                hash[index].num -= 1;
                if (hash[index].val == nums[r]) {
                    break;
                }
            }
        }
		int len = r - l + 1;
		if (len > ans) {
			ans = len;
		}
    }
	free(hash);
	hash = NULL;
	return ans;
}