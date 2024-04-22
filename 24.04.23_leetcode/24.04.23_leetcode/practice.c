#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//2024.04.23力扣网刷题
//宝石与石头——哈希表、字符串——简单
// 给你一个字符串 jewels 代表石头中宝石的类型，另有一个字符串 stones 代表你拥有的石头。 
//stones 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
//字母区分大小写，因此 "a" 和 "A" 是不同类型的石头。
//示例 1：
//输入：jewels = "aA", stones = "aAAbbbb"
//输出：3
//示例 2：
//输入：jewels = "z", stones = "ZZ"
//输出：0
//提示：
//1 <= jewels.length, stones.length <= 50
//jewels 和 stones 仅由英文字母组成
//jewels 中的所有字符都是 唯一的

int numJewelsInStones(char* jewels, char* stones) {
	int num[52] = { 0 };
	for (int i = 0; stones[i]; i++) {
		if (isupper(stones[i]))
			num[stones[i] - 'A' + 26]++;
		else
			num[stones[i] - 'a']++;
	}
	int count = 0;
	for (int i = 0; jewels[i]; i++) {
		if (isupper(jewels[i]))
			count += num[jewels[i] - 'A' + 26];
		else
			count += num[jewels[i] - 'a'];
	}
	return count;
}