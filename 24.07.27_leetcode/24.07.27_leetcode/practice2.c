#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.07.27力扣网刷题
//数组的相对排序——数组、哈希表、计数排序、排序——简单
//给你两个数组，arr1 和 arr2，arr2 中的元素各不相同，arr2 中的每个元素都出现在 arr1 中。
//对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
//示例 1：
//输入：arr1 = [2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19], arr2 = [2, 1, 4, 3, 9, 6]
//输出：[2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19]
//示例  2:
//输入：arr1 = [28, 6, 22, 8, 44, 17], arr2 = [22, 28, 8, 6]
//输出：[22, 28, 8, 6, 17, 44]
//提示：
//1 <= arr1.length, arr2.length <= 1000
//0 <= arr1[i], arr2[i] <= 1000
//arr2 中的元素 arr2[i]  各不相同
//arr2 中的每个元素 arr2[i] 都出现在 arr1 中

//方法一：计数排序
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
	*returnSize = arr1Size;
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	int len = 0;
	//计数
	int nums[1001] = { 0 };
	for (int i = 0; i < arr1Size; i++) {
		nums[arr1[i]] += 1;
	}
	//排序
	for (int i = 0; i < arr2Size; i++) {
		while (nums[arr2[i]]) {
			ans[len++] = arr2[i];
			nums[arr2[i]] -= 1;
		}
	}
	for (int i = 0; i < 1001 && len < arr1Size; i++) {
		while (nums[i]) {
			ans[len++] = i;
			nums[i] -= 1;
		}
	}
	return ans;
}