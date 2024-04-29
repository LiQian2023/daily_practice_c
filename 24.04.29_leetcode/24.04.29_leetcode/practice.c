#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.04.29力扣网刷题
//换水问题——数学、模拟——简单
//超市正在促销，你可以用 numExchange 个空水瓶从超市兑换一瓶水。最开始，你一共购入了 numBottles 瓶水。
//如果喝掉了水瓶中的水，那么水瓶就会变成空的。
//给你两个整数 numBottles 和 numExchange ，返回你 最多 可以喝到多少瓶水。
//示例 1：
//输入：numBottles = 9, numExchange = 3
//输出：13
//解释：你可以用 3 个空瓶兑换 1 瓶水。
//所以最多能喝到 9 + 3 + 1 = 13 瓶水。
//示例 2：
//输入：numBottles = 15, numExchange = 4
//输出：19
//解释：你可以用 4 个空瓶兑换 1 瓶水。
//所以最多能喝到 15 + 3 + 1 = 19 瓶水。
//提示：
//1 <= numBottles <= 100
//2 <= numExchange <= 100

//方法一：模拟
int numWaterBottles(int numBottles, int numExchange) {
	int empty = 0;
	int drink = 0;
	while (numBottles) {
		drink += numBottles;//喝饮料
		empty += numBottles;//获取空瓶
		numBottles = empty / numExchange;//兑换饮料
		empty = empty % numExchange;//剩余空瓶
	}
	return drink;
}
//方法二：数学
int numWaterBottles(int numBottles, int numExchange) {
	return numBottles >= numExchange ? numBottles + (numBottles - numExchange) / (numExchange - 1) + 1 : numBottles;
}