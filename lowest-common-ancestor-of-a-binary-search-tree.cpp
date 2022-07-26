//Problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//TC: O(N) SC: O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode* cur=root;
        if(cur->val < p->val and cur->val < q->val){
            return lowestCommonAncestor(root->right, p,q);
        }else if(cur->val > p->val and cur->val > q->val){
            return lowestCommonAncestor(root->left, p,q);
        }
        return root;
    }
};
