#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.10.15力扣网刷题
//三角形的最大高度——数组、枚举——简单
//给你两个整数 red 和 blue，分别表示红色球和蓝色球的数量。
// 你需要使用这些球来组成一个三角形，
// 满足第 1 行有 1 个球，
// 第 2 行有 2 个球，
// 第 3 行有 3 个球，
// 依此类推。
//每一行的球必须是 相同 颜色，且相邻行的颜色必须 不同。
//返回可以实现的三角形的 最大 高度。
//示例 1：
//输入： red = 2, blue = 4
//输出： 3
//解释：
//上图显示了唯一可能的排列方式。
//示例 2：
//输入： red = 2, blue = 1
//输出： 2
//解释：
//上图显示了唯一可能的排列方式。
//示例 3：
//输入： red = 1, blue = 1
//输出： 1
//示例 4：
//输入： red = 10, blue = 1
//输出： 2
//解释：
//上图显示了唯一可能的排列方式。
//提示：
//1 <= red, blue <= 100


int maxHeightOfTriangle(int red, int blue) {
	int k1 = red;
	int k2 = blue;
	int h1 = 0;
	int h2 = 0;
	for (h1; k1 > h1 || k2 > h1 + 1;) {
		if (k1 < h1 + 1)
			break;
		h1 += 1;
		k1 -= h1;
		if (k2 < h1 + 1)
			break;
		h1 += 1;
		k2 -= h1;
	}
	k1 = blue;
	k2 = red;
	for (h2; k1 > h2 || k2 > h2 + 1;) {
		if (k1 < h2 + 1)
			break;
		h2 += 1;
		k1 -= h2;
		if (k2 < h2 + 1)
			break;
		h2 += 1;
		k2 -= h2;
	}
	return h1 > h2 ? h1 : h2;
}

void test() {
	int red = 9;
	int blue = 3;
	printf("%d\n", maxHeightOfTriangle(red, blue));
}

int main() {
	test();
	return 0;
}