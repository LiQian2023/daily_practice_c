#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//2026.07.12力扣网刷题
//1331. 数组序号转换——中级工程师、数组、哈希表、排序、第18场双周赛——简单
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
typedef struct Hash {
	int val;
	int old_index;
	int index;
}Hash;
int cmp(const void* p1, const void* p2) {
	Hash* a = (Hash*)p1, * b = (Hash*)p2;
	return a->val - b->val;
}
void Print(Hash* h, int len) {
	printf("{");
	for (int i = 0; i < len; i++) {
		printf("'%d': %d, ", h[i].val, h[i].index);
	}
	printf("}\n");
}
int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
	Hash* hash = (Hash*)calloc(arrSize, sizeof(Hash));
	assert(hash);
	for (int i = 0; i < arrSize; i++) {
		hash[i].val = arr[i];
		hash[i].old_index = i;
	}
	qsort(hash, arrSize, sizeof(Hash), cmp);
	for (int i = 0, j = 1, z = 1; j <= arrSize && i < arrSize; i = j, z += 1) {
		hash[i].index = z;
		while (j < arrSize && hash[j].val == hash[i].val) {
			hash[j].index = hash[i].index;
			j += 1;
		}
	}
	int* ans = (int*)calloc(arrSize, sizeof(int));
	assert(ans);
	*returnSize = arrSize;
	for (int i = 0; i < arrSize; i++) {
		int key = hash[i].old_index;
		arr[key] = hash[i].index;
	}
	free(hash);
	return arr;
}