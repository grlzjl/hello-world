/*
	题目描述
	输入一棵二叉树，判断该二叉树是否是平衡二叉树
*/


class Solution {
public:
	bool isBalanced = true;
    bool IsBalanced_Solution(TreeNode* pRoot) {
		height(pRoot);
		return isBalanced;
    }
	int height(TreeNode* root)
	{
		if(!root)
			return 0;
		int lh = height(root->left);
		int rh = height(root->right);
		if(abs(lh-rh) > 1)
			isBalanced = false;
		return 1 + max(lh, rh);
	}
};