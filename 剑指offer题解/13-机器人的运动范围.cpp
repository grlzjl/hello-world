/*
	题目描述	地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/


class Solution {
public:
    int count = 0;
    int movingCount(int threshold, int rows, int cols)
    {
        bool *visit = new bool[rows*cols];
		memset(visit, false, rows*cols);
		dfs(threshold, rows, cols, visit, 0, 0);
        delete[] visit;
		return count;
    }
	
	void dfs(int threshold, int rows, int cols, bool *visit, int r, int c)
	{
		if(r < 0 || r >= rows || c < 0 || c >= cols || visit[r*cols+c])
			return;
		visit[r*cols+c] = true;
		if(digitSum(r, c) > threshold)
			return;
		count++;
		dfs(threshold, rows, cols, visit, r-1, c);
		dfs(threshold, rows, cols, visit, r+1, c);
		dfs(threshold, rows, cols, visit, r, c+1);
		dfs(threshold, rows, cols, visit, r, c-1);
	}
	
	int digitSum(int r, int c)
	{
		int sum = 0;
		while(r)
		{
			sum += r % 10;
			r /= 10;
		}
		while(c)
		{
			sum += c % 10;
			c /= 10;
		}
		return sum;
	}
};