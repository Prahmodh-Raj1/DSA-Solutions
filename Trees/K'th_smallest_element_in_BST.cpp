//Problem link:https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
//TC: O(N) SC: O(N)-Auxillary Stack space
class Solution {
public:
    int cnt,res;
    void inorder(TreeNode* root,int k){
        if(!root) return;
        inorder(root->left,k);
        cnt++;
        if(cnt==k){
            res=root->val;
            return;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt=0;
        inorder(root,k);
        return res;
    }
};
