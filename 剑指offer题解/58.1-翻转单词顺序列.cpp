/*
	题目描述	牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/


class Solution {
public:
    string ReverseSentence(string str) {
        int n = str.size();
		int i = 0, j = 0;
		while(j <= n)
		{
			if(j == n || str[j] == ' ')
			{
				reverse(str, i, j-1);
				i = j + 1;
			}
			j++;
		}
		reverse(str, 0, n-1);
		return str;
    }
	void reverse(string &s, int l, int h)
	{
		while(l < h)
		{
			char t = s[l];
			s[l] = s[h];
			s[h] = t;
			l++;
			h--;
		}
	}
};