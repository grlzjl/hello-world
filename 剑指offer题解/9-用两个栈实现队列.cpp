/*
	题目描述
	用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/


class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
			while(!stack1.empty())
			{
				//此处注意C++的pop()不返回值，与python的区别，得分两步。
				stack2.push(stack1.top());		
				stack1.pop();
			}
		int a = stack2.top();
		stack2.pop();
		return a;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};