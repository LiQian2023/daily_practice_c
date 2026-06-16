#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

//2026.06.16力扣网刷题
//3612. 用特殊操作处理字符串 I——高级工程师、字符串、模拟、第458场周赛——中等
//给你一个字符串 s，它由小写英文字母和特殊字符： * 、# 和 % 组成。
//请根据以下规则从左到右处理 s 中的字符，构造一个新的字符串 result：
//如果字符是 小写 英文字母，则将其添加到 result 中。
//字符 '*' 会 删除 result 中的最后一个字符（如果存在）。
//字符 '#' 会 复制 当前的 result 并 追加 到其自身后面。
//字符 '%' 会 反转 当前的 result。
//在处理完 s 中的所有字符后，返回最终的字符串 result。
//示例 1：
//输入： s = "a#b%*"
//输出： "ba"
//解释：
//i	s[i]	操作	当前 result
//0	'a'	添加 'a'	"a"
//1	'#'	复制 result	"aa"
//2	'b'	添加 'b'	"aab"
//3	'%'	反转 result	"baa"
//4	'*'	删除最后一个字符	"ba"
//因此，最终的 result 是 "ba"。
//示例 2：
//输入： s = "z*#"
//输出： ""
//解释：
//i	s[i]	操作	当前 result
//0	'z'	添加 'z'	"z"
//1	'*'	删除最后一个字符	""
//2	'#'	复制字符串	""
//因此，最终的 result 是 ""。
//提示:
//1 <= s.length <= 20
//s 只包含小写英文字母和特殊字符 * 、# 和 % 。

char* processStr(char* s) {
    int len = strlen(s);
    int size = len + 1;
    char* res = (char*)calloc(size, sizeof(char));
    assert(res);
    for (int i = 0, j = 0; s[i]; i++) {
        switch (s[i]) {
            case '*':
            {
                if (j) {
                    res[--j] = 0;
                }
                break;
            }
            case '#':
            {
                size = 2 * size + 1;
                char* tmp = (char*)realloc(res, size);
                if (!tmp) {
                    perror("realloc()");
                    return NULL;
                }
                res = tmp;
                memmove(res + j, res, j);
                j *= 2;
                break;
            }
            case '%':
            {
                for (int l = 0, r = j - 1; l < r; l++, r--) {
                    char tmp = res[l];
                    res[l] = res[r];
                    res[r] = tmp;
                }
                break;
            }
            default:
            {
                res[j++] = s[i];
                break;
            }
        }
        res[j] = 0;
    }
    return res;
}