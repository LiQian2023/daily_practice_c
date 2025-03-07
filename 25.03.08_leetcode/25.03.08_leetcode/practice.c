#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2025.03.08力扣网刷题
//解密消息——字符串、哈希表——简单
//给你字符串 key 和 message ，分别表示一个加密密钥和一段加密消息。解密 message 的步骤如下：
//使用 key 中 26 个英文小写字母第一次出现的顺序作为替换表中的字母 顺序 。
//将替换表与普通英文字母表对齐，形成对照表。
//按照对照表 替换 message 中的每个字母。
//空格 ' ' 保持不变。
//例如，key = "happy boy"（实际的加密密钥会包含字母表中每个字母 至少一次），据此，可以得到部分对照表（'h' -> 'a'、'a' -> 'b'、'p' -> 'c'、'y' -> 'd'、'b' -> 'e'、'o' -> 'f'）。
//           //abccd efg
//返回解密后的消息。
//示例 1：
//输入：key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
//输出："this is a secret"
//解释：对照表如上图所示。
//提取 "the quick brown fox jumps over the lazy dog" 中每个字母的首次出现可以得到替换表。
//示例 2：
//输入：key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
//输出："the five boxing wizards jump quickly"
//解释：对照表如上图所示。
//提取 "eljuxhpwnyrdgtqkviszcfmabo" 中每个字母的首次出现可以得到替换表。
//提示：
//26 <= key.length <= 2000
//key 由小写英文字母及 ' ' 组成
//key 包含英文字母表中每个字符（'a' 到 'z'）至少一次
//1 <= message.length <= 2000
//message 由小写英文字母和 ' ' 组成

typedef struct HashNode {
	char ch;
}HN;
typedef struct Hash {
	HN* list;
}Hash;
Hash* CreateHash() {
	Hash* h = (Hash*)calloc(1, sizeof(Hash));
	assert(h);
	h->list = (HN*)calloc(26, sizeof(HN));
	assert(h->list);
	return h;
}
void Hash_Record(Hash* h, char* key, int len) {
	int ch = 0;
	for (int i = 0; i < len && ch < 26; i++) {
		if (key[i] != ' ') {
			int k = key[i] - 'a';
			if (h->list[k].ch == 0) {
				h->list[k].ch = ch + 'a';
				ch += 1;
			}
		}
	}
}
void Destroy(Hash** h) {
	free((*h)->list);
	(*h)->list = NULL;
	free(*h);
	*h = NULL;
}
char* decodeMessage(char* key, char* message) {
	Hash* h = CreateHash();
	int len1 = strlen(key), len2 = strlen(message);
	Hash_Record(h, key, len1);
	char* ans = (char*)calloc(len2 + 1, sizeof(char));
	assert(ans);
	int size = 0;
	for (int i = 0; i < len2; i++) {
		int k = message[i] - 'a';
		if (k < 0) {
			ans[size] = ' ';
		}
		else {
			ans[size] = h->list[k].ch;
		}
		size += 1;
	}
	Destroy(&h);
	return ans;
}