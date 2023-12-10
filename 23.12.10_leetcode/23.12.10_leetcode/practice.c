#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.10力扣网刷题
//爬楼梯——记忆化搜索、数学、动态规划——简单
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//示例 1：
//输入：n = 2
//输出：2
//解释：有两种方法可以爬到楼顶。
//1. 1 阶 + 1 阶
//2. 2 阶
//示例 2：
//输入：n = 3
//输出：3
//解释：有三种方法可以爬到楼顶。
//1. 1 阶 + 1 阶 + 1 阶
//2. 1 阶 + 2 阶
//3. 2 阶 + 1 阶
//提示：
//1 <= n <= 45

//法一：递归求解
int climbStairs1(int n) {
	if (1 == n)
		return 1;
	else if (2 == n)
		return 2;
	else
		return climbStairs(n - 1) + climbStairs(n - 2);
}
//法二：迭代求解
int climbStairs(int n) {
	if (1 == n)
		return 1;
	else if (2 == n)
		return 2;
	else
	{
		int a = 1;
		int b = 2;
		int c = a + b;
		for (int i = 3; i < n; i++)
		{
			a = b;
			b = c;
			c = a + b;
		}
		return c;
	}
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
		printf("%d\n", climbStairs(n));
	return 0;
}
