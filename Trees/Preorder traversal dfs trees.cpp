//Definition for a binory tree node
struct Treenode{
	int val;
	Treenode *left;
	Treenode *right;
};

class Solution{
	private:
	void dfs(TreeNode *node,vector<int> &preorder){
		if(node==NULL) return;
		preorder.push_back(node->val);
		dfs(node->left,preorder);
		dfs(node->right,preorder);
	}
public:
	vector<int> preordertraversal(Treenode* root){
		vector<int> preorder;
		dfs(root,preorder);
		return preorder;        //preorder is the vector that stores the order of traversal
	}
};
