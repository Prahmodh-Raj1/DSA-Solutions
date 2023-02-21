//Problem link: https://leetcode.com/problems/subtree-of-another-tree/
//TC:O(N) SC:O(N) - Auxillary stack space
    bool isSame(TreeNode* root1,TreeNode* root2){
        if(!root1 and !root2) return true;
        if((!root1 and root2) or (root1 and !root2)) return false;
        if(root1->val!=root2->val) return false;
        return (isSame(root1->left,root2->left) and isSame(root1->right,root2->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSame(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
