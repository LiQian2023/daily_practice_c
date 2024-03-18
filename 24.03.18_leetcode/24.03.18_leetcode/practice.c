#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.03.18力扣网刷题
//最长有效括号——栈、字符串、动态规划——困难
//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
//示例 1：
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
//示例 2：
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
//示例 3：
//输入：s = ""
//输出：0
//提示：
//0 <= s.length <= 3 * 10^4
//s[i] 为 '(' 或 ')'

#define MAXSIZE 30000
int longestValidParentheses(char* s) {
	char S[MAXSIZE] = { 0 };//数据域
	int i = 0;//指针域——栈顶指针
	int count = 0;//计数器
	int max = 0;//记录最大值
	for (int j = 0; s[j]; j++) //遍历原字符串
	{
		if (s[j] == '(')//遇到左括号
			S[i++] = s[j];//进行入栈操作
		else {
			if (i)//当i不为0时，说明栈非空，此时有与之相匹配的左括号
			{
				count++;//匹配成功，正常计数
				S[--i] = 0;//进行出栈操作
			}
		}
	}
	return 2 * count;
}