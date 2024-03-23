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


//计算有效括号的个数
#define MAXSIZE 10
int ValidParenthesesnumber(char* s) {
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

//最长有效括号
#define MAXSIZE 10
int longestValidParentheses(char* s) {
	char S[MAXSIZE] = { 0 };//数据域
	int i = 0;//指针域——栈顶指针
	int count = 0;//计数器
	int front = 0;//记录归零前一次的有效括号个数
	int max = 0;//记录最大值
	for (int j = 0; s[j]; j++) //遍历原字符串
	{
		if (s[j] == '(')//遇到左括号
		{
			S[i++] = s[j];//进行入栈操作
			front = count;//记录归零前的括号个数
			count = 0;//计数器归零
			if (front > max)
				max = front;
		}
		else {
			if (i)//当i不为0时，说明栈非空，此时有与之相匹配的左括号
			{
				count++;//匹配成功，正常计数
				S[--i] = 0;//进行出栈操作
				if (i == 0)//当匹配完后栈为空栈，说明前后的括号是连续的
					count += front;//当前的括号数应为归零前后括号数相加
				else //当匹配完后栈为非空栈，说明归零前后括号间是断开的
				{
					max = count > front ? count : front;//记录下最大值
				}
			}
		}
	}
	if (i == 0)//当扫描结束后，栈为空栈
		max += count;//将归零前的有效括号个数与归零后的有效括号个数相加
	return 2 * max;
}

//最长有效括号——栈
int longestValidParentheses1(char* s) {
	int len = strlen(s);//计算当前字符串的长度——可要可不要
	if (!len)//当长度为0时
		return 0;//此时我们就不需要其它操作了，可以直接返回0
	int* S = (int*)calloc(len + 1, sizeof(int));//创建顺序栈
	assert(S);//如果创建失败则打断程序的运行
	int i = 0;//指向栈顶元素的指针
	S[0] = -1;//将-1进行入栈
	int Length = 0;//记录当前有效括号的长度
	int max = 0;//记录有效括号长度的最大值
	//遍历字符串
	for (int j = 0; s[j]; j++) {
		if (s[j] == '(') //遇到左括号时
			S[++i] = j;//将左括号的下标进行入栈
		else if (s[j] == ')' && S[i] == -1)//当扫描的第一个元素为右括号时
			S[i] = j;//将-1出栈，并将此时的右括号下标进行入栈
		else if (s[j] == ')' && s[S[i]] != '(') //当扫描到右括号时栈顶元素存储的下标对应的元素与右括号不匹配时
			S[i] = j;//将当前栈顶存放的下标进行出栈，并将此时右括号的下标进行入栈
		else if (s[j] == ')' && s[S[i]] == '(')//当扫描到右括号时，栈顶元素存储的下标对应的元素与右括号相匹配
		{
			S[i--] = 0;//将栈顶元素出栈后移动栈顶指针
			Length = j - S[i];//将当前右括号的下标与当前的栈顶元素进行作差，得到有效括号的长度
			max = max > Length ? max : Length;//记录有效括号长度的最大值
		}
	}
	return max;
}

void test() {
	char s[MAXSIZE] = { 0 };
	while (scanf("%s", s) == 1) {
		printf("%d\n", longestValidParentheses(s));
	}
}

int main() {
	test();
	return 0;
}