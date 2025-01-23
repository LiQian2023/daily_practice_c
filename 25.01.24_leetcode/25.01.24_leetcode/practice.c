#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//2025.01.24力扣网刷题
//亲密字符串——哈希表、字符串——简单
//给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。
//交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。
//例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
//示例 1：
//输入：s = "ab", goal = "ba"
//输出：true
//解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。
//示例 2：
//输入：s = "ab", goal = "ab"
//输出：false
//解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。
//示例 3：
//输入：s = "aa", goal = "aa"
//输出：true
//解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
//提示：
//1 <= s.length, goal.length <= 2 * 10^4
//s 和 goal 由小写英文字母组成

typedef struct LinkNode {
	int i;//字符下标
	struct LinkNode* next;
}LN;

typedef struct Hash {
	int num;//字符个数
	LN* head;
}Hash;

Hash* Create() {
	Hash* ch = (Hash*)calloc(26, sizeof(Hash));
	assert(ch);
	for (int i = 0; i < 26; i++) {
		ch[i].head = (LN*)calloc(1, sizeof(LN));
		assert(ch[i].head);
	}
	return ch;
}

void Put(LN* head, int i) {
	assert(head);
	LN* p = (LN*)calloc(1, sizeof(LN));
	assert(p);
	p->i = i;
	p->next = NULL;
	LN* l = head;
	while (l->next&& l->next->i < i) {
		l = l->next;
	}
	p->next = l->next;
	l->next = p;
}

int Remove(LN* head, int i) {
	assert(head);
	LN* l = head, * p = head->next;
	while (p && p->i != i) {
		l = p;
		p = l->next;
	}
	if (p == NULL) {
		return 1;
	}
	l->next = p->next;
	p->next = NULL;
	free(p);
	p = NULL;
	return 0;
}

void Destroy(Hash* hash) {
	assert(hash);
	for (int i = 0; i < 26; i++) {
		LN* p = hash[i].head;
		while (p && p->next) {
			LN* tmp = p->next;
			p->next = tmp->next;
			tmp->next = NULL;
			free(tmp);
			tmp = NULL;
		}
		free(p);
		p = NULL;
	}
}
bool buddyStrings(char* s, char* goal) {
	int len1 = strlen(s), len2 = strlen(goal);
	if (len1 != len2)
		return false;
	Hash* ch = Create();
	bool flag = false;//判断是否存在多个相同元素
	for (int i = 0; goal[i]; i++) {
		int key = goal[i] - 'a';
		ch[key].num += 1;
		Put(ch[key].head, i);
		if (ch[key].num > 1) {
			flag = true;
		}
	}
	int count = 0;
	for (int i = 0; s[i] && count < 3; i++) {
		int key = s[i] - 'a';
		if (ch[key].num == 0) {
			count = -1;
			break;
		}
		else {
			ch[key].num -= 1;
			count += Remove(ch[key].head, i);
		}
	}
	if (count == 0 && flag) {
		count = 2;
	}
	free(ch);
	ch = NULL;
	return count == 2;
}