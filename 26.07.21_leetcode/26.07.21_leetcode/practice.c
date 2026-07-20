#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2026.07.21力扣网刷题
//3992. 重新排列字符串以避免字符对——中级工程师、第187场双周赛——简单
//给你一个字符串 s 和两个 不同 的小写英文字母 x 和 y。
//重新排列 s 中的字符来构造一个新的字符串 t，使得：
//t 是 s 的一个 排列。
//在 t 中，所有 y 都必须在所有 x 之前。
//返回 任意 一个有效的字符串 t。
//排列 是对一个字符串中所有字符的重新排列。
//示例 1：
//输入： s = "aabc", x = "a", y = "c"
//输出： "cbaa"
//解释：
//字符串 "cbaa" 是 "aabc" 的一个排列，且每次出现的 'c' 都在每次出现的 'a' 之前。
//示例 2：
//输入： s = "dcab", x = "d", y = "b"
//输出： "cabd"
//解释：
//字符串 "cabd" 是 "dcab" 的一个排列，且每次出现的 'b' 都在每次出现的 'd' 之前。
//示例 3：
//输入： s = "axe", x = "o", y = "x"
//输出： "axe"
//解释：
//字符串 "axe" 已经有效。因为 'o' 没有在字符串中出现，所以自动满足要求的条件。
//提示：
//1 <= s.length <= 100
//s 仅由小写英文字母组成。
//x 和 y 都是小写英文字母。
//x != y


char* rearrangeString1(char* s, char x, char y) {
    int n = strlen(s);
    char hash[26] = { 0 };
    for (int i = 0; s[i]; i++) {
        int key = s[i] - 'a';
        hash[key] += 1;
    }
    char* ans = (char*)calloc(n + 1, sizeof(char));
    assert(ans);
    int size = 0;
    int key = y - 'a';
    while (size < n && hash[key]) {
        ans[size++] = y;
        hash[key] -= 1;
    }
    key = x - 'a';
    while (size < n && hash[key]) {
        ans[size++] = x;
        hash[key] -= 1;
    }
    for (int i = 0; i < 26; i++) {
        while (size < n && hash[i]) {
            ans[size++] = i + 'a';
            hash[i] -= 1;
        }
    }
    return ans;
}

char* rearrangeString(char* s, char x, char y) {
    int count_x = 0, n = strlen(s);
    char* ans = (char*)calloc(n + 1, sizeof(char));
    assert(ans);
    int size = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == x) {
            count_x += 1;
        }
        else {
            ans[size++] = s[i];
        }
    }
    while (count_x) {
        ans[size++] = x;
        count_x -= 1;
    }
    return ans;
}