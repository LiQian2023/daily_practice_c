#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//2024.07.18力扣网刷题
//最常见的单词——数组、哈希表、字符串、计数——简单
//给你一个字符串 paragraph 和一个表示禁用词的字符串数组 banned ，返回出现频率最高的非禁用词。题目数据 保证 至少存在一个非禁用词，且答案 唯一 。
//paragraph 中的单词 不区分大小写 ，答案应以 小写 形式返回。
//示例 1：
//输入：paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
//输出："ball"
//解释：
//"hit" 出现了 3 次，但它是禁用词。
//"ball" 出现了两次（没有其他单词出现这么多次），因此它是段落中出现频率最高的非禁用词。
//请注意，段落中的单词不区分大小写，
//标点符号会被忽略（即使它们紧挨着单词，如 "ball,"），
//并且尽管 "hit" 出现的次数更多，但它不能作为答案，因为它是禁用词。
//示例 2：
//输入：paragraph = "a.", banned = []
//输出："a"
//提示：
//1 <= paragraph.length <= 1000
//paragraph 由英文字母、空格 ' '、和以下符号组成："!?',;."
//0 <= banned.length <= 100
//1 <= banned[i].length <= 10
//banned[i] 仅由小写英文字母组成
typedef struct HashTable {
	char* value;
	int count;
}HT;

void Delete(HT hash[],int* len, int l, int r) {
	while (r < *len) {
		hash[l] = hash[r];
		l++, r++;
	}
	hash[l].value = NULL;
	hash[l].count = 0;
	*len -= r - l;
}
int int_cmp(const void* p1, const void* p2) {
	return ((HT*)p2)->count - ((HT*)p1)->count;
}
int str_cmp(const void* p1, const void* p2) {
	return strcmp(((HT*)p1)->value, ((HT*)p2)->value);
}
char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
	HT hash[1000] = { 0 };
	const char* strDelimit = "!?',;. ";
	int len = 0;
	//拆分
	for (char* ret = strtok(paragraph, strDelimit); ret; ret = strtok(NULL, strDelimit)) {
		for (int i = 0; ret[i]; i++) {
			if (isupper(ret[i]))
				ret[i] = tolower(ret[i]);
		}
		hash[len++].value = ret;
	}
	////复制
	//char tmp[1001]= { 0 };
	//for (int i = 0; paragraph[i]; i++) {
	//	tmp[i] = paragraph[i];
	//}
	////拆分
	//for (char* ret = strtok(tmp, strDelimit); ret; ret = strtok(NULL, strDelimit)) {
	//	for (int i = 0; ret[i]; i++) {
	//		if (isupper(ret[i]))
	//			ret[i] = tolower(ret[i]);
	//	}
	//	hash[len++].value = ret;
	//}
	//排序
	qsort(hash, len, sizeof(HT), str_cmp);

	//计数
	for (int l = 0, r = 0; l < len; l++) {
		r = l + 1;
		while (r < len && strcmp(hash[l].value, hash[r].value) == 0) {
			r++;
		}
		hash[l].count += r - l;
		if (r - l > 1)
			Delete(hash, &len, l + 1, r);
	}
	//排序
	qsort(hash, len, sizeof(HT), int_cmp);
	char* ans = NULL;
	if (bannedSize == 0)
		ans = hash[0].value;
	else {
		for (int i = 0; i < len; i++) {
			int count = 0;
			for (int j = 0; j < bannedSize; j++) {
				if(strcmp(hash[i].value, banned[j])) {
					count++;
				}
			}
			if (count == bannedSize) {
				ans = hash[i].value;
				break;
			}
		}
	}
	return ans;
}

void test() {
	char s1[1000] = "x, w' q. s. K? Y? Z. B? T? s? u. v. C? K! u; v, t; x? W. x. t? u' O' H! x? W? n. i, U. u' m' C. y? X? S. z. F; S. O! Q. Y, t! S' L? r? R! z; S' t; y; q; d' A' g; O; q. J, W, y. u! Z' k' K, q! M. D; V? w! l, J! g; Y. V. J; T' R' O' W! L' V; y? O! w? j. s? W. Z, y! z! Z! n. H. q, x, g; s. I? R' W. p; v' y' S. J, w, g' i, n. j' U; v' i! P; y, r, p? z? u; W! X! E. q. X! M; y' X. V' z? u? I. Z! N? L. y' Y, Q, T' w! W? Y' O! n' M. P! s, H. x? l. Q! n, o? T; r? K, K! z; q' P! O! W, q. y' V, R? V! S, t. H; z; q? p, R? j, E' P. V; T! s! z, P; p; q' y; S, P, Z, u! i; J' u! Y, m? X? l, q. R! Q, Y! W. Y; U? O. z! W' k' w' K; z? p? O; k, s! M. M' f! m; Z! z' y; o' u; x! i. u' f' n. W' T, F; X? n, V' R. l, y; x; V' K. r. H. G, R; P. m? X, u, P; i? n? X. E! X; j' l' z? g. f? X. U, N? t, t; R' L' l; W? K! y, S, w, p, R! x, f, T' I; O' Z; t; l' O; n? d! u; r, m, p; V' E' Q! R! U? J! e' V! z! X' v! O' O' t. Z, T! Y. X' M? T? V. n, P. V' M! S! d, n, h. g' Y! t' Z? u; W; x' W? U; m' Y' r? w, b! s; s, z?";

	char* s2[20] = { "y","c","s","a","f","p","n","g","q","h","u","r","m","d","v","e","j","w","i","x" };
	int len = 1;
	printf("%s\n", mostCommonWord(s1, s2, len));
}

int main() {
	test();
	return 0;
}