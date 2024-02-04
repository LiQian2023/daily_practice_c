#define _CRT_SECURE_NO_WARNINGS 1

#include "pratice.h"

//2024.02.05力扣网刷题
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

typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}StackNode,*LinkStack;
//链栈初始化
void InitStack(LinkStack* S) {
	*S = NULL;//不带头结点的链栈
}
//链栈的入栈
bool Push(LinkStack* S,int x) {
	if (!S) {
		perror("Push():S");
		return false;
	}
	StackNode* p = (StackNode*)calloc(1, sizeof(StackNode));
	if (!p) {
		perror("Push():calloc()");
		return false;
	}
	p->data = x;
	p->next = *S;
	*S = p;
	return true;
}
//链栈的出栈
bool Pop(LinkStack* S, int* x) {
	if (!S || !x) {
		perror("Pop():S||x");
		return false;
	}
	if (!(*S))
		return false;
	StackNode* p = *S;
	*x = p->data;
	*S = (*S)->next;
	free(p);
	return true;
}
//查找栈顶元素
bool GetTop(LinkStack S, int* x) {
	if (!x) {
		perror("GetTop():x");
		return false;
	}
	*x = S->data;
	return true;
}
int calPoints(char** operations, int operationsSize) {
	LinkStack S = { 0 };
	InitStack(&S);
	int sum = 0;
	for (int i = 0; i < operationsSize; i++) {
		if (isdigit(operations[i][0])) {
			int x = 0;
			for (int j = 0; operations[i][j]; j++) {
				x = x * 10 + operations[i][j] - '0';
			}
			Push(&S, x);
		}
		else if (operations[i][0] == 'C') {
			if (i >= 1) {
				int x = 0;
				Pop(&S, &x);
			}
		}
		else if (operations[i][0] == 'D') {
			int x = 0;
			GetTop(S, &x);
			Push(&S, 2 * x);
		}
		else if (operations[i][0] == '+') {
			int x1 = 0;
			Pop(&S, &x1);
			int x2 = 0;
			GetTop(S, &x2);
			Push(&S, x1);
			Push(&S, x1 + x2);
		}
		else if (operations[i][0] == '-') {
			int x = 0;
			for (int j = 1; operations[i][j]; j++) {
				x = x * 10 + operations[i][j] - '0';
			}
			Push(&S, -x);
		}
	}
	int x = 0;
	while (Pop(&S, &x)) {
		sum += x;
	}
	return sum;
}

void test1() {
	char ch1[1000][6] = { 0 };
	char* ch[1000] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			scanf("%s", ch1[i]);
			ch[i] = &ch1[i];
		}
		int ret = calPoints(ch, n);
		printf("%d\n", ret);
	}
}
