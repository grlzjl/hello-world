/*
	题目描述	请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
		queue<TreeNode*> que;
		que.push(pRoot);
		bool re = false;
		while(!que.empty())
		{
			int count = que.size();
			vector<int> row;
			while(count-- > 0)
			{
				TreeNode *p = que.front();
                que.pop();
				if(!p)
					continue;
				row.push_back(p->val);
				que.push(p->left);
				que.push(p->right);
			}
			if(re)
				reverse(row.begin(), row.end());
			re = !re;
			if(row.size())
				res.push_back(row);
		}
		return res;
    }
    
};