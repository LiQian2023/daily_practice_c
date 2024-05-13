#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.05.13力扣网刷题
//递枕头——数学、模拟——简单
//n 个人站成一排，按从 1 到 n 编号。
//最初，排在队首的第一个人拿着一个枕头。每秒钟，拿着枕头的人会将枕头传递给队伍中的下一个人。
//一旦枕头到达队首或队尾，传递方向就会改变，队伍会继续沿相反方向传递枕头。
//例如，当枕头到达第 n 个人时，TA 会将枕头传递给第 n - 1 个人，然后传递给第 n - 2 个人，依此类推。
//给你两个正整数 n 和 time ，返回 time 秒后拿着枕头的人的编号。
//示例 1：
//输入：n = 4, time = 5
//输出：2
//解释：队伍中枕头的传递情况为：1 -> 2 -> 3 -> 4 -> 3 -> 2 。
//5 秒后，枕头传递到第 2 个人手中。
//示例 2：
//输入：n = 3, time = 2
//输出：3
//解释：队伍中枕头的传递情况为：1 -> 2 -> 3 。
//2 秒后，枕头传递到第 3 个人手中。
//提示：
//2 <= n <= 1000
//1 <= time <= 1000

//方法一：模拟
int passThePillow(int n, int time) {
	int flag = 0;
	int i = 1;
	for (int j = 1; j <= time; j++) {
		if (flag == 0 && i < n)
			i++;
		else if (flag == 0 && i == n) {
			flag = 1;
			i--;
		}
		else if (flag == 1 && i > 1)
			i--;
		else if (flag == 1 && i == 1) {
			flag = 0;
			i++;
		}
	}
	return i;
}

//方法二：数学
int passThePillow(int n, int time) {
	time = time % ((n - 1) * 2);
	if (time > n - 1)
		time = (n - 1) * 2 - time;
	return time + 1;
}