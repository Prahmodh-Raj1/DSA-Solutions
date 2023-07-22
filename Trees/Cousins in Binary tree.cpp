//Prob link: https://leetcode.com/problems/cousins-in-binary-tree
//TC: O(N) SC: O(H)
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
// #2 Method helper
class Solution{
public:
void dfs(TreeNode* root,int prevNodeValue, int currentDepth, int x, int y, int& depthX, int& parentX, int& depthY, int& parentY) {
    // Edge case: When the tree is empty
    if(!root)
        return;

    // If the node value is equal to X
    if(root->val == x) {
        depthX = currentDepth; parentX = prevNodeValue;
        return;
    }

    // If the node value is equal to Y
    if(root->val == y) {
        depthY = currentDepth; parentY = prevNodeValue;
        return;
    }

    dfs(root->left, root->val, currentDepth+1, x, y, depthX, parentX, depthY, parentY);
    dfs(root->right, root->val, currentDepth+1, x, y, depthX, parentX, depthY, parentY);
}

// #2 Method to verify is if the node values X and Y in the tree are cousins or not - O(N) & O(H)
bool isCousins(TreeNode* root, int x, int y) {
    // Edge case: When the tree is empty
    if(!root)
        return false;

    int depthX, parentX; // Require to respectively store the depth and parent of X
    int depthY, parentY; // Require to respectively store the depth and parent of Y

    dfs(root, 0, 0, x, y, depthX, parentX, depthY, parentY);

    // If the depth of X and Y is equal and if their parents are different
    if(depthX == depthY && parentX != parentY)
        return true;
    else
        return false;
}
};
