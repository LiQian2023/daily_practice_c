#include <stdio.h>
#include <stdbool.h>

//20226.02.18力扣网刷题
//693. 交替位二进制数——位运算——简单
//给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。
//示例 1：
//输入：n = 5
//输出：true
//解释：5 的二进制表示是：101
//示例 2：
//输入：n = 7
//输出：false
//解释：7 的二进制表示是：111.
//示例 3：
//输入：n = 11
//输出：false
//解释：11 的二进制表示是：1011.
//提示：
//1 <= n <= 2^31 - 1

bool hasAlternatingBits(int n) {
	int pre = n & 1;
	while (n) {
		n >>= 1;
		int bit = n & 1;
		if (bit != pre) {
			pre = bit;
		}
		else {
			return false;
		}
	}
	return true;
}