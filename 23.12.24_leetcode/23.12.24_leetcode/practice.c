#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2023.12.24力扣网刷题
//加一——数学、数组——简单
//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//示例 1：
//输入：digits = [1, 2, 3]
//输出：[1, 2, 4]
//解释：输入数组表示数字 123。
//示例 2：
//输入：digits = [4, 3, 2, 1]
//输出：[4, 3, 2, 2]
//解释：输入数组表示数字 4321。
//示例 3：
//输入：digits = [0]
//输出：[1]
//提示：
//1 <= digits.length <= 100
//0 <= digits[i] <= 9
#include <assert.h>
#include <stdlib.h>
#include <math.h>

//法一：合并与拆分
int* plusOne1(int* digits, int digitsSize, int* returnSize) {
	assert(digits && returnSize);
	long long sum = 0;
	for (int i = 0; i < digitsSize; i++)
		sum += digits[i] * pow(10, digitsSize - 1 - i);
	sum += 1;
	long long a = sum;
	for (*returnSize = 0; a > 0; a /= 10)
	{
		*returnSize += 1;
	}
	int* ans = (int*)calloc(*returnSize, sizeof(int));

	for (int i = 0; i < *returnSize; i++)
	{
		ans[i] = sum % 10;
		sum /= 10;
	}
	int l = 0, r = *returnSize - 1;
	while (l < r)
	{
		int tmp = ans[l];
		ans[l] = ans[r];
		ans[r] = tmp;
		l++, r--;
	}
	return ans;
}
//法二：顺序表
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	if ((!digits) && (!returnSize))
		return NULL;
	*returnSize = digitsSize;
	int* ans = (int*)calloc(digitsSize, sizeof(int));
	if (!ans)
		return NULL;
	digits[digitsSize - 1] += 1;
	//创建顺序表
	int i = 0, j = digitsSize - 1;
	while (i < digitsSize) {
		ans[i++] = digits[j--];
	}
	//进位
	for (j = 0; j < i - 1; j++) {
		if (ans[j] > 9) {
			ans[j] %= 10;
			ans[j + 1]++;
		}
	}
	if (ans[j] > 9) {
		ans = (int*)realloc(ans, sizeof(int) * (i + 1));
		ans[j] %= 10;
		ans[j + 1] = 1;
		j++;
	}
	*returnSize = j + 1;
	//翻转
	for (i = 0, j; i < j; i++, j--) {
		int tmp = ans[i];
		ans[i] = ans[j];
		ans[j] = tmp;
	}
	return ans;
}
int main()
{
	int arr[100] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int* ret = NULL;
		int size = 0;
		ret = plusOne(arr, n, &size);
		for (int i = 0; i < size; i++)
		{
			printf("%d ", ret[i]);
		}
		printf("\n");
	}
	return 0;
}