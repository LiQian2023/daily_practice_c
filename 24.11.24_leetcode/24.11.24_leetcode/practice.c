#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.11.24力扣网刷题
//点名——位运算、数组、哈希表、数学、二分查找——简单
//某班级 n 位同学的学号为 0 ~n - 1。点名结果记录于升序数组 records。假定仅有一位同学缺席，请返回他的学号。
//示例 1:
//输入: records = [0, 1, 2, 3, 5]
//输出 : 4
//示例 2 :
//输入 : records = [0, 1, 2, 3, 4, 5, 6, 8]
//输出 : 7
//提示：
//1 <= records.length <= 10000

//方法一：数组
int takeAttendance(int* records, int recordsSize) {
	int ans = 0;
	for (int i = 0; i < recordsSize; i++) {
		if (ans != records[i])
			break;
		ans += 1;
	}
	return ans;
}

//方法二：二分查找
int takeAttendance(int* records, int recordsSize) {
	int l = 0, r = recordsSize - 1;
	while (l <= r) {
		int m = (r - l) / 2 + l;
		if (records[m] != m) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return l;
}

//方法三：位运算
int takeAttendance(int* records, int recordsSize) {
	int i = 0;
	for (; i < recordsSize; i++) {
		records[i] ^= i;
		if (records[i]) {
			break;
		}
	}
	return i;
}

//方法四：数学
int takeAttendance(int* records, int recordsSize) {
	int sum = recordsSize * (recordsSize + 1) / 2;
	for (int i = 0; i < recordsSize; i++) {
		sum -= records[i];
	}
	return sum;
}

//方法五：哈希表
int takeAttendance(int* records, int recordsSize) {
	int* hash = (int*)calloc(recordsSize + 1, sizeof(int));
	assert(hash);
	for (int i = 0; i < recordsSize; i++) {
		int key = records[i];
		hash[key] += 1;
	}
	int ans = 0;
	for (ans = 0; ans < recordsSize + 1; ans++) {
		if (!hash[ans])
			break;
	}
	free(hash);
	return ans;
}