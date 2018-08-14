// 16_RegularExpressionsMatching.cpp : 定义控制台应用程序的入口点。
//

// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include "stdafx.h"

#include <cstdio>


/*///////////////////////////////////////////////////////////////////////////////////////////////////
	解这题需要把题意仔细研究清楚，反正我试了好多次才明白的。
	首先，考虑特殊情况：
	1>两个字符串都为空，返回true
	2>当第一个字符串不空，而第二个字符串空了，返回false（因为这样，就无法
	匹配成功了,而如果第一个字符串空了，第二个字符串非空，还是可能匹配成
	功的，比如第二个字符串是“a*a*a*a*”,由于‘*’之前的元素可以出现0次，
	所以有可能匹配成功）
	之后就开始匹配第一个字符，这里有两种可能：匹配成功或匹配失败。但考虑到pattern
	下一个字符可能是‘*’， 这里我们分两种情况讨论：pattern下一个字符为‘*’或
	不为‘*’：
	1>pattern下一个字符不为‘*’：这种情况比较简单，直接匹配当前字符。如果
	匹配成功，继续匹配下一个；如果匹配失败，直接返回false。注意这里的
	“匹配成功”，除了两个字符相同的情况外，还有一种情况，就是pattern的
	当前字符为‘.’,同时str的当前字符不为‘\0’。
	2>pattern下一个字符为‘*’时，稍微复杂一些，因为‘*’可以代表0个或多个。
	这里把这些情况都考虑到：
	a>当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，
	跳过这个‘*’符号；
	b>当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符
	不变。（这里匹配1个或多个可以看成一种情况，因为：当匹配一个时，
	由于str移到了下一个字符，而pattern字符不变，就回到了上边的情况a；
	当匹配多于一个字符时，相当于从str的下一个字符继续开始匹配）
	之后再写代码就很简单了。
////////////////////////////////////////////////////////////////////////////////////////////////*/
//class Solution {
//public:
//	bool match(char* str, char* pattern)
//	{
//		if (*str == '\0' && *pattern == '\0')
//			return true;
//		if (*str != '\0' && *pattern == '\0')
//			return false;
//		//if the next character in pattern is not '*'
//		if (*(pattern+1) != '*')
//		{
//			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
//				return match(str+1, pattern+1);
//			else
//				return false;
//		}
//		//if the next character is '*'
//		else
//		{
//			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
//				return match(str, pattern+2) || match(str+1, pattern);
//			else
//				return match(str, pattern+2);
//		}
//	}
//};



bool matchCore(const char* str, const char* pattern);

bool match(const char* str, const char* pattern)
{
	if(str == nullptr || pattern == nullptr)
		return false;

	return matchCore(str, pattern);
}

bool matchCore(const char* str, const char* pattern)
{
	if(*str == '\0' && *pattern == '\0')
		return true;

	if(*str != '\0' && *pattern == '\0')
		return false;

	if(*(pattern + 1) == '*')
	{
		if(*pattern == *str || (*pattern == '.' && *str != '\0'))
			// 进入有限状态机的下一个状态
			return matchCore(str + 1, pattern + 2)
			// 继续留在有限状态机的当前状态 
			|| matchCore(str + 1, pattern)
			// 略过一个'*' 
			|| matchCore(str, pattern + 2);
		else
			// 略过一个'*'
			return matchCore(str, pattern + 2);
	}

	if(*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);

	return false;
}

// ====================测试代码====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
	if(testName != nullptr)
		printf("%s begins: ", testName);

	if(match(string, pattern) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	Test("Test01", "", "", true);
	Test("Test02", "", ".*", true);
	Test("Test03", "", ".", false);
	Test("Test04", "", "c*", true);
	Test("Test05", "a", ".*", true);
	Test("Test06", "a", "a.", false);
	Test("Test07", "a", "", false);
	Test("Test08", "a", ".", true);
	Test("Test09", "a", "ab*", true);
	Test("Test10", "a", "ab*a", false);
	Test("Test11", "aa", "aa", true);
	Test("Test12", "aa", "a*", true);
	Test("Test13", "aa", ".*", true);
	Test("Test14", "aa", ".", false);
	Test("Test15", "ab", ".*", true);
	Test("Test16", "ab", ".*", true);
	Test("Test17", "aaa", "aa*", true);
	Test("Test18", "aaa", "aa.a", false);
	Test("Test19", "aaa", "a.a", true);
	Test("Test20", "aaa", ".a", false);
	Test("Test21", "aaa", "a*a", true);
	Test("Test22", "aaa", "ab*a", false);
	Test("Test23", "aaa", "ab*ac*a", true);
	Test("Test24", "aaa", "ab*a*c*a", true);
	Test("Test25", "aaa", ".*", true);
	Test("Test26", "aab", "c*a*b", true);
	Test("Test27", "aaca", "ab*a*c*a", true);
	Test("Test28", "aaba", "ab*a*c*a", false);
	Test("Test29", "bbbba", ".*a*a", true);
	Test("Test30", "bcbbabab", ".*a*a", false);

	return 0;
}