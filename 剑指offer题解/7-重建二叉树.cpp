/*
	题目描述	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	map<int, int> indexForInorder;
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		for(int i=0; i<vin.size(); i++)
		{
			indexForInorder[vin[i]]=i;
		}
		return reConstruct(pre, 0, pre.size()-1, 0);
    }
	
	TreeNode* reConstruct(vector<int> &pre, int pL, int pR, int vL)
	{
		if(pL > pR)
			return NULL;
		TreeNode *root = new TreeNode(pre[pL]);
		int index = indexForInorder[root->val];
		int leftTreeSize = index - vL;
		root->left = reConstruct(pre, pL+1, pL+leftTreeSize, vL);
		root->right = reConstruct(pre, pL+leftTreeSize+1, pR, vL+leftTreeSize+1);
		return root;
	}
};