//Prob link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected
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
unordered_map<int,vector<int>> adj; //adjacency list
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
int  depth(TreeNode* root){
    if(!root) return 0;
    return 1 + max(depth(root->left),depth(root->right));
}
public:
    int amountOfTime(TreeNode* root, int start) {
        //creating the graph
        queue<pair<TreeNode*,int>> q;  //stores the node and it's parent
        q.push({root,-1});
        while(!q.empty()){
            auto [node,parent] = q.front();
            q.pop();
            if(parent!=-1){
                adj[parent].push_back(node->val);
                adj[node->val].push_back(parent);
            }
            if(node->left) q.push({node->left,node->val});
            if(node->right) q.push({node->right,node->val});            
        }
        //BFS
        queue<pair<int,int>> bfs;  //stores the node along with the time taken to reach the node
        unordered_map<int,bool> vis;
        bfs.push({start,0});
        int time=0;
        while(!bfs.empty()){
            auto [node,steps] = bfs.front();
            bfs.pop();
            time = max(time,steps);
            vis[node]=true;
            for(auto it:adj[node]){
                if(vis.find(it)==vis.end()){
                    bfs.push({it,steps+1});
                }
            }    
        }
        return time;
    }
};
