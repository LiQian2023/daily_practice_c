#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2025.03.06力扣网刷题
//判断路径是否相交——字符串、哈希表——简单
//给你一个字符串 path，其中 path[i] 的值可以是 'N'、'S'、'E' 或者 'W'，分别表示向北、向南、向东、向西移动一个单位。
//你从二维平面上的原点(0, 0) 处开始出发，按 path 所指示的路径行走。
//如果路径在任何位置上与自身相交，也就是走到之前已经走过的位置，请返回 true ；否则，返回 false 。
//示例 1：
//输入：path = "NES"
//输出：false
//解释：该路径没有在任何位置相交。
//示例 2：
//输入：path = "NESWW"
//输出：true
//解释：该路径经过原点两次。
//提示：
//1 <= path.length <= 10^4
//path[i] 为 'N'、'S'、'E' 或 'W'


typedef struct YNode {
	int count;
}Y;
typedef struct XNode {
	Y* y;
	int y_size;
}X;
typedef struct Hash {
	X* x;
	int x_size;
}Hash;

Hash* CreateHash(int x_size, int y_size) {
	Hash* h = (Hash*)calloc(1, sizeof(Hash));
	assert(h);
	h->x_size = x_size;
	h->x = (X*)calloc(x_size, sizeof(X));
	assert(h->x);
	for (int i = 0; i < x_size; i++) {
		h->x[i].y_size = y_size;
		h->x[i].y = (Y*)calloc(y_size, sizeof(Y));
		assert(h->x[i].y);
	}
	return h;
}

void Destroy(Hash** h) {
	for (int i = 0; i < (*h)->x_size; i++) {
		free((*h)->x[i].y);
		(*h)->x[i].y = NULL;
	}
	free((*h)->x);
	(*h)->x = NULL;
	free(*h);
	*h = NULL;
}

void Coordinate_Record(Hash* h, int x, int y, int* ans) {
	h->x[x].y[y].count += 1;//记录当前坐标
	if (h->x[x].y[y].count > 1) {
		*ans += 1;
	}
}
void Coordinate_Move(int* x, int* y, char dir) {
	switch (dir) {
	case 'N':
		*y += 1;
		break;
	case 'E':
		*x += 1;
		break;
	case'S':
		*y -= 1;
		break;
	case 'W':
		*x -= 1;
		break;
	default:
		break;
	}
}
void Get_Size(int val, int* max, int* min) {
	if (val > *max) {
		*max = val;
	}
	else if (val < *min) {
		*min = val;
	}
}
bool isPathCrossing(char* path) {
	int x_max = 0, x_min = 0;
	int y_max = 0, y_min = 0;
	int x = 0, y = 0;
	for (int i = 0; path[i]; i++) {
		Coordinate_Move(&x, &y, path[i]);
		Get_Size(x, &x_max, &x_min);
		Get_Size(y, &y_max, &y_min);
	}
	int x_size = x_max - x_min + 1;
	int y_size = y_max - y_min + 1;
	printf("x_size = %d\ty_size = %d\n", x_size, y_size);
	Hash* h = CreateHash(x_size, y_size);
	x = 0 - x_min, y = 0 - y_min;
	int ans = 0;
	for (int i = 0; ans == 0; i++) {
		printf("x = %d\ty = %d\n", x, y);
		Coordinate_Record(h, x, y, &ans);
		if (path[i] == 0) {
			break;
		}
		Coordinate_Move(&x, &y, path[i]);//坐标移动
	}
	Destroy(&h);
	return ans;
}