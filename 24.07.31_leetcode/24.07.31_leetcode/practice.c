#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

//2024.07.31力扣网刷题
//整数转罗马数字——哈希表、数学、字符串——中等
//七个不同的符号代表罗马数字，其值如下：
//符号	值
//I	1
//V	5
//X	10
//L	50
//C	100
//D	500
//M	1000
//罗马数字是通过添加从最高到最低的小数位值的转换而形成的。
//将小数位值转换为罗马数字有以下规则：
//如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
//如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，
//例如 4 是 5 (V)减 1 (I) : IV ，9 是 10 (X)减 1 (I)：IX。
//仅使用以下减法形式：4(IV)，9(IX)，40(XL)，90(XC)，400(CD) 和 900 (CM)。
//只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。
//你不能多次附加 5 (V)，50(L) 或 500 (D)。
//如果需要将符号附加4次，请使用 减法形式。
//给定一个整数，将其转换为罗马数字。
//示例 1：
//输入：num = 3749
//输出： "MMMDCCXLIX"
//解释：
//3000 = MMM 由于 1000 (M)+1000 (M)+1000 (M)
//700 = DCC 由于 500 (D)+100 (C)+100 (C)
//40 = XL 由于 50 (L)减 10 (X)
//9 = IX 由于 10 (X)减 1 (I)
//注意：49 不是 50 (L)减 1 (I)因为转换是基于小数位
//示例 2：
//输入：num = 58
//输出："LVIII"
//解释：
//50 = L
//8 = VIII
//示例 3：
//输入：num = 1994
//输出："MCMXCIV"
//解释：
//1000 = M
//900 = CM
//90 = XC
//4 = IV
//提示：
//1 <= num <= 3999


char* intToRoman(int num) {
	char* ans = (char*)calloc(17, sizeof(char));
	assert(ans);
	int tmp[4] = { 0 };
	for (int i = 0; i < 4 && num; i++) {
		tmp[i] = num / (int)pow(10, 3 - i);
		num %= (int)pow(10, 3 - i);
	}
	int len = 0;
	while (tmp[0]) {
		ans[len++] = 'M';
		tmp[0] -= 1;
	}
	while (tmp[1]) {
		if (tmp[1] == 9) {
			ans[len++] = 'C';
			ans[len++] = 'M';
			break;
		}
		else if (tmp[1] == 4) {
			ans[len++] = 'C';
			ans[len++] = 'D';
			break;
		}
		else if (tmp[1] >= 5) {
			ans[len++] = 'D';
			tmp[1] -= 5;
		}
		else {
			ans[len++] = 'C';
			tmp[1] -= 1;
		}
	}
	while (tmp[2]) {
		if (tmp[2] == 9) {
			ans[len++] = 'X';
			ans[len++] = 'C';
			break;
		}
		else if (tmp[2] == 4) {
			ans[len++] = 'X';
			ans[len++] = 'L';
			break;
		}
		else if (tmp[2] >= 5) {
			ans[len++] = 'L';
			tmp[2] -= 5;
		}
		else {
			ans[len++] = 'X';
			tmp[2] -= 1;
		}
	}
	while (tmp[3]) {
		if (tmp[3] == 9) {
			ans[len++] = 'I';
			ans[len++] = 'X';
			break;
		}
		else if (tmp[3] == 4) {
			ans[len++] = 'I';
			ans[len++] = 'V';
			break;
		}
		else if (tmp[3] >= 5) {
			ans[len++] = 'V';
			tmp[3] -= 5;
		}
		else {
			ans[len++] = 'I';
			tmp[3] -= 1;
		}
	}
	return ans;
}

void test() {
	int num = 0;
	while (scanf("%d", &num) == 1) {
		char* ret = intToRoman(num);
		printf("%s\n", ret);
		free(ret);
	}
}

int main() {
	test();
	return 0;
}