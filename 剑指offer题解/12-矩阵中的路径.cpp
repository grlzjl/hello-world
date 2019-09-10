/*
	题目描述	请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
	例如
	a b c e
	s f c s
	a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/


class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
		if(matrix == NULL || strlen(matrix) < strlen(str))
			return false;
		bool *visited = new bool[strlen(matrix)];
		memset(visited, false, strlen(matrix));
		for(int r = 0; r < rows; r++)
		{
			for(int c = 0; c < cols; c++)
			{
				if(backTrack(matrix, rows, cols, r, c, str, 0, visited))
					return true;
			}
		}
		return false;
    }

	bool backTrack(char* matrix, int rows, int cols, int r, int c, char* str, int cur, bool* visited)
	{
		if(cur == strlen(str))
			return true;
		int index = cols * r + c;
		if(r < 0 || r >= rows || c < 0 || c >= cols || matrix[index] != str[cur] || visited[index])
			return false;
		visited[index] = true;
		if(backTrack(matrix, rows, cols, r-1, c, str, cur+1, visited)
			|| backTrack(matrix, rows, cols, r+1, c, str, cur+1, visited)
			|| backTrack(matrix, rows, cols, r, c-1, str, cur+1, visited)
			|| backTrack(matrix, rows, cols, r, c+1, str, cur+1, visited))
			return true;
		visited[index] = false;
		return false;
	}
};