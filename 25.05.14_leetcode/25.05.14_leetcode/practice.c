#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.14力扣网刷题
//移除最小数对使数组有序 I——数组、哈希表、链表、双向链表、有序集合、模拟、堆（优先队列）——简单
//给你一个数组 nums，你可以执行以下操作任意次数：
//选择 相邻 元素对中 和最小 的一对。如果存在多个这样的对，选择最左边的一个。
//用它们的和替换这对元素。
//返回将数组变为 非递减 所需的 最小操作次数 。
//如果一个数组中每个元素都大于或等于它前一个元素（如果存在的话），则称该数组为非递减。
//示例 1：
//输入： nums = [5, 2, 3, 1]
//输出： 2
//解释：
//元素对(3, 1) 的和最小，为 4。替换后 nums = [5, 2, 4]。
//元素对(2, 4) 的和为 6。替换后 nums = [5, 6]。
//数组 nums 在两次操作后变为非递减。
//示例 2：
//输入： nums = [1, 2, 2]
//输出： 0
//解释：
//数组 nums 已经是非递减的。
//提示：
//1 <= nums.length <= 50
//- 1000 <= nums[i] <= 1000

bool Is_Non_decreasing(int* nums, int numsSize) {
	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			return false;
		}
	}
	return true;
}
void Hash_Record(int* nums, int size, int* hash) {
	for (int i = 0; i < size; i++) {
		hash[i] = nums[i] + nums[i + 1];
	}
}
int Find_Min(int* hash, int size) {
	int min = hash[0];
	for (int i = 0; i < size; i++) {
		if (hash[i] < min) {
			min = hash[i];
		}
	}
	return min;
}
int Delete(int* hash, int size, int* nums, int* numsSize, int min, int ans) {
	for (int i = 0; i < size; i++) {
		// 找最左侧最小元素对
		if (hash[i] == min) {
			nums[i] = hash[i];
			for (int j = i + 1; j <= size - 1; j++) {
				nums[j] = nums[j + 1];
			}
			*numsSize -= 1;
			ans += 1;
			break;
		}
	}
	return ans;
}
void Print(int* nums, int numsSize) {
	printf("numsSize = %d\n", numsSize);
	printf("{");
	for (int i = 0; i < numsSize; i++) {
		printf("%2d\t", nums[i]);
	}
	printf("}\n");
}
int minimumPairRemoval(int* nums, int numsSize) {
	int ans = 0;
	bool flag = false;
	while (!flag) {
		Print(nums, numsSize);
		flag = Is_Non_decreasing(nums, numsSize);
		if (!flag) {
			int size = numsSize - 1;
			int* hash = (int*)calloc(size, sizeof(int));
			assert(hash);
			// 哈希记录相邻元素对之和
			Hash_Record(nums, size, hash);
			// 找最小元素对之和
			int min = Find_Min(hash, size);
			// 删除最小元素对
			ans = Delete(hash, size, nums, &numsSize, min, ans);
			free(hash);
		}
	}
	return ans;
}