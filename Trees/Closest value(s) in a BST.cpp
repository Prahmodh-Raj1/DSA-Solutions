
//Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
//TC: O(NlogK) SC: O(N)
class Solution {
private:
    vector<int> traversal;
    void inorder(TreeNode* cur){
        if(!cur) return;
        inorder(cur->left);
        traversal.push_back(cur->val);
        inorder(cur->right);
    }
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     *          we will sort your return value in output
     */
    vector<int> closestKValues(TreeNode *root, double target, int k) {
        // write your code here
        priority_queue<pair<double,int>> pq;
        vector<int> ans;
        TreeNode* cur = root;
        if(!root) return ans;
        inorder(cur);
        int n =  traversal.size();
        for(int i=0;i<n;i++){
            double dif = abs(target - double(traversal[i]));
            pq.push({dif,traversal[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        return ans;
        
    }
};
