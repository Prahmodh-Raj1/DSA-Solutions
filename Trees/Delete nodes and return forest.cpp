//Prob link: https://leetcode.com/problems/delete-nodes-and-return-forest/
//TC: O(N) SC: O(N)
class Solution {
public:
    
    vector<TreeNode*> res;
    
    void util (TreeNode* &root,unordered_map<int,int>& dp)
    {  //using postorder traversal to keep the lower subtrees intact while checking if the node to be deleted is required
        if(root!=NULL)
        {
            util(root->left,dp);
            util(root->right,dp);
            if(dp.find(root->val)!=dp.end())
            {  //this is a node to be deleted
            //adding the left and right subtrees of that node if they exist
                if(root->left)  res.push_back(root->left);
                if(root->right) res.push_back(root->right);
                root=NULL;
				
            }
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int> dp;
        for(int i=0;i<to_delete.size();i++)
            dp[to_delete[i]]=1;
        util(root,dp);
        if(root)
            res.push_back(root);
        return res;
    }
};
