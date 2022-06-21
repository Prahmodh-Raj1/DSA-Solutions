//(height of left subtree) - (height of right subtree) <=1
//Brute force approach
bool chk(Node){               //TC:O(N^2)    SC:O(1)
	if(node==NULL) return true;
	int lh=findhleft(node->left);
	int rh=findhright(node->right);
	if(abs (rh-lh) > 1) return false;
	bool left=chk(node->left);
	bool right=check(node->right);
	if(!left or !right) return false;
	return true;
}

//Optimized solution, if tree is balanced, height of tree is returned, if not balanced, -1 is returned
class Solution{       //TC:O(N)  SC:O(N)
public:
	bool isBalanced(TreeNode* root){
		return check(root)!=-1;
	}
	int check(TreeNode* root){
	 if(root==NULL) return 0;
	 int lh=check(root->left);
	 int rh=check(root->right);
	 if(lh==-1 or rh==-1) return -1;
	 if(abs(lh-rh)>1) return -1;
	 return max(lh,rh) + 1;
    }
};

