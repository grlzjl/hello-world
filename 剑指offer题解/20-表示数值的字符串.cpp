/*
	题目描述	请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/


class Solution {
public:
    bool isNumeric(char* string)
    {
        bool decimal = false, exp = false, afterE = false;
		for(int i = 0; i < strlen(string); i++)
		{
			bool decimal = false, exp = false, afterE = false;
		for(int i = 0; i < strlen(string); i++)
		{
			if(string[i] == '+' || string[i] == '-')
			{
				if(i == 0 || string[i-1] == 'E' || string[i-1] == 'e')
					continue;
				else
					return false;
			}
			else if(string[i] == 'e' || string[i] == 'E')
			{
				if(exp)
					return false;
				exp = true;
			}
			else if(string[i] == '.')
			{
				if(decimal || exp)
					return false;
                decimal = true;
			}
			else if(string[i] >= '0' && string[i] <= '9')
			{
				if(exp)
					afterE = true;
			}
			else
				return false;
		}
		if(exp && (!afterE))
			return false;
		return true;
    }
};


/*
使用正则表达式进行匹配的Python解法：
[] ： 字符集合
() ： 分组
? ： 重复 0 ~ 1 次
+ ： 重复 1 ~ n 次
* ： 重复 0 ~ n 次
. ： 任意字符
\\. ： 转义后的 .
\\d ： 数字
public boolean isNumeric(char[] str) {
	if (str == null || str.length == 0)
		return false;
	return new String(str).matches("[+-]?\\d*(\\.\\d+)?([eE][+-]?\\d+)?");
}
*/