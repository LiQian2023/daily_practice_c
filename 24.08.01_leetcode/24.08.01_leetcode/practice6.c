#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.08.01力扣网刷题
//按照频率将数组升序排序——数组、哈希表、排序——简单
//给你一个整数数组 nums ，请你将数组按照每个值的频率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。
//请你返回排序后的数组。
//示例 1：
//输入：nums = [1, 1, 2, 2, 2, 3]
//输出：[3, 1, 1, 2, 2, 2]
//解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
//示例 2：
//输入：nums = [2, 3, 1, 3, 2]
//输出：[1, 3, 3, 2, 2]
//解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
//示例 3：
//输入：nums = [-1, 1, -6, 4, 5, -6, 1, 4, 1]
//输出：[5, -1, 4, 4, -6, -6, 1, 1, 1]
//提示：
//1 <= nums.length <= 100
//- 100 <= nums[i] <= 100

//方法一：哈希表
typedef struct Hash {
	int count;
	int value;
}Hash;
int cmp_count(const void* p1, const void* p2) {
	if (((Hash*)p1)->count != ((Hash*)p2)->count)
		return((Hash*)p2)->count - ((Hash*)p1)->count;
	return ((Hash*)p1)->value - ((Hash*)p2)->value;
}
int* frequencySort(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	Hash H[201] = { 0 };
	int min = nums[0], max = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] < min)
			min = nums[i];
		else if (nums[i] > max)
			max = nums[i];
	}
	for (int i = 0; i < numsSize; i++) {
		H[nums[i] - min].count += 1;
		H[nums[i] - min].value = nums[i];
	}
	qsort(H, max - min + 1, sizeof(Hash), cmp_count);
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	int len = 0;
	for (int i = max - min; i >= 0;) {
		if (H[i].count) {
			ans[len++] = H[i].value;
			H[i].count -= 1;
		}
		else {
			i--;
		}
		if (len == *returnSize)
			break;
	}
	return ans;
}

void test6() {
	int nums[10] = { -1,1,-6,4,5,-6,1,4,1 };
	int len = 9;
	int size = 0;
	int* ret = frequencySort(nums, len, &size);
	Print_int(ret, size);
	free(ret);
}