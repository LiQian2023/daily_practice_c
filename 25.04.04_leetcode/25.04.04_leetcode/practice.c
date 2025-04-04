#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdlib.h>
#include <assert.h>
//2025.04.04力扣网刷题
//删列造序——数组、字符串——简单
//给你由 n 个小写字母字符串组成的数组 strs，其中每个字符串长度相等。
//这些字符串可以每个一行，排成一个网格。例如，strs = ["abc", "bce", "cae"] 可以排列为：
//abc
//bce
//cae
//你需要找出并删除 不是按字典序非严格递增排列的 列。
//在上面的例子（下标从 0 开始）中，列 0（'a', 'b', 'c'）和列 2（'c', 'e', 'e'）都是按字典序非严格递增排列的，而列 1（'b', 'c', 'a'）不是，所以要删除列 1 。
//返回你需要删除的列数。
//示例 1：
//输入：strs = ["cba", "daf", "ghi"]
//输出：1
//解释：网格示意如下：
//cba
//daf
//ghi
//列 0 和列 2 按升序排列，但列 1 不是，所以只需要删除列 1 。
//示例 2：
//输入：strs = ["a", "b"]
//输出：0
//解释：网格示意如下：
//a
//b
//只有列 0 这一列，且已经按升序排列，所以不用删除任何列。
//示例 3：
//输入：strs = ["zyx", "wvu", "tsr"]
//输出：3
//解释：网格示意如下：
//zyx
//wvu
//tsr
//所有 3 列都是非升序排列的，所以都要删除。
//提示：
//n == strs.length
//1 <= n <= 100
//1 <= strs[i].length <= 1000
//strs[i] 由小写英文字母组成

int minDeletionSize(char** strs, int strsSize) {
	int row = strsSize;
	int col = strlen(strs[0]);
	int* tmp = (int*)calloc(col, sizeof(int));
	assert(tmp);
	for (int i = 1; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (tmp[j] == 0) {
				if (strs[i][j] - strs[i - 1][j] < 0) {
					tmp[j] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < col; i++) {
		ans += tmp[i];
	}
	free(tmp);
	tmp = NULL;
	return ans;
}