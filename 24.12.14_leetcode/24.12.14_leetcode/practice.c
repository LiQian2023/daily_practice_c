#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.12.14力扣网刷题
//面试题 16.11.跳水板——数组、数学——简单
//你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。
//返回的长度需要从小到大排列。
//示例 1
//输入：
//shorter = 1
//longer = 2
//k = 3
//输出：[3, 4, 5, 6]
//解释：
//可以使用 3 次 shorter，得到结果 3；使用 2 次 shorter 和 1 次 longer，得到结果 4 。以此类推，得到最终结果。
//提示：
//0 < shorter <= longer
//0 <= k <= 100000

int* divingBoard(int shorter, int longer, int k, int* returnSize) {
	*returnSize = 0;
	int* ans = NULL;
	if (k) {
		int base = 2 * k;
		ans = (int*)calloc(base, sizeof(int));
		assert(ans);
		if (shorter == longer) {
			ans[*returnSize] = shorter * k;
			*returnSize += 1;
		}
		else {
			for (int i = 0; i <= k; i++) {
				ans[*returnSize] = shorter * (k - i) + longer * i;
				*returnSize += 1;
				if (*returnSize == base) {
					base += 10;
					int* tmp = (int*)realloc(ans, base * sizeof(int));
					if (!tmp) {
						perror("realloc");
						return ans;
					}
					ans = tmp;
				}
			}
		}
	}
	return ans;
}