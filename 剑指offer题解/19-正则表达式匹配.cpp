/*
	题目描述	请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
	
	注：原解用的动态规划，比较难懂
*/


class Solution {
public:
    bool match(char* str, char* pattern)
    {
		if(*str == '\0' && *pattern == '\0')
			return true;
		if(*str != '\0' && *pattern == '\0')
			return false;
		
		if(*(pattern+1)!='*')
		{
			if((*pattern == '.' && *str != '\0') || *pattern == *str)
				return match(str+1, pattern+1);
			else
				return false;
		}
		else
		{
			if(*str == *pattern || (*pattern == '.' && *str != '\0'))
				return match(str, pattern+2) || match(str+1, pattern);
			else
				return match(str, pattern+2);
		}
    }
};

//原答案中的动态规划python解法
public boolean match(char[] str, char[] pattern) {
	
	int m = str.length, n = pattern.length;
	boolean[][] dp = new boolean[m + 1][n + 1];
	
	dp[0][0] = true;
	for (int i = 1; i <= n; i++)
		if (pattern[i - 1] == '*')
			dp[0][i] = dp[0][i - 2];
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')
				dp[i][j] = dp[i - 1][j - 1];
			else if (pattern[j - 1] == '*')
				if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.') {
					dp[i][j] |= dp[i][j - 1]; // a* counts as single a
					dp[i][j] |= dp[i - 1][j]; // a* counts as multiple a
					dp[i][j] |= dp[i][j - 2]; // a* counts as empty
				} else
					dp[i][j] = dp[i][j - 2]; // a* only counts as emptyreturn dp[m][n];
	return dp[m][n];
}