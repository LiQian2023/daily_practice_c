#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
//2024.07.10力扣网刷题
//统计移除递增子数组的数目 I——数组、双指针、二分查找、枚举——简单
//给你一个下标从 0 开始的 正 整数数组 nums 。
//如果 nums 的一个子数组满足：移除这个子数组后剩余元素 严格递增 ，那么我们称这个子数组为 移除递增 子数组。
//比方说，[5, 3, 4, 6, 7] 中的[3, 4] 是一个移除递增子数组，因为移除该子数组后，[5, 3, 4, 6, 7] 变为[5, 6, 7] ，是严格递增的。
//请你返回 nums 中 移除递增 子数组的总数目。
//注意 ，剩余元素为空的数组也视为是递增的。
//子数组 指的是一个数组中一段连续的元素序列。
//示例 1：
//输入：nums = [1, 2, 3, 4]
//输出：10
//解释：10 个移除递增子数组分别为：[1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3], [2, 3, 4] 和[1, 2, 3, 4]。
//移除任意一个子数组后，剩余元素都是递增的。注意，空数组不是移除递增子数组。
//示例 2：
//输入：nums = [6, 5, 7, 8]
//输出：7
//解释：7 个移除递增子数组分别为：[5], [6], [5, 7], [6, 5], [5, 7, 8], [6, 5, 7] 和[6, 5, 7, 8] 。
//nums 中只有这 7 个移除递增子数组。
//示例 3：
//输入：nums = [8, 7, 6, 6]
//输出：3
//解释：3 个移除递增子数组分别为：[8, 7, 6], [7, 6, 6] 和[8, 7, 6, 6] 。
//注意[8, 7] 不是移除递增子数组因为移除[8, 7] 后 nums 变为[6, 6] ，它不是严格递增的。
//提示：
//1 <= nums.length <= 50
//1 <= nums[i] <= 50

//方法一：模拟——O(N^3)
bool isIncrease(int* nums, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (nums[i] >= nums[i + 1])
			return false;
	}
	return true;
}

int incremovableSubarrayCount1(int* nums, int numsSize) {
	int ans = 0;
	for (int l = 0; l < numsSize; l++) {
		for (int r = l; r < numsSize; r++) {
			int tmp[50] = { 0 };
			int len = 0;
			//获取删除子数组后的数组
			for (int i = 0; i < numsSize; i++) {
				if (i == l) {
					i = r;
					continue;
				}
				tmp[len++] = nums[i];
			}
			//判断数组是否为递增数组
			if (isIncrease(tmp, len)) {
				ans++;
			}
		}
	}
	return ans;
}

//方法二：双指针
int incremovableSubarrayCount(int* nums, int numsSize) {
	int ans = 1;//空数组数
	int l = 0, r = 1;
	//获取左侧递增子数组中右侧元素下标
	while (r < numsSize && nums[l] < nums[r]) {
		l++, r++;
		ans++;
	}
	//左侧移除递增数组个数 = 空数组 + 左侧元素个数
	ans += (r < numsSize);
	l = r;//记录移除数组的左侧元素下标
	//获取移除数组右侧元素最小下标
	for (r = numsSize - 2; r >= 0; r--) {
		//获取右侧移除数组左侧元素下标
		while (l > 0 && nums[l - 1] >= nums[r + 1]) {
			l--;
		}
		//获取右侧移除递增数组个数
		ans += l + (l <= r);//当r < l时，说明查找范围与左侧重叠
		//判断当前右侧下标是否为最小下标
		if (nums[r] >= nums[r + 1])
			break;
	}
	return ans;
}

void test() {
	int nums[50] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
		int ret = incremovableSubarrayCount(nums, n);
		printf("%d\n", ret);
	}
}

int main() {
	test();
	return 0;
}