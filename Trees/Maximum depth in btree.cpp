class Solution{
public:                  //TC: O(N)     SC:O(N) in worst case
	int maxDepth(TreeNode* root){
		if(root==NULL) return 0;
		int lh=maxDepth(root->left);
		int rh=maxDepth(root->right);
		return 1+max(lh,rh);      //taking the max out of left height and right height
	}
};

