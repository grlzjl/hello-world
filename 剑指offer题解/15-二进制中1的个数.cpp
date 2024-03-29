/*
	题目描述
	输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
	
	提示：
	n&(n-1)	该位运算去除 n 的位级表示中最低的那一位。
*/


class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
		while(n)
		{
			count++;
			n = n&(n-1);
		}
		return count;
    }
};