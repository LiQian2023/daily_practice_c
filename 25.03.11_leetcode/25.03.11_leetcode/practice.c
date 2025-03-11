#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2025.03.11力扣网刷题
//差值数组不同的字符串——数组、哈希表、字符串——简单
//给你一个字符串数组 words ，每一个字符串长度都相同，令所有字符串的长度都为 n 。
//每个字符串 words[i] 可以被转化为一个长度为 n - 1 的 差值整数数组 difference[i] ，其中对于 0 <= j <= n - 2 有 difference[i][j] = words[i][j + 1] - words[i][j] 。
//注意两个字母的差值定义为它们在字母表中 位置 之差，也就是说 'a' 的位置是 0 ，'b' 的位置是 1 ，'z' 的位置是 25 。
//比方说，字符串 "acb" 的差值整数数组是[2 - 0, 1 - 2] = [2, -1] 。
//words 中所有字符串 除了一个字符串以外 ，其他字符串的差值整数数组都相同。你需要找到那个不同的字符串。
//请你返回 words中 差值整数数组 不同的字符串。
//示例 1：
//输入：words = ["adc", "wzy", "abc"]
//输出："abc"
//解释：
//- "adc" 的差值整数数组是[3 - 0, 2 - 3] = [3, -1] 。
//- "wzy" 的差值整数数组是[25 - 22, 24 - 25] = [3, -1] 。
//- "abc" 的差值整数数组是[1 - 0, 2 - 1] = [1, 1] 。
//不同的数组是[1, 1]，所以返回对应的字符串，"abc"。
//示例 2：
//输入：words = ["aaa", "bob", "ccc", "ddd"]
//输出："bob"
//解释：除了 "bob" 的差值整数数组是[13, -13] 以外，其他字符串的差值整数数组都是[0, 0] 。
//提示：
//3 <= words.length <= 100
//n == words[i].length
//2 <= n <= 20
//words[i] 只含有小写英文字母。

typedef struct Hash {
	int count;
	int* arr;
	int i;
}Hash;

void Print_num(int* num, int len) {
	printf("[");
	for (int i = 0; i < len; i++) {
		printf("%d\t", num[i]);
	}
	printf("]\n");
}
void Print_Hash(Hash* h, int* len) {
	for (int i = 0; i < 2; i++) {
		printf("h[%d].count = %d\n", i, h[i].count);
		printf("h[%d].arr = ", i);
		Print_num(h[i].arr, len[i] - 1);
	}
}

void Insert(Hash** h, int** num, int i, int* len, int key) {
	(*h)[key].count = 1;
	(*h)[key].arr = (int*)calloc(len[i] - 1, sizeof(int));
	assert((*h)[key].arr);
	memcpy((*h)[key].arr, num[i], (len[i] - 1) * sizeof(int));
	(*h)[key].i = i;
}
void Destroy(Hash** h, int*** num, int** len, int size) {
	for (int i = 0; i < 2; i++) {
		free((*h)[i].arr);
		(*h)[i].arr = NULL;
	}
	free(*h);
	*h = NULL;
	for (int i = 0; i < size; i++) {
		free((*num)[i]);
		(*num)[i] = NULL;
	}
	free(*num);
	*num = NULL;
	free(*len);
	*len = NULL;
}
char* oddString(char** words, int wordsSize) {
	int** num = (int**)calloc(wordsSize, sizeof(int*));
	int* len = (int*)calloc(wordsSize, sizeof(int));
	for (int i = 0; i < wordsSize; i++) {
		len[i] = strlen(words[i]);
		num[i] = (int*)calloc(len[i] - 1, sizeof(int));
		assert(num[i]);
		for (int j = 0; j < len[i] - 1; j++) {
			num[i][j] = words[i][j + 1] - words[i][j];
		}
	}
	Hash* h = (Hash*)calloc(2, sizeof(Hash));
	assert(h);
	for (int i = 0; i < wordsSize; i++) {
		if (h[0].count == 0) {
			Insert(&h, num, i, len, 0);
		}
		else {
			if (memcmp(h[0].arr, num[i], (len[i] - 1) * sizeof(int))) {
				if (h[1].count == 0) {
					Insert(&h, num, i, len, 1);
				}
				else {
					h[1].count += 1;
				}
			}
			else {
				h[0].count += 1;
			}
		}
	}
	int pi = 0;
	for (int i = 0; i < 2; i++) {
		if (h[i].count == 1) {
			pi = h[i].i;
			break;
		}
	}
	Destroy(&h, &num, &len, wordsSize);
	return words[pi];
}