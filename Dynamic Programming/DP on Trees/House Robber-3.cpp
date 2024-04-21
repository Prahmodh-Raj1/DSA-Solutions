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
    int dfs(TreeNode* root,unordered_map<TreeNode*,int>& dp){
        if(root==NULL) return 0; //cant rob anything - base condition

        //memoization
        if(dp.count(root)) return dp[root];
        //2 Cases:we can rob, or we can not rob
        //If we rob on the current level, we can only rob from it's grandchildren
        int choose=0;
        if(root->left!=NULL){
            choose+=dfs(root->left->left,dp) + dfs(root->left->right,dp);
        }
        if(root->right!=NULL){
            choose+=dfs(root->right->left,dp)+ dfs(root->right->right,dp);
        }

        choose+=root->val;
        int notchoose = dfs(root->left,dp) + dfs(root->right,dp);  //moving to the next level without robbing
        return dp[root] = max(choose,notchoose);
    }
public:
    int rob(TreeNode* root) {
        //cant rob from back to back levels
        unordered_map<TreeNode*,int> dp;
        return dfs(root,dp);
    }
};
