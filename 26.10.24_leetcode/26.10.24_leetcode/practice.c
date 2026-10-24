#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2026.10.24力扣网刷题
//2409. 统计共同度过的日子数——中级工程师、数学、字符串、第87场双周赛——简单
//Alice 和 Bob 计划分别去罗马开会。
//给你四个字符串 arriveAlice ，leaveAlice ，arriveBob 和 leaveBob 。Alice 会在日期 arriveAlice 到 leaveAlice 之间在城市里（日期为闭区间），而 Bob 在日期 arriveBob 到 leaveBob 之间在城市里（日期为闭区间）。每个字符串都包含 5 个字符，格式为 "MM-DD" ，对应着一个日期的月和日。
//请你返回 Alice和 Bob 同时在罗马的天数。
//你可以假设所有日期都在 同一个 自然年，而且 不是 闰年。每个月份的天数分别为：[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] 。
//示例 1：
//输入：arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
//输出：3
//解释：Alice 从 8 月 15 号到 8 月 18 号在罗马。Bob 从 8 月 16 号到 8 月 19 号在罗马，他们同时在罗马的日期为 8 月 16、17 和 18 号。所以答案为 3 。
//示例 2：
//输入：arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
//输出：0
//解释：Alice 和 Bob 没有同时在罗马的日子，所以我们返回 0 。
//提示：
//所有日期的格式均为 "MM-DD" 。
//Alice 和 Bob 的到达日期都 早于或等于 他们的离开日期。
//题目测试用例所给出的日期均为 非闰年 的有效日期。
void str_to_int(char* str, int* ops) {
	int month = (str[0] - '0') * 10 + (str[1] - '0');
	int day = (str[3] - '0') * 10 + (str[4] - '0');
	ops[0] = month, ops[1] = day;
}
int getDays(int* ops1, int* ops2, int* months) {
	int days = 0;
	if (ops2[0] > ops1[0]) {
		days += months[ops1[0] - 1] - ops1[1] + 1;
		for (int i = ops1[0] + 1; i < ops2[0]; i++) {
			days += months[i - 1];
		}
		days += ops2[1];
	}
	else {
		days += ops2[1] - ops1[1] + 1;
	}
	return days;
}
int countDaysTogether1(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int ops1[2] = { 0, 0 }, ops2[2] = { 0,0 }, ops3[2] = { 0, 0 }, ops4[2] = { 0, 0 };
	str_to_int(arriveAlice, ops1);
	str_to_int(leaveAlice, ops2);
	str_to_int(arriveBob, ops3);
	str_to_int(leaveBob, ops4);
	// ops3[0] <= ops2[0] && ops1[0] <= ops4[0]
	int flag1 = strcmp(arriveAlice, arriveBob),
		flag2 = strcmp(leaveAlice, leaveBob),
		flag3 = strcmp(arriveAlice, leaveBob),
		flag4 = strcmp(arriveBob, leaveAlice);
	if (flag4 > 0 || flag3 > 0) {
		return 0;
	}
	if (flag1 >= 0 && flag2 <= 0) {
		return getDays(ops1, ops2, months);
	}
	if (flag1 <= 0 && flag2 >= 0) {
		return getDays(ops3, ops4, months);
	}
	if (flag1 >= 0 && flag2>=0) {
		return getDays(ops1, ops4, months);
	}
	return getDays(ops3, ops2, months);
}

int getDay(char* date) {
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int month = (date[0] - '0') * 10 + (date[1] - '0');
	int day = (date[3] - '0') * 10 + (date[4] - '0');
	for (int i = 0; i < month - 1; i++) {
		day += months[i];
	}
	return day;
}

int countDaysTogether2(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
	int begin1 = getDay(arriveAlice), end1 = getDay(leaveAlice),
		begin2 = getDay(arriveBob), end2 = getDay(leaveBob);
	if (begin1 > end2 || begin2 > end1) {
		return 0;
	}
	if (begin1 >= begin2) {
		if (end1 <= end2) {
			return end1 - begin1 + 1;
		}
		else {
			return end2 - begin1 + 1;
		}
	}
	if (end2 <= end1) {
		return end2 - begin2 + 1;
	}
	return end1 - begin2 + 1;
}

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
	int begin1 = getDay(arriveAlice), end1 = getDay(leaveAlice),
		begin2 = getDay(arriveBob), end2 = getDay(leaveBob);
	int maxBegin = begin1 > begin2 ? begin1 : begin2;
	int minEnd = end1 < end2 ? end1 : end2;
	int ans = minEnd - maxBegin + 1;
	return ans >= 0 ? ans : 0;
}