#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2024.06.2力扣网刷题
//反转字符串中的单词——双指针、字符串——中等
//给你一个字符串 s ，请你反转字符串中 单词 的顺序。
//单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
//返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
//注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
//示例 1：
//输入：s = "the sky is blue"
//输出："blue is sky the"
//示例 2：
//输入：s = "  hello world  "
//输出："world hello"
//解释：反转后的字符串中不能存在前导空格和尾随空格。
//示例 3：
//输入：s = "a good   example"
//输出："example good a"
//解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
//提示：
//1 <= s.length <= 10^4
//s 包含英文大小写字母、数字和空格 ' '
//s 中 至少存在一个 单词
//进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。

//方法一：双指针——新字符串
char* reverseWords1(char* s) {
	//去首尾空格
	int len = strlen(s);
	int l = 0, r = len - 1;
	while (s[l] == ' ') {
		for (int i = l; s[i]; i++) {
			s[i] = s[i + 1];
		}
		len--;
		r--;
	}
	while (s[r] == ' ') {
		len--;
		r--;
	}
	//申请新空间
	char* str = (char*)calloc(len + 1, sizeof(char));
	assert(str);
	//逆序拷贝单词
	l = r;
	int i = 0; //新字符串下标
	r++;
	while (l >= 0) {
		if (s[l] == ' ') {
			int flag = 0;
			for (int j = l + 1; j < r; j++) {
				str[i++] = s[j];
				flag = 1;
			}
			if (flag)
				str[i++] = ' ';
			r = l;
		}
		l--;
	}
	for (int j = 0; j < r; j++) {
		str[i++] = s[j];
	}
	return str;
}

// 方法二：双指针
void move(char* s,int l) {
	for (int i = l; s[i]; i++) {
		s[i] = s[i + 1];
	}
}
void swap(char* l, char* r) {
	char tmp = *l;
	*l = *r;
	*r = tmp;
}
char* reverseWords(char* s) {
	//去收尾空格
	int len = strlen(s);
	int l = 0, r = len - 1;
	while (s[l] == ' ') {
		move(s, l);
		len--;
		r--;
	}
	while (s[r] == ' ') {
		s[r] = '\0';
		len--;
		r--;
	}
	//反转整个字符串
	while (l < r) {
		swap(&s[l], &s[r]);
		l++, r--;
	}
	//反转单词
	l = 0, r = 1;
	while (r < len) {
		//获取完整单词长度
		while (s[r] && s[r] != ' ')
			r++;
		//处理最后一个单词
		r--;
		//记录单词长度
		int end = r + 1;
		//翻转单词
		while (l < r) {
			swap(&s[l], &s[r]);
			l++, r--;
		}
		//记录下一个单词首字母位置
		l = end + 1;
		//去掉单词间的空格
		while (l <= len && s[l] == ' ') {
			move(s, l);
			len--;
		}
		r = l;
	}
	return s;
}

void test() {
	char a[10] = "\022";
	printf("%s\n", a);
}

void test2() {
	char str[100] = { 0 };
	while (gets(str)) {
		char* ret = reverseWords(str);
		printf("%s\n", ret);
		free(ret);
	}
}

int main() {
	test2();
	return 0;
}