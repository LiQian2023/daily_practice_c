#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2025.02.09力扣网刷题
//字符串中不同整数的数目——哈希表、字符串——简单
//给你一个字符串 word ，该字符串由数字和小写英文字母组成。
//请你用空格替换每个不是数字的字符。例如，"a123bc34d8ef34" 将会变成 " 123  34 8  34" 。注意，剩下的这些整数为（相邻彼此至少有一个空格隔开）："123"、"34"、"8" 和 "34" 。
//返回对 word 完成替换后形成的 不同 整数的数目。
//只有当两个整数的 不含前导零 的十进制表示不同， 才认为这两个整数也不同。
//示例 1：
//输入：word = "a123bc34d8ef34"
//输出：3
//解释：不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
//示例 2：
//输入：word = "leet1234code234"
//输出：2
//示例 3：
//输入：word = "a1b01c001"
//输出：1
//解释："1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
//提示：
//1 <= word.length <= 1000
//word 由数字和小写英文字母组成

typedef struct LinkNode {
	char* num;
}LN;

typedef struct Hash {
	LN* head;
	int count;
}Hash;

Hash* CreateHash(int size) {
	Hash* h = (Hash*)calloc(1, sizeof(Hash));
	assert(h);
	h->head = (LN*)calloc(size, sizeof(LN));
	assert(h->head);
	h->count = 0;
	return h;
}
bool SearchSame(Hash* h, char* str, int* begin) {
	int size = h->count;
	while (str[*begin] == '0') {
		*begin += 1;
	}
	for (int i = 0; size && i < size; i++) {
		if (strcmp((h->head)[i].num, str + *begin) == 0) {
			return false;
		}
	}
	return true;
}
void Destroy(Hash* h) {
	int size = h->count;
	for (int i = 0; i < size; i++) {
		free((h->head)[i].num);
	}
	free(h->head);
}
int numDifferentIntegers(char* word) {
	int len = strlen(word);
	Hash* h = CreateHash(len);
	for (int i = 0, j = 0; j < len; j++) {
		if (word[j] >= '0' && word[j] <= '9') {
			i = j;
			while (word[j] >= '0' && word[j] <= '9') {
				j += 1;
			}
			int size = j - i;
			char* tmp = (char*)calloc(size + 1, sizeof(char));
			assert(tmp);
			strncpy(tmp, word + i, size);
			int begin = 0;
			if (SearchSame(h, tmp, &begin)) {
				int key = h->count;
				(h->head)[key].num = (char*)calloc(size + 1, sizeof(char));
				assert((h->head)[key].num);
				strncpy((h->head)[key].num, tmp + begin, size);
				h->count += 1;
			}
			free(tmp);
		}
	}
	int ans = h->count;
	Destroy(h);
	free(h);
	return ans;
}