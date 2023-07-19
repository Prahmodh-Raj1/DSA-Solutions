//Problem link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
//TC: O(N)  SC: O(1)
int maxAncestorDiff(TreeNode* root, int mini = INT_MAX, int maxi = INT_MIN) {
        // base case
        if (!root) return (maxi - mini);
        // update mini and maxi
        mini = min(mini, root->val), maxi = max(maxi, root->val);
        // finding the maximum distance we would like to find by going left and right
        return max(maxAncestorDiff(root->left, mini, maxi), maxAncestorDiff(root->right, mini, maxi));
    }
