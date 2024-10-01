#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
//2024.10.01力扣网刷题
//最大数——贪心、数组、字符串、排序——中等
//给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
//注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
//示例 1：
//输入：nums = [10, 2]
//输出："210"
//示例 2：
//输入：nums = [3, 30, 34, 5, 9]
//输出："9534330"
//提示：
//1 <= nums.length <= 100
//0 <= nums[i] <= 10^9


int cmp(const void** p1, const void** p2) {
	char* str1 = *(char**)p1;
	char* str2 = *(char**)p2;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 == len2)
		return strcmp(str2, str1);
	int i = 0, j = 0;
	for (; i < len1 && j < len2;i+=1,j+=1) {
		if (str1[i] != str2[j])
			return str2[i] - str1[j];
	}
	if (len1 > len2)
		return str2[j - 1] - str1[i];
	return str2[j] - str1[i - 1];
}
char* get_Str(int x) {
	char* tmp = (char*)calloc(11, sizeof(char));
	assert(tmp);
	if (x == 0) {
		tmp[0] = '0';
	}
	else {
		int n = 0;
		for (int a = x; a; a /= 10) {
			n += 1;
		}
		for (int i = n - 1; i >= 0; i--) {
			tmp[i] = x % 10 + '0';
			x /= 10;
		}
	}
	return tmp;
}
void MergeSort(char** a, int left, int right, char** b) {
	if (left >= right)
		return;
	//分区
	int key = (right - left) / 2;
	MergeSort(a, left, left + key, b);
	MergeSort(a, left + key + 1, right, b);
	//归并
	int size = left;
	int i = left, j = left + key + 1;
	while (i <= left + key && j <= right) {
		int len1 = strlen(a[i]);
		int len2 = strlen(a[j]);
		char* tmp1 = (char*)calloc(len1 + len2 + 1, sizeof(char));
		assert(tmp1);
		strncat(tmp1, a[i],len1);
		strncat(tmp1, a[j], len2);
		char* tmp2 = (char*)calloc(len1 + len2 + 1, sizeof(char));
		assert(tmp1);
		strncat(tmp2, a[j], len2);
		strncat(tmp2, a[i], len1);
		if (strcmp(tmp1, tmp2) > 0) {
			b[size] = (char*)calloc(len1 + 1, sizeof(char));
			assert(b[size]);
			memcpy(b[size], a[i], len1);
			i += 1;
		}
		else{
			b[size] = (char*)calloc(len2 + 1, sizeof(char));
			assert(b[size]);
			memcpy(b[size], a[j], len2);
			j += 1;
		}
		size += 1;
		free(tmp1);
		tmp1 = NULL;
		free(tmp2);
		tmp2 = NULL;
	}
	while (i <= left + key) {
		int len1 = strlen(a[i]);
		b[size] = (char*)calloc(len1 + 1, sizeof(char));
		assert(b[size]);
		memcpy(b[size], a[i], len1);
		size += 1;
		i += 1;
	}
	while (j <= right) {
		int len2 = strlen(a[j]);
		b[size] = (char*)calloc(len2 + 1, sizeof(char));
		assert(b[size]);
		memcpy(b[size], a[j], len2);
		size += 1;
		j += 1;
	}
	//复制
	for (int i = left; i <= right; i++) {
		memcpy(a[i], b[i], strlen(b[i]) + 1);
		free(b[i]);
		b[i] = NULL;
	}
}
char* largestNumber(int* nums, int numsSize) {
	char** ch = (char**)calloc(numsSize, sizeof(char*));
	assert(ch);
	//转字符串
	for (int i = 0; i < numsSize; i++) {
		ch[i] = get_Str(nums[i]);
	}
	//计算字符串长度
	int len = 0;
	for (int i = 0; i < numsSize; i++) {
		len += strlen(ch[i]);
	}
	//申请空间
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	//归并排序
	char** tmp = (char**)calloc(numsSize, sizeof(char*));
	assert(tmp);
	MergeSort(ch, 0, numsSize - 1, tmp);
	//合并字符串
	for (int i = 0; i < numsSize; i++) {
		strncat(ans, ch[i], strlen(ch[i]));
	}
	if (ans[0] == '0')
		ans[1] = 0;
	//释放临时空间
	free(tmp);
	tmp = NULL;
	for (int i = 0; i < numsSize; i++) {
		free(ch[i]);
		ch[i] = NULL;
	}
	free(ch);
	ch = NULL;
	return ans;
}

void test() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int size = 10;
	char* ret = largestNumber(arr, size);
	printf("%s\n", ret);
	free(ret);
	ret = NULL;
}

void test1() {
	char str1[10] = "abc";
	char str2[10] = "def";
	strncat(str1, str2, 3);
	for (int i = 0; i < 3; i++) {
		str2[i] = 0;
	}
	printf("%s\n", str1);
}
int main() {
	test();
	return 0;
}