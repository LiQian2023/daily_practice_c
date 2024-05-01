#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//2024.05.01力扣网刷题
//Excel 表列序号——数学、字符串——简单
//给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回 该列名称对应的列序号 。
//例如：
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//示例 1:
//输入: columnTitle = "A"
//输出 : 1
//示例 2 :
//	输入 : columnTitle = "AB"
//	输出 : 28
//	示例 3 :
//	输入 : columnTitle = "ZY"
//	输出 : 701
//	提示：
//	1 <= columnTitle.length <= 7
//	columnTitle 仅由大写英文组成
//	columnTitle 在范围["A", "FXSHRXW"] 内

int titleToNumber1(char* columnTitle) {
	int ans = 0;
	for (int i = 0; i < strlen(columnTitle); i++)
		ans = ans * 26 + (columnTitle[i] - 'A') + 1;
	return ans;
}

int titleToNumber(char* columnTitle) {
	int ans = 0;
	for (int i = 0; columnTitle[i]; i++)
		ans = ans * 26 + (columnTitle[i] - 'A') + 1;
	return ans;
}
void test() {
	char ch[7] = { 0 };
	while (scanf("%s", ch) == 1) {
		printf("%d\n", titleToNumber(ch));
	}
}

int main() {
	test();
	return 0;
}