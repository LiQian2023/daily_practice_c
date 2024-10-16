#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//2024.10.16力扣网刷题
//最小时间差——数组、数学、字符串、排序——中等
//给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
//示例 1：
//输入：timePoints = ["23:59", "00:00"]
//输出：1
//示例 2：
//输入：timePoints = ["00:00", "23:59", "00:00"]
//输出：0
//提示：
//2 <= timePoints.length <= 2 * 10^4
//timePoints[i] 格式为 "HH:MM"

int cmp(const void** p1, const void** p2) {
	return strcmp(*(char**)p1, *(char**)p2);
}

void str_to_int(int* tmp1, int* tmp2, char* a, char* b) {
	for (int i = 0; i < 2; i++) {
		*tmp1 *= 10;
		*tmp1 += a[i] - '0';
		*tmp2 *= 10;
		*tmp2 += b[i] - '0';
	}
}
int get_ans(char* a, char* b) {
	int h = 0, tmp1 = 0, tmp2 = 0;
	int m = 0, tmp3 = 0, tmp4 = 0;
	//获取时差
	str_to_int(&tmp1, &tmp2, a, b);
	//获取分差
	str_to_int(&tmp3, &tmp4, a + 3, b + 3);
	//时差大于12小时
	if (abs(tmp2 - tmp1) > 12) {
		h = 24 - abs(tmp2 - tmp1);
	}
	else {
		h = abs(tmp2 - tmp1);
	}
	if ((abs(tmp2 - tmp1) > 12 && tmp4 - tmp3 < 0) || (abs(tmp2 - tmp1) <= 12 && tmp2 - tmp1 < 0 && tmp4 - tmp3 > 0) || (abs(tmp2 - tmp1) <= 12 && tmp2 - tmp1 > 0 && tmp4 - tmp3 < 0)) {
		h -= 1;
		m = 60 - abs(tmp4 - tmp3);
	}
	else {
		m = abs(tmp4 - tmp3);
	}
	return h * 60 + m;
}
int findMinDifference(char** timePoints, int timePointsSize) {
	qsort(timePoints, timePointsSize, sizeof(char*), cmp);
	int min = get_ans(timePoints[timePointsSize - 1], timePoints[0]);
	for (int i = 1; i < timePointsSize; i++) {
		int tmp = get_ans(timePoints[i - 1], timePoints[i]);
		if (tmp < min)
			min = tmp;
	}
	return min;
}

void test() {
	char str1[6] = "05:31";
	char str2[6] = "22:08";
	char str3[6] = "00:35";
	char* time[3] = { str1,str2,str3 };
	int size = 3;
	printf("%d\n", findMinDifference(time, size));
}

int main() {
	test();
	return 0;
}