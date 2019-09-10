# hello-world
/*
输入测试
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5
*/

/*第一次 错误 30分
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool solute(string s)
{
	stack<int> nums;
	stack<char> signs;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] > '0' && s[i] <= '9')
			nums.push(s[i]-'0');
		else if(s[i] == '+' || s[i] == '-')
			signs.push(s[i]);
		else if(s[i] == 'x')
		{
			int t = nums.top();
			nums.pop();
			nums.push(t*(s[i+1]-'0'));
			i++;
		}
		else if(s[i] == '/')
		{
			int t = nums.top();
			nums.pop();
			/*if(t % (s[i+1] - '0') != 0)
				return false;*/
			nums.push(t/(s[i+1]-'0'));
			i++;
		}
		else
			return false;
	}
	while(!signs.empty())
	{
		char t = signs.top();
		signs.pop();
		int t1 = nums.top();
		nums.pop();
		int t2 = nums.top();
		nums.pop();
		if(t == '+')
			nums.push(t1 + t2);
		else
			nums.push(t2 - t1);	
	}
	return (nums.top() == 24);
}

int main()
{
	int n;
	cin >> n;
	vector<string> list;
	for(int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		list.push_back(t);
	}
	for(int i = 0; i < n; i++)
	{
		if(solute(list[i]))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
*/
