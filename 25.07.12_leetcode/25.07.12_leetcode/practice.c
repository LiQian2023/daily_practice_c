#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2025.07.12力扣网刷题
//IP 地址无效化——字符串——简单
//给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
//所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。
//示例 1：
//输入：address = "1.1.1.1"
//输出："1[.]1[.]1[.]1"
//示例 2：
//输入：address = "255.100.50.0"
//输出："255[.]100[.]50[.]0"
//提示：
//给出的 address 是一个有效的 IPv4 地址

char* defangIPaddr(char* address) {
	int size = 0;
	int len = strlen(address);
	for (int i = 0; i < len; i++) {
		if (address[i] == '.') {
			size += 1;
		}
	}
	char* ans = (char*)calloc(len + 2 * size + 1, sizeof(char));
	assert(ans);
	for (int i = 0, j = 0; i < len; i++) {
		if (address[i] == '.') {
			ans[j] = '[';
			ans[j + 1] = address[i];
			ans[j + 2] = ']';
			j += 3;
		}
		else {
			ans[j] = address[i];
			j += 1;
		}
	}
	return ans;
}