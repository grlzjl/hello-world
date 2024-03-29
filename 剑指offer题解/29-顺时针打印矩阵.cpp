/*
	题目描述	输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		int up, down, left, right, row, col;
		row = matrix.size();
		col = matrix[0].size();
		up = left = 0;
		down = row - 1;
		right = col - 1;
		vector<int> res;
		while(1)
		{
			for(int i = left; i <= right; i++)
				res.push_back(matrix[up][i]);
			if(++up > down)
				break;
			for(int i = up; i <= down; i++)
				res.push_back(matrix[i][right]);
			if(--right < left)
				break;
			for(int i = right; i >= left; i--)
				res.push_back(matrix[down][i]);
			if(--down < up)
				break;
			for(int i = down; i >= up; i--)
				res.push_back(matrix[i][left]);
			if(++left > right)
				break;
		}
		return res;
    }
};