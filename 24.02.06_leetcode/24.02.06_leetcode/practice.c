#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"


//2024.02.06力扣网刷题
//缀点成线——几何、数组、数学——简单
//给定一个数组 coordinates ，其中 coordinates[i] = [x, y] ， [x, y] 表示横坐标为 x、纵坐标为 y 的点。请你来判断，这些点是否在该坐标系中属于同一条直线上。
//示例 1：
//输入：coordinates = [[1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7]]
//输出：true
//示例 2：
//输入：coordinates = [[1, 1], [2, 2], [3, 4], [4, 5], [5, 6], [7, 7]]
//输出：false
//提示：
//2 <= coordinates.length <= 1000
//coordinates[i].length == 2
//- 10 ^ 4 <= coordinates[i][0], coordinates[i][1] <= 10 ^ 4
//coordinates 中不含重复的点

//方法一：求斜率——y=kx+c;带入值
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
	double k = 0, c = 0;
	int x = 0, y = 0;
	if (coordinates[0][0] == coordinates[1][0] && coordinates[0][1] != coordinates[1][1]) {
		k = 0;
		x = 1;//与y轴平行
	}
	else if (coordinates[0][0] != coordinates[1][0] && coordinates[0][1] == coordinates[1][1]) {
		k = 0;
		y = 1;//与x轴平行
	}
	else if (coordinates[0][0] == 0 && coordinates[0][1] == 0) {
		//过原点
		k = coordinates[0][1] / coordinates[0][0];
		c = 0;
	}
	else {
		//不过原点
		k = ((coordinates[0][1] - coordinates[1][1]) * 1.0) / (coordinates[0][0] - coordinates[1][0]);//求斜率
		c = coordinates[0][1] - (k * coordinates[0][0]);//求常数
	}
	for (int i = 2; i < coordinatesSize; i++) {
		//与y轴平行，x相等
		if (x) {
			if (coordinates[i][0] != coordinates[i - 1][0])
				return false;
		}
		//与x轴平行，y相等
		else if (y) {
			if (coordinates[i][1] != coordinates[i - 1][1])
				return false;
		}
		else if (coordinates[i][1] * 1.0 != k * coordinates[i][0] + c)
			return false;
	}
	return true;
}

void test1() {
	int arr[1000][2] = { 0 };
	int m = 0;
	while (scanf("%d", &m) == 1) {
		int* pa[1000] = { 0 };
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &arr[i][0], &arr[i][1]);
			pa[i] = arr[i];
		}
		if (checkStraightLine(pa, m, 2)) {
			printf("true\n");
		}
		else
			printf("false\n");
	}
}