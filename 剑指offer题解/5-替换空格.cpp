/*
	题目描述
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/


class Solution {
public:
	void replaceSpace(char *str,int length) {
		int n=0;
		for(int i=0; i<length; i++)
			if(str[i]==' ')
				n++;
		for(int i=length-1, j=length+2*n-1; i>=0 && j>i; i--)
		{
			if(str[i]!=' ')
			{
				str[j--]=str[i];
			}
			else
			{
				str[j--]='0';
				str[j--]='2';
				str[j--]='%';
			}
		}
	}
};