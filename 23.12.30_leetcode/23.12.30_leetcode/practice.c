#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
//2023.12.30力扣网刷题
//一周中的第几天——数学——简单
//给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。
//输入为三个整数：day、month 和 year，分别表示日、月、年。
//您返回的结果必须是这几个值中的一个{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" }。
//示例 1：
//输入：day = 31, month = 8, year = 2019
//输出："Saturday"
//示例 2：
//输入：day = 18, month = 7, year = 1999
//输出："Sunday"
//示例 3：
//输入：day = 15, month = 8, year = 1993
//输出："Sunday"
//提示：
//给出的日期一定是在 1971 到 2100 年之间的有效日期。

int isLeepYear(int year)
{
	int sum = 0;
	for (int i = 1971; i < year; i++)
	{
		if ((0 == i % 4 && 0 != i % 100) || (0 == i % 400))
			sum++;
	}
	return sum;
}
int Sum_month(int month)
{
	int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;
	for (int i = 0; i < month - 1; i++)
		sum += Month[i];
	return sum;
}
bool isleep(int year)
{
	if ((0 == year % 4 && 0 != year % 100) || (0 == year % 400))
		return true;
	else
		return false;
}
char* dayOfTheWeek(int day, int month, int year) {
	char* week[7] = {  "Thursday","Friday", "Saturday","Sunday", "Monday", "Tuesday", "Wednesday"};//1971年第一个七天
	int leep = isLeepYear(year);
	int months = Sum_month(month);
	int years = year - 1971;
	int days = day + months + 365 * years + leep;
	if (isleep(year))
	{
		if (month > 2)
			days += 1;
	}
	int i = days % 7;
	return week[i];
}
int main()
{
	int d = 0, m = 0, y = 0;
	while (scanf("%d%d%d", &d, &m, &y) == 3)
	{
		char* ret = dayOfTheWeek(d, m, y);
		printf("%s\n", ret);
	}
	return 0;
}