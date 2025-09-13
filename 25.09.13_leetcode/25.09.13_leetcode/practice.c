#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2025.09.13力扣网刷题
//动态口令——数组、字符串、双指针——简单
//某公司门禁密码使用动态口令技术。初始密码为字符串 password，密码更新均遵循以下步骤：
//设定一个正整数目标值 target
//将 password 前 target 个字符按原顺序移动至字符串末尾
//请返回更新后的密码字符串。
//示例 1：
//输入 : password = "s3cur1tyC0d3", target = 4
//输出 : "r1tyC0d3s3cu"
//示例 2：
//输入 : password = "lrloseumgh", target = 6
//输出 : "umghlrlose"
//提示：
//1 <= target < password.length <= 10000

char* dynamicPassword(char* password, int target) {
	int len = strlen(password);
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	int size = 0;
	for (int i =  target; i < len; size++, i++) {
		ans[size] = password[i];
	}
	for (int i = 0; i < target; size++, i++) {
		ans[size] = password[i];
	}
	return ans;
}