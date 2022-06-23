//Problem link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

//Recursive dfs  TC: O(N)  SC: O(H)
class Solution {
public:
    int cur;
    int sumNumbers(TreeNode* root) {
        int sum=0;
        cur=root->val;
        summ(root,sum);
        return sum;
    }
    void summ(TreeNode* root,int& sum){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){  //if we've reached the leaf node
            sum+=cur;
            cur=cur/10;
            return;
        }
        if(root->left!=NULL){
            cur=cur*10+root->left->val;
        } 
        summ(root->left,sum);
        if(root->right!=NULL){
            cur=cur*10+root->right->val;
        } 
        summ(root->right,sum);
        cur/=10;
        return;
    }
};
