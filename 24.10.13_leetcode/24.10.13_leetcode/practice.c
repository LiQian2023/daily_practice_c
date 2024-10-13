#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//2024.10.13力扣网刷题
//根据字符出现频率排序——哈希表、字符串、桶排序、计数、排序、堆（优先队列）——中等
//给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。
//返回 已排序的字符串 。如果有多个答案，返回其中任何一个。
//示例 1:
//输入: s = "tree"
//输出 : "eert"
//解释 : 'e'出现两次，'r'和't'都只出现一次。
//因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
//示例 2 :
//输入 : s = "cccaaa"
//输出 : "cccaaa"
//解释 : 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
//注意"cacaca"是不正确的，因为相同的字母必须放在一起。
//示例 3 :
//输入 : s = "Aabb"
//输出 : "bbAa"
//解释 : 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
//注意'A'和'a'被认为是两种不同的字符。
//提示 :
//1 <= s.length <= 5 * 10^5
//s 由大小写英文字母和数字组成

typedef struct Hash {
	char key;
	int value;
}Hash;
int cmp(const void* p1, const void* p2) {
	Hash* a = (Hash*)p1;
	Hash* b = (Hash*)p2;
	if (a->value == b->value)
		return b->key - a->key;
	return b->value - a->value;
}
char* frequencySort(char* s) {
	Hash ch[63] = { 0 };
	for (int i = 0; s[i]; i++) {
		int key = s[i];
		if (isdigit(key)) {
			key -= '0';
		}
		else if (isupper(key)) {
			key = key - 'A' + 10;
		}
		else {
			key = key - 'a' + 36;
		}
		ch[key].value += 1;
		ch[key].key = s[i];
	}
	qsort(ch, 63, sizeof(Hash), cmp);
	int len = 0;
	for (int i = 0; i < 63; i++) {
		while (ch[i].value) {
			s[len] = ch[i].key;
			ch[i].value -= 1;
			len += 1;
		}
	}
	return s;
}

void test() {
	char s[63] = "Street";
	//for (int i = 0; i < 62; i++) {
	//	if (i < 10) {
	//		s[i] = i + '0';
	//	}
	//	else if (i < 36) {
	//		s[i] = 'A' + i - 10;
	//	}
	//	else {
	//		s[i] = 'a' + i - 36;
	//	}
	//}
	printf("%s\n", frequencySort(s));
}

int main() {
	test();
	return 0;
}