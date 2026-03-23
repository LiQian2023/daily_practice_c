#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.03.23力扣网刷题
//3842. 切换打开灯泡——中级工程师、数组、哈希表、排序、模拟、第489场周赛——简单
//给你一个整数数组 bulbs，其中每个元素的取值范围为 1 到 100。
//有 100 个电灯泡，按从 1 到 100 编号，初始时所有灯泡均为关闭状态。
//对于数组 bulbs 中的每一个元素 bulbs[i]，执行以下操作：
//如果第 bulbs[i] 个灯泡当前是关闭状态，将其打开。
//如果第 bulbs[i] 个灯泡当前是打开状态，将其关闭。
//返回一个整数列表，表示最终处于打开状态的灯泡编号，按升序排列。如果没有灯泡是打开的，返回一个空列表。
//示例 1：
//输入： bulbs = [10, 30, 20, 10]
//输出：[20, 30]
//解释：
//第 bulbs[0] = 10 个灯泡当前是关闭状态，将其打开。
//第 bulbs[1] = 30 个灯泡当前是关闭状态，将其打开。
//第 bulbs[2] = 20 个灯泡当前是关闭状态，将其打开。
//第 bulbs[3] = 10 个灯泡当前是打开状态，将其关闭。
//最终，第 20 个和第 30 个灯泡处于打开状态。
//示例 2：
//输入： bulbs = [100, 100]
//输出：[]
//解释：
//第 bulbs[0] = 100 个灯泡当前是关闭状态，将其打开。
//第 bulbs[1] = 100 个灯泡当前是打开状态，将其关闭。
//最终，没有灯泡处于打开状态。
//提示：
//1 <= bulbs.length <= 100
//1 <= bulbs[i] <= 100

int* toggleLightBulbs(int* bulbs, int bulbsSize, int* returnSize) {
	int hash[101] = { 0 };
	*returnSize = 0;
	for (int i = 0; i < bulbsSize; i++) {
		hash[bulbs[i]] = !hash[bulbs[i]];
		if (hash[bulbs[i]]) {
			*returnSize += 1;
		}
		else {
			*returnSize -= 1;
		}
	}
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	int size = 0;
	for (int i = 0; i < 101; i++) {
		if (hash[i]) {
			ans[size] = i;
			size += 1;
		}
	}
	return ans;
}