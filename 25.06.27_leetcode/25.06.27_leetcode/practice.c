#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
//2025.06.27力扣网刷题
//数组中的字符串匹配——数组、字符串、字符串匹配——简单
//给你一个字符串数组 words ，数组中的每个字符串都可以看作是一个单词。请你按 任意 顺序返回 words 中是其他单词的 子字符串 的所有单词。
//示例 1：
//输入：words = ["mass", "as", "hero", "superhero"]
//输出：["as", "hero"]
//解释："as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
//["hero", "as"] 也是有效的答案。
//示例 2：
//输入：words = ["leetcode", "et", "code"]
//输出：["et", "code"]
//解释："et" 和 "code" 都是 "leetcode" 的子字符串。
//示例 3：
//输入：words = ["blue", "green", "bu"]
//输出：[]
//提示：
//1 <= words.length <= 100
//1 <= words[i].length <= 30
//words[i] 仅包含小写英文字母。
//题目数据 保证 words 的每个字符串都是独一无二的。

bool str_index(char* s, char* p) {
    int i = 0, j = 0, z = 0;
    for (; s[i] && p[j];) {
        if (s[i] == p[j]) {
            i += 1;
            j += 1;
        }
        else {
            i = z + 1;
            z += 1;
            j = 0;
        }
    }
    return !p[j];
}
int str_cmp(const void* p1, const void* p2) {
    char* str1 = *(char**)p1, * str2 = *(char**)p2;
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 > len2) {
        return -1;
    }
    else if (len1 < len2) {
        return 1;
    }
    return 0;
}
void Print(char** words, int len) {
    for (int i = 0; i < len; i++) {
        printf("%s,\t", words[i]);
    }
    printf("\n");
}
bool in_ans(char** ans, char* p, int len) {
    for (int i = 0; i < len; i++) {
        if (strcmp(ans[i], p) == 0) {
            return true;
        }
    }
    return false;
}
char** stringMatching(char** words, int wordsSize, int* returnSize) {
    qsort(words, wordsSize, sizeof(char*), str_cmp);
    Print(words, wordsSize);
    char** ans = (char**)calloc(wordsSize, sizeof(char*));
    assert(ans);
    *returnSize = 0;
    for (int i = 0; i < wordsSize - 1;) {
        int sorce = i;
        bool flag = false;
        int len1 = strlen(words[i]);
        for (int j = i + 1; j < wordsSize; j++) {
            int len2 = strlen(words[j]);
            if (str_index(words[i], words[j])) {
                if (!in_ans(ans, words[j], *returnSize)) {
                    ans[*returnSize] = (char*)calloc(len2 + 1, sizeof(char));
                    assert(ans[*returnSize]);
                    strncpy(ans[*returnSize], words[j], len2);
                    *returnSize += 1;
                }
            }
            else {
                flag = true;
                if (sorce == i) {
                    sorce = j;
                }
                else {
                    sorce = fmin(sorce, j);
                }
            }
        }
        if (!flag) {
            break;
        }
        i = sorce;
    }
    return ans;
}