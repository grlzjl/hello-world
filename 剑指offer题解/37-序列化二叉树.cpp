/*
	题目描述
	请实现两个函数，分别用来序列化和反序列化二叉树	二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过某种符号表示空节点（#），以,表示一个结点值的结束（value,）。	二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
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
	char* Serialize(TreeNode *root) {    
        string s;
		sSerialize(root, s);
		char* str = new char[s.size()];
        strcpy(str, s.data());
		return str;
    }
	void sSerialize(TreeNode *root, string &s)
	{
		if(!root)
		{
			s += '#';
			return;
		}
		s += to_string(root->val) + ',';
		sSerialize(root->left, s);
		sSerialize(root->right, s);
	}
	
    TreeNode* Deserialize(char *str) {
		if(str == NULL)
			return NULL;
		return des(str);
    }
	TreeNode* des(char *&str)
	{
		if(*str == '#')
		{
			str++;
			return NULL;
		}
		int num = 0;
		while(*str != ',')
			num = num*10 + (*(str++) - '0');
		str++;
		TreeNode *root = new TreeNode(num);
		root->left = des(str);
		root->right = des(str);
		return root;
	}
};



//抄的论坛题解
class Solution {
public:
	char* Serialize(TreeNode *root)
	{
		if(!root)
			return "#";
		string s = to_string(root->val);
		s.push_back(',');
		char *left = Serialize(root->left);
		char *right = Serialize(root->right);
		char *res = new char[strlen(left) + strlen(right) + s.size()];
		strcpy(res, s.c_str());
		strcat(res, left);
		strcat(res, right);
		return res;
	}
	
    TreeNode* Deserialize(char *str) {
		if(str == NULL)
			return NULL;
		return des(str);
    }
	TreeNode* des(char *&str)
	{
		if(*str == '#')
		{
			str++;
			return NULL;
		}
		int num = 0;
		while(*str != ',')
			num = num*10 + (*(str++) - '0');
		str++;
		TreeNode *root = new TreeNode(num);
		root->left = des(str);
		root->right = des(str);
		return root;
	}
};