/*
	题目描述	一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/


class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int num = 0;
		for(int i = 0; i < data.size(); i++)
			num ^= data[i];
		num &= -num;
		*num1 = *num2 = 0;
		for(int i = 0; i < data.size(); i++)
		{
			if((data[i] & num) == 0)			//此处注意运算顺序内层加括号
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
    }
};