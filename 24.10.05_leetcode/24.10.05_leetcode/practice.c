#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.10.05力扣网刷题
//前 K 个高频元素——数组、哈希表、分治、桶排序、计数、快速选择、排序、堆（优先队列）——中等
//给你一个整数数组nums和一个整数k ，请你返回其中出现频率前k高的元素。你可以按任意顺序返回答案。
//示例1 :
//输入: nums = [1, 1, 1, 2, 2, 3], k = 2
//输出 : [1, 2]
//示例2 :
//输入 : nums = [1], k = 1
//输出 : [1]
//提示：
//1 <= nums.length <= 10 ^ 5
//k的取值范围是[1, 数组中不相同的元素的个数]
//题目数据保证答案唯一，换句话说，数组中前k个高频元素的集合是唯一的
//进阶：你所设计算法的时间复杂度必须优于O(nlogn) ，其中n是数组大小。
typedef struct Hash {
	int value;
	int count;
}Hash;
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
int hash_cmp(const void* p1, const void* p2) {
	return ((Hash*)p2)->count - ((Hash*)p1)->count;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
	*returnSize = k;
	int* ans = (int*)calloc(numsSize, sizeof(int));
	assert(ans);
	qsort(nums, numsSize, sizeof(int), cmp);
	//哈希计数
	Hash* h = (Hash*)calloc(numsSize, sizeof(Hash));
	assert(h);
	int len = 0;
	int l = 0, r = 0;
	while (r < numsSize) {
		while (r < numsSize && nums[l] == nums[r]) {
			r += 1;
		}
		h[len].value = nums[l];
		h[len].count = r - l;
		len += 1;
		l = r;
	}
	qsort(h, len, sizeof(Hash), hash_cmp);
	for (int i = 0; i < k; i++) {
		ans[i] = h[i].value;
	}
	free(h);
	return ans;
}