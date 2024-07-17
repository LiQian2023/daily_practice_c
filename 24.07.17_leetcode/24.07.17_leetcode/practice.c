#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


//2024.07.17力扣网刷题
//两个列表的最小索引总和——数组、哈希表、字符串——简单
//假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
//你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。
//示例 1:
//输入:
//list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，
//list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//输出 : ["Shogun"]
//解释 : 他们唯一共同喜爱的餐厅是“Shogun”。
//示例 2 : 
//输入 : list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["KFC", "Shogun", "Burger King"]
//输出 : ["Shogun"]
//解释 : 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0 + 1)。
//提示 :
//1 <= list1.length, list2.length <= 1000
//1 <= list1[i].length, list2[i].length <= 30
//list1[i] 和 list2[i] 由空格 ' ' 和英文字母组成。
//list1 的所有字符串都是 唯一 的。
//list2 中的所有字符串都是 唯一 的。


char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
	char** ans = (char**)calloc(1000, sizeof(char*));
	assert(ans);
	int min = -1;
	int len = 0;
	for (int i = 0; i < list1Size; i++) {
		int j = 0;
		while (j < list2Size && strcmp(list1[i], list2[j])) {
			j++;
		}
		if (j<list2Size && (min == -1 || min > i + j)) {
			min = i + j;
			len = 0;
			ans[len++] = list1[i];
		}
		else if (min == i + j) {
			ans[len++] = list1[i];
		}
	}
	*returnSize = len;
	return ans;
}


void test1() {
	char* s1[4] = { "vacag","KFC" };
	char* s2[4] = { "fvo","xrljq","jrl","KFC" };
	int len = 0;
	char** ret = findRestaurant(s1, 2, s2, 4, &len);
	for (int i = 0; i < len; i++) {
		printf("%s\n", ret[i]);
	}
	free(ret);
}
#include <limits.h>
void test() {
	printf("%d\n", SHRT_MAX);
	printf("%d\n", SHRT_MIN);
}

int main() {
	test1();
	return 0;
}