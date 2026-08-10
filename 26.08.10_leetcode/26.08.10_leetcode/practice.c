#include <stdio.h>

//2026.08.10力扣网刷题
//11. 盛最多水的容器——贪心、数组、双指针——中等
//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是(i, 0) 和(i, height[i]) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//返回容器可以储存的最大水量。
//说明：你不能倾斜容器。
//示例 1：
//输入：[1, 8, 6, 2, 5, 4, 8, 3, 7]
//输出：49
//解释：图中垂直线代表输入数组[1, 8, 6, 2, 5, 4, 8, 3, 7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
//示例 2：
//输入：height = [1, 1]
//输出：1
//提示：
//n == height.length
//2 <= n <= 10^5
//0 <= height[i] <= 10^4

// 方法一：暴力求解
int maxArea(int* height, int heightSize) {
	int ans = 0;
	for (int i = 0; i < heightSize; i++) {
		for (int j = heightSize - 1; j > i; j--) {
			int w = j - i;
			int h = height[i] < height[j] ? height[i] : height[j];
			int area = w * h;
			if (area > ans) {
				ans = area;
			}
		}
	}
	return ans;
}

// 方法二：
int maxArea(int* height, int heightSize) {
	int mid = heightSize / 2;
	int left = mid, right = mid;
	if (heightSize % 2 == 0) {
		left -= 1;
	}
	for (int i = left, j = right; i >= 0 && j < heightSize; i--, j++) {
		if (height[i] > height[left] || (left - i > height[left] - height[i])) {
			left = i;
		}
		if (height[j] > height[right]|| (j - right > height[right] - height[j])) {
			right = j;
		}
	}
	int w = right - left;
	int h = height[left] < height[right] ? height[left] : height[right];
	return w * h;
}