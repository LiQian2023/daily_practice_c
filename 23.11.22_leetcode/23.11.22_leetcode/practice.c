#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.11.22力扣刷题

//最小偶倍数——数学、数论——简单
//给你一个正整数 n ，返回 2 和 n 的最小公倍数（正整数）。
//示例 1：
//输入：n = 5
//输出：10
//解释：5 和 2 的最小公倍数是 10 。
//示例 2：
//输入：n = 6
//输出：6
//解释：6 和 2 的最小公倍数是 6 。注意数字会是它自身的倍数。
//提示：
//1 <= n <= 150
int smallestEvenMultiple(int n) {
	if (n % 2 == 0)
		return n;
	return 2 * n;
}



#if 0
////温度转换——数学——简单
////给你一个四舍五入到两位小数的非负浮点数celsius来表示温度
//// 以摄氏度(Celsius)为单位
//// 你需要将摄氏度转化为开氏度(Kelvin)和华氏度(Fahrenheit)，
//// 并以数组ans=[kelvin,fahrenheit]的形式返回结果
//// 返回数组ans。与实际误差不超过10^(-5)的会视为正确答案
//// 开氏度=摄氏度+273.15
//// 华氏度=摄氏度*1.80+32
//// 输入：celsius=36.50
//// 输出：[309.65000,97.70000]
//// 解释：36.5摄氏度：转化为开氏度是309.65，
//// 转化为华氏度是97.70.
//// 输入：celsius=122.11
//// 输出：[395.26000,251.79800]
//// 解释：122.11摄氏度：转化为开氏度是395.26，
//// 转化为华氏度是251.798.
////0<=celsius<=1000
//
//double* convertTemperature(double celsius, int* returnSize) {
//	double kelvin= celsius + 273.15;
//	double fahrenheit = celsius * 1.80 + 32.00;
//	return   [kelvin ,fahrenheit] ;
//}
#endif