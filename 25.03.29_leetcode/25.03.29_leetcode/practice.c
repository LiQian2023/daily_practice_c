#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2025.03.29力扣网刷题
//山羊拉丁文——字符串——简单
//给你一个由若干单词组成的句子 sentence ，单词间由空格分隔。每个单词仅由大写和小写英文字母组成。
//请你将句子转换为 “山羊拉丁文（Goat Latin）”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。山羊拉丁文的规则如下：
//如果单词以元音开头（'a', 'e', 'i', 'o', 'u'），在单词后添加"ma"。
//例如，单词 "apple" 变为 "applema" 。
//如果单词以辅音字母开头（即，非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
//例如，单词 "goat" 变为 "oatgma" 。
//根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从 1 开始。
//例如，在第一个单词后添加 "a" ，在第二个单词后添加 "aa" ，以此类推。
//返回将 sentence 转换为山羊拉丁文后的句子。
//示例 1：
//输入：sentence = "I speak Goat Latin"
//输出："Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
//示例 2：
//输入：sentence = "The quick brown fox jumped over the lazy dog"
//输出："heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
//提示：
//1 <= sentence.length <= 150
//sentence 由英文字母和空格组成
//sentence 不含前导或尾随空格
//sentence 中的所有单词由单个空格分隔
int GetNum(char* sentence) {
    int n = 0;
    for (char* tmp = strtok(sentence, " "); tmp; tmp = strtok(NULL, " ")) {
        n += 1;
    }
    return n;
}
char* toGoatLatin(char* sentence) {
    int len = strlen(sentence); // 字符串长度
    char* copy = (char*)calloc(len + 1, sizeof(char));
    assert(copy);
    strcpy(copy, sentence);
    printf("copy = %s\n", copy);
    int num = GetNum(copy); // 单词数量
    free(copy);
    copy = NULL;
    int a_num = num * (num + 1) / 2; // 增加'a'的数量
    printf("a_num = %d\n", a_num);
    int space = num - 1; // 空格数量
    char* ans = (char*)calloc(len + num * 2 + a_num + space + 1, sizeof(char));
    assert(ans);
    int n = 1;
    printf("sentence = %s\n", sentence);
    for (char* tmp = strtok(sentence, " "); tmp; tmp = strtok(NULL, " ")) {
        int size = strlen(tmp);
        printf("size = %d\n", size);
        if (tmp[0] != 'a' && tmp[0] != 'e' && tmp[0] != 'i' && tmp[0] != 'o' &&
            tmp[0] != 'u' && tmp[0] != 'A' && tmp[0] != 'E' && tmp[0] != 'I' && tmp[0] != 'O' &&
            tmp[0] != 'U') {
            char ch = tmp[0];
            for (int j = 0; j < size - 1; j++) {
                tmp[j] = tmp[j + 1];
            }
            tmp[size - 1] = ch;
        }
        strcat(ans, tmp);
        char* suffix = (char*)calloc(2 + n + 1, sizeof(char));
        assert(suffix);
        suffix[0] = 'm';
        for (int j = 1; j < 2 + n; j++) {
            suffix[j] = 'a';
        }
        strcat(ans, suffix);
        free(suffix);
        suffix = NULL;
        n += 1;
        if (n <= num) {
            strcat(ans, " ");
        }
        printf("ans = %s\n", ans);
    }
    return ans;
}