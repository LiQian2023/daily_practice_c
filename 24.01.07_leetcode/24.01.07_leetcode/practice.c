#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//2024.01.07力扣网刷题
//赎金信——哈希表、字符串、计数——简单
//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//如果可以，返回 true ；否则返回 false 。
//magazine 中的每个字符只能在 ransomNote 中使用一次。
//示例 1：
//输入：ransomNote = "a", magazine = "b"
//输出：false
//示例 2：
//输入：ransomNote = "aa", magazine = "ab"
//输出：false
//示例 3：
//输入：ransomNote = "aa", magazine = "aab"
//输出：true
//提示：
//1 <= ransomNote.length, magazine.length <= 10^5
//ransomNote 和 magazine 由小写英文字母组成
int cmp(const void* p1, const void* p2) {
	return *(char*)p1 - *(char*)p2;
}

bool canConstruct(char* ransomNote, char* magazine) {
	int len1 = strlen(magazine);
	int len2 = strlen(ransomNote);
	qsort(magazine, len1, 1, cmp);
	qsort(ransomNote, len2, 1, cmp);
	int i = 0, j = 0;
	for (i = 0; i < len2; i++) {
		int flag = 0;
		for (j; j < len1; j++) {
			if (magazine[j] == ransomNote[i]) {
				flag = 1;
				j++;
				break;
			}
		}
		if (!flag) {
			return false;
		}
	}
	return true;
}
int main() {
	char ch1[100000] = { 0 };
	char ch2[100000] = { 0 };
	while (scanf("%s%s",ch1,ch2) == 2) {
		if (canConstruct(ch1, ch2)) {
			printf("true\n");
		}
		else {
			printf("false\n");
		}
	}
	return 0;
}