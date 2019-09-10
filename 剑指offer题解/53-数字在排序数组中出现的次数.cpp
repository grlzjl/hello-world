/*
	题目描述
	统计一个数字在排序数组中出现的次数。
*/


class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int i = binarySearch(data, k);
		if(i < 0 || i >= data.size() || data[i] != k)
			return 0;
		int count = 0;
		while(data[i-1] == k)
			i--;
		while(data[i++] == k)
			count++;
		return count;
    }
	int binarySearch(vector<int> &data, int k)
	{
		int l = 0, h = data.size()-1, m;
		while(l < h)
		{
			m = l + (h-l)/2;
			if(data[m] == k)
				return m;
			else if(data[m] < k)
				l = m+1;
			else if(data[m] > k)
				h = m-1;
		}
		return l;
	}
};