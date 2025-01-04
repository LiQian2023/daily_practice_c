#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.01.04力扣网刷题
//卡牌分组——数学、哈希表、数组、计数、数论——简单
//给定一副牌，每张牌上都写着一个整数。
//此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
//每组都有 X 张牌。
//组内所有的牌上都写着相同的整数。
//仅当你可选的 X >= 2 时返回 true。
//示例 1：
//输入：deck = [1, 2, 3, 4, 4, 3, 2, 1]
//输出：true
//解释：可行的分组是[1, 1]，[2, 2]，[3, 3]，[4, 4]
//示例 2：
//输入：deck = [1, 1, 1, 2, 2, 2, 3, 3]
//输出：false
//解释：没有满足要求的分组。
//提示：
//1 <= deck.length <= 10^4
//0 <= deck[i] < 10^4

typedef struct Hash {
	int key;
	int value;
}Hash;
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int commen_factor(int a, int b) {
	if (a < b)
		Swap(&a, &b);
	int max = a, min = b;
	while (a % min != 0 || b % min != 0) {
		max += 1, min -= 1;
	}
	return min;
}
void Print(Hash* h, int len) {
	for (int i = 0; i < len; i++) {
		printf("key = %d, value = %d\n", h[i].key, h[i].value);
	}
}
bool hasGroupsSizeX(int* deck, int deckSize) {
	Hash* h = (Hash*)calloc(deckSize, sizeof(Hash));
	assert(h);
	int x = 0;
	for (int i = 0; i < deckSize; i++) {
		int key = deck[i] % deckSize;
		if (h[key].value == 0) {
			h[key].key = deck[i];
			h[key].value = 1;
		}
		else {
			while (h[key].key != deck[i] && h[key].value) {
				key += 1;
			}
			if (h[key].key == deck[i]) {
				h[key].value += 1;
				if (h[key].value > x)
					x = h[key].value;
			}
			else {
				h[key].key = deck[i];
				h[key].value = 1;
			}
		}
	}
	Print(h, deckSize);
	for (int i = 0; i < deckSize; i++) {
		if (h[i].value) {
			if (h[i].value == 1)
				return false;
			else {
				if (x != h[i].value) {
					int tmp = commen_factor(x, h[i].value);
					if (tmp == 1)
						return false;
					x = tmp;
				}
			}
		}
	}
	free(h);
	return true;
}