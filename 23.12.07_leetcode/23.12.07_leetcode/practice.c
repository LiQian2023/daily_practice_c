#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.07力扣网刷题
//温度转换——数学——简单
//给你一个四舍五入到两位小数的非负浮点数 celsius 来表示温度，以 摄氏度（Celsius）为单位。
//你需要将摄氏度转换为 开氏度（Kelvin）和 华氏度（Fahrenheit），并以数组 ans = [kelvin, fahrenheit] 的形式返回结果。
//返回数组 ans 。与实际答案误差不超过 10 - 5 的会视为正确答案。
//注意：
//开氏度 = 摄氏度 + 273.15
//华氏度 = 摄氏度 * 1.80 + 32.00
//示例 1 ：
//输入：celsius = 36.50
//输出：[309.65000, 97.70000]
//解释：36.50 摄氏度：转换为开氏度是 309.65 ，转换为华氏度是 97.70 。
//示例 2 ：
//输入：celsius = 122.11
//输出：[395.26000, 251.79800]
//解释：122.11 摄氏度：转换为开氏度是 395.26 ，转换为华氏度是 251.798 。
//提示：
//0 <= celsius <= 1000
#include <stdlib.h>


double* convertTemperature(double celsius, int* returnSize) {
	double* ans = (double*)malloc(16);
	if (ans == NULL)
		return NULL;
	ans[0] = celsius + 273.15;
	ans[1] = celsius * 1.80 + 32.00;
	*returnSize = 2;
	return ans;
}
int main()
{
	double n = 0;
	while (scanf("%lf", &n) == 1)
	{
		int m = 20;
		double* p = convertTemperature(n, &m);
		printf("[%3.5lf, %3.5lf]\n", p[0], p[1]);
		free(p);
	}
	return 0;
}