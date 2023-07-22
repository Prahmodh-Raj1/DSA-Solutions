//Prob link: https://leetcode.com/problems/univalued-binary-tree
//TC: O(N) SC: O(H)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool dfs(TreeNode* root){
        if(!root) return true;
        if(root->left){
            if(root->left->val!=root->val) return false;
        }
        if(root->right){
            if(root->right->val!=root->val) return false;
        }
        return dfs(root->left) and dfs(root->right);
        
        
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root->left and !root->right) return true;
        return dfs(root);
    }
};
