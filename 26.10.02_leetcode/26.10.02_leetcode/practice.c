#include <stdio.h>
#include <stdbool.h>

//2026.10.02力扣网刷题
//357. 统计各位数字都不同的数字个数——数学、动态规划、回溯——中等
//给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10n 。
//示例 1：
//输入：n = 2
//输出：91
//解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围内的所有数字。
//示例 2：
//输入：n = 0
//输出：1
//提示：
//0 <= n <= 8

int countNumbersWithUniqueDigits1(int n) {
	int dp[9] = { 0 };
	dp[0] = 1;
	dp[1] = 9;
	for (int i = 2; i < 9; i++) {
		dp[i] = dp[i - 1] * (11 - i);
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += dp[i];
	}
	return ans;
}
void DFS(int n, int count, bool* visited, int* ans) {
	if (count > n) {
		return;
	}
	*ans += 1;
	if (count == n) {
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		DFS(n, count + 1, visited, ans);
		visited[i] = false;
	}
}
int countNumbersWithUniqueDigits(int n) {
	int ans = 1;
	bool visited[10] = { 0 };
	for (int i = 1; i < 10; i++) {
		visited[i] = true;
		DFS(n, 1, visited, &ans);
		visited[i] = false;
	}
	return ans;
}