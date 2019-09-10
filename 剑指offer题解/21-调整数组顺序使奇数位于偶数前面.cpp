/*
	题目描述	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/


class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> temp(array);
		array.clear();
		for(int i = 0; i < temp.size(); i++)
			if(temp[i] % 2 == 1)
				array.push_back(temp[i]);
		for(int i = 0; i < temp.size(); i++)
			if(temp[i] % 2 == 0)
				array.push_back(temp[i]);
    }
};

//另有一种以时间换空间的方法，用类似冒泡方法每次将偶数放到最右（或奇数到最左？）