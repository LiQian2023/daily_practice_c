#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>

//2025.09.12力扣网刷题
//路径加密——字符串——简单
//假定一段路径记作字符串 path，其中以 "." 作为分隔符。现需将路径加密，加密方法为将 path 中的分隔符替换为空格 " "，请返回加密后的字符串。
//示例 1：
//输入：path = "a.aef.qerf.bb"
//输出："a aef qerf bb"
//限制：
//0 <= path.length <= 10000

char* pathEncryption(char* path) {
	for (int i = 0; path[i]; i++) {
		if (path[i] == '.') {
			path[i] = ' ';
		}
	}
	return path;
}