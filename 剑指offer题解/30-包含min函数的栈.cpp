/*
	题目描述	定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/


class Solution {
public:
	stack<int> s;
	stack<int> mins;
    void push(int value) {
        s.push(value);
		if(mins.empty())
			mins.push(value);
		else
			mins.push(value < mins.top() ? value : mins.top());
    }
    void pop() {
        s.pop();
		mins.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return mins.top();
    }
};