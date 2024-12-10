#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//2024.12.10力扣网刷题
//统计对称整数的数目——数学、枚举——简单
//给你两个正整数 low 和 high 。
//对于一个由 2 * n 位数字组成的整数 x ，如果其前 n 位数字之和与后 n 位数字之和相等，则认为这个数字是一个对称整数。
//返回在[low, high] 范围内的 对称整数的数目 。
//示例 1：
//输入：low = 1, high = 100
//输出：9
//解释：在 1 到 100 范围内共有 9 个对称整数：11、22、33、44、55、66、77、88 和 99 。
//示例 2：
//输入：low = 1200, high = 1230
//输出：4
//解释：在 1200 到 1230 范围内共有 4 个对称整数：1203、1212、1221 和 1230 。
//提示：
//1 <= low <= high <= 10^4
int get_count(int n) {
	int ans = 0;
	while (n) {
		ans += 1;
		n /= 10;
	}
	return ans;
}
int Sum(int n) {
	int ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
int countSymmetricIntegers(int low, int high) {
	int ans = 0;
	for (int i = low; i <= high; i++) {
		int count = get_count(i);
		if (count % 2) {
			continue;
		}
		int n = count / 2;
		int div = (int)pow(10, n);
		int a = i / div;
		int b = i % div;
		if (Sum(a) == Sum(b))
			ans += 1;
	}
	return ans;
}