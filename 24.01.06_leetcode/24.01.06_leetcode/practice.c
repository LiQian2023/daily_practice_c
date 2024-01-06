#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.01.06力扣网刷题
//在区间范围内统计奇数数目——数学——简单
//给你两个非负整数 low 和 high 。请你返回 low 和 high 之间（包括二者）奇数的数目。
//示例 1：
//输入：low = 3, high = 7
//输出：3
//解释：3 到 7 之间奇数数字为[3, 5, 7] 。
//示例 2：
//输入：low = 8, high = 10
//输出：1
//解释：8 到 10 之间奇数数字为[9] 。
//提示：
//0 <= low <= high <= 10 ^ 9

//法一：顺序排查
int countOdds1(int low, int high) {
	int count = 0;
	for (int i = low; i <= high; i++) {
		if (i % 2 != 0)
			count++;
	}
	return count;
}
//法二：累加
int countOdds2(int low, int high) {
	int count = 0;
	if (low % 2 == 0) {
		for (low += 1; low <= high; low += 2)
			count++;
	}
	else {
		for (low; low <= high; low += 2)
			count++;
	}
	return count;
}
//法三：取半
int countOdds(int low, int high) {
	int count = (high - low) / 1 + 1;
	int num = 0;
	if (0 != low % 2 && 0 != high % 2) {
		num = count / 2 + 1;
	}
	else{
		num = count / 2;
	}
	return num;
}
int main() {
	int n = 0, m = 0;
	while (scanf("%d%d", &n, &m) == 2) {
		int ret = countOdds(n, m);
		printf("%d\n", ret);
	}
	return 0;
}