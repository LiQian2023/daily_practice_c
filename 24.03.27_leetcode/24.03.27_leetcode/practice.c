#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.03.27力扣网刷题
//Fizz Buzz——字符串、数学、模拟——简单
//给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：
//answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
//answer[i] == "Fizz" 如果 i 是 3 的倍数。
//answer[i] == "Buzz" 如果 i 是 5 的倍数。
//answer[i] == i （以字符串形式）如果上述条件全不满足。
//示例 1：
//输入：n = 3
//输出：["1", "2", "Fizz"]
//示例 2：
//输入：n = 5
//输出：["1", "2", "Fizz", "4", "Buzz"]
//示例 3：
//输入：n = 15
//输出：["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"]
//提示：
//1 <= n <= 10^4

char* Getstring(int n) {
	int len = 0;
	int a = n;
	while (a) {
		len++;
		a /= 10;
	}
	char* ch = (char*)calloc(len + 1, sizeof(char));
	assert(ch);
	for (int i = len-1; n; i--) {
		ch[i] = n % 10 + '0';
		n /= 10;
	}
	return ch;
}

char** fizzBuzz(int n, int* returnSize) {
	char** ans = (char**)calloc(n, sizeof(char*));
	assert(ans);
	*returnSize = n;
	int i = 0;
	for (int j = 1; j <= n; j++) {
		if (j % 3 == 0 && j % 5 == 0)
			ans[i] = "FizzBuzz";
		else if (j % 3 == 0 && j % 5 != 0)
			ans[i] = "Fizz";
		else if (j % 3 != 0 && j % 5 == 0)
			ans[i] = "Buzz";
		else {
			ans[i] = Getstring(j);
		}
		i++;
	}
	return ans;
}