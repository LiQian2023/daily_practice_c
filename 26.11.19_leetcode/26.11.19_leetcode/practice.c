#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.11.19力扣网刷题
//2567. 修改两个元素的最小分数——高级工程师、贪心、数组、排序、第98场双周赛——中等
//给你一个下标从 0 开始的整数数组 nums 。
//nums 的 最小 得分是满足 0 <= i < j < nums.length 的 | nums[i] - nums[j] | 的最小值。
//nums的 最大 得分是满足 0 <= i < j < nums.length 的 | nums[i] - nums[j] | 的最大值。
//nums 的分数是 最大 得分与 最小 得分的和。
//我们的目标是最小化 nums 的分数。你 最多 可以修改 nums 中 2 个元素的值。
//请你返回修改 nums 中 至多两个 元素的值后，可以得到的 最小分数 。
//| x | 表示 x 的绝对值。
//示例 1：
//输入：nums = [1, 4, 3]
//输出：0
//解释：将 nums[1] 和 nums[2] 的值改为 1 ，nums 变为[1, 1, 1] 。 | nums[i] - nums[j] | 的值永远为 0 ，所以我们返回 0 + 0 = 0 。
//示例 2：
//输入：nums = [1, 4, 7, 8, 5]
//输出：3
//解释：
//将 nums[0] 和 nums[1] 的值变为 6 ，nums 变为[6, 6, 7, 8, 5] 。
//最小得分是 i = 0 且 j = 1 时得到的 | nums[i] - nums[j] | = | 6 - 6 | = 0 。
//最大得分是 i = 3 且 j = 4 时得到的 | nums[i] - nums[j] | = | 8 - 5 | = 3 。
//最大得分与最小得分之和为 3 。这是最优答案。
//提示：
//3 <= nums.length <= 10^5
//1 <= nums[i] <= 10^9
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Adjust_Down_Min_Heap(int* nums, int len, int parent) {
	int child = parent * 2 + 1;
	while (child < len) {
		if (child + 1 < len && nums[child] > nums[child + 1]) {
			child += 1;
		}
		if (nums[parent] <= nums[child]) {
			break;
		}
		Swap(&nums[parent], &nums[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void Adjust_Down_Max_Heap(int* nums, int len, int parent) {
	int child = parent * 2 + 1;
	while (child < len) {
		if (child + 1 < len && nums[child] < nums[child + 1]) {
			child += 1;
		}
		if (nums[parent] >= nums[child]) {
			break;
		}
		Swap(&nums[parent], &nums[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void CreatMinHeap(int* nums, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_Down_Min_Heap(nums, len, i);
	}
}
void CreatMaxHeap(int* nums, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_Down_Max_Heap(nums, len, i);
	}
}
void Max_Heap_Sort(int* nums, int len) {
	for (int i = len - 1; i > 0; i--) {
		Swap(&nums[0], &nums[i]);
		Adjust_Down_Max_Heap(nums, i, 0);
	}
}
void Min_Heap_Sort(int* nums, int len) {
	for (int i = len - 1; i > 0; i--) {
		Swap(&nums[0], &nums[i]);
		Adjust_Down_Min_Heap(nums, i, 0);
	}
}
int minimizeSum(int* nums, int numsSize) {
	int min[3] = { nums[0], nums[1], nums[2] }, max[3] = { nums[numsSize - 1], nums[numsSize - 2], nums[numsSize - 3] };
	CreatMaxHeap(min, 3);
	CreatMinHeap(max, 3);
	for (int i = 0; i < numsSize; i++) {
		if (i > 2 && nums[i] < min[0]) {
			min[0] = nums[i];
			Adjust_Down_Max_Heap(min, 3, 0);
		}
		if (i<numsSize - 3 && nums[i] > max[0]) {
			max[0] = nums[i];
			Adjust_Down_Min_Heap(max, 3, 0);
		}
	}
	Max_Heap_Sort(min, 3);
	Min_Heap_Sort(max, 3);
	int a = max[0] - min[2], b = max[2] - min[0], c = max[1] - min[1];
	int ans = a < b ? a : b;
	ans = ans < c ? ans : c;
	return ans;
}