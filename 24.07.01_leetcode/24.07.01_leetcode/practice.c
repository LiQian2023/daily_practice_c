#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2024.07.01力扣网刷题
//密钥格式化——字符串——简单
//给定一个许可密钥字符串 s，仅由字母、数字字符和破折号组成。字符串由 n 个破折号分成 n + 1 组。你也会得到一个整数 k 。
//我们想要重新格式化字符串 s，使每一组包含 k 个字符，除了第一组，它可以比 k 短，但仍然必须包含至少一个字符。此外，两组之间必须插入破折号，并且应该将所有小写字母转换为大写字母。
//返回 重新格式化的许可密钥 。
//示例 1：
//输入：S = "5F3Z-2e-9-w", k = 4
//输出："5F3Z-2E9W"
//解释：字符串 S 被分成了两个部分，每部分 4 个字符；
//注意，两个额外的破折号需要删掉。
//示例 2：
//输入：S = "2-5g-3-J", k = 2
//输出："2-5G-3J"
//解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
//提示 :
//1 <= s.length <= 10^5
//s 只包含字母、数字和破折号 '-'.
//1 <= k <= 10^4

//方法一：字符串——库函数调用
char* licenseKeyFormatting1(char* s, int k) {
	char* str[100] = { 0 };
	int i = 0;
	//拆分字符串
	for (str[i] = strtok(s, "-"); str[i]; str[i] = strtok(NULL, "-")) 
		i++;
	char str1[100] = { 0 };
	//连接字符串
	for (int j = 0; j < i; j++) 
		strcat(str1, str[j]);
	int len = strlen(str1);
	int n1 = len / k;
	int n2 = len % k;
	char* ans = (char*)calloc(len + n1 + 1, sizeof(char));
	if (!ans)
		return NULL;
	//格式化字符串
	//格式化第一部分
	i = 0;//ans下标
	int j = 0;//str1下标
	while (n2) {
		if (islower(str1[j]))
			str1[j] = toupper(str1[j]);
		ans[i++] = str1[j++];
		n2--;
	}
	if (i && str1[j])
		ans[i++] = '-';
	n2 = k;
	//格式化剩余部分
	for (j; str1[j]; j++) {
		if (!n2 && str1[j]) {
			ans[i++] = '-';
			n2 = k;
		}
		if (islower(str1[j]))
			str1[j] = toupper(str1[j]);
		ans[i++] = str1[j];
		n2--;
	}
	return ans;
}
//方法二：字符串
char* licenseKeyFormatting(char* s, int k) {
	//格式化处理
	int len = 0;
	for (int i = 0; s[i]; i++) {
		if (islower(s[i]))
			s[i] = toupper(s[i]);
		if (s[i] != '-')
			len++;
	}
	int n1 = len / k;
	int n2 = len % k;
	char* ans = (char*)calloc(len + n1 + 1, sizeof(char));
	if (!ans)
		return NULL;
	int i = 0;
	int j = 0;
	//格式化第一部分
	while (n2) {
		if (s[j] == '-')
			j++;
		else {
			ans[i++] = s[j++];
			n2--;
		}
	}
	//处理特殊情况
	if (i && s[j])
		ans[i++] = '-';
	n2 = k;
	//格式化剩余部分
	while (s[j]) {
		if (s[j] == '-')
			j++;
		else {
			if (!n2 && s[j]) {
				ans[i++] = '-';
				n2 = k;
			}
			else {
				ans[i++] = s[j++];
				n2--;
			}
		}
	}
	return ans;
}
void test1() {
	char str[100] = { 0 };
	int k = 0;
	while (scanf("%s%d", str, &k) == 2) {
		char* ret = licenseKeyFormatting(str, k);
		printf("%s\n", ret);
		free(ret);
	}
}

int main() {
	test1();
	return 0;
}