#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2026.08.24力扣网刷题
//4030. 判断 ASCII 值回文——中级工程师、第516场周赛——简单
//给你一个由小写英文字母组成的字符串 s。
//将 s 中的每个字符替换为其 ASCII 值对应的 8 位二进制表示，包括前导零，并保持字符原有顺序，从而构造一个二进制字符串。
//如果得到的二进制字符串是一个 回文串 ，则返回 true；否则返回 false。
//二进制字符串 是指仅由字符 '0' 和 '1' 组成的字符串。
//回文串 是指正着读和反着读都相同的字符串。
//示例 1：
//输入： s = "ff"
//输出： true
//解释：
//字符 f 的 ASCII 值为 102，其 8 位二进制表示为 01100110。
//因此，得到的二进制字符串为 0110011001100110。
//由于该二进制字符串是一个 回文串 ，因此输出为 true。
//示例 2：
//输入： s = "leet"
//输出： false
//解释：
//字符 l、e、e 和 t 的 ASCII 值分别为 108、101、101 和 116 。
//它们对应的 8 位二进制表示分别为 01101100、01100101、01100101 和 01110100。
//因此，得到的二进制字符串为 01101100011001010110010101110100。
//由于该二进制字符串不是一个 回文串 ，因此输出为 false。
//提示：
//1 <= s.length <= 100
//s 仅由小写英文字母组成。

void Int_to_Bi(int x, char* tmp, int* begin) {
    for (int i = *begin + 7; i >= *begin && x; i--) {
        tmp[i] = x % 2;
        x /= 2;
    }
    *begin += 8;
}
bool isPalindromic(char* s) {
    int len = strlen(s), size = len * 8;
    char* tmp = (char*)calloc(size + 1, sizeof(char));
    assert(tmp);
    int top = 0;
    for (int i = 0; i < len; i++) {
        Int_to_Bi(s[i], tmp, &top);
    }
    bool ans = true;
    for (int l = 0, r = top - 1; l < r; l++, r--) {
        if (tmp[l] != tmp[r]) {
            ans = false;
            break;
        }
    }
    free(tmp);
    return ans;
}