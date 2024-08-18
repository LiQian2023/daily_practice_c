#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.08.18力扣网刷题
//使数组中所有元素都等于零——贪心、数组、哈希表、排序、模拟、堆（优先队列）——简单
//给你一个非负整数数组 nums 。在一步操作中，你必须：
//选出一个正整数 x ，x 需要小于或等于 nums 中 最小 的 非零 元素。
//nums 中的每个正整数都减去 x。
//返回使 nums 中所有元素都等于 0 需要的 最少 操作数。
//示例 1：
//输入：nums = [1, 5, 0, 3, 5]
//输出：3
//解释：
//第一步操作：选出 x = 1 ，之后 nums = [0, 4, 0, 2, 4] 。
//第二步操作：选出 x = 2 ，之后 nums = [0, 2, 0, 0, 2] 。
//第三步操作：选出 x = 2 ，之后 nums = [0, 0, 0, 0, 0] 。
//示例 2：
//输入：nums = [0]
//输出：0
//解释：nums 中的每个元素都已经是 0 ，所以不需要执行任何操作。
//提示：
//1 <= nums.length <= 100
//0 <= nums[i] <= 100

void CountSort(int* nums, int len) {
	int count[101] = { 0 };
	int min = nums[0], max = nums[0];
	for (int i = 0; i < len; i++) {
		count[nums[i]] += 1;
		if (min > nums[i])
			min = nums[i];
		if (max < nums[i])
			max = nums[i];
	}
	len = 0;
	for (int i = min; i <= max; i++) {
		while (count[i]) {
			nums[len++] = i;
			count[i] -= 1;
		}
	}
}
//方法一：模拟
int minimumOperations(int* nums, int numsSize) {
	CountSort(nums, numsSize);
	int ans = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i]) {
			int key = nums[i];
			for (int j = i; j < numsSize; j++) {
				nums[j] -= key;
			}
			ans += 1;
		}
	}
	return ans;
}

//方法二：分治
int minimumOperations(int* nums, int numsSize) {
	CountSort(nums, numsSize);
	int ans = 0;
	int key = 0;
	for (int i = 0; i < numsSize; i++) {
		nums[i] -= key;
		if (nums[i]) {
			nums[numsSize - 1] -= nums[i];
			ans += 1;
			key += nums[i];
		}
		if (nums[numsSize - 1] == 0)
			break;
	}
	return ans;
}

void test() {
	int a[10] = { 1,5,0,3,5 };
	int len = 5;
	printf("%d\n", minimumOperations(a, len));
}

int main() {
	test();
	return 0;
}