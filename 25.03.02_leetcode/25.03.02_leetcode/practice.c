#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//2025.03.02力扣网刷题
//统计出现过一次的公共字符串——数组、哈希表、字符串、计数——简单
//给你两个字符串数组 words1 和 words2 ，请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。
//示例 1：
//输入：words1 = ["leetcode", "is", "amazing", "as", "is"], words2 = ["amazing", "leetcode", "is"]
//输出：2
//解释：
//- "leetcode" 在两个数组中都恰好出现一次，计入答案。
//- "amazing" 在两个数组中都恰好出现一次，计入答案。
//- "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
//- "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
//所以，有 2 个字符串在两个数组中都恰好出现了一次。
//示例 2：
//输入：words1 = ["b", "bb", "bbb"], words2 = ["a", "aa", "aaa"]
//输出：0
//解释：没有字符串在两个数组中都恰好出现一次。
//示例 3：
//输入：words1 = ["a", "ab"], words2 = ["a", "a", "a", "ab"]
//输出：1
//解释：唯一在两个数组中都出现一次的字符串是 "ab" 。
//提示：
//1 <= words1.length, words2.length <= 1000
//1 <= words1[i].length, words2[j].length <= 30
//words1[i] 和 words2[j] 都只包含小写英文字母。

typedef struct HashNode {
	char* str;//值
	int count[2];//计数
	struct HashNode* next;//头指针
}HN;

typedef struct Hash {
	HN* hash;
}Hash;

void Print(Hash* h) {
	for (int i = 0; i < 26; i++) {
		if (h->hash[i].count[0] > 1) {
			HN* head = h->hash[i].next;

		}
	}
}
Hash* CreateHash() {
	//创建哈希指针
	Hash* h = (Hash*)calloc(1, sizeof(Hash));
	assert(h);
	//创建哈希表
	h->hash = (HN*)calloc(26, sizeof(HN));
	assert(h->hash);
	for (int i = 0; i < 26; i++) {
		//创建头结点
		HN* head = (HN*)calloc(1, sizeof(HN));
		assert(head);
		//后插插入头结点
		head->next = h->hash[i].next;
		h->hash[i].next = head;
		h->hash[i].count[0] = 1;
	}
	return h;
}

void Destroy(Hash** h) {
	for (int i = 0; i < 26; i++) {
		HN* head = (*h)->hash[i].next;
		HN* p = head->next;
		while (p) {
			//删除结点
			head->next = p->next;
			p->next = NULL;
			//释放结点字符串空间
			free(p->str);
			p->str = NULL;
			//释放结点空间
			free(p);
			p = head->next;
		}
		//释放头结点空间
		free(head);
		head = NULL;
	}
	//释放哈希表空间
	free((*h)->hash);
	(*h)->hash = NULL;
	//释放指针空间
	free(*h);
	*h = NULL;
}
void Insert(Hash* h, char* str, int key, int side) {
	h->hash[key].count[0] += 1;//计数
	HN* l = h->hash[key].next;//前驱指针
	HN* r = l->next;//当前指针
	//遍历链表
	while (r && strcmp(r->str, str)) {
		l = r;
		r = l->next;
	}
	//未找到该字符串
	if (!r) {
		//申请结点空间
		r = (HN*)calloc(1, sizeof(HN));
		assert(r);
		//申请字符串空间
		r->str = (char*)calloc(strlen(str) + 1, sizeof(char));
		assert(r->str);
		//拷贝字符串
		strcpy(r->str, str);
		//字符串计数
		r->count[side] = 1;
		//插入结点
		r->next = l->next;
		l->next = r;
	}
	else {
		//字符串计数
		r->count[side] += 1;
	}
}
void Record(Hash* h, char** words, int len, int side) {
	for (int i = 0; i < len; i++) {
		int key = words[i][0] - 'a';
		Insert(h, words[i], key, side);
	}
}
int Search(Hash* h) {
	int ret = 0;
	for (int i = 0; i < 26; i++) {
		if (h->hash[i].count[0] > 1) {
			HN* head = h->hash[i].next;
			HN* p = head->next;
			while (p) {
				if (p->count[0] == 1 && p->count[0] == p->count[1]) {
					ret += 1;
				}
				p = p->next;
			}
		}
	}
	return ret;
}
int countWords(char** words1, int words1Size, char** words2, int words2Size) {
	Hash* h = CreateHash();
	Record(h, words1, words1Size, 0);
	Record(h, words2, words2Size, 1);
	int ans = Search(h);
	Destroy(&h);
	return ans;
}