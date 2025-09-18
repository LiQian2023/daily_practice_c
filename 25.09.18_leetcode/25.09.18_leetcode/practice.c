#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//2025.09.18力扣网刷题
//种花问题——贪心、数组——简单
//假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。
//示例 1：
//输入：flowerbed = [1, 0, 0, 0, 1], n = 1
//输出：true
//示例 2：
//输入：flowerbed = [1, 0, 0, 0, 1], n = 2
//输出：false
//提示：
//1 <= flowerbed.length <= 2 * 10^4
//flowerbed[i] 为 0 或 1
//flowerbed 中不存在相邻的两朵花
//0 <= n <= flowerbed.length

void plant(int* flowerbed, int flowerbedSize, int begin, int flag, int* n) {
	for (int l = begin + 2 * flag; l < flowerbedSize && l >= 0 && *n; l += flag) {
		if ((l >= 0 && l < flowerbedSize && flowerbed[l]) || (l >= 1 && flowerbed[l - 1]) || (l < flowerbedSize - 1 && flowerbed[l + 1])) {
			continue;
		}
		flowerbed[l] = 1;
		*n -= 1;
	}
}
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
	int begin = 0;
	for (int i = 0; i < flowerbedSize; i++) {
		if (flowerbed[i]) {
			begin = i;
			break;
		}
	}
	if (flowerbed[begin] == 0 && n) {
		flowerbed[begin] = 1;
		n -= 1;
	}
	plant(flowerbed, flowerbedSize, begin, -1, &n);
	plant(flowerbed, flowerbedSize, begin, 1, &n);
	return n == 0;
}