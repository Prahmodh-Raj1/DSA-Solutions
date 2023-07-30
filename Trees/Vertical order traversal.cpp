//Problem link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
//TC: O(N) SC: O(level*N)
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
struct node{
    int vertical;
    int level;
    TreeNode* curnode;
    node(TreeNode* _curnode,int _vertical,int _level){
        vertical = _vertical;
        level = _level;
        curnode = _curnode;
    }
};
class Solution {
private:
    void bfs(TreeNode* root,map<int,map<int,multiset<int>>>& mp){
        queue<node> q;
        q.push(node(root,0,0));
        while(!q.empty()){
            for(int i=0;i<q.size();i++){
                TreeNode* cur = q.front().curnode;
                int vertical = q.front().vertical;
                int level = q.front().level;
                q.pop();
                if(cur->left){
                    q.push(node(cur->left,vertical-1,level+1)); //THAT'S HOW THE COORDINATES MOVE AT EVERY NODE FOR EACH LEFT CHILD
                }
                if(cur->right){
                    q.push(node(cur->right,vertical+1,level+1));
                }
                mp[vertical][level].insert(cur->val); 
            }
        }
    }   
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp; //stores mp[vertical] -->  (mp[vertical][level]=val)
        //using a multiset since we need to store even duplicate values in sorted order
        //we first need to sort by vertical, then by level's nodes
        bfs(root,mp); 
        vector<vector<int>> ans;
        for(auto it:mp){
            vector<int> col;
            for(auto i:it.second){
                for(auto p:i.second){
                    col.push_back(p);
                }
                
            }
            ans.push_back(col);
        }
        return ans;
    }
};
