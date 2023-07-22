//Prob link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
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
    bool dfscheck(TreeNode* root){
        if(!root->left and !root->right){
            return true;
        }
        if(root->left and !root->right) return true;
         if(root->right and !root->left) return false;
        
        
        
        return dfscheck(root->left) and dfscheck(root->right);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        //conditions to be checked
        //if from the current node, the left node is empty and the node has only the RHS
        //if it's a leaf node, then we need to check for both sides null
        if(root->left==NULL and root->right==NULL) return true;
        queue<TreeNode*> q;
        bool checkend = false;
        q.push(root);
        //When level-order traversal in a complete tree, after the last node, all nodes in the queue should be null
        while(!q.empty()){
            
                TreeNode* cur = q.front();
                q.pop();
                if(!cur) checkend=true;
                else{
                    if(checkend) return false;
                
                    q.push(cur->left);
                    q.push(cur->right);
                }
            
        }
        return true;
    }
};
