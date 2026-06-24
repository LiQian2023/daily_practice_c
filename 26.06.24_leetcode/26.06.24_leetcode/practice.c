#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.06.24力扣网刷题
//20. 有效的括号——栈、字符串——简单
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
//示例 1：
//输入：s = "()"
//输出：true
//示例 2：
//输入：s = "()[]{}"
//输出：true
//示例 3：
//输入：s = "(]"
//输出：false
//示例 4：
//输入：s = "([])"
//输出：true
//示例 5：
//输入：s = "([)]"
//输出：false
//提示：
//1 <= s.length <= 10^4
//s 仅由括号 '()[]{}' 组成

bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)calloc(len, sizeof(char));
    assert(stack);
    int top = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[top++] = s[i];
        }
        else {
            if (top == 0) {
                top += 1;
                break;
            }
            char ch = stack[top - 1];
            bool flag1 = (ch == '[' && s[i] == ']'),
                flag2 = (ch == '{' && s[i] == '}'),
                flag3 = (ch == '(' && s[i] == ')');
            if (!flag1 && !flag2 && !flag3) {
                break;
            }
            top -= 1;
        }
    }
    free(stack);
    return top == 0;
}