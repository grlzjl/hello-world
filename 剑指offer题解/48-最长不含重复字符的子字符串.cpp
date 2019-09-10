/*
	题目描述（无链接，类似LeetCode3.）	输入一个字符串（只包含a~z的字符），求其最长不含重复字符的子字符串的长度。例如对于 arabcacfr，最长不含重复字符的子字符串为 acfr，长度为 4。
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int curLen = 0, maxLen = 0;
		int *preIndex = new int[26];
		memset(preIndex, -1, sizeof(int)*26);
		for(int i = 0; i < s.size(); i++)
		{
			int t = s[i]-'a';
			if(preIndex[t] == -1 || i-preIndex>curLen)	//此处注意后面的条件
			{
				curLen++;
			}
			else
			{
				if(maxLen < curLen)
					maxLen = curLen;
				curLen = i - preIndex[t];
			}
			preIndex[t] = i;
		}
		
		return max(curLen, maxLen);
    }
};


//另附之前LeetCode做的答案，哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        map<char, int> hash;
        for(int i = 0, j = 0; j < n; j++)
        {
            if(hash.count(s[j]))
                i = max(hash[s[j]]+1, i);
            ans = max(ans, j-i+1);
            hash[s[j]] = j;
        }
        return ans;
    }
};