#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//2024.08.07力扣网刷题
//使每位学生都有座位的最少移动次数——贪心、数组、排序——简单
//一个房间里有 n 个 空闲 座位和 n 名 站着的 学生，房间用一个数轴表示。
//给你一个长度为 n 的数组 seats ，其中 seats[i] 是第 i 个座位的位置。
//同时给你一个长度为 n 的数组 students ，其中 students[j] 是第 j 位学生的位置。
//你可以执行以下操作任意次：
//增加或者减少第 i 位学生的位置，每次变化量为 1 （也就是将第 i 位学生从位置 x 移动到 x + 1 或者 x - 1）
//请你返回使所有学生都有座位坐的 最少移动次数 ，并确保没有两位学生的座位相同。
//请注意，初始时有可能有多个座位或者多位学生在 同一 位置。
//示例 1：
//输入：seats = [3, 1, 5], students = [2, 7, 4]
//输出：4
//解释：学生移动方式如下：
//- 第一位学生从位置 2 移动到位置 1 ，移动 1 次。
//- 第二位学生从位置 7 移动到位置 5 ，移动 2 次。
//- 第三位学生从位置 4 移动到位置 3 ，移动 1 次。
//总共 1 + 2 + 1 = 4 次移动。
//示例 2：
//输入：seats = [4, 1, 5, 9], students = [1, 3, 2, 6]
//输出：7
//解释：学生移动方式如下：
//- 第一位学生不移动。
//- 第二位学生从位置 3 移动到位置 4 ，移动 1 次。
//- 第三位学生从位置 2 移动到位置 5 ，移动 3 次。
//- 第四位学生从位置 6 移动到位置 9 ，移动 3 次。
//总共 0 + 1 + 3 + 3 = 7 次移动。
//示例 3：
//输入：seats = [2, 2, 6, 6], students = [1, 3, 2, 6]
//输出：4
//解释：学生移动方式如下：
//- 第一位学生从位置 1 移动到位置 2 ，移动 1 次。
//- 第二位学生从位置 3 移动到位置 6 ，移动 3 次。
//- 第三位学生不移动。
//- 第四位学生不移动。
//总共 1 + 3 + 0 + 0 = 4 次移动。
//提示：
//n == seats.length == students.length
//1 <= n <= 100
//1 <= seats[i], students[j] <= 100

//方法一：qsort排序
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
	qsort(seats, seatsSize, sizeof(int), cmp);
	qsort(students, studentsSize, sizeof(int), cmp);
	int ans = 0;
	for (int i = 0; i < seatsSize; i++) {
		ans += abs(seats[i] - students[i]);
	}
	return ans;
}