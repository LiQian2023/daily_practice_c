#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//2024.10.19力扣网刷题
//适龄的朋友——数组、双指针、二分查找、排序——中等
//在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。
//如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：
//ages[y] <= 0.5 * ages[x] + 7
//ages[y] > ages[x]
//ages[y] > 100 && ages[x] < 100
//否则，x 将会向 y 发送一条好友请求。
//注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。
//返回在该社交媒体网站上产生的好友请求总数。
//示例 1：
//输入：ages = [16, 16]
//输出：2
//解释：2 人互发好友请求。
//示例 2：
//输入：ages = [16, 17, 18]
//输出：2
//解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
//示例 3：
//输入：ages = [20, 30, 100, 110, 120]
//输出：3
//解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
//提示：
//n == ages.length
//1 <= n <= 2 * 10^4
//1 <= ages[i] <= 120
int cmp(const void* p1, const void* p2) {
	return *(int*)p2 - *(int*)p1;
}
int Binary_Search(int* a, int l, int r, int key) {
	while (l <= r) {
		int mid = (r - l) / 2 + l;
		if (a[mid] > key) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return l;
}
int numFriendRequests(int* ages, int agesSize) {
	qsort(ages, agesSize, sizeof(int), cmp);
	int ans = 0;
	if (ages[0] == ages[agesSize - 1]) {
		if (ages[0] * 0.5 + 7 < ages[0])
			ans += agesSize * (agesSize - 1);
	}
	else {
		for (int i = 0; i < agesSize - 1; i++) {
			int key = ages[i] * 0.5 + 7;
			int l = i + 1, r = agesSize - 1;
			int ret = Binary_Search(ages, l, r, key);
			ans += ret - l;
			ret -= 1;
			while (ret > i) {
				if (ages[i] == ages[ret])
					ans += 1;
				ret -= 1;
			}
		}
	}
	return ans;
}