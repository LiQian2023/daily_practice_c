#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.08.01力扣网刷题
//心算挑战——贪心、数组、排序——简单
//「力扣挑战赛」心算项目的挑战比赛中，要求选手从 N 张卡牌中选出 cnt 张卡牌，
//若这 cnt 张卡牌数字总和为偶数，则选手成绩「有效」且得分为 cnt 张卡牌数字总和。
//给定数组 cards 和 cnt，其中 cards[i] 表示第 i 张卡牌上的数字。 
//请帮参赛选手计算最大的有效得分。若不存在获取有效得分的卡牌方案，则返回 0。
//示例 1：
//输入：cards = [1, 2, 8, 9], cnt = 3
//输出：18
//解释：选择数字为 1、8、9 的这三张卡牌，此时可获得最大的有效得分 1 + 8 + 9 = 18。
//示例 2：
//输入：cards = [3, 3, 1], cnt = 1
//输出：0
//解释：不存在获取有效得分的卡牌方案。
//提示：
//1 <= cnt <= cards.length <= 10 ^ 5
//1 <= cards[i] <= 1000

//方法一：计数排序
int maxmiumScore(int* cards, int cardsSize, int cnt) {
	int nums[1001] = { 0 };
	int odd = 0, even = 0, max = cards[0];
	for (int i = 0; i < cardsSize; i++) {
		nums[cards[i]] += 1;
		if (cards[i] % 2)
			odd += 1;
		else
			even += 1;
		if (cards[i] > max)
			max = cards[i];
	}
	if (cnt % 2 && even == 0)
		return 0;
	int len = 0;
	int i = max, j = max - 1;
	if (max % 2) {
		i = max - 1;
		j = max;
	}
	//偶数排序
	while (i >= 0) {
		if (nums[i]) {
			cards[len++] = i;
			nums[i] -= 1;
		}
		else {
			i -= 2;
		}
	}
	//奇数排序
	while (j >= 0) {
		if (nums[j]) {
			cards[len++] = j;
			nums[j] -= 1;
		}
		else {
			j -= 2;
		}
	}
	int ans = 0;
	i = 0, j = even;
	if (cnt % 2) {
		ans += cards[0];
		cnt -= 1;
		i = 1;
	}
	int sum1 = 0, sum2 = 0;
	for (; i < even - 1 && j < cardsSize - 1 && cnt; cnt -= 2) {
		sum1 = cards[i] + cards[i + 1];
		sum2 = cards[j] + cards[j + 1];
		if (sum1 > sum2) {
			ans += sum1;
			i += 2;
		}
		else {
			ans += sum2;
			j += 2;
		}
	}
	if (even - i <= cnt - 1) {
		while (cardsSize - j > cnt - 1 && cnt) {
			ans += cards[j] + cards[j + 1];
			cnt -= 2;
			j += 2;
		}
	}
	else if (cardsSize - j <= cnt - 1) {
		while (even - i > cnt - 1 && cnt) {
			ans += cards[i] + cards[i + 1];
			cnt -= 2;
			i += 2;
		}
	}
	if (cnt)
		ans = 0;
	return ans;
}

void test1() {
	int arr[10] = { 2,4,9,7,4,9,4,4 };
	int len = 8;
	int key = 8;
	printf("%d\n", maxmiumScore(arr, len, key));
}