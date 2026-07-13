#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.07.13力扣网刷题
//1291. 顺次数——资深工程师、枚举、第167场周赛——中等
//我们定义「顺次数」为：每一位上的数字都比前一位上的数字大 1 的整数。
//请你返回由[low, high] 范围内所有顺次数组成的 有序 列表（从小到大排序）。
//示例 1：
//输出：low = 100, high = 300
//输出：[123, 234]
//示例 2：
//输出：low = 1000, high = 13000
//输出：[1234, 2345, 3456, 4567, 5678, 6789, 12345]
//提示：
//10 <= low <= high <= 10 ^ 9
void Realloc(int** ans, int* base, int* pi) {
    int newSize = (*base) * 3 / 2;
    int* tmp = (int*)calloc(newSize, sizeof(int));

    if (!tmp) {
        perror("calloc");
        return;
    }

    for (int i = 0; i < *pi; i++) {
        tmp[i] = (*ans)[i];
    }

    free(*ans);
    *ans = tmp;
    *base = newSize;
}

void DFS(int left, int right, int** ans, int* pi, int* base, int start) {
    if (start >= 10) {
        return;
    }

    int num = start;

    while (num <= right) {
        int last = num % 10;

        if (last == 9) {
            break;
        }

        num = num * 10 + last + 1;

        if (num >= left && num <= right) {
            if (*pi == *base) {
                Realloc(ans, base, pi);
            }

            (*ans)[*pi] = num;
            (*pi)++;
        }
    }

    DFS(left, right, ans, pi, base, start + 1);
}
int cmp(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}
int* sequentialDigits(int low, int high, int* returnSize) {
    int base = 4;
    int* ans = (int*)calloc(base, sizeof(int));

    if (!ans) {
        perror("calloc");
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;

    DFS(low, high, &ans, returnSize, &base, 1);
    qsort(ans, *returnSize, sizeof(int), cmp);
    return ans;
}