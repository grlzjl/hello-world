/*
	题目描述
	把一根绳子剪成多段，并且使得每段的长度乘积最大。
	
	注：牛客已无此题，同LeetCode的343.整数拆分，如下：	给定一个正整数n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
*/


class Solution {
public:
    int integerBreak(int n) {
        if(n<2)
            return 0;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int n2 = 0, n3 = 0;
        n3 = n/3;
        if(n%3==1)
        {
            n3--;
            n2=2;
        }
        else if(n%3==2)
            n2=1;
        return pow(3, n3)*pow(2, n2);
    }
};