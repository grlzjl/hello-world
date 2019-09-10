/*
	题目描述	在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
	输入描述:
	题目保证输入的数组中没有的相同的数字
	数据范围：
		对于%50的数据,size<=10^4
		对于%75的数据,size<=10^5
		对于%100的数据,size<=2*10^5
*/


class Solution {
public:
	long long count = 0;
    int InversePairs(vector<int> data) {
		int *tmp = new int[data.size()];
		mergeSort(data, tmp, 0, data.size()-1);
        return count%1000000007;
    }
	
	void mergeSort(vector<int> &data, int *&tmp, int l, int r)
	{
		if(l >= r)
			return;
		int m = l + (r - l) / 2;
		mergeSort(data, tmp, l, m);
		mergeSort(data, tmp, m+1, r);
		merge(data, tmp, l, m, r);
	}
	
	void merge(vector<int> &data, int *&tmp, int l, int m, int r)
	{
		int i = m, j = r, k = r;
		while(i >= l || j > m)
		{
			if(j <= m)
				tmp[k--] = data[i--];
			else if(i < l)
				tmp[k--] = data[j--];
			else if(data[i] < data[j])
				tmp[k--] = data[j--];
			else
			{
				tmp[k--] = data[i--];
				count += j-m;
			}
		}
		for(k = l; k <= r; k++)
			data[k] = tmp[k];
	}
};