#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//2025.09.26力扣网刷题
//最大三角形面积——数组、数学、几何——简单
//给你一个由 X - Y 平面上的点组成的数组 points ，其中 points[i] = [xi, yi] 。
// 从其中取任意三个不同的点组成三角形，返回能组成的最大三角形的面积。
// 与真实值误差在 10 ^ - 5 内的答案将会视为正确答案。
//示例 1：
//输入：points = [[0, 0], [0, 1], [1, 0], [0, 2], [2, 0]]
//输出：2.00000
//解释：输入中的 5 个点如上图所示，红色的三角形面积最大。
//示例 2：
//输入：points = [[1, 0], [0, 0], [0, 1]]
//输出：0.50000
//提示：
//3 <= points.length <= 50
//- 50 <= xi, yi <= 50
//给出的所有点 互不相同
int get_max(int a, int b, int c) {
	if (a > b) {
		if (a > c) {
			return a;
		}
		return c;
	}
	if (b > c) {
		return b;
	}
	return c;
}
int get_min(int a, int b, int c) {
	if (a > b) {
		if (b > c) {
			return c;
		}
		return b;
	}
	if (a > c) {
		return c;
	}
	return a;
}
int get_mid(int a, int b, int c) {
	if (a > b) {
		if (b > c) {
			return b;
		}
		if (a > c) {
			return c;
		}
		return a;
	}
	if (a > c) {
		return a;
	}
	if (b > c) {
		return c;
	}
	return b;
}
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
	double ans = 0;
	for (int i = 0; i < pointsSize - 2; i++) {
		for (int j = i + 1; j < pointsSize - 1; j++) {
			for (int z = j + 1; z < pointsSize; z++) {
				int x1 = points[i][0];
				int x2 = points[j][0];
				int x3 = points[z][0];
				int y1 = points[i][1];
				int y2 = points[j][1];
				int y3 = points[z][1];
				double tmp = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) * 0.5;
				if (tmp - ans > 0.00001) {
					ans = tmp;
				}
			}
		}
	}
	return ans;
}