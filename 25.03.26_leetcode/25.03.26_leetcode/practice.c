#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>
#include <string.h>

//2025.03.26力扣网刷题
//招式拆解 II——队列、哈希表、字符串、计数——简单
//某套连招动作记作仅由小写字母组成的序列 arr，其中 arr[i] 第 i 个招式的名字。请返回第一个只出现一次的招式名称，如不存在请返回空格。
//示例 1：
//输入：arr = "abbccdeff"
//输出：'a'
//示例 2：
//输入：arr = "ccdd"
//输出：' '
//限制：
//0 <= arr.length <= 50000

char dismantlingAction(char* arr) {
	int hash[26] = { 0 };
	for (int i = 0; arr[i]; i++) {
		int key = arr[i] - 'a';
		hash[key] += 1;
	}
	for (int i = 0; arr[i]; i++) {
		int key = arr[i] - 'a';
		if (hash[key] == 1) {
			return arr[i];
		}
	}
	return ' ';
}