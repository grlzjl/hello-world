/*
	题目描述（Lintcode: https://www.lintcode.com/problem/dices-sum/description）
	扔 n 个骰子，向上面的数字之和为 S。给定 n，请列出所有可能的 S 值及其相应的概率。
*/


class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
		int facet = 6;
	    int MAX = facet * n;
		long dp[n+1][MAX+1] = {0};
		
		for(int i = 1; i <= facet; i++)
			dp[1][i] = 1;
		for(int i = 2; i <= n; i++)
			for(int j = i; j <= MAX; j++)
				for(int k = 1; k <= facet && k <= j; k++)
					dp[i][j] += dp[i-1][j-k];
		
		double totalNum = pow(6, n);
		vector<pair<int, double>> res;
		for(int i = n; i <= MAX; i++)
			res.push_back(make_pair(i, (double)dp[n][i]/totalNum));
		return res;
    }
};