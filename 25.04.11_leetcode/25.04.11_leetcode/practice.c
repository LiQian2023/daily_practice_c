#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.04.11力扣网刷题
//等价多米诺骨牌对的数量——数组、哈希表、计数——简单
//给你一组多米诺骨牌 dominoes 。
//形式上，dominoes[i] = [a, b] 与 dominoes[j] = [c, d] 等价 当且仅当(a == c 且 b == d) 或者(a == d 且 b == c) 。即一张骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌。
//在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对(i, j) 的数量。
//示例 1：
//输入：dominoes = [[1, 2], [2, 1], [3, 4], [5, 6]]
//输出：1
//示例 2：
//输入：dominoes = [[1, 2], [1, 2], [1, 1], [1, 2], [2, 2]]
//输出：3
//提示：
//1 <= dominoes.length <= 4 * 10^4
//dominoes[i].length == 2
//1 <= dominoes[i][j] <= 9
typedef struct HashNode {
	int count;
}HN;
typedef struct Hash {
	HN key[10];
}Hash;
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
	Hash* h = (Hash*)calloc(10, sizeof(Hash));
	assert(h);
	int ans = 0;
	for (int i = 0; i < dominoesSize; i++) {
		int key1 = dominoes[i][0] > dominoes[i][1] ? dominoes[i][1] : dominoes[i][0];
		int key2 = dominoes[i][0] > dominoes[i][1] ? dominoes[i][0] : dominoes[i][1];
		if (h[key1].key[key2].count) {
			ans += h[key1].key[key2].count;
		}
		h[key1].key[key2].count += 1;
	}
	free(h);
	h = NULL;
	return ans;
}