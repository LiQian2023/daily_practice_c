#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//2024.12.31力扣网刷题
//有效的回旋镖——几何、数组、数学——简单
//给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X - Y 平面上的一个点，如果这些点构成一个 回旋镖 则返回 true 。
//回旋镖 定义为一组三个点，这些点 各不相同 且 不在一条直线上 。
//示例 1：
//输入：points = [[1, 1], [2, 3], [3, 2]]
//输出：true
//示例 2：
//输入：points = [[1, 1], [2, 2], [3, 3]]
//输出：false
//提示：
//points.length == 3
//points[i].length == 2
//0 <= xi, yi <= 100

bool isBoomerang(int** points, int pointsSize, int* pointsColSize) {
	int x1 = points[0][0], y1 = points[0][1];
	int x2 = points[1][0], y2 = points[1][1];
	int x3 = points[2][0], y3 = points[2][1];
	if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
		return false;
	if ((x1 == x2 && y1 != y2 && y1 == y3) || (x1 == x3 && y1 != y3 && y1 == y2) ||
		(x2 == x1 && y2 != y1 && y2 == y3) || (x2 == x3 && y2 != y3 && y2 == y1) ||
		(x3 == x1 && y3 != y1 && y3 == y2) || (x3 == x2 && y3 != y2 && y3 == y1))
		return true;
	float k1 = 0.0f, k2 = 0.0f;
	if (x2 - x1) {
		k1 = 1.0 * (y2 - y1) / (x2 - x1);
	}
	if (x3 - x1) {
		k2 = 1.0 * (y3 - y1) / (x3 - x1);
	}
	return k1 - k2;
}