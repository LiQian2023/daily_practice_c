#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.01.03力扣网刷题
//数组元素积的符号——数学、数组——简单
//已知函数 signFunc(x) 将会根据 x 的正负返回特定值：
//如果 x 是正数，返回 1 。
//如果 x 是负数，返回 - 1 。
//如果 x 是等于 0 ，返回 0 。
//给你一个整数数组 nums 。令 product 为数组 nums 中所有元素值的乘积。
//返回 signFunc(product) 。
//示例 1：
//输入：nums = [-1, -2, -3, -4, 3, 2, 1]
//输出：1
//解释：数组中所有值的乘积是 144 ，且 signFunc(144) = 1
//示例 2：
//输入：nums = [1, 5, 0, 2, -3]
//输出：0
//解释：数组中所有值的乘积是 0 ，且 signFunc(0) = 0
//示例 3：
//输入：nums = [-1, 1, -1, 1, -1]
//输出： - 1
//解释：数组中所有值的乘积是 - 1 ，且 signFunc(-1) = -1
//提示：
//1 <= nums.length <= 1000
//- 100 <= nums[i] <= 100
int signFunc(int x) {
	if (x > 0)
		return 1;
	else if (x < 0)
		return -1;
	else
		return 0;
}

int arraySign(int* nums, int numsSize) {
	int count = 1;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] < 0)
		{
			count *= -1;
		}
		else if (nums[i] == 0) {
			count = 0;
			break;
		}
	}
	return signFunc(count);
}
int main() {
	int arr[1000] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int ret = arraySign(arr, n);
		printf("%d\n", ret);
	}
	return 0;
}






////求两个整数的最小公倍数
//int main()
//{
//	int x = 0, y = 0;
//	while (scanf("%d%d", &x, &y) == 2) {
//		if (x < y) {
//			x ^= y;
//			y ^= x;
//			x ^= y;
//		}
//		int z = x * y;
//		int i = x;
//		while (i % x != 0 || i % y != 0 || i > z) {
//			i++;
//		}
//		printf("%d\n", i);
//	}
//	return 0;
//}

////求两个整数的最小公倍数
//int main() {
//	int a = 0, b = 0;
//	scanf("%d%d", &a, &b);
//	int mul = a * b;//两数乘积
//	//交换a，b确保a>b
//	if (a < b) {
//		a ^= b;
//		b ^= a;
//		a ^= b;
//	}
//	//找最大公因数——辗转相除法
//	int c = a % b;
//	while (c != 0) {
//		a = b;
//		b = c;
//	}
//	printf("%d\n", mul / b);
//	return 0;
//}

////求两个整数的最小公倍数
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d%d", &a, &b);
//	if (a < b) {//交换a，b确保a>b
//		a ^= b;
//		b ^= a;
//		a ^= b;
//	}
//	//求最小公倍数
//	int min = a;
//	while (min % b != 0 || min % a != 0) {
//		min++;
//	}
//	printf("%d\n", min);
//	return 0;
//}