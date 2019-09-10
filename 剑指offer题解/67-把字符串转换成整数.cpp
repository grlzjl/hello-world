/*
	题目描述	将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
	输入描述:
	输入一个字符串,包括数字字母符号,可以为空
	输出描述:
	如果是合法的数值表达则返回该数字，否则返回0
*/


class Solution {
public:
    int StrToInt(string str) {
        if(!str.size())
			return 0;
		int i = 0;
		bool neg = str[0] == '-';
		if(str[0] == '+' || str[0] == '-')
			i = 1;
		int num = 0;
		for(; i < str.size(); i++)
		{
			if(str[i] >= '0' && str[i] <= '9')
				num = num*10+str[i]-'0';
			else
				return 0;
		}
		return neg ? -num : num;
    }
};