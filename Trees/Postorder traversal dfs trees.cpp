//Definition for a binory tree node
struct Treenode{
	int val;
	Treenode *left;
	Treenode *right;
};

class Solution{
	private:
	void dfs(TreeNode *node,vector<int> &postorder){
		if(node==NULL) return;
		
		dfs(node->left,postorder);
		dfs(node->right,postorder);
		postorder.push_back(node->val);
	}
public:
	vector<int> postOrderTraversal(TreeNode* root){
		vector<int> postorder;
		dfs(root,postorder);
		return postorder;        //postorder is the vector that stores the order of traversal
	}
};
