/*
	题目描述	输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.empty())
			return false;
		return verify(sequence, 0, sequence.size()-1);
    }
	
	bool verify(vector<int> sequence, int first, int last)
	{
		if(last - first <= 1)
			return true;
		int val = sequence[last];
		int cut = first;
		while(cut < last && sequence[cut] <= val)
			cut++;
		for(int i = cut; i < last; i++)
			if(sequence[i] < val)
				return false;
		return verify(sequence, first, cut-1)
			&& verify(sequence, cut, last-1);
	}
};