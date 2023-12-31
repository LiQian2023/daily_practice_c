#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.31力扣网刷题
//一年中的第几天——数学、字符串——简单
//给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。返回该日期是当年的第几天。
//示例 1：
//输入：date = "2019-01-09"
//输出：9
//解释：给定日期是2019年的第九天。
//示例 2：
//输入：date = "2019-02-10"
//输出：41
//提示：
//date.length == 10
//date[4] == date[7] == '-'，其他的 date[i] 都是数字
//date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日

int dayOfYear(char* date) {
	int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
	int month= (date[5] - '0') * 10 + (date[6] - '0');
	int day = (date[8] - '0') * 10 + (date[9] - '0');
	int days = 0;
	int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < month - 1; i++)
	{
		days += Month[i];
	}
	if (((year % 4 == 0 && year % 100 != 0) ||( year % 400 == 0)) &&month>2) {
		days += 1;
	}
	days += day;
	return days;
}
int main()
{
	char date[11] = { 0 };
	while (scanf("%s", date) == 1) {
		int ret = dayOfYear(date);
		printf("%d\n", ret);
	}
	return 0;
}