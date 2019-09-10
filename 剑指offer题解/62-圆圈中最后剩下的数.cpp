/*
	题目描述
	每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

	如果没有小朋友，请返回-1
*/


class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(!n || !m)
			return -1;
		//用数组耗时较长但可以通过。答案是python列表，可以把访问过的删掉
		bool *mark = new bool[n];
        memset(mark, false, n);
		int k = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				while(mark[k])
					k = (k+1)%n;
                if(j == m-1)
                    mark[k] = true;
                else
                    k = (k+1)%n;
			}
		}
        return k;
    }
};


//抄答案
//官方微博解答：
// http://zhedahht.blog.163.com/blog/static/2541117420072250322938/
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(!n)
			return -1;
		if(n == 1)
			return 0;
		return (LastRemaining_Solution(n-1, m) + m) % n;
    }
};