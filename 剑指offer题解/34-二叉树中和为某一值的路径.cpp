/*
	题目描述	输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
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
	vector<vector<int>> res;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<int> path;
		backTrack(root, expectNumber, path);
		return res;
    }
	void backTrack(TreeNode* node, int target, vector<int> path)
	{
		if(!node)
			return;
		path.push_back(node->val);
		target -= node->val;
		if(target == 0 && !node->left && !node->right)
			res.push_back(path);
		else
		{
			backTrack(node->left, target, path);
			backTrack(node->right, target, path);
		}
		path.pop_back();
	}
};