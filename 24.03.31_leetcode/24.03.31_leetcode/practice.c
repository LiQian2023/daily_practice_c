#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//2024.03.31力扣网刷题
//学生出勤记录 I——字符串——简单
//给你一个字符串 s 表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
//'A'：Absent，缺勤
//'L'：Late，迟到
//'P'：Present，到场
//如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
//按 总出勤 计，学生缺勤（'A'）严格 少于两天。
//学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
//如果学生可以获得出勤奖励，返回 true ；否则，返回 false 。
//示例 1：
//输入：s = "PPALLP"
//输出：true
//解释：学生缺勤次数少于 2 次，且不存在 3 天或以上的连续迟到记录。
//示例 2：
//输入：s = "PPALLL"
//输出：false
//解释：学生最后三天连续迟到，所以不满足出勤奖励的条件。
//提示：
//1 <= s.length <= 1000
//s[i] 为 'A'、'L' 或 'P'

bool checkRecord1(char* s) {
	int num_A = 0;
	int num_L = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] != 'L' && num_L)
			num_L = 0;
		if (s[i] == 'A')
			num_A++;
		else if (s[i] == 'L')
			num_L++;
		if (num_A == 2 || num_L == 3)
			return false;
	}
	return true;
}

bool checkRecord(char* s) {
	int num_A = 0;
	int num_L = 0;
	int l = 0, r = 1;
	while (s[l] && s[r]) {
		if (num_L == 2 && s[l] == 'L' || num_L == 1 && s[l] == s[r] && s[l] == 'L')
			return false;
		else if (num_L && s[l] != 'L')
			num_L = 0;
		if (s[l] == s[r] && s[l] == 'A')
			return false;
		else if (s[l] == 'A' || s[r] == 'A')
			num_A++;
		if (s[l] == s[r] && s[l] == 'L')
			num_L = 2;
		else if (s[r] == 'L')
			num_L = 1;
		l += 2, r += 2;
	}
	if (num_A >= 2)
		return false;
	if (num_L == 2 && s[l] == 'L')
		return false;
	return true;
}

int main() {
	char s[10] = { 0 };
	while (scanf("%s", s) == 1)
		printf("%d\n", checkRecord(s));
	return 0;
}