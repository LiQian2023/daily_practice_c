#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2025.02.06力扣网刷题
//转变日期格式——字符串——简单
//给你一个字符串 date ，它的格式为 Day Month Year ，其中：
//Day 是集合{ "1st", "2nd", "3rd", "4th", ..., "30th", "31st" } 中的一个元素。
//Month 是集合{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" } 中的一个元素。
//Year 的范围在 ​[1900, 2100] 之间。
//请你将字符串转变为 YYYY - MM - DD 的格式，其中：
//YYYY 表示 4 位的年份。
//MM 表示 2 位的月份。
//DD 表示 2 位的天数。
//示例 1：
//输入：date = "20th Oct 2052"
//输出："2052-10-20"
//示例 2：
//输入：date = "6th Jun 1933"
//输出："1933-06-06"
//示例 3：
//输入：date = "26th May 1960"
//输出："1960-05-26"
//提示：
//给定日期保证是合法的，所以不需要处理异常输入。

void int_to_str(char* tmp, int x) {
	int i = 1;
	while (i >= 0) {
		tmp[i] = x % 10 + '0';
		x /= 10;
		i -= 1;
	}
}

char* reformatDate(char* date) {
	char* months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	char* days[31] = { "1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", "19th", "20th", "21st", "22nd", "23rd", "24th", "25th", "26th", "27th", "28th", "29th", "30th", "31st" };
	char* dates[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		if (i == 0)
			dates[i] = strtok(date, " ");
		else
			dates[i] = strtok(NULL, " ");
	}
	int key_mon = 0;
	while (strcmp(months[key_mon], dates[1])) {
		key_mon += 1;
	}
	int key_day = 0;
	while (strcmp(days[key_day], dates[0])) {
		key_day += 1;
	}
	char* ans = (char*)calloc(11, sizeof(char));
	assert(ans);
	strcat(ans, dates[2]);
	strcat(ans, "-");
	char tmp[3] = { 0 };
	int_to_str(tmp, key_mon + 1);
	strcat(ans, tmp);
	strcat(ans, "-");
	int_to_str(tmp, key_day + 1);
	strcat(ans, tmp);
	return ans;
}