#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2024.03.25力扣网刷题
//字符串中的第一个唯一字符——队列、哈希表、字符串、计数——简单
//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
//示例 1：
//输入 : s = "leetcode"
//输出 : 0
//示例 2 :
//	输入 : s = "loveleetcode"
//	输出 : 2
//	示例 3 :
//	输入 : s = "aabb"
//	输出 : -1
//	提示 :
//	1 <= s.length <= 10^5
//	s 只包含小写字母

//计数
int firstUniqChar1(char* s) {
	int num[26] = { 0 };
	char ch[27] = { 0 };
	int i = 0;
	int min = 0;
	int flag = 0;
	for (int j = 0; s[j]; j++) {
		num[s[j] - 'a']++;
		min++;
	}
	for (int j = 0; j < 26; j++) {
		if (num[j] == 1)
		{
			ch[i++] = j + 'a';
			flag = 1;
		}
	}
	for (i = 0; ch[i]; i++) {
		for (int j = 0; s[j]; j++) {
			if (s[j] == ch[i]) {
				min = min < j ? min : j;
				break;
			}
		}
	}
	if (flag)
		return min;
	return -1;
}

//计数
int firstUniqChar1(char* s) {
	int num[26] = { 0 };
	for (int i = 0; s[i]; i++) {
		num[s[i] - 'a']++;
	}
	for (int i = 0; s[i]; i++) {
		if (num[s[i] - 'a'] == 1)
			return i;
	}
	return -1;
}


//队列
int firstUniqChar(char* s) {
	int num[26] = { 0 };
	int front = 0, rear = 0;//队头指针与队尾指针
	int len = 1;//记录队长
	for (int i = 1; s[i]; i++) {
		if (!len)//队列为空
		{
			rear = (rear + 1) % 26;
			num[rear] = i;
			len++;
		}
		if (s[i] == s[num[front]]) {
			num[front] = -1;//元素出队
			front = (front + 1) % 26;//移动队头指针
			len--;//表长-1
		}
		else {
			rear = (rear + 1) % 26;//移动队头指针
			num[rear] = i;//元素入队
			len++;//表长+1
		}
	}
	if (len)
		return front;
	return -1;
}

void test() {
	char s[100] = { 0 };
	while (scanf("%s", s) == 1) {
		printf("%d\n", firstUniqChar(s));
	}
}

int main() {
	test();
	return 0;
}