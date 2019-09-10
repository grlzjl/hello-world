/*
	题目描述
	从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
			if(row.size())						//此处漏掉了，要注意
				res.push_back(row);
		}
		return res;
    }
};