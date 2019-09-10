/*
	题目描述	一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/


class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2)
			return number;
		int a = 1, b = 2, c;
		for(int i = 3; i <= number; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
    }
};