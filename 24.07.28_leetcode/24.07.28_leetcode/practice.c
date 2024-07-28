#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.07.28力扣网刷题
//数组序号转换——数组、哈希表、排序——简单
//给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。
//序号代表了一个元素有多大。序号编号的规则如下：
//序号从 1 开始编号。
//一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
//每个数字的序号都应该尽可能地小。
//示例 1：
//输入：arr = [40, 10, 20, 30]
//输出：[4, 1, 2, 3]
//解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
//示例 2：
//输入：arr = [100, 100, 100]
//输出：[1, 1, 1]
//解释：所有元素有相同的序号。
//示例 3：
//输入：arr = [37, 12, 28, 9, 100, 56, 80, 5, 12]
//输出：[5, 3, 4, 2, 8, 6, 7, 1, 3]
//提示：
//0 <= arr.length <= 10^5
//- 10^9 <= arr[i] <= 10^9


//方法一：哈希表
typedef struct HashNode {
	int value;
	int pi1;
	int pi2;
}HN;

int cmp(const void* p1, const void* p2) {
	return((HN*)p1)->value - ((HN*)p2)->value;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
	*returnSize = arrSize;
	HN* H = (HN*)calloc(arrSize, sizeof(HN));
	assert(H);
	//创建哈希表
	for (int i = 0; i < arrSize; i++) {
		H[i].pi1 = i;
		H[i].value = arr[i];
	}
	//排序
	qsort(H, arrSize, sizeof(HN), cmp);
	//获取排序后的下标
	for (int i = 0; i < arrSize; i++) {
		H[i].pi2 = i;
	}
	//优化下标
	for (int i = 1; i < arrSize; i++) {
		if (H[i].value == H[i - 1].value)
			H[i].pi2 = H[i - 1].pi2;
		else {
			H[i].pi2 = H[i - 1].pi2 + 1;
		}
	}
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	for (int i = 0; i < arrSize; i++) {
		ans[H[i].pi1] = H[i].pi2 + 1;
	}
	free(H);
	return ans;
}