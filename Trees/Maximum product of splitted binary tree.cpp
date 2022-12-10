//Problem link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
//TC :O(N) SC :O(H) : Auxillary stack space
class Solution {
public:
    long long ans=0,total=0;
    const int mod=1e9+7;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        total+=root->val;
        dfs(root->right);
    }
    int postorder(TreeNode* root){
        if(root==NULL) return 0;
        int curr=postorder(root->left)+postorder(root->right)+root->val;
        ans=max(ans,(total-curr)*curr);
        return curr;
    }
    int maxProduct(TreeNode* root) {
        //int sum=0;
        dfs(root);
        postorder(root);
        return ans%mod;
    }
};

