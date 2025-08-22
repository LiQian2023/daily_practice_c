#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//2025.08.22力扣网刷题
//强密码检验器 II——字符串、第80场双周赛——简单
//如果一个密码满足以下所有条件，我们称它是一个 强 密码：
//它有至少 8 个字符。
//至少包含 一个小写英文 字母。
//至少包含 一个大写英文 字母。
//至少包含 一个数字 。
//至少包含 一个特殊字符 。特殊字符为："!@#$%^&*()-+" 中的一个。
//它 不 包含 2 个连续相同的字符（比方说 "aab" 不符合该条件，但是 "aba" 符合该条件）。
//给你一个字符串 password ，如果它是一个 强 密码，返回 true，否则返回 false 。
//示例 1：
//输入：password = "IloveLe3tcode!"
//输出：true
//解释：密码满足所有的要求，所以我们返回 true 。
//示例 2：
//输入：password = "Me+You--IsMyDream"
//输出：false
//解释：密码不包含数字，且包含 2 个连续相同的字符。所以我们返回 false 。
//示例 3：
//输入：password = "1aB!"
//输出：false
//解释：密码不符合长度要求。所以我们返回 false 。
//提示：
//1 <= password.length <= 100
//password 包含字母，数字和 "!@#$%^&*()-+" 这些特殊字符。
bool ispecial(char ch) {
	char* str = "!@#$%^&*()-+";
	for (int i = 0; str[i]; i++) {
		if (ch == str[i]) {
			return true;
		}
	}
	return false;
}
bool strongPasswordCheckerII(char* password) {
	int up = 0, low = 0, sp = 0, dig = 0, size = 0;
	for (int i = 0; password[i]; i++) {
		if (i && password[i] == password[i - 1]) {
			return false;
		}
		if (isdigit(password[i])) {
			dig += 1;
		}
		else if (islower(password[i])) {
			low += 1;
		}
		else if (isupper(password[i])) {
			up += 1;
		}
		else if (ispecial(password[i])) {
			sp += 1;
		}
		size += 1;
	}
	return up && low && sp && dig && size >= 8;
}