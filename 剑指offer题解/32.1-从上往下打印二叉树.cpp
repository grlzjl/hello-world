/*
	题目描述
	从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty())
		{
			int count = que.size();
			while(count-- > 0)
			{
				TreeNode *p = que.front();
                que.pop();
				if(!p)
					continue;
				res.push_back(p->val);
				que.push(p->left);
				que.push(p->right);
			}
		}
		return res;
    }
};