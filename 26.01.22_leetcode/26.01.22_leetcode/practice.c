#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.01.22力扣网刷题
//LCR 041. 数据流中的移动平均值——设计、队列、数组、数据流——简单
//给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。
//实现 MovingAverage 类：
//MovingAverage(int size) 用窗口大小 size 初始化对象。
//double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。
//示例：
//输入：
//inputs = ["MovingAverage", "next", "next", "next", "next"]
//inputs = [[3], [1], [10], [3], [5]]
//输出：
//[null, 1.0, 5.5, 4.66667, 6.0]
//解释：
//MovingAverage movingAverage = new MovingAverage(3);
//movingAverage.next(1); // 返回 1.0 = 1 / 1
//movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
//movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
//movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
//提示：
//1 <= size <= 1000
//- 105 <= val <= 10^5
//最多调用 next 方法 10^4 次
//注意：本题与主站 346 题相同： https ://leetcode.cn/problems/moving-average-from-data-stream/

typedef struct {
	int maxSize;
	int* data;
	int len;
} MovingAverage;

/** Initialize your data structure here. */

MovingAverage* movingAverageCreate(int size) {
	MovingAverage* obj = (MovingAverage*)malloc(sizeof(MovingAverage));
	assert(obj);
	obj->maxSize = size;
	obj->data = (int*)malloc(sizeof(int) * size);
	assert(obj->data);
	obj->len = 0;
	return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
	double average = 0.0;
	obj->len += 1;
	if (obj->len > obj->maxSize) {
		for (int i = 0; i < obj->maxSize - 1; i++) {
			obj->data[i] = obj->data[i + 1];
		}
		obj->data[obj->maxSize - 1] = val;
		obj->len -= 1;
	}
	else {
		obj->data[obj->len - 1] = val;
	}
	for(int i = 0;i<obj->len;i++){
		average += obj->data[i];
	}
	return average / obj->len;
}

void movingAverageFree(MovingAverage* obj) {
	free(obj->data);
	free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);

 * movingAverageFree(obj);
*/