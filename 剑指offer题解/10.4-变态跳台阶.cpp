/*
	题目描述	一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/


class Solution {
public:
    int jumpFloorII(int number) {
		int *dp = new int[number];
		for(int i=0; i<number; i++)
			dp[i] = 1;
		for(int i=1; i<number; i++)
			for(int j=0; j<i; j++)
				dp[i]+=dp[j];
		return dp[number-1];
    }
};

//另解答，由于f(n) - f(n-1) = f(n-1)，因此是等比数列，可以直接求2的n-1次幂
return (int)pow(2, target-1);