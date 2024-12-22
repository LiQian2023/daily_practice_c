#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//2024.12.22力扣网刷题
//统计共同度过的日子数——数学、字符串——简单
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

void Get_date(char* date,int* ans) {
	int month = 0;
	for (int i = 0; i < 2; i++) {
		month *= 10;
		month += date[i] - '0';
	}
	int day = 0;
	for (int i = 3; i < 5; i++) {
		day *= 10;
		day += date[i] - '0';
	}
	ans[0] = month;
	ans[1] = day;
}
int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//获取日期
	int arrive_date1[2] = { 0,0 };
	Get_date(arriveAlice, arrive_date1);
	int leave_date1[2] = { 0,0 };
	Get_date(leaveAlice, leave_date1);
	int arrive_date2[2] = { 0,0 };
	Get_date(arriveBob, arrive_date2);
	int leave_date2[2] = { 0,0 };
	Get_date(leaveBob, leave_date2);
	//其中一人到达之前，另一人已经离开
	if (arrive_date2[0] > leave_date1[0] || 
		arrive_date1[0] > leave_date2[0] || 
		(arrive_date1[0] == leave_date2[0] && arrive_date1[1] > leave_date2[1]) || 
		(arrive_date2[0] == leave_date1[0] && arrive_date2[1] > leave_date1[1]))
		return 0;
	//共同度过的日子的月份开始日期从最晚到达的人的月份开始计算
	int begin_month = arrive_date1[0] <= arrive_date2[0] ? arrive_date2[0] : arrive_date1[0];
	int begin_day = arrive_date1[0] <= arrive_date2[0] ? arrive_date2[1] : arrive_date1[1];
	//处理同一月到达
	if (arrive_date1[0] == arrive_date2[0]) {
		begin_day = arrive_date1[1] > arrive_date2[1] ? arrive_date1[1] : arrive_date2[1];
	}
	//共同度过的日子的月份结束日期从最早离开的人的月份开始计算
	int end_month = leave_date1[0] <= leave_date2[0] ? leave_date1[0]: leave_date2[0];
	int end_day = leave_date1[0] <= leave_date2[0] ? leave_date1[1]: leave_date2[1];
	//处理同一月离开
	if (leave_date1[0] == leave_date2[0]) {
		end_day = leave_date1[1] < leave_date2[1] ? leave_date1[1] : leave_date2[1];
	}
	int ans = 0;
	//获取月份
	if (end_month - begin_month) {
		for (int i = begin_month; i < end_month; i++) {
			if (i == begin_month) {
				ans += months[i] - begin_day + 1;
			}
			else {
				ans += months[i];
			}
		}
		ans += end_day;
	}
	else {
		ans += end_day - begin_day + 1;
	}
	return ans;
}