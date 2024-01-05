#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
//2024.01.05力扣网刷题
// 单调数列——数组——简单
//如果数组是单调递增或单调递减的，那么它是 单调 的。
//如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i] > = nums[j]，那么数组 nums 是单调递减的。
//当给定的数组 nums 是单调数组时返回 true，否则返回 false。
//示例 1：
//输入：nums = [1, 2, 2, 3]
//输出：true
//示例 2：
//输入：nums = [6, 5, 4, 4]
//输出：true
//示例 3：
//输入：nums = [1, 3, 2]
//输出：false
//提示：
//1 <= nums.length <= 10^5
//- 10^5 <= nums[i] <= 10^5

bool isMonotonic(int* nums, int numsSize) {
	int l = 1, r = 1;
	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i] < nums[i + 1]) {
			l = 0;
		}
		else if (nums[i] > nums[i + 1]) {
			r = 0;
		}
	}
	return l || r;
}
int main() {
	int arr[100000] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		if (isMonotonic(arr, n))
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}