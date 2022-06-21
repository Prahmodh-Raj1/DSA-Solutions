class Solution {
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;   //to store the lvl wise traversal
        if(root == NULL) return ans;   //chking if tree is empty
        queue<TreeNode*> q;  //storing the nodes in a queue
        q.push(root); 
        while(!q.empty()) {
            int size = q.size();
            vector<int> level; 
            for(int i = 0;i<size;i++) {
                TreeNode *node = q.front(); 
                q.pop(); 
                if(node->left != NULL) q.push(node->left);  //chking if left exists
                if(node->right != NULL) q.push(node->right);  //chking if right exists
                level.push_back(node->val); //pushing the node into the vector
            }
            ans.push_back(level);   //pushing the vector into the 2d vector
        }
        return ans; 
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> vec=levelOrder(root);
        int ans=vec[vec.size()-1][0];
        return ans;
    }
    /*Optimal soln
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int> result(root->val,1); //root!=null
        dfs(root,1,result);
        return result.first;
    }
private:
    void dfs(TreeNode* root,int height,pair<int,int>& res)
    {
        if(!root->left && !root->right && height>res.second)
        {
            res = make_pair(root->val,height);
        }
        if(root->left) dfs(root->left,height+1,res);
        if(root->right) dfs(root->right,height+1,res);
    }
};*/
};
