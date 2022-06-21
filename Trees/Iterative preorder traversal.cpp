//Iterative preorder traversal
//We create a stack, push the root of tree onto ur stack, while starting to traverse pop the element 
//in ur stack and print it , then push the right element and the left element of root node and push
//onto stack. print the left elemnt from stack after popping, then follow the above steps until there are no left
//and right for the node
class Solution{          //TC: O(N)      SC: O(N)= in the worst case
public:
	vector<int> preorderTraversal(TreeNode* root){
		vector<int> preorder;
		if(root==NULL) return preorder;
		stack<TreeNode*> st;
		st.push(root);
		while(!st.empty()){
			root=st.top();
			st.pop();
			preorder.push_back(root->val);
			if(root->right!=NULL) st.push(root->right);
			if(root->left!=NULL)  st.push(root->left);
		}
		return preorder;
	}
};
