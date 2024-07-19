#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2024.07.20力扣网刷题
//重新排列字符串——数组、字符串——简单
//给你一个字符串 s 和一个 长度相同 的整数数组 indices 。
//请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。
//返回重新排列后的字符串。
//示例 1：
//输入：s = "codeleet", indices = [4, 5, 6, 7, 0, 2, 1, 3]
//输出："leetcode"
//解释：如图所示，"codeleet" 重新排列后变为 "leetcode" 。
//示例 2：
//输入：s = "abc", indices = [0, 1, 2]
//输出："abc"
//解释：重新排列后，每个字符都还留在原来的位置上。
//提示：
//s.length == indices.length == n
//1 <= n <= 100
//s 仅包含小写英文字母
//0 <= indices[i] < n
//	indices 的所有的值都是 唯一 的

//方法一：中间数组
char* restoreString1(char* s, int* indices, int indicesSize) {
	char tmp[100] = { 0 };
	//清空原字符串
	for (int i = 0; i < indicesSize; i++) {
		tmp[i] = s[i];
	}
	for (int i = 0; i < indicesSize; i++) {
		s[indices[i]] = tmp[i];
	}
	return s;
}


//方法二：原地修改——未完成
char* restoreString(char* s, int* indices, int indicesSize) {
	//记录首字符进行替换的位置的元素
	char tmp1 = s[0];
	char tmp2 = s[indices[0]];
	for (int i = 0; i < indicesSize;) {
		s[indices[i]] = tmp1;
		if (indices[indices[i]] == i) {
			s[i] = tmp2;
			indices[indices[i]] = indices[i];
			indices[i] = i;
			i++;
			if (i == indicesSize)
				break;
			tmp1 = s[i];
			tmp2 = s[indices[i]];
		}
		else{
			tmp1 = s[indices[indices[i]]];
			s[indices[indices[i]]] = tmp2;
			int num = indices[indices[i]];
			indices[indices[i]] = indices[i];
			indices[i] = num;
			//获取移动次数
			int count = 0;
			num = indices[i];
			int tmp[7] = { 0 };
			while (num != i) {
				tmp[count] = num;
				count++;
				num = indices[num];
			}
			//反转
			for (int j = 0; j < count; j++) {

			}
			tmp2 = s[indices[i]];
		}
	}
	return s;
}

void test() {
	char s[100] = "aaiougrt";
	int change[100] = { 4,0,2,6,7,3,1,5 };
	char* ret = restoreString(s, change, 8);
	printf("%s\n", ret);
}

void test1() {
	int arr[8] = { 4,0,2,6,7,3,1,5 };
	int count = 0;
	int num = arr[0];
	int tmp[7] = { 0 };
	while (num) {
		tmp[count] = num;
		count++;
		num = arr[num];
	}
}

int main() {
	test1();
	return 0;
}