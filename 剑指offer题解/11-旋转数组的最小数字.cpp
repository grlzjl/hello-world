/*
	题目描述
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
	输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
	例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
	NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n=rotateArray.size();
		if(n == 0)
			return 0;
		int l = 0, h = n-1;
		while(l<h)
		{
			int m = l + (h-l)/2;
			if(rotateArray[m] <= rotateArray[h])
				h = m;
			else
				l = m+1;
		}
		return rotateArray[l];
    }
};

//另答案指出极端情况，即类似{1,1,1,0,1}，当l、m、h三者都相等时需切换到顺序查找。
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n=rotateArray.size();
		if(n == 0)
			return 0;
		int l = 0, h = n-1;
		while(l<h)
		{
			int m = l + (h-l)/2;
			if(rotateArray[l] == rotateArray[m] && rotateArray[m] == rotateArray[h])
				return minNumber(rotateArray, l, h);
			else if(rotateArray[m] <= rotateArray[h])
				h = m;
			else
				l = m+1;
		}
		return rotateArray[l];
    }

private:
	int minNumber(vector<int> nums, int l, int h)
	{
		for(int i=l; i<h; i++)
			if(nums[i]>nums[i+1])
				return nums[i+1];
		return nums[l];
	}
};
