#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.01.15力扣网刷题
//3769. 二进制反射排序——数组、排序、第479场周赛——简单
//给你一个整数数组 nums。
//二进制反射 是对一个 正整数 的二进制表示按顺序反转（忽略前导零）后，将反转得到的二进制数转为十进制的结果。
//请按每个元素的二进制反射值的 升序 对数组进行排序。如果两个不同的数字具有相同的二进制反射值，则 较小 的原始数字应排在前面。
//返回排序后的数组。
//示例 1：
//输入： nums = [4, 5, 4]
//输出：[4, 4, 5]
//解释：
//二进制反射值为：
//4 -> (二进制)100 -> (反转)001 -> 1
//5 -> (二进制)101 -> (反转)101 -> 5
//4 -> (二进制)100 -> (反转)001 -> 1
//根据反射值排序为[4, 4, 5]。
//示例 2：
//输入： nums = [3, 6, 5, 8]
//输出：[8, 3, 6, 5]
//解释：
//二进制反射值为：
//3 -> (二进制)11 -> (反转)11 -> 3
//6 -> (二进制)110 -> (反转)011 -> 3
//5 -> (二进制)101 -> (反转)101 -> 5
//8 -> (二进制)1000 -> (反转)0001 -> 1
//根据反射值排序为[8, 3, 6, 5]。
//注意，3 和 6 的反射值相同，因此需要按原始值的升序排列。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 10^9

typedef struct Hash {
    int data;
    int bin_to_dec;
} Hash;
int b_to_d(int n) {
	// 十进制转二进制反射再转十进制
	int rev = 0;
	while (n) {
		rev = (rev << 1) | (n & 1);
		n >>= 1;
	}
    return rev;
}
int cmp_hash(const void* a, const void* b) {
	Hash* hash_a = (Hash*)a;
	Hash* hash_b = (Hash*)b;
	if (hash_a->bin_to_dec != hash_b->bin_to_dec) {
		return hash_a->bin_to_dec - hash_b->bin_to_dec;
	} else {
		return hash_a->data - hash_b->data;
	}
}
int* sortByReflection(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ans = (int*)calloc(numsSize, sizeof(int));
    assert(ans);
	Hash* hash = (Hash*)calloc(numsSize, sizeof(Hash));
	assert(hash);
	for (int i = 0; i < numsSize; i++) {
		hash[i].data = nums[i];
		hash[i].bin_to_dec = b_to_d(nums[i]);
	}
	qsort(hash, numsSize, sizeof(Hash), cmp_hash);
	for (int i = 0; i < numsSize; i++) {
		ans[i] = hash[i].data;
	}
	free(hash);
	hash = NULL;
    return ans;
}