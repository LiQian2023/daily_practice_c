#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2025.03.13力扣网刷题
//最大字符串配对数目——数组、哈希表、字符串、模拟——简单
//给你一个下标从 0 开始的数组 words ，数组中包含 互不相同 的字符串。
//如果字符串 words[i] 与字符串 words[j] 满足以下条件，我们称它们可以匹配：
//字符串 words[i] 等于 words[j] 的反转字符串。
//0 <= i < j < words.length
//请你返回数组 words 中的 最大 匹配数目。
//注意，每个字符串最多匹配一次。
//示例 1：
//输入：words = ["cd", "ac", "dc", "ca", "zz"]
//输出：2
//解释：在此示例中，我们可以通过以下方式匹配 2 对字符串：
//- 我们将第 0 个字符串与第 2 个字符串匹配，因为 word[0] 的反转字符串是 "dc" 并且等于 words[2]。
//- 我们将第 1 个字符串与第 3 个字符串匹配，因为 word[1] 的反转字符串是 "ca" 并且等于 words[3]。
//可以证明最多匹配数目是 2 。
//示例 2：
//输入：words = ["ab", "ba", "cc"]
//输出：1
//解释：在此示例中，我们可以通过以下方式匹配 1 对字符串：
//- 我们将第 0 个字符串与第 1 个字符串匹配，因为 words[1] 的反转字符串 "ab" 与 words[0] 相等。
//可以证明最多匹配数目是 1 。
//示例 3：
//输入：words = ["aa", "ab"]
//输出：0
//解释：这个例子中，无法匹配任何字符串。
//提示：
//1 <= words.length <= 50
//words[i].length == 2
//words 包含的字符串互不相同。
//words[i] 只包含小写英文字母。

typedef struct HashNode {
	int count;
}HN;
typedef struct Hash {
	HN* list;
	int count;
}H;
H* CreateHash() {
	H* h = (H*)calloc(26, sizeof(H));
	assert(h);
	for (int i = 0; i < 26; i++) {
		h[i].list = (HN*)calloc(26, sizeof(HN));
		assert(h[i].list);
	}
	return h;
}
void Destroy(H** h) {
	for (int i = 0; i < 26; i++) {
		free((*h)[i].list);
		(*h)[i].list = NULL;
	}
	free(*h);
	*h = NULL;
}
void HashRecord(H* h, char* str, int i) {
	int key1 = str[0] - 'a';
	int key2 = str[1] - 'a';
	h[key1].count += 1;
	h[key1].list[key2].count += 1;
}
void HashDelete(H* h, int key1, int key2) {
	h[key1].count -= 1;
	h[key1].list[key2].count -= 1;
}

int maximumNumberOfStringPairs(char** words, int wordsSize) {
	H* h = CreateHash();
	for (int i = 0; i < wordsSize; i++) {
		HashRecord(h, words[i], i);
	}
	int ans = 0;
	for (int i = 0; i < wordsSize; i++) {
		int key1 = words[i][0] - 'a';
		int key2 = words[i][1] - 'a';
		if (key1 != key2) {
			if (h[key2].list[key1].count) {
				ans += 1;
			}
		}
		HashDelete(h, key1, key2);
	}
	Destroy(&h);
	return ans;
}