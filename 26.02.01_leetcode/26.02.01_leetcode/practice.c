#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.02.01力扣网刷题
//面试题 17.10.主要元素——数组、计数——简单
//数组中占比超过一半的元素称之为主要元素。给你一个 整数 数组，找出其中的主要元素。若没有，返回 - 1 。请设计时间复杂度为 O(N) 、空间复杂度为 O(1) 的解决方案。
//示例 1：
//输入：[1, 2, 5, 9, 5, 9, 5, 5, 5]
//输出：5
//示例 2：
//输入：[3, 2]
//输出： - 1
//示例 3：
//输入：[2, 2, 1, 1, 1, 2, 2]
//输出：2


int majorityElement1(int* nums, int numsSize) {
	int ans = -1;
	int elem = 0, count = 0;
	for (int i = 0; i < numsSize; i++) {
		if ( count == 0) {
			elem = nums[i];
		}
		if (nums[i] == elem) {
			count += 1;
		}
		else {
			count -= 1;
		}
	}
	count = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == elem) {
			count += 1;
		}
	}
	return count > numsSize / 2 ? elem : ans;
}

// 排序
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
int majorityElement(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int elem = nums[0], count = 0, ans = -1;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == elem) {
			count += 1;
		}
		else {
			if (count > numsSize / 2) {
				ans = elem;
				break;
			}
			elem = nums[i];
			count = 1;
		}
	}
	if (count > numsSize / 2) {
		ans = elem;
	}
	return ans;
}
