#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.09.23力扣网刷题
//1658. 将 x 减到 0 的最小操作数——资深工程师、数组、哈希表、二分查找、前缀和、滑动窗口、第215场周赛——中等
//给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。
//如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 - 1 。
//示例 1：
//输入：nums = [1, 1, 4, 2, 3], x = 5
//输出：2
//解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
//示例 2：
//输入：nums = [5, 6, 7, 8, 9], x = 4
//输出： - 1
//示例 3：
//输入：nums = [3, 2, 20, 1, 1, 3], x = 10
//输出：5
//解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
//提示：
//1 <= nums.length <= 10^5
//1 <= nums[i] <= 10^4
//1 <= x <= 10^9
void DFS(int* nums, int x, int* ans, int sum, int tmp,int l, int r) {
	if (sum > x) {
		return;
	}
	if (*ans != -1 && tmp >= *ans) {
		return;
	}
	if (sum == x) {
		if (*ans == -1 || tmp < *ans) {
			*ans = tmp;
		}
		return;
	}

	if (l > r) {
		return;
	}
	DFS(nums, x, ans, sum + nums[l], tmp + 1, l + 1, r);
	DFS(nums, x, ans, sum + nums[r], tmp + 1, l, r - 1);
}
int minOperations1(int* nums, int numsSize, int x) {
	int ans = -1;
	DFS(nums, x, &ans, 0, 0, 0, numsSize - 1);
	return ans;
}

int minOperations(int* nums, int numsSize, int x) {
	int prefix = 0;
	for (int i = 0; i < numsSize; i++) {
		prefix += nums[i];
	}
	int target = prefix - x;
	if (target < 0) {
		return -1;
	}
	int ans = -1;
	int window = 0, tmp = -1;
	for (int l = 0, r = 0; r < numsSize;r++) {
		window += nums[r];
		while (window > target) {
			window -= nums[l];
			l += 1;
		}
		if (window == target) {
			if (r - l + 1 > tmp) {
				tmp = r - l + 1;
			}
		}
	}
	ans = tmp != -1 ? numsSize - tmp : -1;
	return ans;
}