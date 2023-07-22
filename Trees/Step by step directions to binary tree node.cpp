//Prob link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another
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
    
    TreeNode* LCA(TreeNode* root,int p,int q){
        if(!root or p==root->val or q==root->val) return root;
        TreeNode* left = LCA(root->left,p,q);
        TreeNode* right  = LCA(root->right,p,q);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
    bool traverse(TreeNode* root,string& path,int val){
        if(!root) return false;
        if(root->val==val) return true;
        path+='L';
        if(traverse(root->left,path,val)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(traverse(root->right,path,val)){
            return true;
        }
        path.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int st, int dest) {
        TreeNode* lca  = LCA(root,st,dest);
        //find the LCA of the two nodes, then find the directions from LCA to start, then invert them(make it equal to S)
        //then find the directions of destination to the 
        string LtoS="";
        string LtoD="";
        traverse(lca,LtoS,st);
        traverse(lca,LtoD,dest);
        for(auto& it: LtoS) it='U';
        return LtoS + LtoD;
    }
};
