#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//2024.07.13力扣网刷题
//判断一个数组是否可以变为有序——位运算、数组、排序——中等
//给你一个下标从 0 开始且全是 正 整数的数组 nums 。
//一次 操作 中，如果两个 相邻 元素在二进制下数位为 1 的数目 相同 ，那么你可以将这两个元素交换。
//你可以执行这个操作 任意次 （也可以 0 次）。
//如果你可以使数组变有序，请你返回 true ，否则返回 false 。
//示例 1：
//输入：nums = [8, 4, 2, 30, 15]
//输出：true
//解释：我们先观察每个元素的二进制表示。 
//2 ，4 和 8 分别都只有一个数位为 1 ，分别为 "10" ，"100" 和 "1000" 。
//15 和 30 分别有 4 个数位为 1 ："1111" 和 "11110" 。
//我们可以通过 4 个操作使数组有序：
//- 交换 nums[0] 和 nums[1] 。8 和 4 分别只有 1 个数位为 1 。数组变为[4, 8, 2, 30, 15] 。
//- 交换 nums[1] 和 nums[2] 。8 和 2 分别只有 1 个数位为 1 。数组变为[4, 2, 8, 30, 15] 。
//- 交换 nums[0] 和 nums[1] 。4 和 2 分别只有 1 个数位为 1 。数组变为[2, 4, 8, 30, 15] 。
//- 交换 nums[3] 和 nums[4] 。30 和 15 分别有 4 个数位为 1 ，数组变为[2, 4, 8, 15, 30] 。
//数组变成有序的，所以我们返回 true 。
//注意我们还可以通过其他的操作序列使数组变得有序。
//示例 2：
//输入：nums = [1, 2, 3, 4, 5]
//输出：true
//解释：数组已经是有序的，所以我们返回 true 。
//示例 3：
//输入：nums = [3, 16, 8, 4, 2]
//输出：false
//解释：无法通过操作使数组变为有序。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 2^8

bool isSort(int* nums, int size) {
	for (int i = 1; i < size - 1; i++) {
		if (nums[i] < nums[i - 1])
			return false;
	}
	return true;
}

int number(int num) {
	int count = 0;
	while (num) {
		if (num & 1)
			count++;
		num >>= 1;
	}
	return count;
}
void Max_Min(int* nums,int* one, int l, int r,int len, int* max_l,int* min_r) {
	while (l > 0 && one[l] == one[l - 1]) {
		if (nums[l] > *max_l)
			*max_l = nums[l];
		l--;
	}
	if (nums[l] > *max_l)
		*max_l = nums[l];
	while (r < len - 1 && one[r] == one[r + 1]) {
		if (nums[r] < *min_r)
			*min_r = nums[r];
		r++;
	}
	if (nums[r] < *min_r)
		*min_r = nums[r];
}
bool canSortArray(int* nums, int numsSize) {
	//判断原数组是否有序
	if (isSort(nums, numsSize))
		return true;
	//记录元素二进制中1的个数
	int one[100] = { 0 };
	int len = 0;
	for (int i = 0; i < numsSize; i++) {
		one[len++] = number(nums[i]);
	}
	//判断相邻两个元素是否可以交换
	int l = 0, r = 1;
	while (r < len) {
		if (one[l] != one[r]) {
			//找最大值与最小值
			int max_l = nums[l];
			int min_r = nums[r];
			Max_Min(nums, one, l, r, len, &max_l, &min_r);
			if (max_l > min_r)
				return false;
		}
		l++, r++;
	}
	return true;
}

void test() {
	int nums[100] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
		printf("%d\n", canSortArray(nums, n));
	}
}

int main() {
	test();
	return 0;
}