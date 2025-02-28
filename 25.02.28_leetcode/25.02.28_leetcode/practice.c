#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
//2025.02.28力扣网刷题
//统计字符串中的元音子字符串——哈希表、字符串——简单
//子字符串 是字符串中的一个连续（非空）的字符序列。
//元音子字符串 是 仅 由元音（'a'、'e'、'i'、'o' 和 'u'）组成的一个子字符串，且必须包含 全部五种 元音。
//给你一个字符串 word ，统计并返回 word 中 元音子字符串的数目 。
//示例 1：
//输入：word = "aeiouu"
//输出：2
//解释：下面列出 word 中的元音子字符串（斜体加粗部分）：
//- "aeiouu"
//- "aeiouu"
//示例 2：
//输入：word = "unicornarihan"
//输出：0
//解释：word 中不含 5 种元音，所以也不会存在元音子字符串。
//示例 3：
//输入：word = "cuaieuouac"
//输出：7
//解释：下面列出 word 中的元音子字符串（斜体加粗部分）：
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//示例 4：
//输入：word = "bbaeixoubb"
//输出：0
//解释：所有包含全部五种元音的子字符串都含有辅音，所以不存在元音子字符串。
//提示：
//1 <= word.length <= 100
//word 仅由小写英文字母组成

typedef struct HashNode {
    bool exist; // 存在标志
    int count;  // 出现次数
} HN;
typedef struct Hash {
    HN* node;
    int n;
} Hash;
void Print(Hash* h) {
    char vowels[6] = "aeiou";
    printf("h->n = %d\n", h->n);
    for (int i = 0; i < 5; i++) {
        int key = vowels[i] - 'a';
        printf("h->node[%d] = %c = %d\t", key, vowels[i], h->node[key].count);
    }
    printf("\n");
}
// 是否为元音字母
bool isvowel(char x) {
    char vowels[6] = "aeiou";
    for (int i = 0; i < 5; i++) {
        if (vowels[i] == x) {
            return true;
        }
    }
    return false;
}
Hash* CreateHash() {
    Hash* h = (Hash*)calloc(1, sizeof(Hash));
    assert(h);
    h->n = 0;
    h->node = (HN*)calloc(26, sizeof(HN));
    assert(h->node);
    return h;
}
int Hash_Record(char* word, Hash* h, int begin, int end) {
    int i = begin;
    for (i; i < end; i += 1) {
        int key = word[i] - 'a';
        h->node[key].count += 1;
        if (h->node[key].exist == false) {
            h->n += 1;
            h->node[key].exist = true;
        }
        if (h->n == 5) {
            break;
        }
    }
    return i;
}
void Destroy(Hash** h) {
    free((*h)->node);
    free((*h));
}

// 搜索子串
int Search_Sub(char* word, int begin, int end) {
    Hash* h = CreateHash();
    // 哈希记录
    int i = Hash_Record(word, h, begin, end);
    int ret = 0;
    Print(h);
    if (h->n == 5) {
        ret += end - i;
    }
    Destroy(&h);
    h = NULL;
    return ret;
}
int countVowelSubstrings(char* word) {
    int len = strlen(word);
    int ans = 0;
    for (int l = 0; l < len; l += 1) {
        // 找到第一个元音字符
        if (isvowel(word[l])) {
            for (int r = l; r <= len; r++) {
                // 找到非元音字符
                if (!isvowel(word[r]) || r == len) {
                    if (r - l >= 5) {
                        ans += Search_Sub(word, l, r);
                    }
                    break;
                }
            }
        }
    }
    return ans;
}