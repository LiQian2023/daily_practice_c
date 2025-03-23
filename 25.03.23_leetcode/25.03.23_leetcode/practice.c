#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.03.23力扣网刷题
//判断一个括号字符串是否有效——栈、贪心、字符串——中等
//一个括号字符串是只由 '(' 和 ')' 组成的 非空 字符串。如果一个字符串满足下面 任意 一个条件，那么它就是有效的：
//字符串为().
//它可以表示为 AB（A 与 B 连接），其中A 和 B 都是有效括号字符串。
//它可以表示为(A) ，其中 A 是一个有效括号字符串。
//给你一个括号字符串 s 和一个字符串 locked ，两者长度都为 n 。locked 是一个二进制字符串，只包含 '0' 和 '1' 。对于 locked 中 每一个 下标 i ：
//如果 locked[i] 是 '1' ，你 不能 改变 s[i] 。
//如果 locked[i] 是 '0' ，你 可以 将 s[i] 变为 '(' 或者 ')' 。
//如果你可以将 s 变为有效括号字符串，请你返回 true ，否则返回 false 。
//示例 1：
//输入：s = "))()))", locked = "010100"
//输出：true
//解释：locked[1] == '1' 和 locked[3] == '1' ，所以我们无法改变 s[1] 或者 s[3] 。
//我们可以将 s[0] 和 s[4] 变为 '(' ，不改变 s[2] 和 s[5] ，使 s 变为有效字符串。
//示例 2：
//输入：s = "()()", locked = "0000"
//输出：true
//解释：我们不需要做任何改变，因为 s 已经是有效字符串了。
//示例 3：
//输入：s = ")", locked = "0"
//输出：false
//解释：locked 允许改变 s[0] 。
//但无论将 s[0] 变为 '(' 或者 ')' 都无法使 s 变为有效字符串。
//示例 4：
//输入：s = "(((())(((())", locked = "111111010111"
//输出：true
//解释：locked 允许我们改变 s[6] 和 s[8]。
//我们将 s[6] 和 s[8] 改为 ')' 使 s 变为有效字符串。
//提示：
//n == s.length == locked.length
//1 <= n <= 10^5
//s[i] 要么是 '(' 要么是 ')' 。
//locked[i] 要么是 '0' 要么是 '1' 。

bool Need_Push(char* s, int* stack, int i, int top) {
    // 栈为空
    bool flag1 = top == 0;
    bool flag2 = false;
    bool flag3 = false;
    // 匹配失败
    if (!flag1) {
        // 新元素与栈顶元素相等
        flag2 = s[stack[top - 1]] == s[i];
        // 栈顶为左括号，新元素为右括号
        flag3 = s[stack[top - 1]] == ')' && s[i] == '(';
    }
    return flag1 || flag2 || flag3;
}

bool canBeValid1(char* s, char* locked) {
    int len = strlen(s);
    int* stack1 = (int*)calloc(len, sizeof(int));
    assert(stack1);
    int top1 = 0;
    int* stack2 = (int*)calloc(len, sizeof(int));
    assert(stack2);
    int top2 = 0;
    for (int i = 0; i < len; i++) {
        // 不可变
        if (locked[i] == '1') {
            if (Need_Push(s, stack1, i, top1)) {
                stack1[top1] = i;
                top1 += 1;
            }
            else {
                top1 -= 1;
            }
        }
        // 可变
        else {
            stack2[top2] = i;
            top2 += 1;
        }
    }
    int n = 0;
    while (top1 && top2) {
        printf("top1 = %d\ttop2 = %d\n", top1, top2);
        int key1 = stack1[top1 - 1], key2 = stack2[top2 - 1];
        printf("s[%d] = %c\ts[%d] = %c\n", key1, s[key1], key2, s[key2]);
        // 不可变栈，栈顶为左括号，可变栈栈顶元素位于不可变栈左侧
        bool flag1 = s[key1] == ')' && key2 < key1;
        // 不可变栈，栈顶为右括号，可变栈栈顶元素位于右侧
        bool flag2 = s[key1] == '(' && key2 > key1;
        // 匹配成功
        if (flag1 || flag2) {
            top1 -= 1;
        }
        else {
            // 记录可变栈中元素未与不可变栈中元素匹配成功的个数
            n += 1;
        }
        top2 -= 1;
    }
    free(stack1);
    free(stack2);
    n += top2;
    return top1 == 0 && n % 2 == 0;
}
//方法二：数学
bool canBeValid(char* s, char* locked) {
    int len = strlen(s);
    int top1 = 0, top2 = 0;
    for (int i = 0; i < len; i++) {
        if (locked[i] == '1') {
            int diff = 0;
            if (s[i] == '(') {
                diff = 1;
            }
            else {
                diff = -1;
            }
            top1 += diff;
            top2 = fmax(top2 + diff, (i + 1) % 2);
        }
        else {
            top1 += 1;
            top2 = fmax(top2 - 1, (i + 1) % 2);
        }
        if (top1 < top2) {
            return false;
        }
    }
    return !top2;
}
char s1[] = ")(()))((()((((()))()((()()()))(|()()()((()))()(())()()|)";
char s2[] = "0000000000000000000000000000000|1111111111111111111111|1";
char s3[] = ")(()))((()((((()))()((()()()))(";