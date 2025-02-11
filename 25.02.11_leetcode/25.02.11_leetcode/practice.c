#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2025.02.11力扣网刷题
//两句话中的不常见单词——哈希表、字符串、计数——简单
//句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。
//如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现 ，那么这个单词就是 不常见的 。
//给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按 任意顺序 组织。
//示例 1：
//输入：s1 = "this apple is sweet", s2 = "this apple is sour"
//输出：["sweet", "sour"]
//示例 2：
//输入：s1 = "apple apple", s2 = "banana"
//输出：["banana"]
//提示：
//1 <= s1.length, s2.length <= 200
//s1 和 s2 由小写英文字母和空格组成
//s1 和 s2 都不含前导或尾随空格
//s1 和 s2 中的所有单词间均由单个空格分隔

typedef struct LinkNode {
	int count;//单词出现次数
	char* str;//单词
	int size;
	struct LinkNode* next;
}LN;

typedef struct Hash {
	LN* list;//链表头指针
}Hash;
LN* CreateList() {
	LN* head = (LN*)calloc(1, sizeof(LN));
	assert(head);
	return head;
}
Hash* CreateHash() {
	Hash* h = (Hash*)calloc(1, sizeof(Hash));
	assert(h);
	h->list = (LN*)calloc(26, sizeof(LN));
	assert(h->list);
	for (int i = 0; i < 26; i++) {
		(h->list)[i].count = 0;//链表中单词总数
		(h->list)[i].str = NULL;//头结点不存放单词
		(h->list)[i].next = NULL;//头结点指向的第一个单词
	}
	return h;
}
bool strindex(Hash* h, char* str, int key) {
	int size = (h->list)[key].count;//单词总数
	LN* tmp = (h->list)[key].next;//链表中的第一个单词结点
	while (size && tmp) {
		if (strcmp(tmp->str, str) == 0) {
			tmp->count += 1;
			break;
		}
		tmp = tmp->next;
		size -= 1;
	}
	return size;
}
void Insert(Hash** h, int key, char* ptr) {
	//当前表尾结点为空指针，为该结点申请空间
	LN* tmp = (LN*)calloc(1, sizeof(LN));;//链表中的第一个单词结点
	assert(tmp);
	//通过尾插插入新结点
	tmp->next = ((*h)->list)[key].next;
	((*h)->list)[key].next = tmp;
	//单词数量+1
	((*h)->list)[key].count += 1;
	tmp->size = strlen(ptr);
	//为该结点存储的字符串申请空间
	tmp->str = (char*)calloc(tmp->size + 1, sizeof(char));
	assert(tmp->str);
	strncpy(tmp->str, ptr, tmp->size);
	tmp->count += 1;
}
void str_split(Hash** h, char* s1) {
	for (char* ptr = strtok(s1, " "); ptr; ptr = strtok(NULL, " ")) {
		int key = ptr[0] - 'a';
		if (strindex(*h, ptr, key) == false) {
			Insert(h, key, ptr);
		}
	}
}
void Print(Hash* h) {
	printf("h:\n");
	for (int i = 0; i < 26; i++) {
		LN* ptr = (h->list)[i].next;
		while (ptr) {
			printf("ptr->count = %d\tptr->size = %d\tptr->str = %s\tptr->next = %p\n", ptr->count, ptr->size, ptr->str, ptr->next);
			ptr = ptr->next;
		}
	}
}
void DestroyHash(Hash** h) {
	for (int i = 0; i < 26; i++) {
		while (((*h)->list)[i].count) {
			LN* ptr = ((*h)->list)[i].next;
			free(ptr->str);//释放字符串空间
			ptr->str = NULL;
			//通过尾删，删除需要释放的结点空间
			((*h)->list)[i].next = ptr->next;
			ptr->next = NULL;
			free(ptr);//释放结点空间
			((*h)->list)[i].count -= 1;
		}
	}
	free((*h)->list);//释放链表空间
}
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
	Hash* h = CreateHash();
	str_split(&h, s1);
	str_split(&h, s2);
	*returnSize = 0;
	int base = 0;
	for (int i = 0; i < 26; i++) {
		base += (h->list)[i].count;
	}
	char** ans = (char**)calloc(base, sizeof(char*));
	assert(ans);
	for (int i = 0; i < 26; i++) {
		if ((h->list)[i].count) {
			LN* ptr = (h->list)[i].next;
			while (ptr) {
				if (ptr->count == 1) {
					ans[*returnSize] = (char*)calloc(ptr->size + 1, sizeof(char));
					assert(ans[*returnSize]);
					strncpy(ans[*returnSize], ptr->str, ptr->size);
					*returnSize += 1;
				}
				ptr = ptr->next;
			}
		}
	}
	DestroyHash(&h);
	free(h);//释放哈希表空间
	return ans;
}