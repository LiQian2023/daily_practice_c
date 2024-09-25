#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
//2024.09.25力扣网刷题
//字母异位词分组——数组、哈希表、字符串、排序——中等
//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
//示例 1:
//输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出 : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
//示例 2 :
//输入 : strs = [""]
//输出 : [[""]]
//示例 3 :
//输入 : strs = ["a"]
//输出 : [["a"]]
//提示：
//1 <= strs.length <= 10^4
//0 <= strs[i].length <= 100
//strs[i] 仅包含小写字母

bool strCmp(char* s1, char* s2) {
	if (strlen(s1) != strlen(s2)) {
		return false;
	}
	char ch[26] = { 0 };
	//记录串1
	for (int i = 0; s1[i]; i++) {
		ch[s1[i] - 'a'] += 1;
	}
	//记录串2
	for (int i = 0; s2[i]; i++) {
		ch[s2[i] - 'a'] -= 1;
	}
	//查表
	for (int i = 0; i < 26; i++) {
		if (ch[i])
			return false;
	}
	return true;
}
//方法一：暴力求解
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
	//申请空间
	int base1 = strsSize;//初始空间大小
	char*** ans = (char***)calloc(base1, sizeof(char**));
	assert(ans);
	*returnColumnSizes = (int*)calloc(base1, sizeof(int));
	assert(*returnColumnSizes);
	*returnSize = 0;
	//查找
	for (int i = 0; i < strsSize; i++) {
		if (strs[i] == NULL)
			continue;
		//申请空间
		int base2 = 10;//每组异位词初始空间大小
		ans[*returnSize] = (char**)calloc(base2, sizeof(char*));
		assert(ans[*returnSize]);
		int size = 0;//元素下标
		//记录首元素
		ans[*returnSize][size] = strs[i];
		(*returnColumnSizes)[*returnSize] = 1;
		//寻找异位词
		for (int j = i + 1; j < strsSize; j++) {
			if (strs[j] == NULL)
				continue;
			bool flag = strCmp(strs[i], strs[j]);
			//相同
			if (flag) {
				size += 1;
				//扩容
				if (size == base2) {
					base2 += 10;
					char** tmp = (char**)realloc(ans[*returnSize], base2 * sizeof(char*));
					assert(tmp);
					ans[*returnSize] = tmp;
				}
				//记录
				ans[*returnSize][size] = strs[j];
				(*returnColumnSizes)[*returnSize] += 1;
				//删除
				strs[j] = NULL;
			}
		}
		*returnSize += 1;
		//扩容
		if (*returnSize == base1) {
			base1 += 10;
			char*** tmp = (char***)realloc(ans, base1 * sizeof(char**));
			assert(tmp);
			ans = tmp;
			int* tmp2 = (int*)realloc(*returnColumnSizes, base1 * sizeof(int));
			assert(tmp2);
			*returnColumnSizes = tmp2;
		}
	}
	return ans;
}

//方法二：哈希表+排序
typedef struct Hash {
	int len;
	char sort[101];
	char value[101];
}Hash;
int str_cmp(const void* p1, const void* p2) {
	return *(char*)p1 - *(char*)p2;
}
int hash_cmp(const void* p1, const void* p2) {
	Hash* a = (Hash*)p1;
	Hash* b = (Hash*)p2;
	if (a->len != b->len) {
		return a->len - b->len;
	}
	return strcmp(a->sort, b->sort);
}
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
	Hash* h = (Hash*)calloc(strsSize, sizeof(Hash));
	assert(h);
	//记录元素
	for (int i = 0; i < strsSize; i++) {
		int len = strlen(strs[i]);
		memcpy(h[i].value, strs[i], len);
		h[i].len = len;
		memcpy(h[i].sort, strs[i], len);
		qsort(h[i].sort, len, sizeof(char), str_cmp);
	}
	//元素排序
	qsort(h, strsSize, sizeof(Hash), hash_cmp);
	//合并
	char*** ans = (char***)calloc(strsSize, sizeof(char**));
	assert(ans);
	*returnColumnSizes = (int*)calloc(strsSize, sizeof(int));
	assert(*returnColumnSizes);
	*returnSize = 0;
	(*returnColumnSizes)[*returnSize] = 0;
	int base = 10;//初始异位词个数
	ans[*returnSize] = (char**)calloc(base, sizeof(char*));
	assert(ans[*returnSize]);
	for (int i = 0; i < strsSize; i++) {
		//记录首元素与异位词
		if (i == 0|| strcmp(h[i].sort, h[i - 1].sort) == 0) {
			//异位词个数==初始个数，扩容
			if ((*returnColumnSizes)[*returnSize] == base) {
				base += 10;
				char** tmp = (char**)realloc(ans[*returnSize], base * sizeof(char*));
				assert(tmp);
				ans[*returnSize] = tmp;
			}
			ans[*returnSize][(*returnColumnSizes)[*returnSize]] = (char*)calloc(h[i].len + 1, sizeof(char));
			assert(ans[*returnSize][(*returnColumnSizes)[*returnSize]]);
			memcpy(ans[*returnSize][(*returnColumnSizes)[*returnSize]], h[i].value, h[i].len + 1);
			(*returnColumnSizes)[*returnSize] += 1;
		}
		//记录非异位词
		else {
			*returnSize += 1;//分区编号
			base = 10;//初始异位词个数
			//申请空间
			ans[*returnSize] = (char**)calloc(base, sizeof(char*));
			assert(ans[*returnSize]);
			(*returnColumnSizes)[*returnSize] = 0;//元素编号
			ans[*returnSize][(*returnColumnSizes)[*returnSize]] = (char*)calloc(h[i].len + 1, sizeof(char));
			assert(ans[*returnSize][(*returnColumnSizes)[*returnSize]]);
			memcpy(ans[*returnSize][(*returnColumnSizes)[*returnSize]], h[i].value, h[i].len + 1);
			(*returnColumnSizes)[*returnSize] += 1;
		}
	}
	*returnSize += 1;
	free(h);
	return ans;
}