#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2025.09.08力扣网刷题
//优惠券校验器——数组、哈希表、排序、字符串、第457场周赛——简单
//给你三个长度为 n 的数组，分别描述 n 个优惠券的属性：code、businessLine 和 isActive。其中，第 i 个优惠券具有以下属性：
//code[i]：一个 字符串，表示优惠券的标识符。
//businessLine[i]：一个 字符串，表示优惠券所属的业务类别。
//isActive[i]：一个 布尔值，表示优惠券是否当前有效。
//当以下所有条件都满足时，优惠券被认为是 有效的 ：
//code[i] 不能为空，并且仅由字母数字字符（a - z、A - Z、0 - 9）和下划线（_）组成。
//businessLine[i] 必须是以下四个类别之一："electronics"、"grocery"、"pharmacy"、"restaurant"。
//isActive[i] 为 true 。
//返回所有 有效优惠券的标识符 组成的数组，按照以下规则排序：
//先按照其 businessLine 的顺序排序："electronics"、"grocery"、"pharmacy"、"restaurant"。
//在每个类别内，再按照 标识符的字典序（升序）排序。
//示例 1：
//输入： code = ["SAVE20", "", "PHARMA5", "SAVE@20"], businessLine = ["restaurant", "grocery", "pharmacy", "restaurant"], isActive = [true, true, true, true]
//输出：["PHARMA5", "SAVE20"]
//解释：
//第一个优惠券有效。
//第二个优惠券的标识符为空（无效）。
//第三个优惠券有效。
//第四个优惠券的标识符包含特殊字符 @（无效）。
//示例 2：
//输入： code = ["GROCERY15", "ELECTRONICS_50", "DISCOUNT10"], businessLine = ["grocery", "electronics", "invalid"], isActive = [false, true, true]
//输出：["ELECTRONICS_50"]
//解释：
//第一个优惠券无效，因为它未激活。
//第二个优惠券有效。
//第三个优惠券无效，因为其业务类别无效。
//提示：
//n == code.length == businessLine.length == isActive.length
//1 <= n <= 100
//0 <= code[i].length, businessLine[i].length <= 100
//code[i] 和 businessLine[i] 由可打印的 ASCII 字符组成。
//isActive[i] 的值为 true 或 false。
typedef struct Hash {
	char* code;
	char business;
	int len;
}Hash;
bool Is_Effictive(char* str, int len) {
	if (len) {
		for (int i = 0; i < len; i++) {
			if (!isalnum(str[i])) {
				if (str[i] != '_') {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
bool in(char* str, char** list) {
	for (int i = 0; i < 4; i++) {
		if (strcmp(str, list[i]) == 0) {
			return true;
		}
	}
	return false;
}
int cmp(const void* p1, const void* p2) {
	Hash a = *((Hash*)p1),  b = *((Hash*)p2);
	if (a.business != b.business) {
		return a.business - b.business;
	}
	return strcmp(a.code, b.code);
}
void Print(Hash* hash, int len) {
	for (int i = 0; i < len; i++) {
		printf("hash[%d].code = %s\t.business = %c\t.len = %d\n", i, hash[i].code, hash[i].business, hash[i].len);
	}
}
char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize) {
	Hash* hash = (Hash*)calloc(codeSize, sizeof(Hash));
	assert(hash);
	*returnSize = 0;
	char* list[4] = { "electronics","grocery","pharmacy","restaurant" };
	for (int i = 0; i < codeSize; i++) {
		int len = strlen(code[i]);
		if (Is_Effictive(code[i], len)) {
			if (in(businessLine[i], list)) {
				if (isActive[i]) {
					hash[*returnSize].code = (char*)calloc(len + 1, sizeof(char));
					assert(hash[*returnSize].code);
					strncpy(hash[*returnSize].code, code[i], len);
					hash[*returnSize].business = businessLine[i][0];
					hash[*returnSize].len = len;
					*returnSize += 1;
				}
			}
		}
	}
	qsort(hash, *returnSize, sizeof(Hash), cmp);
	char** ans = (char**)calloc(*returnSize, sizeof(char*));
	assert(ans);
	for (int i = 0; i < *returnSize; i++) {
		ans[i] = (char*)calloc(hash[i].len + 1, sizeof(char));
		assert(ans[i]);
		strncpy(ans[i], hash[i].code, hash[i].len);
	}
	free(hash);
	hash = NULL;
	return ans;
}