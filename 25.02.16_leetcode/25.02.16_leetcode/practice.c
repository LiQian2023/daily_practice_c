#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.02.16力扣网刷题
//将每个元素替换为右侧最大元素——数组——简单
//给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 - 1 替换。
//完成所有替换操作后，请你返回这个数组。
//示例 1：
//输入：arr = [17, 18, 5, 4, 6, 1]
//输出：[18, 6, 6, 6, 1, -1]
//解释：
//- 下标 0 的元素-- > 右侧最大元素是下标 1 的元素(18)
//- 下标 1 的元素-- > 右侧最大元素是下标 4 的元素(6)
//- 下标 2 的元素-- > 右侧最大元素是下标 4 的元素(6)
//- 下标 3 的元素-- > 右侧最大元素是下标 4 的元素(6)
//- 下标 4 的元素-- > 右侧最大元素是下标 5 的元素(1)
//- 下标 5 的元素-- > 右侧没有其他元素，替换为 - 1
//示例 2：
//输入：arr = [400]
//输出：[-1]
//解释：下标 0 的元素右侧没有其他元素。
//提示：
//1 <= arr.length <= 10^4
//1 <= arr[i] <= 10^5

typedef struct Hash_Count {
	int i;//下标
	int count;//计数
}HC;

void Print(int* h, int len) {
	for (int i = 0; i < len; i++) {
		printf("h[%d] = %d\n", i, h[i]);
	}
}
int* replaceElements1(int* arr, int arrSize, int* returnSize) {
	//找最值
	int max = arr[0], min = arr[0];
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	//计数
	HC* tmp = (HC*)calloc(max - min + 1, sizeof(HC));
	assert(tmp);
	for (int i = 0; i < arrSize; i++) {
		int key = arr[i] - min;
		if (i > tmp[key].i) {
			tmp[key].i = i;
		}
		tmp[key].count += 1;
	}
	//哈希表排序
	int* h = (int*)calloc(arrSize, sizeof(int));
	assert(h);
	int key = 0;
	for (int i = max - min; i >= 0; i--) {
		while (tmp[i].count) {
			h[key] = tmp[i].i;
			tmp[i].count -= 1;
			key += 1;
		}
	}
	free(tmp);
	//哈希表遍历
	*returnSize = arrSize;
	int* ans = (int*)calloc(arrSize, sizeof(int));
	assert(ans);
	for (int i = 0, index = 0; i < arrSize && index < arrSize;) {
		int key = h[index];
		if (key > i) {
			ans[i] = arr[key];
			i += 1;
		}
		else if (key <= i) {
			index += 1;
		}
	}
	free(h);
	ans[arrSize - 1] = -1;
	return ans;
}

int* replaceElements(int* arr, int arrSize, int* returnSize) {
	int* ans = (int*)calloc(arrSize, sizeof(int));
	assert(ans);
	*returnSize = arrSize;
	int max = -1;
	for (int i = arrSize - 1; i >= 0; i--) {
		int tmp = arr[i];//记录当前值
		ans[i] = max;//当前值修改为最大值
		max = max > tmp ? max : tmp;//记录最大值
	}
	return ans;
}