#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

//2024.07.29力扣网刷题
//棒球比赛——栈、数组、模拟——简单
//你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。
//比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：
//整数 x - 表示本回合新获得分数 x
//"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
//"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
//"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
//请你返回记录中所有得分的总和。
//示例 1：
//输入：ops = ["5", "2", "C", "D", "+"]
//输出：30
//解释：
//"5" - 记录加 5 ，记录现在是[5]
//"2" - 记录加 2 ，记录现在是[5, 2]
//"C" - 使前一次得分的记录无效并将其移除，记录现在是[5].
//"D" - 记录加 2 * 5 = 10 ，记录现在是[5, 10].
//"+" - 记录加 5 + 10 = 15 ，记录现在是[5, 10, 15].
//所有得分的总和 5 + 10 + 15 = 30
//示例 2：
//输入：ops = ["5", "-2", "4", "C", "D", "9", "+", "+"]
//输出：27
//解释：
//"5" - 记录加 5 ，记录现在是[5]
//"-2" - 记录加 - 2 ，记录现在是[5, -2]
//"4" - 记录加 4 ，记录现在是[5, -2, 4]
//"C" - 使前一次得分的记录无效并将其移除，记录现在是[5, -2]
//"D" - 记录加 2 * -2 = -4 ，记录现在是[5, -2, -4]
//"9" - 记录加 9 ，记录现在是[5, -2, -4, 9]
//"+" - 记录加 - 4 + 9 = 5 ，记录现在是[5, -2, -4, 9, 5]
//"+" - 记录加 9 + 5 = 14 ，记录现在是[5, -2, -4, 9, 5, 14]
//所有得分的总和 5 + -2 + -4 + 9 + 5 + 14 = 27
//示例 3：
//输入：ops = ["1"]
//输出：1
//提示：
//1 <= ops.length <= 1000
//ops[i] 为 "C"、"D"、"+"，或者一个表示整数的字符串。整数范围是[-3 * 10^4, 3 * 10^4]
//对于 "+" 操作，题目数据保证记录此操作时前面总是存在两个有效的分数
//对于 "C" 和 "D" 操作，题目数据保证记录此操作时前面总是存在一个有效的分数

//方法一：模拟
int Chr_to_Int(char* s, int* flag) {
	int num = 0;
	for (int j = 0; s[j]; j++) {
		if (s[j] == '-') {
			*flag = -1;
		}
		else {
			num *= 10;
			num += s[j] - '0';
		}
	}
	return num;
}

int calPoints(char** operations, int operationsSize) {
	int Stack[1000] = { 0 };
	int top = -1;
	int flag = 1;
	int num = Chr_to_Int(operations[0], &flag);
	num *= flag;
	Stack[++top] = num;
	for (int i = 1; i < operationsSize; i++) {
		if (isdigit(operations[i][0]) || operations[i][0] == '-') {
			flag = 1;
			num = Chr_to_Int(operations[i], &flag);
			num *= flag;
			Stack[++top] = num;
		}
		else {
			switch (operations[i][0]) {
			case 'D':
				num = Stack[top];
				num *= 2;
				Stack[++top] = num;
				break;
			case 'C':
				top -= 1;
				break;
			case '+':
				num = Stack[top--];
				int sum = num + Stack[top];
				Stack[++top] = num;
				Stack[++top] = sum;
				break;
			default:
				break;
			}
		}
	}
	int ans = 0;
	while (top > -1) {
		ans += Stack[top--];
	}
	return ans;
}

void test() {
	char* ops[10] = { "5","-2","4","C","D","9","+","+" };
	int len = 8;
	printf("%d\n", calPoints(ops, len));
}

int main() {
	test();
	return 0;
}