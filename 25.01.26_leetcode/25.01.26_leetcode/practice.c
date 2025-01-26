#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
//2025.01.26力扣网刷题
//拼写单词——数组、哈希表、字符串、计数——简单
//给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。
//假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。
//注意：每次拼写（指拼写词汇表中的一个单词）时，chars 中的每个字母都只能用一次。
//返回词汇表 words 中你掌握的所有单词的 长度之和。
//示例 1：
//输入：words = ["cat", "bt", "hat", "tree"], chars = "atach"
//输出：6
//解释：
//可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
//示例 2：
//输入：words = ["hello", "world", "leetcode"], chars = "welldonehoneyr"
//输出：10
//解释：
//可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
//提示：
//1 <= words.length <= 1000
//1 <= words[i].length, chars.length <= 100
//所有字符串中都仅包含小写英文字母

int countCharacters(char** words, int wordsSize, char* chars) {
    char ch[26] = { 0 };
    for (int i = 0; chars[i]; i++) {
        int key = chars[i] - 'a';
        ch[key] += 1;
    }
    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        char tmp[26] = { 0 };
        for (int j = 0; j < 26; j++) {
            tmp[j] = ch[j];
        }
        bool flag = true;
        for (int j = 0; words[i][j]; j++) {
            int key = words[i][j] - 'a';
            if (tmp[key] == 0) {
                flag = false;
                break;
            }
            tmp[key] -= 1;
        }
        if (flag) {
            ans += strlen(words[i]);
        }
    }
    return ans;
}