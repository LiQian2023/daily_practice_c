#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.03.08力扣网刷题
//3683. 完成一个任务的最早时间——中级工程师、第467场周赛——简单
//给你一个二维整数数组 tasks，其中 tasks[i] = [si, ti]。
//数组中的每个[si, ti] 表示一个任务，该任务的开始时间为 si，完成该任务需要 ti 个时间单位。
//返回至少完成一个任务的最早时间。
//示例 1：
//输入： tasks = [[1, 6], [2, 3]]
//输出： 5
//解释：
//第一个任务从时间 t = 1 开始，并在 1 + 6 = 7 时完成。第二个任务在时间 t = 2 开始，并在 2 + 3 = 5 时完成。因此，最早完成的任务在时间 5。
//示例 2：
//输入： tasks = [[100, 100], [100, 100], [100, 100]]
//输出： 200
//解释：
//三个任务都在时间 100 + 100 = 200 时完成。
//提示：
//1 <= tasks.length <= 100
//tasks[i] = [si, ti]
//1 <= si, ti <= 100

int earliestTime(int** tasks, int tasksSize, int* tasksColSize) {
	int ans = tasks[0][0] + tasks[0][1];
	for (int i = 1; i < tasksSize; i++) {
		int time = tasks[i][0] + tasks[i][1];
		if(time < ans) {
			ans = time;
		}
	}
	return ans;
}