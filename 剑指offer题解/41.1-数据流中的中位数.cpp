/*
	题目描述	如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/


class Solution {
private:
	int N = 0;
	priority_queue<int, vector<int>, less<int>> leftHeap;
	priority_queue<int, vector<int>, greater<int>> rightHeap;
public:
    void Insert(int num)
    {
        if(N % 2 == 0)
		{
			leftHeap.push(num);
			int t = leftHeap.top();
			leftHeap.pop();
			rightHeap.push(t);
		}
		else
		{
			rightHeap.push(num);
			int t = rightHeap.top();
			rightHeap.pop();
			leftHeap.push(t);
		}
		N++;
    }

    double GetMedian()
    { 
		if(N % 2 == 0)
			return (leftHeap.top()+rightHeap.top())/2.0;
		else
			return rightHeap.top();
    }
};