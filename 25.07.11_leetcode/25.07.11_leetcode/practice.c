#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2025.07.11力扣网刷题
//Bigram 分词——字符串——简单
//给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。
//对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。
//示例 1：
//输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
//输出：["girl", "student"]
//示例 2：
//输入：text = "we will we will rock you", first = "we", second = "will"
//输出：["we", "rock"]
//提示：
//1 <= text.length <= 1000
//text 由小写英文字母和空格组成
//text 中的所有单词之间都由 单个空格字符 分隔
//1 <= first.length, second.length <= 10
//first 和 second 由小写英文字母组成
//text 不包含任何前缀或尾随空格。

char** findOcurrences(char* text, char* first, char* second, int* returnSize) {
	int len = strlen(text);
	*returnSize = 0;
	int* pi = (int*)calloc(len / 2, sizeof(int));
	assert(pi);
	for (int i = 0, j = 0; text[j] && text[i];) {
		while (text[j] && text[j] != ' ') {
			j += 1;
		}
		if (text[j] && strncmp(text + i, first, j - i) == 0) {
			int secend_begin = j + 1;
			int secend_end = secend_begin;
			while (text[secend_end] && text[secend_end] != ' ') {
				secend_end += 1;
			}
			if (text[secend_end] && strncmp(text + secend_begin, second, secend_end - secend_begin) == 0) {
				int third_begin = secend_end + 1;
				if (text[third_begin]) {
					pi[*returnSize] = third_begin;
					*returnSize += 1;
				}
			}
		}
		if (!text[j]) {
			break;
		}
		i = j + 1;
		j = i;
	}
	char** ans = (char**)calloc(*returnSize, sizeof(char*));
	assert(ans);
	for (int i = 0; i < *returnSize; i++) {
		int begin = pi[i], end = pi[i];
		while (text[end] && text[end] != ' ') {
			end += 1;
		}
		ans[i] = (char*)calloc(end - begin + 1, sizeof(char));
		assert(ans[i]);
		strncpy(ans[i], text + begin, end - begin);
	}
	free(pi);
	pi = NULL;
	return ans;
}