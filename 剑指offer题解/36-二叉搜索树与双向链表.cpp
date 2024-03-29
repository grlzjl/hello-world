/*
	题目描述	输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
	TreeNode *pre = NULL, *head = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        inOrder(pRootOfTree);
		return head;
    }
	
	void inOrder(TreeNode* root)
	{
		if(!root)
			return;
		inOrder(root->left);
		root->left = pre;
		if(pre != NULL)
			pre->right = root;
		pre = root;
		if(head == NULL)
			head = root;
		inOrder(root->right);
	}
};