#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2026.05.08力扣网刷题
//LCR 042. 最近的请求次数——设计、队列、数据流——简单
//写一个 RecentCounter 类来计算特定时间范围内最近的请求。
//请实现 RecentCounter 类：
//RecentCounter() 初始化计数器，请求数为 0 。
//int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在[t - 3000, t] 内发生的请求数。
//保证 每次对 ping 的调用都使用比之前更大的 t 值。
//示例：
//输入：
//inputs = ["RecentCounter", "ping", "ping", "ping", "ping"]
//inputs = [[], [1], [100], [3001], [3002]]
//输出：
//[null, 1, 2, 3, 3]
//解释：
//RecentCounter recentCounter = new RecentCounter();
//recentCounter.ping(1);     // requests = [1]，范围是 [-2999,1]，返回 1
//recentCounter.ping(100);   // requests = [1, 100]，范围是 [-2900,100]，返回 2
//recentCounter.ping(3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
//recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]，范围是 [2,3002]，返回 3
//提示：
//1 <= t <= 10^9
//保证每次对 ping 调用所使用的 t 值都 严格递增
//至多调用 ping 方法 10^4 次
//注意：本题与主站 933 题相同： https ://leetcode.cn/problems/number-of-recent-calls/

typedef struct {
	int* data;
	int front;
	int rear;
	int baseSize;
	int len;
} RecentCounter;


RecentCounter* recentCounterCreate() {
	RecentCounter* obj = (RecentCounter*)calloc(1, sizeof(RecentCounter));
	assert(obj);
	obj->baseSize = 10;
	obj->data = (int*)calloc(obj->baseSize, sizeof(int));
	assert(obj->data);
	obj->front = 0;
	obj->rear = 0;
	obj->len = 0;
	return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
	int left = t - 3000;
	while (obj->len && obj->data[obj->front] < left) {
		obj->len -= 1;
		obj->front = (obj->front + 1) % obj->baseSize;
	}
	obj->len += 1;
	if (obj->len == obj->baseSize) {
		int size = obj->baseSize + obj->baseSize / 2;
		int* tmp = (int*)calloc(size, sizeof(int));
		assert(tmp);
		int j = 0;
		for (int i = obj->front; i != obj->rear; i = (i + 1) % obj->baseSize, j += 1) {
			tmp[j] = obj->data[i];
		}
		free(obj->data);
		obj->data = tmp;
		obj->front = 0;
		obj->rear = j;
		obj->baseSize = size;
	}
	obj->data[obj->rear] = t;
	obj->rear = (obj->rear + 1) % obj->baseSize;
	return obj->len;
}

void recentCounterFree(RecentCounter* obj) {
	free(obj->data);
	obj->data = NULL;
	free(obj);
	obj = NULL;
}