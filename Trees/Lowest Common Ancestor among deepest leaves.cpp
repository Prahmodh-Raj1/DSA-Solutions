//Prob link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves
//TC: O(N) SC: O(N)
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
    unordered_map<TreeNode*,int> dep;
    int depth(TreeNode* root){
        if(!root) return 0;
        if(dep.find(root)==dep.end()){
            dep[root] = 1  + max(depth(root->left),depth(root->right));
        }
        return dep[root];

    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;
        int l = depth(root->left);
        int r = depth(root->right);
        if(l==r){
            return root;
        } 
        else if(l<r){
            return  lcaDeepestLeaves(root->right);
        }else{
            return lcaDeepestLeaves(root->left);
        }
        return NULL;
    }
};
