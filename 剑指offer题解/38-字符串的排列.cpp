/*
	题目描述	输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
	输入描述:
	输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/


class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
		if(!str.size())
			return res;
		vector<char> set;
		//set.resize(str.size());	不行，通不过
		for(int i = 0; i < str.size(); i++)
			set.push_back(str[i]);
		sort(set.begin(), set.end());
		bool *visit = new bool[set.size()];
        memset(visit, false, set.size());
		string s;
		backTrack(set, visit, s, res);
		return res;
    }
	void backTrack(vector<char> &set, bool *&visit, string &s, vector<string> &res)
	{
		if(s.size() == set.size())
		{
			res.push_back(s);
			return;
		}
		for(int i = 0; i < set.size(); i++)
		{
			if(visit[i])
				continue;
			if(i != 0 && set[i] == set[i-1] && !visit[i-1])
				continue;
			visit[i] = true;
			s.push_back(set[i]);
			backTrack(set, visit, s, res);
			s.pop_back(); 
			visit[i] = false;
		}
	}
};