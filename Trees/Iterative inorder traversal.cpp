//use a stack, also have a node initialised as root of tree, at every iteration take whatever is in 
//the node and put into stack(if node is not null), if there exists a left node, take that ele and push onto
//stack and reassign node,if there exists a right node, take that ele and push onto
//stack and reassign node . if node is null, pop and print stack's top
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){ //TC: O(N) AND SC:O(N)=O(height of tree)
		stack<TreeNode*> st;
		TreeNode* node=root;
		vector<int> inorder;
		while(true){
			if(node!=NULL){
				st.push(node);
				node=node->left;
			}
			else{      //if node=null
				if(st.empty()) break;
				node=st.top();
				st.pop();
				inorder.push_back(node->val);
				node=node->right;
			}
		}
		return inorder;
	}
};
