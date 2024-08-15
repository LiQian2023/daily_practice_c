#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//2024.08.15力扣网刷题
//多个数组求交集——数组、哈希、计数、排序——简单
//给你一个二维整数数组 nums ，其中 nums[i] 是由 不同 正整数组成的一个非空数组，
//按 升序排列 返回一个数组，数组中的每个元素在 nums 所有数组 中都出现过。
//示例 1：
//输入：nums = [[3, 1, 2, 4, 5], [1, 2, 3, 4], [3, 4, 5, 6]]
//输出：[3, 4]
//解释：
//nums[0] = [3, 1, 2, 4, 5]，nums[1] = [1, 2, 3, 4]，nums[2] = [3, 4, 5, 6]，
//在 nums 中每个数组中都出现的数字是 3 和 4 ，所以返回[3, 4] 。
//示例 2：
//输入：nums = [[1, 2, 3], [4, 5, 6]]
//输出：[]
//解释：
//不存在同时出现在 nums[0] 和 nums[1] 的整数，所以返回一个空列表[] 。
//提示：
//1 <= nums.length <= 1000
//1 <= sum(nums[i].length) <= 1000
//1 <= nums[i][j] <= 1000
//nums[i] 中的所有值 互不相同


typedef struct Hash {
	int value;
	int count;
}Hash;

int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
	//numsSize——数组长度
	//numsColSize——子数组长度
	int hash[1001] = { 0 };
	int min = nums[0][0], max = nums[0][0];
	printf("min = %d\nmax = %d\n", min, max);
	for (int i = 0; i < numsSize; i++) {
		printf("i = %d\n", i);
		printf("numsColSize[%d] = %d\n", i, numsColSize[i]);
		for (int j = 0; j < numsColSize[i]; j++) {
			int key = nums[i][j];
			printf("key = %d\n", key);
			hash[key] += 1;
			printf("hash[%d] = %d\n", key, hash[key]);
			if (min > key)
				min = key;
			if (max < key)
				max = key;
		}
	}
	int* ans = (int*)calloc(*numsColSize, sizeof(int));
	assert(ans);
	int len = 0;
	printf("min = %d\nmax = %d\n", min, max);
	for (int i = min; i <= max; i++) {
		printf("hash[%d] = %d\n", i, hash[i]);
		printf("numsSize = %d\n", numsSize);
		if (hash[i] == numsSize) {
			ans[len++] = i;
			printf("len = %d\n", len);
			printf("ans[%d] = %d\n", len - 1, ans[len - 1]);
		}
			
	}
	*returnSize = len;
	return ans;
}

void test() {
	int a1[10] = { 3,1,2,4,5 };
	int a2[10] = { 1,2,3,4 };
	int a3[10] = { 3,4,5,6 };
	int* arr[3] = { &a1,&a2,&a3 };
	int** tmp = arr;
	int row = 3;
	int col = 5;
	int size = 0;
	int* ret = intersection(tmp, row, &col, &size);
	for (int i = 0; i < size; i++)
		printf("%d ", ret[i]);
}

int main() {
	test();
	return 0;
}