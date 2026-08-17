#include <stdio.h>

//2026.08.17力扣网刷题
//4020. 电梯请求 I——中级工程师、第189场双周赛——简单
//给你一个整数 n ，表示一栋楼房的楼层数，楼层编号从 0 到 n - 1 。
//同时给你一个整数数组 requests ，其中 requests 表示楼层请求的序列。
//一部电梯初始在 0 层，遵循以下规则：
//电梯每秒移动一层。
//电梯按给定的顺序处理请求。
//如果电梯已经在请求的楼层，则不需要移动。
//处理完一个请求后，电梯立即开始向下一个请求的楼层移动。
//返回处理所有请求所需的 总时间 （以秒为单位）。
//示例 1：
//输入： n = 5, requests = [2, 1, 4, 3]
//输出： 7
//解释：
//requests[0] = 2：从 0 层移动到 2 层需要 2 秒。
//requests[1] = 1：从 2 层移动到 1 层需要 1 秒。
//requests[2] = 4：从 1 层移动到 4 层需要 3 秒。
//requests[3] = 3：从 4 层移动到 3 层需要 1 秒。
//所需的总时间是 2 + 1 + 3 + 1 = 7 秒。
//示例 2：
//输入： n = 3, requests = [2, 0, 0]
//输出： 4
//解释：
//requests[0] = 2：从 0 层移动到 2 层需要 2 秒。
//requests[1] = 0：从 2 层移动到 0 层需要 2 秒。
//requests[2] = 0：不需要移动。
//所需的总时间是 2 + 2 + 0 = 4 秒。
//提示：
//1 <= n <= 100
//1 <= requests.length <= 100
//0 <= requests[i] <= n - 1

int elevatorRequests(int n, int* requests, int requestsSize) {
	int ans = 0, cur = 0;
	for (int i = 0; i < requestsSize; i++) {
		ans += abs(requests[i] - cur);
		cur = requests[i];
	}
	return ans;
}