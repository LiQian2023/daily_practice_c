#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.11.03力扣网刷题
//所有奇数长度子数组的和——数组、数学、前缀和——简单
//给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。
//子数组 定义为原数组中的一个连续子序列。
//请你返回 arr 中 所有奇数长度子数组的和 。
//示例 1：
//输入：arr = [1, 4, 2, 5, 3]
//输出：58
//解释：所有奇数长度子数组和它们的和为：
//[1] = 1
//[4] = 4
//[2] = 2
//[5] = 5
//[3] = 3
//[1, 4, 2] = 7
//[4, 2, 5] = 11
//[2, 5, 3] = 10
//[1, 4, 2, 5, 3] = 15
//我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
//示例 2：
//输入：arr = [1, 2]
//输出：3
//解释：总共只有 2 个长度为奇数的子数组，[1] 和[2]。它们的和为 3 。
//示例 3：
//输入：arr = [10, 11, 12]
//输出：66
//提示：
//1 <= arr.length <= 100
//1 <= arr[i] <= 1000
//进阶：
//你可以设计一个 O(n) 时间复杂度的算法解决此问题吗？

//方法一：暴力求解
int sumOddLengthSubarrays1(int* arr, int arrSize) {
	int len = arrSize % 2 ? arrSize : arrSize - 1;//最长子数组长度
	int ans = 0;
	for (len; len > 0; len -= 2) {
		for (int i = 0; i <= arrSize - len; i++) {
			for (int j = i; j < i + len; j++) {
				ans += arr[j];
			}
		}
	}
	return ans;
}

//方法二：数学
int sumOddLengthSubarrays(int* arr, int arrSize) {
	int ans = 0;
	for (int i = 0; i < arrSize; i++) {
		int left = i, right = arrSize - i - 1;//坐标左右侧的元素个数
		int left_odd = (left + 1) / 2;//左侧奇数个数
		int right_odd = (right + 1) / 2;//右侧奇数个数
		int left_even = left / 2 + 1;//左侧偶数个数——0也是偶数
		int right_even = right / 2 + 1;//右侧偶数个数
		ans += arr[i] * (left_odd * right_odd + left_even * right_even);
	}
	return ans;
}

void test() {
	//int arr[100] = { 1,4,2,5,3 };
	//int arr[100] = { 7,6,8,6 };
	int arr[100] = { 6,9,14,5,3,8,7,12,13,1 };
	//int size = 5;
	//int size = 4;
	int size = 10;
	int len = sumOddLengthSubarrays(arr, size);
	printf("len = %d\n", len);
}

int main() {
	test();
	return 0;
}