/*
	题目描述	请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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
    bool isSymmetrical(TreeNode* pRoot)
    {
		if(!pRoot)
			return true;
		return isSym(pRoot->left, pRoot->right);
    }
	
	bool isSym(TreeNode* left, TreeNode* right)
	{
		if(!left && !right)
			return true;
		else if(!left || !right)
			return false;
		else if(left->val != right->val)
			return false;
		else
			return isSym(left->left, right->right)
				&& isSym(left->right, right->left);
	}
};