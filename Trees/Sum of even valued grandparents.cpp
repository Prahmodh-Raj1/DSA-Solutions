//Problem link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/ 
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
    int sum=0;
    void work(TreeNode* root){
        if(root==NULL) return;
        int cursum=0;
        if(root->left) cursum+=root->left->val;
        if(root->right) cursum+=root->right->val;
        sum+=cursum;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        if(!(root->val & 1)){
            work(root->left);
            work(root->right);
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        return sum;
    }
};
