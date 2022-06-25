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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*,bool>> q;
        q.push({root,false});
        int cnt=0;
        vector<vector<int>> ans;
        while(!q.empty()){
            
            int k=q.size();
            for(int i=0;i<k;i++){
                auto p=q.front();
                q.pop();
                if(p.second==true and !p.first->left and !p.first->right) cnt+=p.first->val;
                if(p.first->left!=NULL) q.push({p.first->left,true});
                if(p.first->right!=NULL) q.push({p.first->right,false});
                
            }  
        }
        return cnt;
    }
};
