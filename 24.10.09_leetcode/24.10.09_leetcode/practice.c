#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.10.09力扣网刷题
//根据身高重建队列——树状数组、线段树、数组、排序——中等
//假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
//每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
//请你重新构造并返回输入数组 people 所表示的队列。
//返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
//示例 1：
//输入：people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
//输出： [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
//解释：
//编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
//编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
//编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
//编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
//编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
//编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
//因此 [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]] 是重新构造后的队列。
//示例 2：
//输入：people = [[6, 0], [5, 0], [4, 0], [3, 2], [2, 2], [1, 4]]
//输出： [[4, 0], [5, 0], [2, 2], [3, 2], [1, 4], [6, 0]]
//提示：
//1 <= people.length <= 2000
//0 <= hi <= 10^6
//0 <= ki < people.length
//题目数据确保队列可以被重建

int cmp(const void** p1, const void** p2) {
	int* a = *(int**)p1;
	int* b = *(int**)p2;
	if (a[1] == b[1])
		return a[0] - b[0];
	return a[1] - b[1];
}
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes) {
	qsort(people, peopleSize, sizeof(int*), cmp);
	//插入排序
	for (int i = 0; i < peopleSize - 1; i++) {
		int j = i;
		int h = people[j + 1][0];
		int k = people[j + 1][1];
		int count = 0;
		for (int z = 0; z < i + 1; z++) {
			if (people[z][0] >= h)
				count += 1;
		}
		while (j >= 0 && people[j][0] > h && count > k) {
			people[j + 1][0] = people[j][0];
			people[j + 1][1] = people[j][1];
			count -= 1;
			j -= 1;
		}
		people[j + 1][0] = h;
		people[j + 1][1] = k;
	}
	*returnSize = peopleSize;
	*returnColumnSizes = (int*)calloc(peopleSize, sizeof(int));
	assert(*returnColumnSizes);
	int** ans = (int**)calloc(peopleSize, sizeof(int*));
	assert(ans);
	for (int i = 0; i < peopleSize; i++) {
		(*returnColumnSizes)[i] = 2;
		ans[i] = (int*)calloc(2, sizeof(int));
		assert(ans[i]);
		ans[i][0] = people[i][0];
		ans[i][1] = people[i][1];
	}
	return ans;
}