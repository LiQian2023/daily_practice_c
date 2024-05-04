#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.05.04力扣网刷题
//日期之间隔几天——数学、字符串——简单
//请你编写一个程序来计算两个日期之间隔了多少天。
//日期以字符串形式给出，格式为 YYYY - MM - DD，如示例所示。
//示例 1：
//输入：date1 = "2019-06-29", date2 = "2019-06-30"
//输出：1
//示例 2：
//输入：date1 = "2020-01-15", date2 = "2019-12-31"
//输出：15
//提示：
//给定的日期是 1971 年到 2100 年之间的有效日期。
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int Leap_year(int year) {
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int Leap(int year1, int year2) {
	int count = 0;
	for (int i = year2; i < year1;) {
		if (Leap_year(i)) {
			count++;
			i += 4;
		}
		else
			i++;
	}
	return count;
}
void char_to_int(char* date,int* year,int* month,int* day) {
	//获取年
	for (int i = 0; i < 4; i++) 
		*year = *year * 10 + date[i] - '0';
	//获取月
	for (int i = 5; i < 7; i++) 
		*month = *month * 10 + date[i] - '0';
	//获取日
	for (int i = 8; i < 10; i++) 
		*day = *day * 10 + date[i] - '0';
}
int Months(int* month, int month1, int month2) {
	int months = 0;
	months = month1 - month2 - 1 + 12;
	int ans = 0;
	for (int i = 0; i < months; i++) {
		ans += month[month2 - 1];
		month2 = (month2 + 1) % 12;
	}
	return ans;
}
int daysBetweenDates(char* date1, char* date2) {
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year1 = 0, year2 = 0;
	int month1 = 0, month2 = 0;
	int day1 = 0, day2 = 0;
	int ans = 0;
	char_to_int(date1, &year1, &month1, &day1);
	char_to_int(date2, &year2, &month2, &day2);
	//确保1的年份更大
	if (year1 < year2) {
		Swap(&year1, &year2);
		Swap(&month1, &month2);
		Swap(&day1, &day2);
	}
	//获取这两年的闰年情况
	int leap1 = Leap_year(year1);
	int leap2 = Leap_year(year2);
	for (int i = year2; i < year1 - 1; i++)
		ans += 365;//记录到前一年
	//在同一年中
	if (year1 - year2 == 0) {
		if (leap1)//大年为闰年
			month[1]++;
		int max = month1 > month2 ? month1 : month2;
		int min = month1 > month2 ? month2 : month1;
		for (int i = min - 1; i < max - 1; i++)
			ans += month[i];
		ans += day1 - day2 > 0 ? day1 - day2 : day2 - day1;
	}
	else {
		//闰年的数量
		int leap = Leap(year1, year2);
		int months = month1 - month2 + 12;
		int days = day1 - day2;
		if (days < 0)
		{
			days += month[(month1 - 1 + 11) % 12];
			months--;
		}
		ans += days;
		int m = month2 - 1;
		for (int i = 0; i < months; i++) {
			ans += month[m];
			m = (m + 1) % 12;
		}
		if (month1 > 2)
			ans += leap1;
		if (month2 > 2 && leap2)
			leap--;
		ans += leap;
	}
	return ans;
}

void test() {
	char ch1[11] = { 0 };
	char ch2[11] = { 0 };
	while (scanf("%s%s", ch1, ch2) == 2)
		printf("%d\n", daysBetweenDates(ch1, ch2));
}

int main() {
	test();
	return 0;
}