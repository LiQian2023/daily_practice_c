#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.01.15力扣网刷题
// 使三个字符串相等——字符串——简单
//给你三个字符串 s1、s2 和 s3。 你可以根据需要对这三个字符串执行以下操作 任意次数 。
//在每次操作中，你可以选择其中一个长度至少为 2 的字符串 并删除其 最右位置上 的字符。
//如果存在某种方法能够使这三个字符串相等，请返回使它们相等所需的 最小 操作次数；否则，返回 - 1。
//示例 1：
//输入：s1 = "abc"，s2 = "abb"，s3 = "ab"
//输出：2
//解释：对 s1 和 s2 进行一次操作后，可以得到三个相等的字符串。
//可以证明，不可能用少于两次操作使它们相等。
//示例 2：
//输入：s1 = "dac"，s2 = "bac"，s3 = "cac"
//输出： - 1
//解释：因为 s1 和 s2 的最左位置上的字母不相等，所以无论进行多少次操作，它们都不可能相等。因此答案是 - 1 。
//提示：
//1 <= s1.length, s2.length, s3.length <= 100
//s1、s2 和 s3 仅由小写英文字母组成。

int findMinimumOperations(char* s1, char* s2, char* s3) {
	int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
	int ans = 0, i = 0;
	for (i; i < len1 && i < len2 && i < len3; i++) {
		if (s1[i] != s2[i] || s1[i] != s3[i] || s2[i] != s3[i]) {
			break;
		}
	}
	ans = len1 - i + len2 - i + len3 - i;
	return ans == len1 + len2 + len3 ? -1 : ans;
}
#if 0
//超过阈值的最少操作数 II——数组、模拟、堆（优先队列）——中等
//给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。
//一次操作中，你将执行：
//选择 nums 中最小的两个整数 x 和 y 。
//将 x 和 y 从 nums 中删除。
//将 min(x, y) * 2 + max(x, y) 添加到数组中的任意位置。
//注意，只有当 nums 至少包含两个元素时，你才可以执行以上操作。
//你需要使数组中的所有元素都大于或等于 k ，请你返回需要的 最少 操作次数。
//示例 1：
//输入：nums = [2, 11, 10, 1, 3], k = 10
//输出：2
//解释：第一次操作中，我们删除元素 1 和 2 ，然后添加 1 * 2 + 2 到 nums 中，nums 变为[4, 11, 10, 3] 。
//第二次操作中，我们删除元素 3 和 4 ，然后添加 3 * 2 + 4 到 nums 中，nums 变为[10, 11, 10] 。
//此时，数组中的所有元素都大于等于 10 ，所以我们停止操作。
//使数组中所有元素都大于等于 10 需要的最少操作次数为 2 。
//示例 2：
//输入：nums = [1, 1, 2, 4, 9], k = 20
//输出：4
//解释：第一次操作后，nums 变为[2, 4, 9, 3] 。
//第二次操作后，nums 变为[7, 4, 9] 。
//第三次操作后，nums 变为[15, 9] 。
//第四次操作后，nums 变为[33] 。
//此时，数组中的所有元素都大于等于 20 ，所以我们停止操作。
//使数组中所有元素都大于等于 20 需要的最少操作次数为 4 。
//提示：
//2 <= nums.length <= 2 * 10^5
//1 <= nums[i] <= 10^9
//1 <= k <= 10^9
//输入保证答案一定存在，也就是说一定存在一个操作序列使数组中所有元素都大于等于 k 。
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Adjust_down(int* nums, int len, int parent) {
	int child = parent * 2 + 1;
	while (child < len) {
		if (child + 1 < len && nums[child + 1] < nums[child]) {
			child += 1;
		}
		if (nums[child] < nums[parent]) {
			Swap(&nums[child], &nums[parent]);
		}
		parent = child;
		child = parent * 2 + 1;
	}
}
void Create_Heap(int* nums, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_down(nums, len, i);
	}
}
void Heap_Sort(int* nums, int len) {
	for (int i = len - 1; i; i--) {
		Swap(&nums[0], &nums[i]);
		Adjust_down(nums, i, 0);
	}
}
int minOperations(int* nums, int numsSize, int k) {
	Create_Heap(nums, numsSize);
	int ans = 0;
	while (nums[0] < k) {
		//排序
		int a = nums[0], b = nums[1];
		if ((k - b) / 2 < a) {
			nums[0] = k, nums[1] = k;
		}
		else {
			nums[0] = a * 2 + b;
			nums[1] = k;
		}
		ans += 1;
		Heap_Sort(nums, numsSize);
	}
	return ans;
}
#endif