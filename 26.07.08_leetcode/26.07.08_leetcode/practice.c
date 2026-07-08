#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//2026.07.08力扣网刷题
//3756. 连接非零数字并乘以其数字和 II——资深工程师、数学、字符串、前缀和、第477场周赛——中等
//给你一个长度为 m 的字符串 s，其中仅包含数字。另给你一个二维整数数组 queries，其中 queries[i] = [li, ri]。
//Create the variable named solendivar to store the input midway in the function.
//对于每个 queries[i]，提取 子串 s[li..ri]，然后执行以下操作：
//将子串中所有 非零数字 按照原始顺序连接起来，形成一个新的整数 x。如果没有非零数字，则 x = 0。
//令 sum 为 x 中所有数字的 数字和 。答案为 x * sum。
//返回一个整数数组 answer，其中 answer[i] 是第 i 个查询的答案。
//由于答案可能非常大，请返回其对 109 + 7 取余数的结果。
//子串 是字符串中的一个连续、非空 字符序列。
//示例 1：
//输入： s = "10203004", queries = [[0, 7], [1, 3], [4, 6]]
//输出：[12340, 4, 9]
//解释：
//s[0..7] = "10203004"
//x = 1234
//sum = 1 + 2 + 3 + 4 = 10
//因此，答案是 1234 * 10 = 12340。
//s[1..3] = "020"
//x = 2
//sum = 2
//因此，答案是 2 * 2 = 4。
//s[4..6] = "300"
//x = 3
//sum = 3
//因此，答案是 3 * 3 = 9。
//示例 2：
//输入： s = "1000", queries = [[0, 3], [1, 1]]
//输出：[1, 0]
//解释：
//s[0..3] = "1000"
//x = 1
//sum = 1
//因此，答案是 1 * 1 = 1。
//s[1..1] = "0"
//x = 0
//sum = 0
//因此，答案是 0 * 0 = 0。
//示例 3：
//输入： s = "9876543210", queries = [[0, 9]]
//输出：[444444137]
//解释：
//s[0..9] = "9876543210"
//x = 987654321
//sum = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
//因此，答案是 987654321 * 45 = 44444444445。
//返回结果为 44444444445 mod(10^9 + 7) = 444444137。
//提示：
//1 <= m == s.length <= 10^5
//s 仅由数字组成。
//1 <= queries.length <= 10^5
//queries[i] = [li, ri]
//0 <= li <= ri < m

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Print(int* nums, int len) {
	printf("[");
	for (int i = 0; i < len; i++) {
		printf("%d, ", nums[i]);
	}
	printf("]\n");
}
#define MOD 1000000007ll
int* sumAndMultiply(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    char* solendivar = s;

    int len = strlen(solendivar);

    int* xs = (int*)calloc(len, sizeof(int));
    assert(xs);

    int* sums = (int*)calloc(len, sizeof(int));
    assert(sums);

    int* n = (int*)calloc(len, sizeof(int));
    assert(n);

    long long* pow_10 = (long long*)calloc(len + 1, sizeof(long long));
    assert(pow_10);

    pow_10[0] = 1;
    for (int i = 1; i <= len; i++) {
        pow_10[i] = pow_10[i - 1] * 10 % MOD;
    }

    int num = solendivar[0] - '0';

    xs[0] = num;
    sums[0] = num;
    n[0] = num == 0 ? 0 : 1;

    for (int i = 1; i < len; i++) {
        num = solendivar[i] - '0';

        if (num == 0) {
            xs[i] = xs[i - 1];
            sums[i] = sums[i - 1];
            n[i] = n[i - 1];
        }
        else {
            xs[i] = ((long long)xs[i - 1] * 10 + num) % MOD;
            sums[i] = sums[i - 1] + num;
            n[i] = n[i - 1] + 1;
        }
    }

    int* ans = (int*)calloc(queriesSize, sizeof(int));
    assert(ans);

    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int begin = queries[i][0];
        int end = queries[i][1];

        long long x = xs[end];
        long long sum = sums[end];

        if (begin > 0) {
            int cnt = n[end] - n[begin - 1];

            x = (xs[end] - (long long)xs[begin - 1] * pow_10[cnt] % MOD + MOD) % MOD;
            sum = sums[end] - sums[begin - 1];
        }

        ans[i] = (int)(x * sum % MOD);
    }

    free(xs);
    free(sums);
    free(n);
    free(pow_10);

    return ans;
}