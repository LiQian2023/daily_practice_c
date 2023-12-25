#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.25力扣网刷题
//交替合并字符串——双指针、字符串——简单
//给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。
//返回 合并后的字符串 。
//示例 1：
//输入：word1 = "abc", word2 = "pqr"
//输出："apbqcr"
//解释：字符串合并情况如下所示：
//word1：  a   b   c
//word2：    p   q   r
//合并后：  a p b q c r
//示例 2：
//输入：word1 = "ab", word2 = "pqrs"
//输出："apbqrs"
//解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
//word1：  a   b
//word2：    p   q   r   s
//合并后：  a p b q   r   s
//示例 3：
//输入：word1 = "abcd", word2 = "pq"
//输出："apbqcd"
//解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
//word1：  a   b   c   d
//word2：    p   q
//合并后：  a p b q c   d
//提示：
//1 <= word1.length, word2.length <= 100
//word1 和 word2 由小写英文字母组成
#include <string.h>
#include <stdlib.h>
char* mergeAlternately(char* word1, char* word2) {
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	char* ch = (char*)calloc(len1 + len2 + 1, sizeof(char));
	int i = 0, j = 0;
	if (len1 == len2)
	{
		i = 0, j = 0;
		for (int z = 0; z + 1 < len1 + len2; z++)
		{
			ch[z] = word1[i];
			ch[z + 1] = word2[j];
			i++;
			j++;
			z++;
		}
	}
	else if (len1 > len2)
	{
		i = 0, j = 0;
		for (int z = 0; z < len1 + len2; z++)
		{
			if (!word2[j])
			{
				ch[z] = word1[i];
				i++;
			}
			else
			{
				ch[z] = word1[i];
				ch[z + 1] = word2[j];
				i++, j++;
				z++;
			}
		}
	}
	else
	{
		i = 0, j = 0;
		for (int z = 0; z < len1 + len2; z++)
		{
			if (!word1[i])
			{
				ch[z] = word2[j];
				j++;
			}
			else
			{
				ch[z] = word1[i];
				ch[z + 1] = word2[j];
				i++, j++;
				z++;
			}
		}
	}
	return ch;
}
int main()
{
	char ch1[100] = { 0 };
	char ch2[100] = { 0 };
	int m = 0, n = 0;
	while (scanf("%d%d", &m, &n) == 2)
	{
		scanf("%s%s", ch1, ch2);
		char* ch3 = mergeAlternately(ch1, ch2);
		printf("%s\n", ch3);
	}
	return 0;
}