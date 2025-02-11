#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

//2025.02.12力扣网刷题
//独特的电子邮件地址——数组、哈希表、字符串——简单
//每个 有效电子邮件地址 都由一个 本地名 和一个 域名 组成，以 '@' 符号分隔。除小写字母之外，电子邮件地址还可以含有一个或多个 '.' 或 '+' 。
//例如，在 alice@leetcode.com中， alice 是 本地名 ，而 leetcode.com 是 域名 。
//如果在电子邮件地址的 本地名 部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名中没有点的同一地址。请注意，此规则 不适用于域名 。
//例如，"alice.z@leetcode.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。
//如果在 本地名 中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件。同样，此规则 不适用于域名 。
//例如 m.y + name@email.com 将转发到 my@email.com。
//可以同时使用这两个规则。
//给你一个字符串数组 emails，我们会向每个 emails[i] 发送一封电子邮件。返回实际收到邮件的不同地址数目。
//示例 1：
//输入：emails = ["test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"]
//输出：2
//解释：实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。
//示例 2：
//输入：emails = ["a@leetcode.com", "b@leetcode.com", "c@leetcode.com"]
//输出：3
//提示：
//1 <= emails.length <= 100
//1 <= emails[i].length <= 100
//emails[i] 由小写英文字母、'+'、'.' 和 '@' 组成
//每个 emails[i] 都包含有且仅有一个 '@' 字符
//所有本地名和域名都不为空
//本地名不会以 '+' 字符作为开头
//域名以 ".com" 后缀结尾。
//域名在 ".com" 后缀前至少包含一个字符

void Delete_ch(char** s, int begin, int end) {
	bool flag = true;
	for (int i = begin, j = i; i <= end && j <= end; i++, j++) {
		//@之前
		if (flag) {
			//忽略'.'
			while ((*s)[j] == '.') {
				j += 1;
			}
			//跳过'+'
			if ((*s)[j] == '+') {
				while ((*s)[j] != '@') {
					j += 1;
				}
			}
			if ((*s)[j] == '@') {
				flag = false;
			}
		}
		(*s)[i] = (*s)[j];
	}
}
int numUniqueEmails(char** emails, int emailsSize) {
	for (int i = 0; i < emailsSize; i++) {
		int len = strlen(emails[i]);
		int j = 0;
		while (j < len && emails[i][j] != '.' && emails[i][j] != '+' && emails[i][j] != '@') {
			j += 1;
		}
		if (j < len && emails[i][j] != '@')
			Delete_ch(&emails[i], j, len);
	}
	char** hash = (char**)calloc(emailsSize, sizeof(char*));
	assert(hash);
	int ans = 0;
	for (int i = 0; i < emailsSize; i++) {
		bool same = false;
		int len = strlen(emails[i]);
		for (int j = 0; j < ans; j++) {
			if (strcmp(emails[i], hash[j]) == 0) {
				same = true;
				break;
			}
		}
		if (!same) {
			hash[ans] = (char*)calloc(len + 1, sizeof(char));
			assert(hash[ans]);
			strncpy(hash[ans], emails[i], len);
			ans += 1;
		}
	}
	for (int i = 0; i < ans; i++) {
		free(hash[i]);
		hash[i] = NULL;
	}
	free(hash);
	return ans;
}