/*
	题目描述	输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
		if(k > input.size() || k <= 0)
			return res;
		priority_queue<int, vector<int>, less<int>> heap;
		for(int i = 0; i < input.size(); i++)
		{
			heap.push(input[i]);
			if(heap.size() > k)
				heap.pop();
		}
		for(int i = 0; i < k; i++)
		{
			res.push_back(heap.top());
			heap.pop();
		}
		reverse(res.begin(), res.end());
		return res;
    }
};


//利用快排的partition
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
		if(k > input.size() || k <= 0)
			return res;
		findKthSmall(input, k);
		for(int i = 0; i < k; i++)
			res.push_back(input[i]);
		return res;
    }
	
	void findKthSmall(vector<int> &input, int k)
	{
		int l = 0, h = input.size()-1;
		while(l < h)
		{
			int j = partition(input, l, h);
			if(j == k-1)
				break;
			if(j >= k)
				h = j-1;
			else
				l = j+1;
		}
	}
	
	int partition(vector<int> &input, int l, int h)
	{
		int p = input[l];
		int i = l+1, j = h;
		while(i<j)
		{
			while(i<=h && input[i]<p)
				i++;
			while(j>=l && input[j]>=p)
				j--;
			if(i >= j)
				break;
			swap(input, i, j);
		}
		swap(input, l, j);
		return j;
	}
	
	void swap(vector<int> &input, int i, int j)
	{
		int t = input[i];
		input[i] = input[j];
		input[j] = t;
	}
};
