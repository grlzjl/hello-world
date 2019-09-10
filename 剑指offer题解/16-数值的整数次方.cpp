/*
	题目描述	给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/


class Solution {
public:
    double Power(double base, int exponent) {
		if(exponent == 0)
			return 1;
		int sign = 1;
		if(exponent < 0)
		{
			sign = -1;
			exponent = 0 - exponent;
		}
		double res = 1.0;
		while(exponent)
		{
			res *= base;
			exponent--;
		}
		return sign==1 ? res : (1.0/res);
    }
};